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
using std::max_element;

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

std::vector<uint64_t> const& DepthCount::getDepthOfEachClass() const
{
	assert(!depthOfEachClass.empty());
	return depthOfEachClass;
}

size_t DepthCount::getDepth() const
{
	assert(!depthOfEachClass.empty());
	if (!depth)
		depth = *max_element(depthOfEachClass.begin(), depthOfEachClass.end());
	return *depth;
}

function<DepthCount(Node const*)> depthCounter()
{
	// Used to get which nodes have already been visited and what result did they got. Captured by lambda.
	function<DepthCount(Node const*)> returnedLambda = [](Node const* node) 
	{
		DepthCount result;
		unordered_map<Node const*, size_t> depth;
		function<size_t(Node const*)> dfs = [&dfs, depth, &resultForOuter = result] (Node const* node) mutable
		{
			if (depth.find(node) != depth.cend())
			{
				return depth.at(node);
			}
			size_t result = 1;
			size_t i = resultForOuter.depthOfEachClass.size();
			resultForOuter.depthOfEachClass.push_back(0);
			for (auto const* x : node->getInheritors())
			{
				result = std::max(result, 1 + dfs(x));
			}
			resultForOuter.depthOfEachClass[i] = result;
			return depth[node] = result;
		};
		dfs(node);
		return move(result);
	};
	return returnedLambda;
}

std::vector<uint64_t> const& WidthCount::getWidthOfEachClass() const
{
	assert(!widthOfEachClass.empty());
	return widthOfEachClass;
}

size_t WidthCount::getWidth() const
{
	assert(!widthOfEachClass.empty());
	if (!width)
		width = *max_element(widthOfEachClass.begin(), widthOfEachClass.end());
	return *width;
}

function<WidthCount(Node const*)> widthCounter()
{
	// Used to get which nodes have already been visited. Captured by lambda.
	function<WidthCount(Node const*)> returnedLambda = [](Node const* node) {
		WidthCount result;
		unordered_set<Node const*> filter;
		deque<Node const*> queue;
		function<size_t(Node const*)> dfs = [&dfs, filter, queue, &resultForOuter = result] (Node const* node) mutable
		{
			queue.push_front(node);
			size_t result = queue.size();
			for (size_t i = 0; i < result; ++i)
			{
				auto const* x = queue.front();
				queue.pop_front();
				resultForOuter.widthOfEachClass.push_back(result);
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
		dfs(node);
		return result;
	};
	return returnedLambda;
}

}}}