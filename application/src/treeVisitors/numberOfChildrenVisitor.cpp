#include "numberOfChildrenVisitor.hpp"
#include "node.hpp"

#include <iostream>
using std::cout;
using std::endl;

namespace JWB { namespace details {

NumberOfChildrenVisitor::NumberOfChildrenVisitor(std::unordered_set<Node const*> filter, ReturnVisitorStatus<NumberOfChildrenVisitor>& returnStatus) :
	Visitor(filter),
	returnStatus(returnStatus)
	{}

void NumberOfChildrenVisitor::updateResult()
{
	if (!node->getInheritors().empty())
	{
		returnStatus.sumOfChildren += node->getInheritors().size();
		returnStatus.numberOfInterfacesThatHaveChildren++;
	}
}

void NumberOfChildrenVisitor::visit(TreeInterfaceDescription const* treeInterfaceDescription)
{
	updateResult();
}

void NumberOfChildrenVisitor::visit(TreeClassDescription const* treeClassDesciption)
{
	updateResult();
}

void NumberOfChildrenVisitor::visitBack(TreeInterfaceDescription const* treeInterfaceDescription) {}
void NumberOfChildrenVisitor::visitBack(TreeClassDescription const* treeClassDescription) {}

}}