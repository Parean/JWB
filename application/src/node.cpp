#include "node.hpp"

#include <cassert>

using semesterProject::InterfaceDescription;
using std::move;

semesterProject::Node::Node(InterfaceDescription* interface) :
	interfaceDescription(interface)
{}

void semesterProject::Node::addInheritor(Node* newInheritor)
{
	// newInheritor should be never nullptr. Otherwise it's a bag.
	assert(newInheritor);
	inheritors.push_back(newInheritor);
}

void semesterProject::Node::addParent(Node* newParent)
{
	// newParent should be never nullptr. Otherwise it's a bag.
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

void semesterProject::Node::takeVisitor(semesterProject::Visitor* visitor) const
{
	// visitor should be never nullptr. Otherwise it's a bag.
	assert(visitor);
	if (!visitor->hasVisited(this))
	{
		interfaceDescription->takeVisitor(visitor);
		visitor->makeVisited(this);
		for (auto const* x : inheritors)
		{
			x->takeVisitor(visitor);
		}
	}
}
