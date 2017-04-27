#pragma once

#include "node.hpp"
#include "visitor.hpp"

#include <unordered_set>
#include <type_traits>

namespace JWB {	namespace details {
/// @class InheritanceTree.
/// Class that represents the inheritance tree (dag actially).
class InheritanceTree
{
public:
	InheritanceTree() = default;
	InheritanceTree(InheritanceTree const&) = delete;
	InheritanceTree(InheritanceTree&& movedTree) = default;
	InheritanceTree& operator=(InheritanceTree const&) = delete;
	InheritanceTree& operator=(InheritanceTree&& movedTree) = delete;

	/// Takes two vectors and sets them as roots - interfaces, that have no parents - and nodes - all contained nodes.
	InheritanceTree(std::vector<Node const*> roots, std::vector<std::shared_ptr<Node>> nodes);

	/// Dfs down throughout the tree. Template parameter is needed Visitor.
	/// TemplateVisitor should be inheritor of semesterProject::Visitor.
	template <class TemplateVisitor>
	ReturnVisitorStatus<TemplateVisitor> dfsDown() const
	{
		// TemplateVisitor should be inheritor of semesterProject::Visitor.
		static_assert(std::is_base_of<Visitor, TemplateVisitor>::value, "Dfs visitor should be derived from Visitor.");
		std::unordered_set<Node const*> filter;
		ReturnVisitorStatus<TemplateVisitor> result;
		TemplateVisitor visitor(filter, result);
		takeVisitorDown(&visitor, pseudoRoot);
		return result;
	}

	/// Takes lambda (from dfsFunctions) and applies them to roots
	/// Takes lambdas that return void.
	template <class... Args>
	void lambdaDfs(std::function<void(Args...)> lambda) const
	{
		lambda(pseudoRoot);
	}

	/// Takes lambda (from dfsFunctions) and applies them to roots
	/// Takes lambdas that does not return void.
	template <class returnValue, class... Args>
	returnValue lambdaDfs(std::function<returnValue(Args...)> lambda) const
	{
		auto result = lambda(pseudoRoot);
		return result;
	}

private:
	Node const* pseudoRoot;
	std::vector<std::shared_ptr<Node const>> nodes;
};


}} // end of namespace JWB::details