#pragma once

#include <vector>
#include <memory>

#include "classDescription.hpp"
#include "interfaceDescription.hpp"

namespace JWB {	namespace details {

/// @class MetricsCalculator
/// @brief The object of this class is passed to the listener and stores all the data it needs during the tree traversal,
///        then it is used by the client code to calculate various metrics
class MetricsCalculator
{
	public:
		MetricsCalculator() = default;
		MetricsCalculator(MetricsCalculator const&) = delete;
		MetricsCalculator(MetricsCalculator&&) = delete;
		MetricsCalculator& operator=(MetricsCalculator const&) = delete;
		MetricsCalculator& operator=(MetricsCalculator&&) = delete;

		void addClass(std::shared_ptr <const ClassDescription> const &classPtr);
		void addInterface(std::shared_ptr <const InterfaceDescription>  const &interfacePtr);

		void showNumberOfMethods() const;
		void showNumberOfFields() const;

		// Metrics
		double getMethodHidingFactor() const;
		double getAttributeHidingFactor() const;

	private:
		std::vector <std::shared_ptr <const ClassDescription> > classes;
		std::vector <std::shared_ptr <const InterfaceDescription> > interfaces;
};

}}
