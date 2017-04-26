#include "treeMetricsCalculator.hpp"
#include "inheritanceTreeConstructorListener.hpp"
#include "inheritanceFactorVisitor.hpp"
#include "graphSearchFunctions.hpp"
#include "treePrinterVisitor.hpp"
#include "numberOfChildrenVisitor.hpp"
#include "attributeInheritanceFactorVisitor.hpp"

using std::unordered_set;
using std::vector;
using std::move;

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

InheritanceTree treeConstruction(antlr4::tree::ParseTree* parseTree)
{
	CurrentlyBuildingTree hierarchyTreeTemplate;
	inheritanceTreeConstructorListener listener(hierarchyTreeTemplate);
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parseTree);
	InheritanceTree inheritanceTree = move(hierarchyTreeTemplate.buildTree());
	return move(inheritanceTree);
}

TreeMetricsCalculator::TreeMetricsCalculator(antlr4::tree::ParseTree* parseTree) :
	inheritanceTree(treeConstruction(parseTree)),
	classLists(privateGetClassLists(inheritanceTree))
{
}

double TreeMetricsCalculator::getMethodInheritanceHidingFactor() const
{
	ReturnVisitorStatus<InheritanceAndPolymorphismFactorVisitor> result;
	unordered_set<Node const*> filter;
	InheritanceAndPolymorphismFactorVisitor visitor(filter, result);
	for (auto const* x : classLists)
	{
		takeVisitorDown(&visitor, x);
	}
	return result.totalMethodNumber ? (double)result.inheritedMethodNumber / result.totalMethodNumber : 0;
}

double TreeMetricsCalculator::getAttributeInheritanceHidingFactor() const
{
	ReturnVisitorStatus<AttributeInheritanceFactorVisitor> result;
	unordered_set<Node const*> filter;
	AttributeInheritanceFactorVisitor visitor(filter, result);
	for (auto const* x : classLists)
	{
		takeVisitorDown(&visitor, x);
	}
	return result.totalAttributeNumber ? (double)result.inheritedAttributeNumber / result.totalAttributeNumber : 0;
}

double TreeMetricsCalculator::getPolymorpismFactor() const
{
	ReturnVisitorStatus<InheritanceAndPolymorphismFactorVisitor> result;
	unordered_set<Node const*> filter;
	InheritanceAndPolymorphismFactorVisitor visitor(filter, result);
	for (auto const* x : classLists)
	{
		takeVisitorDown(&visitor, x);
	}
	return result.totalMethodNumber ? (double)result.overridenMethodNumber / result.totalMethodNumber : 0;
}

double TreeMetricsCalculator::getNumberOfChildrenMetric() const
{
	ReturnVisitorStatus<NumberOfChildrenVisitor> result;
	unordered_set<Node const*> filter;
	NumberOfChildrenVisitor visitor(filter, result);
	for (auto const* x : classLists)
	{
		takeVisitorDown(&visitor, x);
	}
	return result.numberOfInterfacesThatHaveChildren ? (double)result.sumOfChildren / result.numberOfInterfacesThatHaveChildren : 0;
}

size_t TreeMetricsCalculator::getDepthOfInheritanceTree() const
{
	return inheritanceTree.lambdaDfs(graphSearchFunctions::depthCounter()) - 1;
}

size_t TreeMetricsCalculator::getWidthOfInheritanceTree() const
{
	return inheritanceTree.lambdaDfs(graphSearchFunctions::widthCounter());
}

void TreeMetricsCalculator::printInheritanceTree() const
{
	inheritanceTree.dfsDown<TreePrinterVisitor>();
}

}} // end of namespace JWB::details