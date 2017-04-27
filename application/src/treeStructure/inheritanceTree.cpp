#include "inheritanceTree.hpp"

#include <cassert>

using std::vector;
using std::move;
using std::shared_ptr;
using std::unordered_set;
using std::string;
using std::make_unique;

namespace JWB {	namespace details {

InheritanceTree::InheritanceTree(vector<Node const*> roots, vector<shared_ptr<Node>> nodes) :
	pseudoRoot(new Node(new TreeInterfaceDescription("PseudoRoot"), move(roots))),
	nodes(nodes.cbegin(), nodes.cend())
{
	assert(!this->pseudoRoot->getInheritors().empty());
	assert(!this->nodes.empty());	
}

}} // end of namespace JWB::details