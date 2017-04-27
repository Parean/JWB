#pragma once

#include "inheritanceTree.hpp"

#include <functional>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

namespace JWB {	namespace details { namespace graphSearchFunctions
{
/// Prints all node's names in the inheritance dag.
std::function<void(Node const*)> printer();

/// Used to count depth of the inheritance dag.
std::function<size_t(Node const*)> depthCounter();

/// Used to count width of the inheritance dag.
std::function<size_t(Node const*)> widthCounter();

}}} // end of namespace JWB::details::graphSearsFunctions