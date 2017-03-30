#include "visitor.hpp"

#include <cassert>

using std::unordered_set;

semesterProject::Visitor::Visitor(unordered_set<Node const*>& filter) :
	filter(filter)
	{}

bool semesterProject::Visitor::hasVisited(semesterProject::Node const* node)
{
	return filter.find(node) != filter.cend();
}

void semesterProject::Visitor::makeVisited(semesterProject::Node const* node)
{
	assert(filter.find(node) == filter.cend());
	filter.insert(node);
}