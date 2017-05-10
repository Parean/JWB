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

	// Note. By saying classes we also mean interfaces, if given metrics makes sence in that context.
	// getFactor of getMetric - practicly everywhere means getting mean value by the metric.
	// scanFactor/scanMetric - returns analitics of classes, that differ more than a half from mean value by the metric.
	// totalAnalyzis returns all classes paired with value by the metric.

	// Ratio of the number of inherited methods to total number of methods.
	double getMethodInheritanceFactor() const;
	analitics<int64_t, double> scanMethodInheritanceFactor() const;
	analitics<int64_t, double> totalAnalyzisMethodInheritanceFactor() const;

	// Ratio of the number of inherited attributes to total number of attributes.
	double getAttributeInheritanceFactor() const;
	analitics<uint64_t, double> scanAttributeInheritanceFactor() const;
	analitics<uint64_t, double> totalAnalyzisAttributeInheritanceFactor() const;

	// Ratio of the number of overridden methods to total number of methods.
	double getPolymorpismFactor() const;
	analitics<int64_t, double> scanPolymorpismFactor() const;
	analitics<int64_t, double> totalAnalyzisPolymorpismFactor() const;

	// Average number of children that classes, that do have children, have.
	// Classes that do not have children are extracted from scan.
	double getNumberOfChildrenMetric() const;
	analitics<uint64_t, double> scanNumberOfChildrenMetric() const;
	analitics<uint64_t, double> totalAnalyzisNumberOfChildrenMetric() const;

	// Maximum (!) depth of Inheritance tree. Average value is given in analitics.
	size_t getDepthOfInheritanceTree() const;
	analitics<uint64_t, double> scanDepthOfInheritanceTree() const;
	analitics<uint64_t, double> totalAnalyzisDepthOfInheritanceTree() const;

	// Maximum (!) width of Inheritance tree. Average value is given in analitics.
	size_t getWidthOfInheritanceTree() const;
	analitics<uint64_t, double> scanWidthOfInheritanceTree() const;
	analitics<uint64_t, double> totalAnalyzisWidthOfInheritanceTree() const;

	// Prints tree in dfs order.
	void printInheritanceTree() const;

private:
	InheritanceTree inheritanceTree;

	struct ResultContainter;
	std::shared_ptr<ResultContainter> results;

	std::vector<Node const*> classLists;

};

}} // end of namespace JWB::details