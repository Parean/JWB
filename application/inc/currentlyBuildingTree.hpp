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
		void addNodeAndConnections(std::string inheritorName, std::vector<std::string> parentNames);

		/// With the help of masks builds a real tree. Continueing use of the object
		/// after this method is not valid.
		InheritanceTree buildTree();
		
	private:
		using DoubleIterator = std::pair<std::vector<std::shared_ptr<semesterProject::Node>>::const_iterator, std::vector<std::vector<std::string>>::const_iterator>;
		std::vector<std::shared_ptr<Node>> nodes;
		std::vector<std::vector<std::string>> connections;
		std::unordered_map<std::string, Node*> nodeByName;

		bool isBuilded = false;
	};
}