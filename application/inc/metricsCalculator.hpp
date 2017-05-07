#pragma once

#include <vector>
#include <memory>

#include "classDescription.hpp"
#include "antlr4-runtime.h"
#include "interfaceDescription.hpp"
#include "antlrComponentsKeeper.hpp"

namespace JWB {	namespace details {

/// @class MetricsCalculator
/// @brief The object of this class is passed to the listener and stores all the data it needs during the tree traversal,
///        then it is used by the client code to calculate various metrics
class MetricsCalculator
{
	public:
		MetricsCalculator() = delete;
		MetricsCalculator(MetricsCalculator const&) = delete;
		MetricsCalculator(MetricsCalculator&&) = delete;
		MetricsCalculator& operator=(MetricsCalculator const&) = delete;
		MetricsCalculator& operator=(MetricsCalculator&&) = delete;

		MetricsCalculator(AntlrComponentsKeeper &keeper);

		// Increment numberSourceLinesOfCode
		void bumpNumberSourceLinesOfCode();

		// Adds number to numberSourceLinesOfCode
		void bumpNumberSourceLinesOfCode(size_t number);

		void addClass(std::shared_ptr <const ClassDescription> const &classPtr);
		void addInterface(std::shared_ptr <const InterfaceDescription>  const &interfacePtr);

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

	private:
		// Vector of streams of tokens to count the comments
		std::vector <antlr4::CommonTokenStream*> tokens;

		size_t numberSourceLinesOfCode = 0;
		std::vector <std::shared_ptr <const ClassDescription> > classes;
		std::vector <std::shared_ptr <const InterfaceDescription> > interfaces;
};

}}
