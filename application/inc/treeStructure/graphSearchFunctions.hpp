#pragma once

#include "inheritanceTree.hpp"

#include <functional>
#include <vector>
#include <boost/optional.hpp>

namespace JWB {	namespace details { namespace graphSearchFunctions
{
/// Prints all node's names in the inheritance dag.
std::function<void(Node const*)> printer();

class DepthCount
{
public:
	DepthCount() = default;
	DepthCount(DepthCount const&) = delete;
	DepthCount(DepthCount&&) = default;
	DepthCount& operator=(DepthCount const&) = delete;
	DepthCount& operator=(DepthCount&&) = default;

	std::vector<uint64_t> const& getDepthOfEachClass() const;
	size_t getDepth() const;

private:
	friend std::function<DepthCount(Node const*)> depthCounter();

	std::vector<uint64_t> depthOfEachClass; // given in dfs order.
	boost::optional<size_t> mutable depth; // As there must be at least one node in tree, we use depth == 0 to know that it was not counted.
};

/// Used to count depth of the inheritance dag.
std::function<DepthCount(Node const*)> depthCounter();

class WidthCount
{
public:
	WidthCount() = default;
	WidthCount(WidthCount const&) = delete;
	WidthCount(WidthCount&&) = default;
	WidthCount& operator=(WidthCount const&) = delete;
	WidthCount& operator=(WidthCount&&) = default;

	std::vector<uint64_t> const& getWidthOfEachClass() const;
	size_t getWidth() const;

private:
	friend std::function<WidthCount(Node const*)> widthCounter();

	std::vector<uint64_t> widthOfEachClass; // given in bfs order.
	boost::optional<size_t> mutable width; // As there must be at least one node in tree, we use depth == 0 to know that it was not counted.
};

/// Used to count width of the inheritance dag.
std::function<WidthCount(Node const*)> widthCounter();

}}} // end of namespace JWB::details::graphSearsFunctions
