#include "node.hpp"

#include <cassert>

using std::move;
using std::vector;

namespace JWB {	namespace details {

Node::Node(TreeInterfaceDescription* interface) :
	treeInterfaceDescription(interface)
{}

Node::Node(TreeInterfaceDescription* interface, vector<Node const*> inheritors) :
	treeInterfaceDescription(interface),
	inheritors(move(inheritors))
{}

void Node::addInheritor(Node const* newInheritor)
{
	// newInheritor should be never nullptr. Otherwise it's a bag.
	assert(newInheritor);
	inheritors.push_back(newInheritor);
}

void Node::addParent(Node const* newParent)
{
	// newParent should be never nullptr. Otherwise it's a bag.
	assert(newParent);
	parents.push_back(newParent);
}

bool Node::isOrphan() const
{
	return parents.empty();
}

TreeInterfaceDescription const* Node::getInterface() const
{
	return treeInterfaceDescription.get();
}

vector<Node const*> const& Node::getInheritors() const
{
	return inheritors;
}

vector<Node const*> const& Node::getParents() const
{
	return parents;
}

void Node::updateHashes()
{
	treeInterfaceDescription->updateHashes();
}

void takeVisitorDown(Visitor* visitor, Node const* node)
{
	// visitor should be never nullptr. Otherwise it's a bag.
	assert(visitor);
	if (!visitor->hasVisited(node))
	{
		visitor->setCurrent(node);
		node->getInterface()->takeVisitor(visitor);
		for (auto const* x : node->getInheritors())
		{
			takeVisitorDown(visitor, x);
		}
		visitor->setCurrent(node);
		node->getInterface()->takeVisitorBack(visitor);
		visitor->makeVisited(node);
	}
}

void takeVisitorUp(Visitor* visitor, Node const* node)
{
	// visitor should be never nullptr. Otherwise it's a bag.
	assert(visitor);
	if (!visitor->hasVisited(node))
	{
		visitor->setCurrent(node);
		node->getInterface()->takeVisitor(visitor);
		for (auto const* x : node->getParents())
		{
			takeVisitorDown(visitor, x);
		}
		visitor->setCurrent(node);
		node->getInterface()->takeVisitorBack(visitor);
		visitor->makeVisited(node);
	}
}

}} // end of namespace JWB::details