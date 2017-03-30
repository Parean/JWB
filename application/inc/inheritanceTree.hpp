#pragma once

#include "node.hpp"

#include <unordered_set>
#include <type_traits>

namespace semesterProject
{
	class Visitor;

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
		InheritanceTree(std::vector<Node*> roots, std::vector<std::shared_ptr<Node>> nodes);

		/// Returns reference to roots.
		std::vector<Node*> const& getRoots() const;

		/// Dfs throughout the tree. Template parameter is needed Visitor.
		/// TemplateVisitor should be inheritor of semesterProject::Visitor.
		template <class TemplateVisitor>
		void dfs() const
		{
			// TemplateVisitor should be inheritor of semesterProject::Visitor.
			static_assert(std::is_base_of<semesterProject::Visitor, TemplateVisitor>::value, "Dfs visitor should be derived from Visitor.");
			std::unordered_set<Node const*> filter;
			TemplateVisitor visitor(filter);
			for (auto const* x : roots)
			{
				x->takeVisitor(&visitor);
			}
		}

		/// Takes lambda (from dfsFunctions) and applies them to roots
		/// Takes lambdas that return void.
		template <class... Args>
		void lambdaDfs(std::function<void(Args...)> lambda) const
		{
			for (auto const* x : roots)
			{
				lambda(x);
			}
		}

		/// Takes lambda (from dfsFunctions) and applies them to roots
		/// Takes lambdas that does not return void.
		template <class returnValue, class... Args>
		std::vector<returnValue> lambdaDfs(std::function<returnValue(Args...)> lambda) const
		{
			std::vector<returnValue> returnVector;
			for (auto const* x : roots)
			{
				returnVector.push_back(lambda(x));
			}
			return std::move(returnVector);
		}

	private:
		std::vector<Node*> roots;
		std::vector<std::shared_ptr<Node>> nodes;
	};
}
