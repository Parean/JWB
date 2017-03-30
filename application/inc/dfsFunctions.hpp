#pragma once

#include "inheritanceTree.hpp"

#include <functional>

namespace semesterProject
{
	/// Struct that holds static functions that return lambdas to traverse inheritance dag in specified order.
	struct dfsFunctions
	{
		/// Prints all node's names in the inheritance dag.
		std::function<void(semesterProject::Node const*)> static printer();

		/// Used to count depth of the inheritance dag.
		std::function<size_t(semesterProject::Node const*)> static depthCounter();

		/// Used to count width of the inheritance dag.
		std::function<size_t(semesterProject::Node const*)> static widthCounter();
	};
}