#include <algorithm>
#include <iostream>
#include <cassert>
#include <memory>

#include "simpleMetricsCalculator.hpp"
#include "simpleMetricsListener.hpp"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::swap;
using namespace antlr4;

namespace JWB {	namespace details {

SimpleMetricsCalculator::SimpleMetricsCalculator(AntlrComponentsKeeper &keeper)
{
	tokens = keeper.getTokens();
	auto trees = keeper.getTrees();

	assert(!tokens.empty());
	assert(!trees.empty());

	for (auto const& t : trees)
	{
		SimpleMetricsListener simpleMetricsListener(this);
		tree::ParseTreeWalker::DEFAULT.walk(&simpleMetricsListener, t);
	}
}

void SimpleMetricsCalculator::bumpNumberSourceLinesOfCode()
{
	numberSourceLinesOfCode++;
}

std::list <std::shared_ptr <ClusteringClassDescription> > const& SimpleMetricsCalculator::getClasses() const
{
	return classes;
}

void SimpleMetricsCalculator::setClasses(std::list <std::shared_ptr <ClusteringClassDescription> > newClasses)
{
	swap(newClasses, classes);
}

void SimpleMetricsCalculator::bumpNumberSourceLinesOfCode(size_t number)
{
	numberSourceLinesOfCode += number;
}

void SimpleMetricsCalculator::addClass(shared_ptr <ClusteringClassDescription> const &classPtr)
{
	assert(classPtr.get());
	classes.push_front(classPtr);
}

void SimpleMetricsCalculator::addInterface(shared_ptr <ClusteringInterfaceDescription> const &interfacePtr)
{
	assert(interfacePtr.get());
	interfaces.push_back(interfacePtr);
}


size_t SimpleMetricsCalculator::getNumberOfCommentLines() const
{
	size_t numberOfCommentLines = 0;

	for (auto const& ts : tokens)
	{
		for(auto const& t : ts->getTokens())
		{
			// If token is comment, it is located in hidden channel and getChannel() return 1
			// If token doesn't located in hidden channel, getChannel() return 0 and we move on to the next iteration
			if (!t->getChannel())
				continue;

			if (t->getText().substr(0,2) == "//")
			{
				numberOfCommentLines++;
				continue;
			}

			// We count the number of lines in the comments, so in a multiline comment, we need to count the line feed characters
			for(auto const& c : t->getText())
			{
				if (c == '\n')
					numberOfCommentLines++;
			}

			// Last line hasn`t feed character
			numberOfCommentLines++;
		}
	}

	return numberOfCommentLines;
}

void SimpleMetricsCalculator::showNumberOfMethods() const
{
	for (auto const& c : classes)
	{
		cout << c->getName()  << " has " << c->getNumberOfMethods() << " methods, "
			 << c->getNumberOfPrivateMethods() << " of which is private." << endl;
	}
	for (auto const& i : interfaces)
	{
		cout << i->getName()  << " has " << i->getNumberOfMethods() << " methods, "
		 	 << i->getNumberOfPrivateMethods() << " of which is private." << endl;
	}
}

void SimpleMetricsCalculator::showNumberOfFields() const
{
	for (auto const& c : classes)
	{
		cout << c->getName()  << " has " << c->getNumberOfAttributes() << " attributes, "
		 	 << c->getNumberOfPrivateAttributes() << " of which is private." << endl;
	}
}

double SimpleMetricsCalculator::getMethodHidingFactor() const
{
	size_t numOfMethods = 0;
	size_t numOfPrivateMethods = 0;

	for (auto const& c : classes)
	{
		numOfMethods += c->getNumberOfMethods();
		numOfPrivateMethods += c->getNumberOfPrivateMethods();
	}

	for (auto const& i : interfaces)
	{
		numOfMethods += i->getNumberOfMethods();
		numOfPrivateMethods += i->getNumberOfPrivateMethods();
	}

	if (!numOfMethods)
		return 0;

	return (double)numOfPrivateMethods / numOfMethods;
}

double SimpleMetricsCalculator::getAttributeHidingFactor() const
{
	size_t numOfAttributes = 0;
	size_t numOfPrivateAttributes = 0;

	for (auto const& c : classes)
	{
		numOfAttributes += c->getNumberOfAttributes();
		numOfPrivateAttributes += c->getNumberOfPrivateAttributes();
	}

	if (!numOfAttributes)
		return 0;

	return (double)numOfPrivateAttributes / numOfAttributes;
}

size_t SimpleMetricsCalculator::getSourceLinesOfCode() const
{
	return numberSourceLinesOfCode;
}

double SimpleMetricsCalculator::getCommentPercentage() const
{
	return (double)getNumberOfCommentLines() / getSourceLinesOfCode();
}

void SimpleMetricsCalculator::showCyclomaticComplexities() const
{
	cout << endl << "Cyclomatic complexities:" << endl;
	for (auto const& c : classes)
	{
		cout << endl << "> " << c->getName() << endl;
		auto const& methods = c->getMethods();

		for (auto m : methods)
		{
			cout << m.second->getName() << " — " << m.second->getIndependentPaths() << endl;
		}

		cout << "Average cyclomatic complexity — " << c->getAverageCyclomaticComplexity() << endl;
	}
}

size_t SimpleMetricsCalculator::getAverageCyclomaticComplexity() const
{
	int sumOfCyclomaticComplexities = 0;

	for (auto const& c : classes)
		sumOfCyclomaticComplexities += c->getAverageCyclomaticComplexity();

	if (classes.empty())
		return 0;

	return	(double)sumOfCyclomaticComplexities / classes.size() + 0.5;
}

}}
