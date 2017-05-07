#include "treeMethodDescription.hpp"

#include <cassert>
#include <unordered_map>
#include <queue>

using std::vector;
using std::string;
using std::move;
using std::hash;
using std::unordered_map;
using std::queue;

namespace JWB {	namespace details {

namespace methodComparison{

bool compare(TreeMethodDescription const& firstMethod, TreeMethodDescription const& secondMethod)
{
	return firstMethod == secondMethod;
}

// Checks if firstType is wider than secondType. That means that eighter first type is generic or second isn't.
// Warning, if types are not generic this function does not check if they are equal!
bool typeIsWider(string const& firstType, string const& secondType)
{
	assert(!firstType.empty());
	assert(!secondType.empty());
	// Alert! Does not check for equality (widely spoken). Running on not equal types (widely spoken) is undefined!
	return firstType[0] == '#' || secondType[0] != '#';
}

// Checks if firstMethod is wider than senond. That means that first is a generic method that can be reduced to the signature of the second.
bool isWider(TreeMethodDescription const& firstMethod, TreeMethodDescription const& secondMethod)
{
	assert(firstMethod.getParamTypes().size() == secondMethod.getParamTypes().size());
	bool result = typeIsWider(firstMethod.getReturnType(), secondMethod.getReturnType());
	for (auto x = firstMethod.getParamTypes().cbegin(), y = secondMethod.getParamTypes().cend(); 
		x != firstMethod.getParamTypes().cend() && y != secondMethod.getParamTypes().cend() && result; 
		++x, ++y)
	{
		result = typeIsWider(*x, *y);
	}
	return result;
}

} // end of namespace JWD::details::methodComparison

// Takes graph as two unorderedMaps and start node as an size_t. Than finds connectivity component.
// If there are two different types (real, not generic templates) in the component, false is returned.
// Otherwise it is true.
bool checkConnectivityComponent(
	size_t startNodeNumber,
	TreeMethodDescription const& firstMethod,
	TreeMethodDescription const& secondMethod,
	unordered_map<string, vector<size_t>> const& firstMethodTypesNodes,
	unordered_map<string, vector<size_t>> const& secondMethodTypesNodes,
	vector<bool>& firstMethodTypesNodesVisited,
	vector<bool>& secondMethodTypesNodesVisited
	)
{
	// Check graph correctness. It is almost bigraph in fact.
	assert(firstMethodTypesNodesVisited.size() == secondMethodTypesNodesVisited.size());
	string typeInComponent = "#"; // undefined, '#' is an easy symbol to be compared.
	queue<size_t> queueOfNodes({startNodeNumber});
	while (!queueOfNodes.empty())
	{
		size_t nodeToVisit = queueOfNodes.front();
		queueOfNodes.pop();
		// Check node correctness. It should be able to access graph.
		assert(nodeToVisit < firstMethodTypesNodesVisited.size());
		// If node is visited in one partite of graph, correlating should be visited as well.
		assert(firstMethodTypesNodesVisited.at(nodeToVisit) == secondMethodTypesNodesVisited.at(nodeToVisit));
		// If visited, just skip it.
		if (firstMethodTypesNodesVisited.at(nodeToVisit))
		{
			continue;
		}
		// 0 means it is returnType.
		if (nodeToVisit == 0)
		{
			assert(!firstMethod.getReturnType().empty());
			assert(!secondMethod.getReturnType().empty());
			// If types are not generic, they should be equal.
			if (firstMethod.getReturnType()[0] != '#' && secondMethod.getReturnType()[0] != '#' &&
				firstMethod.getReturnType() != secondMethod.getReturnType())
			{
				return false;
			}
			// If first is not generic, typeInComponent should be equal or undefined.
			// typeInComponent is set equal if it is undefined.
			if (firstMethod.getReturnType()[0] != '#')
			{
				if (typeInComponent == "#")
					typeInComponent = firstMethod.getReturnType();
				else if (typeInComponent != firstMethod.getReturnType())
					return false;
			}
			// If second is not generic, typeInComponent should be equal or undefined.
			// typeInComponent is set equal if it is undefined.
			if (secondMethod.getReturnType()[0] != '#')
			{
				if (typeInComponent == "#")
					typeInComponent = secondMethod.getReturnType();
				else if (typeInComponent != secondMethod.getReturnType())
					return false;
			}
			// All connected nodes are added to queue.
			for (auto x : firstMethodTypesNodes.at(firstMethod.getReturnType()))
			{
				queueOfNodes.push(x);
			}
			if (firstMethod.getReturnType()[0] != '#')
			{
				for (auto x : secondMethodTypesNodes.at(firstMethod.getReturnType()))
				{
					queueOfNodes.push(x);
				}
			}
			for (auto x : secondMethodTypesNodes.at(secondMethod.getReturnType()))
			{
				queueOfNodes.push(x);
			}
			if (secondMethod.getReturnType()[0] != '#')
			{
				for (auto x : firstMethodTypesNodes.at(secondMethod.getReturnType()))
				{
					queueOfNodes.push(x);
				}
			}
		}
		else
		{
			string firstMethodVisitingTypeName = firstMethod.getParamTypes()[nodeToVisit - 1];
			string secondMethodVisitingTypeName = secondMethod.getParamTypes()[nodeToVisit - 1];
			assert(!firstMethodVisitingTypeName.empty());
			assert(!secondMethodVisitingTypeName.empty());
			// If types are not generic, they should be equal.
			if (firstMethodVisitingTypeName[0] != '#' && secondMethodVisitingTypeName[0] != '#' &&
				firstMethodVisitingTypeName != secondMethodVisitingTypeName)
			{
				return false;
			}
			// If first is not generic, typeInComponent should be equal or undefined.
			// typeInComponent is set equal if it is undefined.
			if (firstMethodVisitingTypeName[0] != '#')
			{
				if (typeInComponent == "#")
					typeInComponent = firstMethodVisitingTypeName;
				else if (typeInComponent != firstMethodVisitingTypeName)
					return false;
			}
			// If second is not generic, typeInComponent should be equal or undefined.
			// typeInComponent is set equal if it is undefined.
			if (secondMethodVisitingTypeName[0] != '#')
			{
				if (typeInComponent == "#")
					typeInComponent = secondMethodVisitingTypeName;
				else if (typeInComponent != secondMethodVisitingTypeName)
					return false;
			}
			// All connected nodes are added to queue.
			for (auto x : firstMethodTypesNodes.at(firstMethodVisitingTypeName))
			{
				queueOfNodes.push(x);
			}
			for (auto x : secondMethodTypesNodes.at(secondMethodVisitingTypeName))
			{
				queueOfNodes.push(x);
			}
		}
		// Nodes are set visited.
		firstMethodTypesNodesVisited[nodeToVisit] = true;
		secondMethodTypesNodesVisited[nodeToVisit] = true;
	}
	// If nothing special wasn't found, than it is true.
	return true;
}

bool TreeMethodDescription::operator==(TreeMethodDescription const& method) const
{
	// If methods have different names or different parameter pack size, than they can never be equal.
	if (getParamTypes().size() != method.getParamTypes().size() || getName() != method.getName())
		return false;
	// If even one of methods is generic.
	if (this->getIsGeneric() || method.getIsGeneric())
	{
		// If we have generic methods, we need to build a graph.
		// Graph consistes of verxes - parameters in method signature
		// and connections, if types of parameters (in the same method) are the same.
		// There is also connection between parameters with the same number in the other method, but it is implicit.
		// There are imlicit connections two parameters of the another method, if types are equal and they are not generic.
		unordered_map<string, vector<size_t>> firstMethodTypesNodes;
		firstMethodTypesNodes.reserve(getParamTypes().size() + 1);
		unordered_map<string, vector<size_t>> secondMethodTypesNodes;
		secondMethodTypesNodes.reserve(method.getParamTypes().size() + 1);
		firstMethodTypesNodes[getReturnType()].push_back(0);
		secondMethodTypesNodes[method.getReturnType()].push_back(0);
		// Graph is constructed. Types in each methods are marked as appearing in vertexes.
		for (size_t i = 0; i < getParamTypes().size(); ++i)
			firstMethodTypesNodes[getParamTypes()[i]].push_back(i + 1);
		for (size_t i = 0; i < method.getParamTypes().size(); ++i)
			secondMethodTypesNodes[method.getParamTypes()[i]].push_back(i + 1);

		vector<bool> firstMethodTypesNodesVisited(getParamTypes().size() + 1);
		vector<bool> secondMethodTypesNodesVisited(method.getParamTypes().size() + 1);
		// checkConnectivityComponent is ran on all connectivity components.
		bool result = checkConnectivityComponent(0, *this, method,
			firstMethodTypesNodes,
			secondMethodTypesNodes,
			firstMethodTypesNodesVisited,
			secondMethodTypesNodesVisited);
		for (size_t i = 0; i < getParamTypes().size() && result; ++i)
		{
			result = checkConnectivityComponent(i + 1, *this, method,
				firstMethodTypesNodes,
				secondMethodTypesNodes,
				firstMethodTypesNodesVisited,
				secondMethodTypesNodesVisited);
		}

		return result;
	}
	else
	{
		assert(!lazyHashUpdateNeed);
		assert(!method.lazyHashUpdateNeed);
		return this->getId() == method.getId();
	}
}

void TreeMethodDescription::addParam(string paramType)
{
	assert(!paramType.empty());
	if (paramType[0] == '#')
		isGeneric = true;
	paramTypes.push_back(move(paramType));
	lazyHashUpdateNeed = true;
}

string const& TreeMethodDescription::getName() const
{
	return name;
}

string const& TreeMethodDescription::getReturnType() const
{
	return returnType;
}

vector<string> const& TreeMethodDescription::getParamTypes() const
{
	return paramTypes;
}

AccessModifier TreeMethodDescription::getAccessModifier() const
{
	return accessModifier;
}

bool TreeMethodDescription::getIsGeneric() const
{
	return isGeneric;
}

void TreeMethodDescription::updateId()
{
	// If hash needs to be updated, update.
	// Hash is valued as hash from sum of strings from class name, param names, return type.
	if (lazyHashUpdateNeed)
	{
		string hashHelper = (char)accessModifier + returnType + name;
		for (auto const& x : paramTypes)
			hashHelper += ',' + x;
		lazyHash = hash<string>()(hashHelper);
		lazyHashUpdateNeed = false;
	}
}

size_t TreeMethodDescription::getId() const
{
	// Assert to verify that there was an invokation of updateHash() between this one and addParam(string).
	assert(!lazyHashUpdateNeed);
	return lazyHash;
}

}} // end of namespace JWB::details