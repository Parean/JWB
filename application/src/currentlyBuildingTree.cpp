#include <cassert>

#include "currentlyBuildingTree.hpp"

using std::vector;
using std::string;
using std::move;
using std::pair;
using std::shared_ptr;
using semesterProject::Node;

void semesterProject::CurrentlyBuildingTree::addNodeAndConnections(string inheritorName, vector<string> parentNames)
{
	// As object use after building real tree is not valid, continueing use of the object counts as a bag.
	assert(!isBuilded);
	// inheritorName should not be empty. It's a bag.
	assert(!inheritorName.empty());

	// New node is constructed.
	nodes.emplace_back(new Node(move(inheritorName)));
	// It's name is used to get in future its pointer by name.
	nodeByName[nodes.back()->getInterface()->getName()] = nodes.back().get();
	// Then all parents of the interface are moved into a vector.
	connections.emplace_back(move(parentNames));
}

semesterProject::InheritanceTree semesterProject::CurrentlyBuildingTree::buildTree()
{
	// Nodes should not be empty when a tree is constructed. It's a bag.
	assert(nodes.size() == connections.size());

	// All connections are set here. Interfaces are checked to be userdefined, not got from a library and then added to the inheritence tree.
	for (DoubleIterator doubleIterator(nodes.begin(), connections.begin()); doubleIterator.first != nodes.end() && doubleIterator.second != connections.end(); doubleIterator.first++, doubleIterator.second++)
	{
		for (auto const& parentName : *doubleIterator.second)
		{
			if (nodeByName.find(parentName) != nodeByName.end())
			{
				(*doubleIterator.first)->addParent(nodeByName.at(parentName));
				nodeByName.at(parentName)->addInheritor(doubleIterator.first->get());
			}
		}
	}

	// Roots are distingwished from the rest and contained aside.
	vector<Node*> roots;
	for (auto const& nodePointer : nodes)
	{
		if (nodePointer->isOrphan())
		{
			roots.push_back(nodePointer.get());
		}
	}

	// This sets the object in invalid state to be used.
	isBuilded = true;

	return move(InheritanceTree(move(roots), move(nodes)));
}