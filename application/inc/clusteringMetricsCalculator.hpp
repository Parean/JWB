#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <forward_list>
#include <memory>

#include "simpleMetricsCalculator.hpp"
#include "clusteringMethodDescription.hpp"
#include "antlrComponentsKeeper.hpp"

namespace JWB {	namespace details {

/// @class ClusteringMetricsCalculator
/// @brief The object of this class is used to calculate metrics for clustering

/// !WARNING! In current implementation after "cluster" is called, the initial splitting is destroyed
/// If you want to save it, use the getClasses() function before running clustering and copy list
class ClusteringMetricsCalculator : public SimpleMetricsCalculator
{
public:
	ClusteringMetricsCalculator() = delete;
	ClusteringMetricsCalculator(ClusteringMetricsCalculator const&) = delete;
	ClusteringMetricsCalculator(ClusteringMetricsCalculator&&) = delete;
	ClusteringMetricsCalculator& operator=(ClusteringMetricsCalculator const&) = delete;
	ClusteringMetricsCalculator& operator=(ClusteringMetricsCalculator&&) = delete;

	// It calls the constructor of SimpleMetricsCalculator, get trees from keeper
	// and then traverses all the trees using ClusteringMetricsListener
	ClusteringMetricsCalculator(AntlrComponentsKeeper &keeper);

	// If isNormalized == true, normalized value of metric will be returned, otherwise it returns normal value
	double getAfferentCoupling(bool isNormalized = true) const;
	double getCouplingBetweenObjects(bool isNormalized = true) const;
	double getDataAbstractionCoupling(bool isNormalized = true) const;
	double getInstability(bool isNormalized = true) const;
	double getInformationFlowBasedCohesion(bool isNormalized = true) const;
	double getTightClassCoupling(bool isNormalized = true) const;
	double getLooseClassCoupling(bool isNormalized = true) const;
	double getNumberOfMethods(bool isNormalized = true) const;
	double getNumberOfAttributes(bool isNormalized = true) const;
	double getMessagePassingCoupling(bool isNormalized = true) const;
	double getResponseForAClass(bool isNormalized = true) const;
	double getLocalityOfData(bool isNormalized = true) const;
	double getLackOfCohesionInMethods1(bool isNormalized = true) const;
	double getLackOfCohesionInMethods2(bool isNormalized = true) const;
	double getLackOfCohesionInMethods4(bool isNormalized = true) const;

	// This methods outputs corresponding couplings for each class
	void showUsedClasses() const;
	void showUsingClasses() const;

	// It outputs all metrics
	void showClusteringMetrics(bool isNormalized = true) const;

	// It calculates the main metric by which clustering is performed
	double getAggregatedMetric(bool isNormalized = true) const;

	// It returns a string that represents the best way to split methods into classes
	std::string cluster();

	// Used to merge two classes with indices i and j to one
	std::pair<std::shared_ptr <ClusteringClassDescription>, std::shared_ptr <ClusteringClassDescription> > mergeClasses(int i, int j);

	// Used to separate class into two classes and insert them into list with indices i and j
	void separateClass(
		int i,
		int j,
		std::pair<std::shared_ptr <ClusteringClassDescription>, std::shared_ptr <ClusteringClassDescription> > const& mergedPair
	);

private:

	// It used to create a splitting that consists of classes, each of which has exactly one method
	void createInitialFragmentation();

	// Artificial constant for the normalization of metrics, the maximum allowable values for which depends on the size of the project
	constexpr static size_t CONSTANT_FOR_NORMALIZING = 50;
};

}}
