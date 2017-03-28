#include "node.hpp"

#include <cassert>

using std::string;
using std::move;

semesterProject::Node::Node(string className) :
	interfaceDescription(new InterfaceDescription(move(className)))
{}

void semesterProject::Node::addInheritor(Node* newInheritor)
{
	// newInheritor should be never nullptr. It's a bag.
	assert(newInheritor);
	inheritors.push_back(newInheritor);
}

void semesterProject::Node::addParent(Node* newParent)
{
	// newParent should be never nullptr. It's a bag.
	assert(newParent);
	parents.push_back(newParent);
}

bool semesterProject::Node::isOrphan() const
{
	return parents.empty();
}

semesterProject::InterfaceDescription const* semesterProject::Node::getInterface() const
{
	return interfaceDescription.get();
}
