#include <iostream>
#include <cassert>
#include <algorithm>

#include "simpleMetricsListener.hpp"
#include "clusteringMetricsCalculator.hpp"
#include "clusteringMetricsListener.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::forward_list;
using std::string;
using std::find;
using std::shared_ptr;
using std::move;
using std::unordered_map;
using std::swap;
using std::unordered_set;
using namespace antlr4;

namespace JWB {	namespace details {

ClusteringMetricsCalculator::ClusteringMetricsCalculator(AntlrComponentsKeeper &keeper):
	SimpleMetricsCalculator(keeper)
{
	auto trees = keeper.getTrees();
	assert(!trees.empty());

	for (auto const& t : trees)
	{
		ClusteringMetricsListener clusteringListener(classes);
		tree::ParseTreeWalker::DEFAULT.walk(&clusteringListener, t);
	}
}

void ClusteringMetricsCalculator::showUsedClasses() const
{
	cout << endl << "UsedClasses:" << endl;
	for (auto const& c : classes)
	{
		cout << endl << "> " << c->getName() << endl;
		auto const& usedClasses = c->getUsedClasses();

		for (auto  i = usedClasses.begin(); i != usedClasses.end(); i++)
		{
			cout << i->first << endl << "coupling types: ";
			for (auto  j = i->second.begin(); j != i->second.end(); j++)
			{
				cout << ClusteringClassDescription::getStringCouplingType(*j) << " " ;
			}
			cout << endl << endl;
		}
	}
}

void ClusteringMetricsCalculator::showUsingClasses() const
{
	cout << endl << "UsingClasses:" << endl;
	for (auto const& c : classes)
	{
		cout << endl << "> " << c->getName() << endl;
		auto const& usingClasses = c->getUsingClasses();

		for (auto  i = usingClasses.begin(); i != usingClasses.end(); i++)
		{
			cout << i->first << endl << "coupling types: ";
			for (auto  j = i->second.begin(); j!=i->second.end(); j++)
			{
				cout << ClusteringClassDescription::getStringCouplingType(*j) << " " ;
			}
			cout << endl << endl;
		}
	}
}

double ClusteringMetricsCalculator::getAfferentCoupling(bool isNormalized) const
{
	double CA = 0;

	for (auto const& c : classes)
	{
		if (isNormalized)
			{
				if (c->getUsingClasses().size())
					CA += (c->getUsingClasses().size() / (double)classes.size());
				else
					CA += 1;
			}
		else
			CA += (c->getUsingClasses().size());
	}

	return CA / classes.size();
}

double ClusteringMetricsCalculator::getCouplingBetweenObjects(bool isNormalized) const
{
	double CBO = 0;

	for (auto const& c : classes)
	{
		auto numberOfUsedClasses = c->getUsedClasses().size();
		if (isNormalized)
			{
				if (numberOfUsedClasses)
					CBO += (numberOfUsedClasses / (double)classes.size());
				else
					CBO += 1;
			}
		else
			CBO += numberOfUsedClasses;
	}

	return CBO / classes.size();
}

double ClusteringMetricsCalculator::getDataAbstractionCoupling(bool isNormalized) const
{
	double DAC = 0;

	for (auto const& c : classes)
	{
		size_t numberOfUsedClasses = 0;
		auto  usedClasses = c->getUsedClasses();
		for (auto  i = usedClasses.begin(); i != usedClasses.end(); i++)
		{
			if (find(i->second.begin(), i->second.end(), CouplingType::ATTRIBUTE) != i->second.end())
				numberOfUsedClasses++;
		}

		if (isNormalized)
		{
			if (!numberOfUsedClasses)
				DAC += 0.2;
			else
				DAC += (numberOfUsedClasses / (double)classes.size());
		}
		else
			DAC += numberOfUsedClasses;
	}

	return DAC / classes.size();
}

double ClusteringMetricsCalculator::getInstability(bool isNormalized) const
{
	double INS = 0;

	for (auto const& c : classes)
	{
		size_t CBO = c->getUsedClasses().size();
		size_t CA = c->getUsingClasses().size();

		double classInstability = 0;
		if (CA || CBO)
			classInstability = (double)CBO / (CBO + CA);

		if (isNormalized)
			INS += std::abs(0.5 - classInstability);
		else
			INS += classInstability;
	}

	return INS / classes.size();
}

double ClusteringMetricsCalculator::getInformationFlowBasedCohesion(bool isNormalized) const
{
	double ICH = 0;
	for (auto const& c : classes)
	{
		size_t ICHForClass = 0;

		auto const& methods = c->getMethods();
		for (auto i = methods.begin(); i != methods.end(); i++)
		{
			auto numberOfParameters = i->second->getParameters().size();
			for (auto j = methods.begin(); j != methods.end(); j++)
			{
				ICHForClass += (1 + numberOfParameters) * i->second->getNumberOfCall(j->first);
			}
		}

		if (isNormalized)
			ICH += (1 - (double)ICHForClass / CONSTANT_FOR_NORMALIZING);
		else
			ICH += ICHForClass;
	}

	return ICH / classes.size();
}

double ClusteringMetricsCalculator::getTightClassCoupling(bool isNormalized) const
{
	double TCC = 0;
	for (auto const& c : classes)
	{
		size_t numberOfPairsThatHaveCommonAttributes = 0;

		auto const& methods = c->getMethods();
		size_t numberOfMethods = methods.size();
		if (numberOfMethods < 2)
			continue;

		for (auto i = methods.begin(); i != methods.end(); i++)
		{
			for (auto j = std::next(i,1); j != methods.end(); j++)
			{
				if (std::find_first_of(i->second->getUsedAttributes().begin(), i->second->getUsedAttributes().end(),
					j->second->getUsedAttributes().begin(), j->second->getUsedAttributes().end()) != i->second->getUsedAttributes().end())
						numberOfPairsThatHaveCommonAttributes++;
			}
		}

		if (isNormalized)
			TCC += (1 - (double)numberOfPairsThatHaveCommonAttributes * 2 / (numberOfMethods * (numberOfMethods - 1)));
		else
			TCC += ((double)numberOfPairsThatHaveCommonAttributes * 2 / (numberOfMethods * (numberOfMethods - 1)));
	}

	return TCC / classes.size();
}

// It performs dfs and for current method finds the attributes that it implicitly uses through other methods of the class
// Attributes are stored in the std::shared_ptr<std::unordered_set<std::string>> attributes
// Used to calculate LCC metric
void collectAllAttributes(
	const unordered_map <string, shared_ptr <ClusteringMethodDescription> > &allMethods,
	shared_ptr<unordered_set<string>> &attributes,
	const string &calledMethod,
	unordered_map<string, bool> &used
)
{
	if (used[calledMethod])
		return;

	used[calledMethod] = true;

	auto currentCalledMethod = allMethods.find(calledMethod);
	if (currentCalledMethod == allMethods.end())
		return;

	for (auto &a : currentCalledMethod->second->getUsedAttributes())
	{
		attributes->insert(a);
	}

	for (auto const& cm : currentCalledMethod->second->getCalledMethods())
	{
		if(cm.second->type == TypeOfCalledMethod::CURRENT_CLASS_METHOD)
			 collectAllAttributes(allMethods, attributes, cm.first, used);
	}
}

double ClusteringMetricsCalculator::getLooseClassCoupling(bool isNormalized) const
{
	double LCC = 0;

	for (auto const& c : classes)
	{
		size_t numberOfPairsThatHaveCommonAttributes = 0;

		auto const& methods = c->getMethods();
		size_t numberOfMethods = methods.size();
		if (numberOfMethods < 2)
			continue;

		unordered_map<string, bool> used;
		vector< shared_ptr< unordered_set<string> > > allAttributes;

		for(auto const& m : methods)
			used.insert({m.first, false});

		for(auto const& m : methods)
		{
			shared_ptr<unordered_set<string>> attributes(new unordered_set< string>);
			collectAllAttributes(methods, attributes, m.first, used);
			allAttributes.push_back(attributes);
			for(auto const& i : methods)
				used[i.first] = false;
		}

		for (auto i = allAttributes.begin(); i != allAttributes.end(); i++)
		{
			for (auto j = std::next(i,1); j != allAttributes.end(); j++)
			{
				if (std::find_first_of(i->get()->begin(), i->get()->end(),
					j->get()->begin(), j->get()->end()) != i->get()->end())
						numberOfPairsThatHaveCommonAttributes++;
			}
		}

		if (isNormalized)
			LCC += (1 - (double)numberOfPairsThatHaveCommonAttributes * 2 / (numberOfMethods * (numberOfMethods - 1)));
		else
			LCC += ((double)numberOfPairsThatHaveCommonAttributes * 2 / (numberOfMethods * (numberOfMethods - 1)));
	}

	return LCC / classes.size();
}


double ClusteringMetricsCalculator::getLackOfCohesionInMethods1(bool isNormalized) const
{
	double LCOM1 = 0;
	for (auto const& c : classes)
	{
		size_t numberOfPairsThatHaveCommonAttributes = 0;
		size_t numberOfPairsThatHaveNotCommonAttributes = 0;

		auto const& methods = c->getMethods();
		size_t numberOfMethods = methods.size();
		if (numberOfMethods < 2)
			continue;

		for (auto i = methods.begin(); i != methods.end(); i++)
		{
			for (auto j = std::next(i,1); j != methods.end(); j++)
			{
				if (std::find_first_of(i->second->getUsedAttributes().begin(), i->second->getUsedAttributes().end(),
					j->second->getUsedAttributes().begin(), j->second->getUsedAttributes().end()) != i->second->getUsedAttributes().end())
						numberOfPairsThatHaveCommonAttributes++;
				else
						numberOfPairsThatHaveNotCommonAttributes++;
			}
		}

		if (isNormalized)
			LCOM1 += (std::max(0, (int)(numberOfPairsThatHaveNotCommonAttributes - numberOfPairsThatHaveCommonAttributes)) /
										(double)(numberOfPairsThatHaveNotCommonAttributes + numberOfPairsThatHaveCommonAttributes));
		else
			LCOM1 += std::max(0, (int)(numberOfPairsThatHaveNotCommonAttributes - numberOfPairsThatHaveCommonAttributes));
	}

	return LCOM1 / classes.size();
}

double ClusteringMetricsCalculator::getLackOfCohesionInMethods2(bool isNormalized) const
{
	double LCOM2 = 0;
	for (auto const& c : classes)
	{
		auto const& methods = c->getMethods();
		int numberOfMethods = methods.size();
		if (numberOfMethods < 2)
			continue;

		auto const& attributes = c->getAttributes();
		size_t numberOfAttributes = attributes.size();
		if(!numberOfAttributes)
		{
			double classLCOM2 = -numberOfMethods / (double)(1 - numberOfMethods);

			if (isNormalized)
			{
				if (classLCOM2 > 1)
					LCOM2 += (classLCOM2 / 2);
			}
			else
				LCOM2 += classLCOM2;

			continue;
		}

		size_t numberOfMethodsThatUseAttributes = 0;

		for (auto const& a : attributes)
		{
			for (auto const& m : methods)
			{
				auto const& usedAttributes = m.second->getUsedAttributes();
				if (usedAttributes.find(a) != usedAttributes.end())
					numberOfMethodsThatUseAttributes++;
			}
		}

		double classLCOM2 = ((double)numberOfMethodsThatUseAttributes / attributes.size() - numberOfMethods) / (1 - numberOfMethods);
		if (isNormalized)
		{
			if (classLCOM2 > 1)
				LCOM2 += (classLCOM2 / 2);
		}
		else
			LCOM2 += classLCOM2;
	}

	return LCOM2 / classes.size();
}

// Generate graph described in comments for getNumberOfConnectedComponents() method
// Used to calculate LCOM4 metric
vector< forward_list<int> > generateGraphOfMethodsConnections(
	const unordered_map <string, shared_ptr <ClusteringMethodDescription> > &methods
)
{
	vector< forward_list<int> > areConnected(methods.size(), forward_list<int>());

	int k = 0;
	for (auto i = methods.begin(); i != methods.end(); i++)
	{
		int m = k;
		for (auto j = std::next(i,1); j != methods.end(); j++)
		{
			m++;
			auto calledMethods = j->second->getCalledMethods();
			if (calledMethods.find(i->first) != calledMethods.end())
			{
				areConnected[k].push_front(m);
				areConnected[m].push_front(k);
				continue;
			}

			calledMethods = i->second->getCalledMethods();
			if (calledMethods.find(j->first) != calledMethods.end())
			{
				areConnected[k].push_front(m);
				areConnected[m].push_front(k);
				continue;
			}

			if (std::find_first_of(i->second->getUsedAttributes().begin(), i->second->getUsedAttributes().end(),
			j->second->getUsedAttributes().begin(), j->second->getUsedAttributes().end()) != i->second->getUsedAttributes().end())
			{
				areConnected[k].push_front(m);
				areConnected[m].push_front(k);
				continue;
			}
		}
		k++;
	}

	return move(areConnected);
}

// The most common realization of traversing the graph in depth
// It used to calculate the LCOM4 metric
void dfs(int v, vector<bool> &used, vector< forward_list<int> > &areConnected)
{
	used[v] = true;
	for (auto a : areConnected[v])
	{
		if (!used[a])
			dfs(a, used, areConnected);
	}
}

// It returns number of connected components in class, where two methods are connected if one of them calls the other, or
// they access the same attribute
size_t getNumberOfConnectedComponents(const unordered_map <string, shared_ptr <ClusteringMethodDescription> > &methods)
{
	size_t numberOfMethods = methods.size();
	size_t numberOfComponents = 0;

	auto areConnected = generateGraphOfMethodsConnections(methods);
	vector<bool> used(numberOfMethods, false);

	for (int i = 0; i < numberOfMethods; i++)
		if (!used[i])
		{
			numberOfComponents++;
			dfs(i, used, areConnected);
		}

	return numberOfComponents;
}

double ClusteringMetricsCalculator::getLackOfCohesionInMethods4(bool isNormalized) const
{
	double LCOM4 = 0;

	for (auto const& c : classes)
	{

		auto const& methods = c->getMethods();
		size_t numberOfMethods = methods.size();
		if (numberOfMethods < 2)
			continue;

		size_t numberOfConnectedComponents = getNumberOfConnectedComponents(methods);

		if (isNormalized)
		{
			if (numberOfConnectedComponents > 1)
				LCOM4 += ((double)numberOfConnectedComponents / numberOfMethods);
		}
		else
			LCOM4 += numberOfConnectedComponents;
	}

	return LCOM4 / classes.size();
}




double ClusteringMetricsCalculator::getMessagePassingCoupling(bool isNormalized) const
{
	double MPC = 0;
	for(auto const& c : classes)
	{
		size_t numberOfMessagePassing = 0;

		for(auto const& m : c->getMethods())
		{
			for (auto const& cm : m.second->getCalledMethods())
			{
				if(cm.second->type == TypeOfCalledMethod::DIFFERENT_CLASS_METHOD)
				{
					numberOfMessagePassing += cm.second->numberOfCalls;
				}
			}
		}

		if (isNormalized)
			MPC += ((double)numberOfMessagePassing / CONSTANT_FOR_NORMALIZING);
		else
			MPC += numberOfMessagePassing;
	}

	return MPC / classes.size();
}

double ClusteringMetricsCalculator::getResponseForAClass(bool isNormalized) const
{
	double metricValue = 0;

	for(auto const& c : classes)
	{
		size_t responseForAClass = 0;
		auto const& methods = c->getMethods();
		for(auto const& m : methods)
		{
			for (auto const& cm : m.second->getCalledMethods())
			{
				if(cm.second->type == TypeOfCalledMethod::DIFFERENT_CLASS_METHOD)
				{
					responseForAClass++;
				}
			}
		}

		if(isNormalized)
			metricValue += (1 - responseForAClass / (double)(CONSTANT_FOR_NORMALIZING - methods.size()));
		else
			metricValue += (responseForAClass + methods.size());
	}

	return metricValue / classes.size();
}

double ClusteringMetricsCalculator::getNumberOfMethods(bool isNormalized) const
{
	double NOM = 0;

	for (auto const& c : classes)
	{
		size_t numberOfMethods = c->getNumberOfMethods();

		if (isNormalized)
		{
			switch (numberOfMethods)
			{
			case 1: NOM += 1;
					break;
			default:
				{
					if (numberOfMethods < 3 || numberOfMethods > 7)
						NOM += ((CONSTANT_FOR_NORMALIZING - (double)numberOfMethods) / CONSTANT_FOR_NORMALIZING);
				}
			}
		}
		else
			NOM += numberOfMethods;
	}

	return NOM / classes.size();
}

double ClusteringMetricsCalculator::getNumberOfAttributes(bool isNormalized) const
{
	double NOA = 0;

	for (auto const& c : classes)
	{
		size_t numberOfAttributes = c->getNumberOfAttributes();

		if (isNormalized)
		{
			switch (numberOfAttributes)
			{
			case 0:
			case 1: NOA += ((double)numberOfAttributes / CONSTANT_FOR_NORMALIZING);
					break;
			default:
				{
					if (numberOfAttributes < 2 || numberOfAttributes > 5)
						NOA += ((CONSTANT_FOR_NORMALIZING - (double)numberOfAttributes) / CONSTANT_FOR_NORMALIZING);
				}
			}
		}
		else
			NOA += numberOfAttributes;
	}

	return NOA / classes.size();
}

double ClusteringMetricsCalculator::getLocalityOfData(bool isNormalized) const
{
	double LD = 0;

	for (auto const& c : classes)
	{
		double classLocalityOfData = 0;

		size_t numberOfLocalVariables = 0;
		size_t numberOfAllVariables = 0;

		for (auto const& m : c->getMethods())
		{
			size_t numberOfLocalVariablesInCurrentMethod = 0;

			for(auto const& v : m.second->getUsedLocalVariables())
				numberOfLocalVariablesInCurrentMethod += v.second;

			numberOfAllVariables += (numberOfLocalVariablesInCurrentMethod + m.second->getUsedAttributes().size());
			numberOfLocalVariables += numberOfLocalVariablesInCurrentMethod;
		}

		if (numberOfAllVariables)
			classLocalityOfData = (double)numberOfLocalVariables / numberOfAllVariables;
		else
			if (isNormalized)
				LD += 1;
			else
				continue;

		if (isNormalized)
			LD += (1 - classLocalityOfData);
		else
			LD += classLocalityOfData;
	}

	return LD / classes.size();
}

double ClusteringMetricsCalculator::getAggregatedMetric(bool isNormalized) const
{
	double metricValue = 0;

	// metricValue += getAfferentCoupling(isNormalized);
	// metricValue += getCouplingBetweenObjects(isNormalized);
	// metricValue += getDataAbstractionCoupling(isNormalized);
	// metricValue += getInstability(isNormalized);
	metricValue += getInformationFlowBasedCohesion(isNormalized);
	metricValue += getTightClassCoupling(isNormalized);
	metricValue += getLooseClassCoupling(isNormalized);
	metricValue += getNumberOfMethods(isNormalized);
	metricValue += getNumberOfAttributes(isNormalized);
	metricValue += getMessagePassingCoupling(isNormalized);
	metricValue += getResponseForAClass(isNormalized);
	metricValue += getLocalityOfData(isNormalized);
	metricValue += getLackOfCohesionInMethods1(isNormalized);
	metricValue += getLackOfCohesionInMethods2(isNormalized);
	metricValue += getLackOfCohesionInMethods4(isNormalized);

	return metricValue;
}


void ClusteringMetricsCalculator::createInitialFragmentation()
{
	std::list <std::shared_ptr <ClusteringClassDescription> > newClasses;
	for (auto c : classes)
		for (auto m : c->getMethods())
			newClasses.emplace_back(new ClusteringClassDescription(m.second));

	swap(classes, newClasses);
}

std::pair<std::shared_ptr <ClusteringClassDescription>, std::shared_ptr <ClusteringClassDescription> > ClusteringMetricsCalculator::mergeClasses(int i, int j)
{
	auto iter1 = classes.begin();
	std::advance(iter1, i);
	auto class1 = *iter1;

	auto iter2 = classes.begin();
	std::advance(iter2, j);
	auto class2 = *iter2;

	classes.erase(iter1);
	classes.erase(iter2);

	classes.emplace_back(new ClusteringClassDescription(class1.get(), class2.get()));

	return std::pair<std::shared_ptr <ClusteringClassDescription>, std::shared_ptr <ClusteringClassDescription> >(class1, class2);
}

void ClusteringMetricsCalculator::separateClass(
	int i,
	int j,
	std::pair<std::shared_ptr <ClusteringClassDescription>, std::shared_ptr <ClusteringClassDescription> > const& mergedPair
)
{
	auto iter1 = classes.begin();
	std::advance(iter1, i);
	classes.insert(iter1, mergedPair.first);

	auto iter2 = classes.begin();
	std::advance(iter2, j);
	classes.insert(iter2, mergedPair.second);

	classes.pop_back();
}

void ClusteringMetricsCalculator::showClusteringMetrics(bool isNormalized) const
{
	double metricValue = 0;
	double mainValue = 0;

	cout << endl;

	metricValue = getAfferentCoupling(isNormalized);
	cout << "Afferent coupling: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getCouplingBetweenObjects(isNormalized);
	cout << "Coupling between objects: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getDataAbstractionCoupling(isNormalized);
	cout << "Data abstraction coupling: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getInstability(isNormalized);
	cout << "Instability: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getInformationFlowBasedCohesion(isNormalized);
	cout << "Information flow based cohesion: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getTightClassCoupling(isNormalized);
	cout << "Tight class coupling: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getLooseClassCoupling(isNormalized);
	cout << "Loose class coupling: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getLackOfCohesionInMethods1(isNormalized);
	cout << "LCOM1: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getLackOfCohesionInMethods2(isNormalized);
	cout << "LCOM2: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getLackOfCohesionInMethods4(isNormalized);
	cout << "LCOM4: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getLocalityOfData(isNormalized);
	cout << "Locality of data: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getMessagePassingCoupling(isNormalized);
	cout << "Message passing coupling: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getNumberOfAttributes(isNormalized);
	cout << "Number of attributes: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getNumberOfMethods(isNormalized);
	cout << "Number of methods: " << metricValue << endl;
	mainValue += metricValue;

	metricValue = getResponseForAClass(isNormalized);
	cout << "Response for a class: " << metricValue << endl;
	mainValue += metricValue;

	cout << "Summ: " << mainValue << endl;
}

std::string ClusteringMetricsCalculator::cluster()
{
	createInitialFragmentation();

	// cout <<"-----------------------------"<<endl;
	// cout <<"Current splitting:"<<endl;
	// showNumberOfMethods();

	std::list <std::shared_ptr <ClusteringClassDescription> > newClasses;
	int numberOfClasses = classes.size();
	string value = "";
	double globalMinMetricValue = 10e5;

	while (numberOfClasses > 1)
	{
		// cout << endl<< "Possible variants of merging:" << endl;
		double minMetricValue = 10e5;
 		int imin = 0;
		int jmin = 1;
		for(int i = 0; i < numberOfClasses; ++i)
 		{
			for(int j = i + 1; j < numberOfClasses; ++j)
 			{
				auto mergedPair = mergeClasses(i, j);

				for(auto const& c : classes)
				{
					for(auto const& m : c->getMethods())
					{
						m.second->updateCalledMethods(c->getMethods());
						m.second->updateUsedAttributes(c->getAttributes());
					}
				}

				double metricValue = getAggregatedMetric();

				// cout << mergedPair.first->getName() + mergedPair.second->getName() << ' ' << metricValue << endl;
				// showClusteringMetrics();

				if (metricValue < minMetricValue)
				{
					minMetricValue = metricValue;
					imin = i;
					jmin = j;
				}

				separateClass(i, j, mergedPair);
			}
		}
		mergeClasses(imin, jmin);

		if (minMetricValue < globalMinMetricValue)
		{
			globalMinMetricValue = minMetricValue;
			value = "Optimal splitting is:\n";
			for (auto c : classes)
			{
				value += "> ";
				for(auto m : c->getMethods())
				{
					value += m.first + ' ';
				}
				value += "\n";
			}
		}

		numberOfClasses--;
		// cout <<"-----------------------------"<<endl;
		// cout << "Current splitting:"<<endl;
		// showNumberOfMethods();
	}

	return value;
}

}}
