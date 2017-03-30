#pragma once

#include <memory>

#include "classDescription.hpp"

namespace semesterProject
{
	/// Node of the inheritance tree. Contains an Java interface (or a class).
	/// Also contains pointer to the interface's parents and inheritors if such exist.
	class Node
	{
	public:
		Node() = delete;
		Node(Node const &) = delete;
		Node(Node&& node) = delete;
		Node& operator=(Node const &) = delete;
		Node& operator=(Node&& node) = delete;

		/// Takes string as a parameter and constuct shared_ptr of a Interface of this name.
		Node(InterfaceDescription* interface);

		/// Add inheritor to the contained interface.
		void addInheritor(Node* newInheritor);

		/// Add parent to the contained interface.
		void addParent(Node* newParent);

		/// Get true if there is no parent to the contained interface.
		bool isOrphan() const;

		/// Returns pointer to interface.
		InterfaceDescription const* getInterface() const;

		/// Takes visitor, gives it contained Java interface (class).
		/// After that dfs into inheritors.
		void takeVisitor(Visitor* visitor) const;

	private:
		std::shared_ptr<InterfaceDescription> interfaceDescription;

		std::vector<Node*> inheritors;
		std::vector<Node*> parents;
	};
}