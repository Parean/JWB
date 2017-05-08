#include "treeMetricsCalculator.hpp"
#include "constructInheritanceTree.hpp"
#include "inheritanceFactorVisitor.hpp"
#include "graphSearchFunctions.hpp"
#include "treePrinterVisitor.hpp"
#include "numberOfChildrenVisitor.hpp"
#include "attributeInheritanceFactorVisitor.hpp"

#include <exception>
#include <boost/optional.hpp>

using std::unordered_set;
using std::vector;
using std::move;

#include <iostream>
using std::cout;
using std::endl;

namespace JWB {	namespace details {

class ClassListsVisitor;

template <>
struct ReturnVisitorStatus<ClassListsVisitor>
{
	unordered_set<Node const*> classLists;
};

class ClassListsVisitor : public Visitor
{
public:
	ClassListsVisitor() = delete;
	ClassListsVisitor(ClassListsVisitor const&) = delete;
	ClassListsVisitor(ClassListsVisitor&&) = default;
	ClassListsVisitor& operator=(ClassListsVisitor const&) = delete;
	ClassListsVisitor& operator=(ClassListsVisitor&&) = delete;

	ClassListsVisitor(unordered_set<Node const*> filter, ReturnVisitorStatus<ClassListsVisitor>& result) :
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

vector<Node const*> privateGetClassLists(InheritanceTree const& inheritanceTree)
{
	auto result = inheritanceTree.dfsDown<ClassListsVisitor>();
	vector<Node const*> classLists(result.classLists.size());
	auto it = classLists.begin();
	for (auto const* x : result.classLists)
	{
		*it++ = x;
	}
	return move(classLists);
}

struct TreeMetricsCalculator::ResultContainter
{
	ResultContainter() = default;
	template <typename T>
	using OptRes = typename boost::optional<ReturnVisitorStatus<T>>;

	ReturnVisitorStatus<InheritanceAndPolymorphismFactorVisitor> const& getInheritanceAndPolymorphismFactorResult(vector<Node const*> const& classLists) const
	{
		if (!inheritanceAndPolymorphismFactorResult)
			inheritanceAndPolymorphismFactorResult = countMetric<InheritanceAndPolymorphismFactorVisitor>(classLists);
		return inheritanceAndPolymorphismFactorResult.value();
	}

	ReturnVisitorStatus<AttributeInheritanceFactorVisitor> const& getAttributeInheritanceFactorResult(vector<Node const*> const& classLists) const
	{
		if (!attributeInheritanceFactorResult)
			attributeInheritanceFactorResult = countMetric<AttributeInheritanceFactorVisitor>(classLists);
		return attributeInheritanceFactorResult.value();
	}

	ReturnVisitorStatus<NumberOfChildrenVisitor> const& getNumberOfChildrenResult(vector<Node const*> const& classLists) const
	{
		if (!numberOfChildrenResult)
			numberOfChildrenResult = countMetric<NumberOfChildrenVisitor>(classLists);
		return numberOfChildrenResult.value();
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

	OptRes<InheritanceAndPolymorphismFactorVisitor> mutable inheritanceAndPolymorphismFactorResult;
	OptRes<AttributeInheritanceFactorVisitor> mutable attributeInheritanceFactorResult;
	OptRes<NumberOfChildrenVisitor> mutable numberOfChildrenResult;
	boost::optional<graphSearchFunctions::DepthCount> mutable depthResult;
	boost::optional<graphSearchFunctions::WidthCount> mutable widthResult;
};

TreeMetricsCalculator::TreeMetricsCalculator(AntlrComponentsKeeper &keeper) :
	inheritanceTree(treeConstruction::constructInheritanceTree(keeper)),
	results(new ResultContainter()),
	classLists(privateGetClassLists(inheritanceTree))
{}

double TreeMetricsCalculator::getMethodInheritanceHidingFactor() const
{
	assert(results);
	auto const& result = results->getInheritanceAndPolymorphismFactorResult(classLists);
	return result.totalMethodNumber ? (double)result.inheritedMethodNumber / result.totalMethodNumber : 0;
}

double TreeMetricsCalculator::getAttributeInheritanceHidingFactor() const
{
	assert(results);
	auto const& result = results->getAttributeInheritanceFactorResult(classLists);
	return result.totalAttributeNumber ? (double)result.inheritedAttributeNumber / result.totalAttributeNumber : 0;
}

double TreeMetricsCalculator::getPolymorpismFactor() const
{
	assert(results);
	auto const& result = results->getInheritanceAndPolymorphismFactorResult(classLists);
	return result.totalMethodNumber ? (double)result.overridenMethodNumber / result.totalMethodNumber : 0;
}

double TreeMetricsCalculator::getNumberOfChildrenMetric() const
{
	assert(results);
	auto const& result = results->getNumberOfChildrenResult(classLists);
	return result.numberOfInterfacesThatHaveChildren ? (double)result.sumOfChildren / result.numberOfInterfacesThatHaveChildren : 0;
}

size_t TreeMetricsCalculator::getDepthOfInheritanceTree() const
{
	// -1 as inheritance tree has pseudo-root.
	assert(results);
	return results->getDepthResult(inheritanceTree).getDepth() - 1;
}

size_t TreeMetricsCalculator::getWidthOfInheritanceTree() const
{
	assert(results);
	return results->getWidthResult(inheritanceTree).getWidth();
}

void TreeMetricsCalculator::printInheritanceTree() const
{
	inheritanceTree.dfsDown<TreePrinterVisitor>();
}

}} // end of namespace JWB::details