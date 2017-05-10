#include "treeMetricsCalculator.hpp"
#include "constructInheritanceTree.hpp"
#include "inheritanceFactorVisitor.hpp"
#include "graphSearchFunctions.hpp"
#include "treePrinterVisitor.hpp"
#include "numberOfChildrenVisitor.hpp"
#include "attributeInheritanceFactorVisitor.hpp"
#include "classNamesVisitor.hpp"

#include <exception>
#include <boost/optional.hpp>
#include <numeric>
#include <cmath>

using std::unordered_set;
using std::vector;
using std::move;
using std::pair;
using std::string;
using std::accumulate;
using std::abs;
using std::remove_if;

namespace JWB {	namespace details {

class ClassListsVisitor;

/// @class ReturnVisitorStatus<ClassListsVisitor>
/// @brief Used by ClassListsVisitor to contain classes that do not have parents (while visiting is not in valid state).
template <>
struct ReturnVisitorStatus<ClassListsVisitor>
{
	unordered_set<Node const*> classLists;
};

/// @class ClassListsVisitor
/// @brief Additional visitor that gets all the classes that do not have parents in the inheritance tree.
class ClassListsVisitor : public Visitor
{
public:
	ClassListsVisitor() = delete;
	ClassListsVisitor(ClassListsVisitor const&) = delete;
	ClassListsVisitor(ClassListsVisitor&&) = default;
	ClassListsVisitor& operator=(ClassListsVisitor const&) = delete;
	ClassListsVisitor& operator=(ClassListsVisitor&&) = delete;

	ClassListsVisitor(unordered_set<Node const*>& filter, ReturnVisitorStatus<ClassListsVisitor>& result) :
		Visitor(filter),
		result(result)
	{}

	void visit(TreeClassDescription const*) override {}

	void visit(TreeInterfaceDescription const*) override {}

	void visitBack(TreeClassDescription const*) override
	{
		for (auto const* x : Visitor::node->getInheritors())
		{
			result.classLists.erase(x);
		}
		result.classLists.insert(node);
	}

	void visitBack(TreeInterfaceDescription const*) override {};

private:
	ReturnVisitorStatus<ClassListsVisitor>& result;
};

// Gets classes without parents from inheritance tree. Here classes are classes only.
vector<Node const*> privateGetClassLists(InheritanceTree const& inheritanceTree)
{
	auto result = inheritanceTree.dfsDown<ClassListsVisitor>();
	vector<Node const*> classLists(result.classLists.size());
	copy(result.classLists.begin(), result.classLists.end(), classLists.begin());
	// It is worth mentioning, that classLists does not have any order due to result.classLists is an unorder_map.
	sort(classLists.begin(), 
		classLists.end(), 
		[](Node const* x, Node const* y) 
		{ return x->getInterface()->getName() < y->getInterface()->getName(); } );
	return move(classLists);
}

/// @class ResultContainter
/// @brief Additional structure for lazy storage of metrics results.
class TreeMetricsCalculator::ResultContainter
{
public:
	ResultContainter() = default;

	// Alias for composition of boost::optional and ReturnVisitorStatus.
	template <typename T>
	using OptRes = typename boost::optional<ReturnVisitorStatus<T>>;

	// The following methods return metrics results and counts them, if necessary.

	// auto = ReturnVisitorStatus<InheritanceAndPolymorphismFactorVisitor>, others have other template param.
	auto const& getInheritanceAndPolymorphismFactorResult(vector<Node const*> const& classLists) const
	{
		if (!inheritanceAndPolymorphismFactorResult)
			inheritanceAndPolymorphismFactorResult = countMetric<InheritanceAndPolymorphismFactorVisitor>(classLists);
		return inheritanceAndPolymorphismFactorResult.value();
	}

	auto const& getAttributeInheritanceFactorResult(vector<Node const*> const& classLists) const
	{
		if (!attributeInheritanceFactorResult)
			attributeInheritanceFactorResult = countMetric<AttributeInheritanceFactorVisitor>(classLists);
		return attributeInheritanceFactorResult.value();
	}

	auto const& getNumberOfChildrenResult(vector<Node const*> const& classLists) const
	{
		if (!numberOfChildrenResult)
			numberOfChildrenResult = countMetric<NumberOfChildrenVisitor>(classLists);
		return numberOfChildrenResult.value();
	}

	// Gets only classes names.
	auto const& getClassNamesResult(vector<Node const*> const& classLists) const
	{
		if (!classNamesResult)
			classNamesResult = countMetric<ClassNamesVisitor>(classLists);
		return classNamesResult.value();
	}

	// Gets both classes and iterfaces names.
	auto const& getClassNamesResult(InheritanceTree const& inheritanceTree) const
	{
		if (!intarfacesAndClassNamesResult)
			intarfacesAndClassNamesResult = countMetric<ClassNamesVisitor>(inheritanceTree);
		return intarfacesAndClassNamesResult.value();
	}

	graphSearchFunctions::DepthCount const& getDepthResult(InheritanceTree const& inheritanceTree) const
	{
		if (!depthResult)
			depthResult = move(inheritanceTree.lambdaDfs(graphSearchFunctions::depthCounter()));
		return depthResult.value();
	}

