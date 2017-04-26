#pragma once

#include <unordered_map>
#include "visitor.hpp"

namespace JWB {	namespace details {	
class InheritanceFactorVisitor;

/// @class ReturnVisitorStatus<InheritanceFactorVisitor>
/// @brief Contains result to Method Inheritance Factor (result would be ratio of these two).
template <>
struct ReturnVisitorStatus<InheritanceFactorVisitor> 
{
	ReturnVisitorStatus() = default;
	size_t totalMethodNumber = 0;
	size_t inheritedMethodNumber = 0;
};

/// @class InheritanceFactorVisitor
/// @brief Visitor used to count Method Inheritance Factor.
class InheritanceFactorVisitor : public Visitor
{
public:
	InheritanceFactorVisitor() = delete;
	InheritanceFactorVisitor(InheritanceFactorVisitor const&) = delete;
	InheritanceFactorVisitor(InheritanceFactorVisitor&&) = default;
	InheritanceFactorVisitor& operator=(InheritanceFactorVisitor const&) = delete;
	InheritanceFactorVisitor& operator=(InheritanceFactorVisitor&&) = delete;

	/// Takes filter that will contain visited nodes.
	InheritanceFactorVisitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<InheritanceFactorVisitor>& result);

	/// Visit father of a class inheritance line. (If there is a class parent, InheritanceFactorVisitor may work incorrectly).
	void visit(TreeClassDescription const* TreeClassDescription) override;

	/// Does nothing.
	void visit(TreeInterfaceDescription const* TreeInterfaceDescription) override;

	/// Does nothing.
	void visitBack(TreeClassDescription const*) override;

	/// Does nothing.
	void visitBack(TreeInterfaceDescription const*) override;

private:
	class TreeOfClassesInheritanceVisitor;
	ReturnVisitorStatus<InheritanceFactorVisitor>& result;
};

}} // end of namespace JWB::details