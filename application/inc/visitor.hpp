#pragma once

#include <unordered_set>

namespace semesterProject
{
	class InterfaceDescription;
	class ClassDescription;
	class Node;

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
		Visitor(std::unordered_set<Node const*>& filter);

		/// Return true if node has been visited.
		bool hasVisited(Node const* node);

		/// Make node visited.
		void makeVisited(Node const* node);

		/// Takes ClassDescription and makes some notes.
		virtual void visit(ClassDescription const*) = 0;

		/// Takes InterfaceDescription and makes some notes.
		virtual void visit(InterfaceDescription const*) = 0;

	protected:
		std::unordered_set<Node const*>& filter;
	};
}