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

		template <class TemplateLambda, TemplateLambda lambda>
		void lambdaDfs()
		{

		}

	private:
		std::vector<Node*> roots;
		std::vector<std::shared_ptr<Node>> nodes;
	};
}
