#pragma once

#include "antlr4-runtime.h"
#include "inheritanceTree.hpp"
#include "antlrComponentsKeeper.hpp"

#include <vector>
#include <memory>
#include <string>

namespace JWB {	namespace details {

/// @class TreeMetricsCalculator
/// @brief Estimates metrics connected to inheritance tree.
class TreeMetricsCalculator
{
public:
	// Second element of pair - average value by requested parameter.
	// First element of pair - pairs of names of interfaces/classes (depends on parameter) 
	// and metrics value for this interface/metrics.
	template <typename T, typename U>
	using analitics = std::pair<std::vector<std::pair<std::string, T>>, U>;

	TreeMetricsCalculator() = delete;
	TreeMetricsCalculator(TreeMetricsCalculator const&) = delete;
	TreeMetricsCalculator(TreeMetricsCalculator&&) = delete;
	TreeMetricsCalculator operator=(TreeMetricsCalculator const&) = delete;
	TreeMetricsCalculator operator=(TreeMetricsCalculator&&) = delete;

	TreeMetricsCalculator(AntlrComponentsKeeper& keeper);

	double getMethodInheritanceHidingFactor() const;
	analitics<int64_t, double> scanMethodInheritanceHidingFactor() const;
	analitics<int64_t, double> totalAnalyzisMethodInheritanceHidingFactor() const;

	double getAttributeInheritanceHidingFactor() const;
	analitics<uint64_t, double> scanAttributeInheritanceHidingFactor() const;
	analitics<uint64_t, double> totalAnalyzisAttributeInheritanceHidingFactor() const;

	double getPolymorpismFactor() const;
	analitics<int64_t, double> scanPolymorpismFactor() const;
	analitics<int64_t, double> totalAnalyzisPolymorpismFactor() const;

	// Average number of children that classes, that do have children, have.
	double getNumberOfChildrenMetric() const;
	analitics<uint64_t, double> scanNumberOfChildrenMetric() const;
	analitics<uint64_t, double> totalAnalyzisNumberOfChildrenMetric() const;

	size_t getDepthOfInheritanceTree() const;
	analitics<uint64_t, double> scanDepthOfInheritanceTree() const;
	analitics<uint64_t, double> totalAnalyzisDepthOfInheritanceTree() const;

	size_t getWidthOfInheritanceTree() const;
	analitics<uint64_t, double> scanWidthOfInheritanceTree() const;
	analitics<uint64_t, double> totalAnalyzisWidthOfInheritanceTree() const;

	void printInheritanceTree() const;

private:
	InheritanceTree inheritanceTree;

	struct ResultContainter;
	std::shared_ptr<ResultContainter> results;

	std::vector<Node const*> classLists;

};

}} // end of namespace JWB::details