#pragma once

#include <unordered_map>

#include "inheritanceTree.hpp"

namespace semesterProject
{
	class CurrentlyBuildingTree
	{
	public:
		CurrentlyBuildingTree() = default;
		CurrentlyBuildingTree(CurrentlyBuildingTree const&) = delete;
		CurrentlyBuildingTree(CurrentlyBuildingTree&&) = delete;
		CurrentlyBuildingTree& operator=(CurrentlyBuildingTree const&) = delete;
		CurrentlyBuildingTree& operator=(CurrentlyBuildingTree&&) = delete;

		/// Adds new interface and its parents to masks.
		void addNodeAndConnections(InterfaceDescription* interface, std::vector<std::string> parentNames);

		/// With the help of masks builds a real tree. Continueing use of the object
		/// after this method is not valid.
		InheritanceTree buildTree();
		
	private:
		std::vector<std::shared_ptr<Node>> nodes;
		std::vector<std::vector<std::string>> connections;
		std::unordered_map<std::string, Node*> nodeByName;

		bool isBuilded = false;
	};
}