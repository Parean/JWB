#include "treeDepthWidthVisitor.hpp"
#include <iostream>

using std::unordered_set;

semesterProject::TreeDepthWidthVisitor::TreeDepthWidthVisitor(unordered_set<Node const*>& filter) :
	Visitor(filter)
	{}

void semesterProject::TreeDepthWidthVisitor::visit(ClassDescription const* classDescription)
{
	std::cout << "Class visited!" << std::endl;
}

void semesterProject::TreeDepthWidthVisitor::visit(InterfaceDescription const* interfaceDescription)
{
	std::cout << "Interface visited!" << std::endl;
}
