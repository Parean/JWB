#include "visitor.hpp"

#include <cassert>

using std::unordered_set;

namespace JWB {	namespace details {

Visitor::Visitor(unordered_set<Node const*>& filter, ReturnVisitorStatus<Visitor>) :
	filter(filter),
	node(nullptr)
	{}

bool Visitor::hasVisited(Node const* node)
{
	return filter.find(node) != filter.cend();
}

void Visitor::makeVisited(Node const* node)
{
	filter.insert(node);
}

void Visitor::setCurrent(Node const* node)
{
	this->node = node;
}

}} // end of namespace JWB::details