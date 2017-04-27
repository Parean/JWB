#include "graphSearchFunctions.hpp"
#include "node.hpp"

#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <iostream>

using std::unordered_set;
using std::unordered_map;
using std::function;
using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::deque;

namespace JWB {	namespace details { namespace graphSearchFunctions{

function<void(Node const*)> printer()
{
	// Filter to get which nodes have already been visited. Captured by lambda.
	unordered_set<Node const*> filter;

	function<void(Node const*)> dfs = [&dfs, filter] (Node const* node) mutable
	{
		if (filter.find(node) == filter.cend())
		{
			filter.insert(node);
			cout << node->getInterface()->getName() << endl;
			for (auto const* x : node->getInheritors())
			{
				dfs(x);
			}
		}
	};

	return dfs;
}

function<size_t(Node const*)> depthCounter()
{
	// Used to get which nodes have already been visited and what result did they got. Captured by lambda.
	unordered_map<Node const*, size_t> depth;
	function<size_t(Node const*)> dfs = [&dfs, depth] (Node const* node) mutable
	{
		if (depth.find(node) != depth.cend())
		{
			return depth.at(node);
		}
		size_t result = 1;
		for (auto const* x : node->getInheritors())
		{
			result = std::max(result, 1 + dfs(x));
		}
		return depth[node] = result;
	};
	return dfs;
}

function<size_t(Node const*)> widthCounter()
{
	// Used to get which nodes have already been visited. Captured by lambda.
	unordered_set<Node const*> filter;
	deque<Node const*> queue;

	function<size_t(Node const*)> dfs = [&dfs, filter, queue] (Node const* node) mutable
	{
		queue.push_front(node);
		size_t result = queue.size();
		for (size_t i = 0; i < result; ++i)
		{
			auto const* x = queue.front();
			queue.pop_front();
			for (auto const* y : x->getInheritors())
			{
				if (!filter.count(y))
				{
					filter.insert(y);
					queue.push_back(y);
				}
			}
		}
		if (queue.size())
		{
			node = queue.front();
			queue.pop_front();
			return std::max(result, dfs(node));
		}
		return result;
	};
	return dfs;
}

}}}