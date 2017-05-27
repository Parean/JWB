#include "attributeInheritanceFactorVisitor.hpp"
#include "node.hpp"

#include <cassert>

using std::unordered_set;

namespace JWB { namespace details {

AttributeInheritanceFactorVisitor::AttributeInheritanceFactorVisitor(unordered_set<Node const*>& filter, ReturnVisitorStatus<AttributeInheritanceFactorVisitor>& returnStatus) :
	Visitor(filter),
	returnStatus(returnStatus),
	sumOfCurrentInheritedAttributes(0)
	{}

void AttributeInheritanceFactorVisitor::visit(TreeClassDescription const* treeClassDescription)
{
	stackOfNumbersOfInheritedAttributes.push_back(treeClassDescription->getAttributes().size());
	returnStatus.inheritedAttributeNumber += sumOfCurrentInheritedAttributes;
	returnStatus.inheritedAttributeOfEveryClass.push_back(sumOfCurrentInheritedAttributes);
	returnStatus.totalAttributeNumber += stackOfNumbersOfInheritedAttributes.back() + sumOfCurrentInheritedAttributes;
	sumOfCurrentInheritedAttributes += stackOfNumbersOfInheritedAttributes.back();
}

void AttributeInheritanceFactorVisitor::visitBack(TreeClassDescription const* treeClassDescription)
{
	assert(!stackOfNumbersOfInheritedAttributes.empty());
	sumOfCurrentInheritedAttributes -= stackOfNumbersOfInheritedAttributes.back();
	stackOfNumbersOfInheritedAttributes.pop_back();
}

void AttributeInheritanceFactorVisitor::visit(TreeInterfaceDescription const*) 
{
	assert(true);
}

void AttributeInheritanceFactorVisitor::visitBack(TreeInterfaceDescription const*) 
{
	assert(true);
}

}}