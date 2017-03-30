#include "dfsFunctions.hpp"
#include "node.hpp"

#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <iostream>

using std::unordered_set;
using std::unordered_map;
using std::function;
using std::cin;
using std::cout;
using std::endl;
using std::move;

function<void(semesterProject::Node const*)> semesterProject::dfsFunctions::printer()
{
	// Filter to get which nodes have already been visited. Captured by lambda.
	unordered_set<Node const*> filter;

	function<void(Node const*)> dfs = [&dfs, filter] (semesterProject::Node const* node) mutable
	{
		if (filter.find(node) == filter.cend())
		{
			filter.insert(node);
			cout << node->interfaceDescription->getName() << endl;
			for (auto const* x : node->inheritors)
			{
				dfs(x);
			}
		}
	};

	return dfs;
}

function<size_t(semesterProject::Node const*)> semesterProject::dfsFunctions::depthCounter()
{
	// Used to get which nodes have already been visited and what result did they got.
	unordered_map<Node const*, size_t> depth;
	function<size_t(Node const*)> dfs = [&dfs, depth] (semesterProject::Node const* node) mutable
	{
		if (depth.find(node) != depth.cend())
		{
			return depth.at(node);
		}
		size_t result = 1;
		for (auto const* x : node->inheritors)
		{
			result = std::max(result, 1 + dfs(x));
		}
		return depth[node] = result;
	};
	return dfs;
}

function<size_t(semesterProject::Node const*)> semesterProject::dfsFunctions::widthCounter()
{
	// Used to get which nodes have already been visited and what result did they got.
	unordered_map<Node const*, size_t> depth;
	function<size_t(Node const*)> dfs = [&dfs, depth] (semesterProject::Node const* node) mutable
	{
		if (depth.find(node) != depth.cend())
		{
			return depth.at(node);
		}
		size_t result = node->inheritors.size();
		for (auto const* x : node->inheritors)
		{
			result = std::max(result, dfs(x));
		}
		return depth[node] = result;
	};
	return dfs;
}