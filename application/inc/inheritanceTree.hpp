#pragma once

#include "node.hpp"

namespace semesterProject
{
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

		/// Dfs.
		void dfs();

	private:
		std::vector<Node*> roots;
		std::vector<std::shared_ptr<Node>> nodes;
	};
}