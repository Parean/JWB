#pragma once

#include <unordered_map>
#include <utility>
#include "visitor.hpp"
#include "treeMethodDescription.hpp"

namespace JWB {	namespace details {	
class AnalyzeSimultanInhAndPolyVisitor;

/// @class ReturnVisitorStatus<AnalyzeSimultanInhAndPolyVisitor>
/// @brief Contains result for AnalyzeSimultanInhAndPolyVisitor (empty, all is printed to console).
template <>
struct ReturnVisitorStatus<AnalyzeSimultanInhAndPolyVisitor> 
{
};

/// @class AnalyzeSimultanInhAndPolyVisitor
/// @brief Visitor used to locate simultanious class extension and override.
class AnalyzeSimultanInhAndPolyVisitor : public Visitor
{
public:
	AnalyzeSimultanInhAndPolyVisitor() = delete;
	AnalyzeSimultanInhAndPolyVisitor(AnalyzeSimultanInhAndPolyVisitor const&) = delete;
	AnalyzeSimultanInhAndPolyVisitor(AnalyzeSimultanInhAndPolyVisitor&&) = default;
	AnalyzeSimultanInhAndPolyVisitor& operator=(AnalyzeSimultanInhAndPolyVisitor const&) = delete;
	AnalyzeSimultanInhAndPolyVisitor& operator=(AnalyzeSimultanInhAndPolyVisitor&&) = delete;

	/// Takes filter that will contain visited nodes.
	AnalyzeSimultanInhAndPolyVisitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<AnalyzeSimultanInhAndPolyVisitor>& result);

	/// Gets info about inheritance and polymorphism.
	/// If class is found to override and extend parent classes, a division is suggested.
	void visit(TreeClassDescription const* TreeClassDescription) override;

	/// Does nothing.
	void visit(TreeInterfaceDescription const* TreeInterfaceDescription) override;

	/// Pops all info about inheriting this class from inheritedMethods.
	void visitBack(TreeClassDescription const*) override;

	/// Does nothing.
	void visitBack(TreeInterfaceDescription const*) override;

private:
	struct hash_for_TreeMethodDescription
	{
		size_t operator()(TreeMethodDescription const* p) const;
	};
	struct equal_to_for_TreeMethodDescription
	{
		bool operator()(TreeMethodDescription const* lhs, TreeMethodDescription const* rhs) const;
	};

	std::unordered_map<TreeMethodDescription const*, size_t, hash_for_TreeMethodDescription, equal_to_for_TreeMethodDescription> inheritedMethods;
	std::vector<std::pair<TreeMethodDescription const*,bool>> genericMethods;
	std::vector<size_t> stackOfAddedGenericMethods;
	size_t inheritedMethodsRealSize;

	// Includes both a method and a method that overrides first as two.
	uint64_t numberOfEveryMethodThatWasFoundOnTheWay;
	ReturnVisitorStatus<AnalyzeSimultanInhAndPolyVisitor>& result;
};

}} // end of namespace JWB::details