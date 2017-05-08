#pragma once

#include "antlr4-runtime.h"
#include "inheritanceTree.hpp"
#include "antlrComponentsKeeper.hpp"

#include <vector>
#include <memory>

namespace JWB {	namespace details {

/// @class TreeMetricsCalculator
/// @brief Estimates metrics connected to inheritance tree.
class TreeMetricsCalculator
{
public:
	TreeMetricsCalculator() = delete;
	TreeMetricsCalculator(TreeMetricsCalculator const&) = delete;
	TreeMetricsCalculator(TreeMetricsCalculator&&) = delete;
	TreeMetricsCalculator operator=(TreeMetricsCalculator const&) = delete;
	TreeMetricsCalculator operator=(TreeMetricsCalculator&&) = delete;

	TreeMetricsCalculator(AntlrComponentsKeeper &keeper);

	double getMethodInheritanceHidingFactor() const;
	double getAttributeInheritanceHidingFactor() const;
	double getPolymorpismFactor() const;

	// Average number of children that classes, that do have children, have.
	double getNumberOfChildrenMetric() const;

	size_t getDepthOfInheritanceTree() const;
	size_t getWidthOfInheritanceTree() const;

	void printInheritanceTree() const;

private:
	InheritanceTree inheritanceTree;

	struct ResultContainter;
	std::shared_ptr<ResultContainter> results;

	std::vector<Node const*> classLists;

};

}} // end of namespace JWB::details