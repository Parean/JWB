#pragma once

#include <memory>

#include "treeClassDescription.hpp"

namespace JWB {	namespace details {
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
	Node(TreeInterfaceDescription* interface);
	Node(TreeInterfaceDescription* interface, std::vector<Node const*> inheritors);

	void addInheritor(Node const* newInheritor);

	void addParent(Node const* newParent);

	/// Get true if there is no parent to the contained interface.
	bool isOrphan() const;

	TreeInterfaceDescription const* getInterface() const;
	std::vector<Node const*> const& getInheritors() const;
	std::vector<Node const*> const& getParents() const;

	void updateHashes();

private:
	std::shared_ptr<TreeInterfaceDescription> treeInterfaceDescription;

	std::vector<Node const*> inheritors;
	std::vector<Node const*> parents;
};

/// Takes visitor, gives it contained Java interface (class).
/// After that dfs into inheritors.
void takeVisitorDown(Visitor* visitor, Node const* node);

/// Takes visitor, gives it contained Java interface (class).
/// After that dfs into parents.
void takeVisitorUp(Visitor* visitor, Node const* node);

}} // end of namespace JWB::details