	graphSearchFunctions::WidthCount const& getWidthResult(InheritanceTree const& inheritanceTree) const
	{
		if (!widthResult)
			widthResult = move(inheritanceTree.lambdaDfs(graphSearchFunctions::widthCounter()));
		return widthResult.value();
	}

	
private:
	template <typename T>
	OptRes<T> static countMetric(vector<Node const*> const& classLists)
	{
		ReturnVisitorStatus<T> result;
		unordered_set<Node const*> filter;
		T visitor(filter, result);
		for (auto const* x : classLists)
		{
			takeVisitorDown(&visitor, x);
		}
		return move(result);
	}

	template <typename T>
	OptRes<T> static countMetric(InheritanceTree const& inheritanceTree)
	{
		return move(inheritanceTree.dfsDown<T>());
	}

	OptRes<InheritanceAndPolymorphismFactorVisitor> mutable inheritanceAndPolymorphismFactorResult;
	OptRes<AttributeInheritanceFactorVisitor> mutable attributeInheritanceFactorResult;
	OptRes<NumberOfChildrenVisitor> mutable numberOfChildrenResult;
	OptRes<ClassNamesVisitor> mutable classNamesResult;
	OptRes<ClassNamesVisitor> mutable intarfacesAndClassNamesResult;
	boost::optional<graphSearchFunctions::DepthCount> mutable depthResult;
	boost::optional<graphSearchFunctions::WidthCount> mutable widthResult;
};

TreeMetricsCalculator::TreeMetricsCalculator(AntlrComponentsKeeper &keeper) :
	inheritanceTree(treeConstruction::constructInheritanceTree(keeper)),
	results(new ResultContainter()),
	classLists(privateGetClassLists(inheritanceTree))
{}

// Gets vectors and zips those elements, that value from analiticsVector differs less than a half from average.
// Obtained vector is set as first element of the pair.
// Average is returned as second element of the pair.
template <typename T, typename U>
TreeMetricsCalculator::analitics<T, U>  scan(
	vector<string> const& classNames,
	vector<T> const& analiticsVector,
	U average
	)
{
	assert(!analiticsVector.empty());
	assert(analiticsVector.size() == classNames.size());
	pair<vector<pair<string, T>>, double> result = { {}, average };
	auto analiticsVectorIterator = analiticsVector.begin();
	for (auto _b = ++classNames.cbegin(), _e = classNames.cend(); _b != _e; ++_b)
	{
		if (abs(*analiticsVectorIterator - average) > average / 2)
		{
			result.first.emplace_back(*_b, *analiticsVectorIterator);
		}
		analiticsVectorIterator++;
	}
	return move(result);
}

// Gets vectors and zips them.
// Obtained vector is set as first element of the pair.
// Average is returned as second element of the pair.
template <typename T, typename U>
TreeMetricsCalculator::analitics<T, U> totalAnalyzis(
	vector<string> const& classNames,
	vector<T> const& analiticsVector,
	U average
	)
{
	assert(!analiticsVector.empty());
	assert(analiticsVector.size() == classNames.size());
	pair<vector<pair<string, T>>, double> result = { {}, average };
	result.first.resize(classNames.size());
	std::transform(classNames.cbegin(), classNames.cend(), 
					analiticsVector.cbegin(), result.first.begin(), 
					[](string const& s, T x) -> pair<string,T> { return {s, x}; });
	return move(result);
}

// Gets mean value from given vector.
template <typename T>
double meanValue(vector<T> const& v)
{
	assert(!v.empty());
	return (double)accumulate(v.begin(), v.end(), 0) / v.size();
}

// If second argument is 0, return 0. Otherwise divides elements.
template <typename T, typename U>
double safeDivide(T x, U y)
{
	return y ? (double)x / y : 0;
}

double TreeMetricsCalculator::getMethodInheritanceFactor() const
{
	assert(results);
	auto const& result = results->getInheritanceAndPolymorphismFactorResult(classLists);
	return safeDivide(result.inheritedMethodNumber, result.totalMethodNumber);
}

TreeMetricsCalculator::analitics<int64_t, double> TreeMetricsCalculator::scanMethodInheritanceFactor() const
{
	return move(scan(results->getClassNamesResult(classLists).namesList, 
					results->getInheritanceAndPolymorphismFactorResult(classLists).inheritedMethodOfEveryClass,
					getMethodInheritanceFactor()));
}

TreeMetricsCalculator::analitics<int64_t, double> TreeMetricsCalculator::totalAnalyzisMethodInheritanceFactor() const
{
	return move(totalAnalyzis(results->getClassNamesResult(classLists).namesList, 
							results->getInheritanceAndPolymorphismFactorResult(classLists).inheritedMethodOfEveryClass,
							getMethodInheritanceFactor()));
}

double TreeMetricsCalculator::getAttributeInheritanceFactor() const
{
	assert(results);
	auto const& result = results->getAttributeInheritanceFactorResult(classLists);
	return safeDivide(result.inheritedAttributeNumber, result.totalAttributeNumber);
}

TreeMetricsCalculator::analitics<uint64_t, double> TreeMetricsCalculator::scanAttributeInheritanceFactor() const
{
	return move(scan(results->getClassNamesResult(classLists).namesList, 
					results->getAttributeInheritanceFactorResult(classLists).inheritedAttributeOfEveryClass,
					getAttributeInheritanceFactor()));
}

TreeMetricsCalculator::analitics<uint64_t, double> TreeMetricsCalculator::totalAnalyzisAttributeInheritanceFactor() const
{
	return move(totalAnalyzis(results->getClassNamesResult(classLists).namesList, 
							results->getAttributeInheritanceFactorResult(classLists).inheritedAttributeOfEveryClass,
							getAttributeInheritanceFactor()));
}

double TreeMetricsCalculator::getPolymorpismFactor() const
{
	assert(results);
	auto const& result = results->getInheritanceAndPolymorphismFactorResult(classLists);
	return safeDivide(result.overridenMethodNumber, result.totalMethodNumber);
}

TreeMetricsCalculator::analitics<int64_t, double> TreeMetricsCalculator::scanPolymorpismFactor() const
{
	return move(scan(results->getClassNamesResult(classLists).namesList, 
					results->getInheritanceAndPolymorphismFactorResult(classLists).overridenMethodOfEveryClass,
					getMethodInheritanceFactor()));
}

TreeMetricsCalculator::analitics<int64_t, double> TreeMetricsCalculator::totalAnalyzisPolymorpismFactor() const
{
	return move(totalAnalyzis(results->getClassNamesResult(classLists).namesList, 
							results->getInheritanceAndPolymorphismFactorResult(classLists).overridenMethodOfEveryClass,
							getMethodInheritanceFactor()));
}

double TreeMetricsCalculator::getNumberOfChildrenMetric() const
{
	assert(results);
	auto const& result = results->getNumberOfChildrenResult(classLists);
	return safeDivide(result.sumOfChildren, result.numberOfInterfacesThatHaveChildren);
}

TreeMetricsCalculator::analitics<uint64_t, double> TreeMetricsCalculator::scanNumberOfChildrenMetric() const
{
	auto result = move(scan(results->getClassNamesResult(classLists).namesList, 
					results->getNumberOfChildrenResult(classLists).numberOfChildrenOfEveryClass,
					getNumberOfChildrenMetric()));
	auto& resultV = result.first;
	resultV.erase(remove_if(resultV.begin(), resultV.end(), 
				[](pair<string,uint64_t> const& p) ->bool { return !p.second; }), resultV.end());
	return move(result);
}

TreeMetricsCalculator::analitics<uint64_t, double> TreeMetricsCalculator::totalAnalyzisNumberOfChildrenMetric() const
{
	return move(totalAnalyzis(results->getClassNamesResult(classLists).namesList, 
							results->getNumberOfChildrenResult(classLists).numberOfChildrenOfEveryClass,
							getNumberOfChildrenMetric()));
}

size_t TreeMetricsCalculator::getDepthOfInheritanceTree() const
{
	// -1 as inheritance tree has pseudo-root.
	assert(results);
	return results->getDepthResult(inheritanceTree).getDepth() - 1;
}

TreeMetricsCalculator::analitics<uint64_t, double> TreeMetricsCalculator::scanDepthOfInheritanceTree() const
{
	return move(scan(results->getClassNamesResult(inheritanceTree).namesList, 
			results->getDepthResult(inheritanceTree).getDepthOfEachClass(),
			meanValue(results->getDepthResult(inheritanceTree).getDepthOfEachClass())));
}

TreeMetricsCalculator::analitics<uint64_t, double> TreeMetricsCalculator::totalAnalyzisDepthOfInheritanceTree() const
{
	return move(totalAnalyzis(results->getClassNamesResult(inheritanceTree).namesList, 
			results->getDepthResult(inheritanceTree).getDepthOfEachClass(),
			meanValue(results->getDepthResult(inheritanceTree).getDepthOfEachClass())));
}

size_t TreeMetricsCalculator::getWidthOfInheritanceTree() const
{
	assert(results);
	return results->getWidthResult(inheritanceTree).getWidth();
}

TreeMetricsCalculator::analitics<uint64_t, double> TreeMetricsCalculator::scanWidthOfInheritanceTree() const
{
	return move(scan(results->getClassNamesResult(inheritanceTree).namesList, 
			results->getWidthResult(inheritanceTree).getWidthOfEachClass(),
			meanValue(results->getWidthResult(inheritanceTree).getWidthOfEachClass())));
}

TreeMetricsCalculator::analitics<uint64_t, double> TreeMetricsCalculator::totalAnalyzisWidthOfInheritanceTree() const
{
	return move(totalAnalyzis(results->getClassNamesResult(inheritanceTree).namesList, 
			results->getWidthResult(inheritanceTree).getWidthOfEachClass(),
			meanValue(results->getWidthResult(inheritanceTree).getWidthOfEachClass())));
}

void TreeMetricsCalculator::printInheritanceTree() const
{
	inheritanceTree.dfsDown<TreePrinterVisitor>();
}

}} // end of namespace JWB::details