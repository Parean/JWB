#include "classNamesVisitor.hpp"
#include "treeClassDescription.hpp"

namespace JWB {	namespace details {

ClassNamesVisitor::ClassNamesVisitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<ClassNamesVisitor>& result) :
	Visitor(filter),
	result(result)
{}

void ClassNamesVisitor::visit(TreeClassDescription const* classDecription) 
{
	result.namesList.push_back(classDecription->getName());
}

void ClassNamesVisitor::visit(TreeInterfaceDescription const* interfaceDescription) 
{
	result.namesList.push_back(interfaceDescription->getName());
}

void ClassNamesVisitor::visitBack(TreeClassDescription const*) {}
void ClassNamesVisitor::visitBack(TreeInterfaceDescription const*) {}

}} // JWB::details