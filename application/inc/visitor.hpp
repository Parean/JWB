#pragma once

#include <unordered_set>

namespace JWB {	namespace details {
class TreeInterfaceDescription;
class TreeClassDescription;
class Node;
class Visitor;

/// @class ReturnVisitorStatus<T>
/// @brief Describes return value of the Visitor travel.
template <class T>
struct ReturnVisitorStatus;

/// @class ReturnVisitorStatus<Visitor>
/// Empty struct as Visitor is abstract.
template <>
struct ReturnVisitorStatus<Visitor> {};

/// @class Visitor
/// @brief Visitor travels throw InheritanceTree.
class Visitor
{
public:
	Visitor() = delete;
	Visitor(Visitor const&) = delete;
	Visitor(Visitor&&) = default;
	Visitor& operator=(Visitor const&) = delete;
	Visitor& operator=(Visitor&&) = delete;
	virtual ~Visitor() = default;

	/// Takes filter that will contain visited nodes.
	Visitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<Visitor> = ReturnVisitorStatus<Visitor>());

	/// Return true if node has been visited.
	bool hasVisited(Node const* node);

	/// Make node visited (adds it to filter).
	void makeVisited(Node const* node);

	void setCurrent(Node const* node);

	/// Takes TreeClassDescription and makes some notes (optional, may do nothing).
	/// Invoked before visiting current Class's children.
	virtual void visit(TreeClassDescription const*) = 0;

	/// Takes TreeInterfaceDescription and makes some notes (optional, may do nothing).
	/// Invoked before visiting current Interface's children.
	virtual void visit(TreeInterfaceDescription const*) = 0;

	/// Takes TreeClassDescription and makes some notes (optional, may do nothing).
	/// Invoked after visiting current Children's children.
	virtual void visitBack(TreeClassDescription const*) = 0;

	/// Takes TreeInterfaceDescription and makes some notes (optional, may do nothing).
	/// Invoked after visiting current Interface's children.
	virtual void visitBack(TreeInterfaceDescription const*) = 0;

protected:
	std::unordered_set<Node const*>& filter;
	Node const* node;
};

}} // end of namespace JWB::details