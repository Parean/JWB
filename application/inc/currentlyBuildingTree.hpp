#pragma once

#include <unordered_map>

#include "inheritanceTree.hpp"

namespace JWB {	namespace details {

/// @class CurrentlyBuildingTree
/// @brief Gains information about future InheritanceTree and constructs it.
class CurrentlyBuildingTree
{
public:
	CurrentlyBuildingTree() = default;
	CurrentlyBuildingTree(CurrentlyBuildingTree const&) = delete;
	CurrentlyBuildingTree(CurrentlyBuildingTree&&) = delete;
	CurrentlyBuildingTree& operator=(CurrentlyBuildingTree const&) = delete;
	CurrentlyBuildingTree& operator=(CurrentlyBuildingTree&&) = delete;

	/// Adds new interface and its parents. Parents are not inserted in the interface at the moment.
	/// They will be when buildTree() runs.
	void addNodeAndConnections(TreeInterfaceDescription* interface, std::vector<std::string> parentNames);

	/// With the help of masks builds a real tree. Continuing use of the object
	/// after invokation of this method is not valid.
	InheritanceTree buildTree();
	
private:
	std::vector<std::shared_ptr<Node>> nodes;
	std::vector<std::vector<std::string>> connections;
	std::unordered_map<std::string, Node*> nodeByName;

	bool isBuilded = false;
};

}} // end of namespace JWB::details