#pragma once

#include "visitor.hpp"

#include "vector"

namespace JWB {	namespace details {

class AttributeInheritanceFactorVisitor;

/// @class ReturnVisitorStatus<AttributeInheritanceFactorVisitor>
/// @brief Helper structure for AttributeInheritanceFactorVisitor.
template <>
struct ReturnVisitorStatus<AttributeInheritanceFactorVisitor>
{
	uint64_t inheritedAttributeNumber = 0;
	uint64_t totalAttributeNumber = 0;
	std::vector<uint64_t> inheritedAttributeOfEveryClass;
};


/// @class AttributeInheritanceFactorVisitor.
/// @brief Inheritor of Visitor to measure ratio of number of attributes inherited to total number of those.
class AttributeInheritanceFactorVisitor : public Visitor
{
public:
	AttributeInheritanceFactorVisitor() = delete;
	AttributeInheritanceFactorVisitor(AttributeInheritanceFactorVisitor const&) = delete;
	AttributeInheritanceFactorVisitor(AttributeInheritanceFactorVisitor&&) = default;
	AttributeInheritanceFactorVisitor& operator=(AttributeInheritanceFactorVisitor const&) = delete;
	AttributeInheritanceFactorVisitor& operator=(AttributeInheritanceFactorVisitor&&) = delete;

	AttributeInheritanceFactorVisitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<AttributeInheritanceFactorVisitor>& returnStatus);

	/// Adds number of attributes to stack and updates returnStatus.
	void visit(TreeClassDescription const*) override;

	/// Does nothing.
	void visit(TreeInterfaceDescription const*) override;

	/// Pops from stack.
	void visitBack(TreeClassDescription const*) override;

	/// Does nothing.
	void visitBack(TreeInterfaceDescription const*) override;

private:
	ReturnVisitorStatus<AttributeInheritanceFactorVisitor>& returnStatus;
	std::vector<uint64_t> stackOfNumbersOfInheritedAttributes;
	uint64_t sumOfCurrentInheritedAttributes;
};

}} // end of namespace JWB::details