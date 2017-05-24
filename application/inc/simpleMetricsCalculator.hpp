#pragma once

#include <vector>
#include <list>
#include <memory>

#include "clusteringClassDescription.hpp"
#include "antlr4-runtime.h"
#include "clusteringInterfaceDescription.hpp"
#include "antlrComponentsKeeper.hpp"

namespace JWB {	namespace details {

/// @class SimpleMetricsCalculator
/// @brief The object of this class is passed to the SimpleMetricsListener and stores all the data it needs during the tree traversal,
///        then it is used by the client code to calculate various base metrics
class SimpleMetricsCalculator
{
	public:
		SimpleMetricsCalculator() = delete;
		SimpleMetricsCalculator(SimpleMetricsCalculator const&) = delete;
		SimpleMetricsCalculator(SimpleMetricsCalculator&&) = delete;
		SimpleMetricsCalculator& operator=(SimpleMetricsCalculator const&) = delete;
		SimpleMetricsCalculator& operator=(SimpleMetricsCalculator&&) = delete;

		// It get tokens and trees from keeper and then traverses all the trees using SimpleMetricsListener
		SimpleMetricsCalculator(AntlrComponentsKeeper &keeper);

		// Increment numberSourceLinesOfCode
		void bumpNumberSourceLinesOfCode();

		// Adds number to numberSourceLinesOfCode
		void bumpNumberSourceLinesOfCode(size_t number);

		void addClass(std::shared_ptr <ClusteringClassDescription> const &classPtr);
		void addInterface(std::shared_ptr <ClusteringInterfaceDescription>  const &interfacePtr);

		void showNumberOfMethods() const;
		void showNumberOfFields() const;
		size_t getNumberOfCommentLines() const;

		// It outputs cyclomatic complexity for each method in each class and average cyclomatic complexity for each class
		void showCyclomaticComplexities() const;

		// Metrics
		double getMethodHidingFactor() const;
		double getAttributeHidingFactor() const;
		size_t getSourceLinesOfCode() const;
		double getCommentPercentage() const;
		size_t getAverageCyclomaticComplexity() const;

		std::list <std::shared_ptr <ClusteringClassDescription> > const& getClasses() const;
		void setClasses(std::list <std::shared_ptr <ClusteringClassDescription> > newClasses);


	protected:
		// Vector of streams of tokens to count the comments
		std::vector <antlr4::CommonTokenStream*> tokens;

		size_t numberSourceLinesOfCode = 0;
		std::list <std::shared_ptr <ClusteringClassDescription> > classes;
		std::vector <std::shared_ptr <ClusteringInterfaceDescription> > interfaces;
};

}}
