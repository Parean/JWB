#include "currentlyBuildingTree.hpp"

#include <tuple>
#include <cassert>

#include <iostream>
using std::cout;
using std::endl;

using std::vector;
using std::string;
using std::move;
using std::pair;
using std::shared_ptr;
using std::tuple;
using std::get;

namespace JWB {	namespace details {

void CurrentlyBuildingTree::addNodeAndConnections(TreeInterfaceDescription* interface, vector<string> parentNames)
{
	// As object use after building real tree is not valid, continueing use of the object counts as a bag.
	assert(!isBuilded);
	// Interface should never be nullptr.
	assert(interface);
	// parentsNames may be empty.

	// New node is constructed.
	nodes.emplace_back(new Node(interface));
	// It's name is used to get in future its pointer by name.
	nodeByName[nodes.back()->getInterface()->getName()] = nodes.back().get();
	// Then all parents of the interface are moved into a vector.
	connections.emplace_back(move(parentNames));
}

InheritanceTree CurrentlyBuildingTree::buildTree()
{
	// Nodes should not be empty when a tree is constructed. It's a bag.
	assert(nodes.size());

	// Nodes should be of the same size as the connections.
	assert(nodes.size() == connections.size());

	// Alias to iterate through vectors of shared_ptr of Nodes, vector of vector of strirngs simulatniously.
	using DoubleIterator = tuple <vector <shared_ptr <Node> >::const_iterator, 
								  vector <std::vector <string> >::const_iterator>;

	// All connections are set here. Interfaces are checked to be userdefined, not got from a library and then added to the inheritence tree.
	for (DoubleIterator doubleIterator(nodes.begin(), connections.begin());
			get<0>(doubleIterator) != nodes.end() && get<1>(doubleIterator) != connections.end();
			get<0>(doubleIterator)++, get<1>(doubleIterator)++)
	{
		for (auto const& parentName : *get<1>(doubleIterator))
		{
			if (nodeByName.find(parentName) != nodeByName.end())
			{
				(*get<0>(doubleIterator))->addParent(nodeByName.at(parentName));
				nodeByName.at(parentName)->addInheritor(get<0>(doubleIterator)->get());
			}
		}
	}

	// Roots are distingwished from the rest and contained aside.
	vector<Node const*> roots;
	for (auto nodePointer : nodes)
	{
		if (nodePointer->isOrphan())
		{
			roots.push_back(nodePointer.get());
		}
		nodePointer->updateHashes();
	}

	// This sets the object in invalid state to be used.
	isBuilded = true;

	return move(InheritanceTree(move(roots), move(nodes)));
}

}} // end of namespace JWB::details