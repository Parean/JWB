#pragma once

#include <unordered_map>
#include "visitor.hpp"
#include "treeMethodDescription.hpp"

namespace JWB {	namespace details {	
class InheritanceAndPolymorphismFactorVisitor;

/// @class ReturnVisitorStatus<InheritanceAndPolymorphismFactorVisitor>
/// @brief Contains result to Method Inheritance Factor (result would be ratio of these two).
template <>
struct ReturnVisitorStatus<InheritanceAndPolymorphismFactorVisitor> 
{
	ReturnVisitorStatus() = default;
	uint64_t totalMethodNumber = 0;
	uint64_t inheritedMethodNumber = 0;
	int64_t overridenMethodNumber = 0;
};

/// @class InheritanceAndPolymorphismFactorVisitor
/// @brief Visitor used to count Method Inheritance Factor.
class InheritanceAndPolymorphismFactorVisitor : public Visitor
{
public:
	InheritanceAndPolymorphismFactorVisitor() = delete;
	InheritanceAndPolymorphismFactorVisitor(InheritanceAndPolymorphismFactorVisitor const&) = delete;
	InheritanceAndPolymorphismFactorVisitor(InheritanceAndPolymorphismFactorVisitor&&) = default;
	InheritanceAndPolymorphismFactorVisitor& operator=(InheritanceAndPolymorphismFactorVisitor const&) = delete;
	InheritanceAndPolymorphismFactorVisitor& operator=(InheritanceAndPolymorphismFactorVisitor&&) = delete;

	/// Takes filter that will contain visited nodes.
	InheritanceAndPolymorphismFactorVisitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<InheritanceAndPolymorphismFactorVisitor>& result);

	/// Visit father of a class inheritance line. (If there is a class parent, InheritanceAndPolymorphismFactorVisitor may work incorrectly).
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
	size_t inheritedMethodsRealSize;
	ReturnVisitorStatus<InheritanceAndPolymorphismFactorVisitor>& result;
};

}} // end of namespace JWB::details