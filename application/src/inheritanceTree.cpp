#include "inheritanceTree.hpp"
#include <string>
#include <unordered_map>

using std::vector;
using std::move;
using std::shared_ptr;
using semesterProject::Node;
using std::unordered_map;
using std::string;

semesterProject::InheritanceTree::InheritanceTree(vector<Node*> roots, vector<shared_ptr<Node>> nodes) :
	roots(move(roots)) ,
	nodes(move(nodes))
	{}

vector<Node*> const& semesterProject::InheritanceTree::getRoots() const
{
	return roots;
}

void semesterProject::InheritanceTree::dfs()
{

}