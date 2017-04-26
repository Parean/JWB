#pragma once

#include "visitor.hpp"

#include "vector"

namespace JWB {	namespace details {

class AttributeInheritanceFactorVisitor;

template <>
struct ReturnVisitorStatus<AttributeInheritanceFactorVisitor>
{
	uint64_t inheritedAttributeNumber = 0;
	uint64_t totalAttributeNumber = 0;
};

class AttributeInheritanceFactorVisitor : public Visitor
{
public:
	AttributeInheritanceFactorVisitor() = delete;
	AttributeInheritanceFactorVisitor(AttributeInheritanceFactorVisitor const&) = delete;
	AttributeInheritanceFactorVisitor(AttributeInheritanceFactorVisitor&&) = default;
	AttributeInheritanceFactorVisitor& operator=(AttributeInheritanceFactorVisitor const&) = delete;
	AttributeInheritanceFactorVisitor& operator=(AttributeInheritanceFactorVisitor&&) = delete;

	AttributeInheritanceFactorVisitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<AttributeInheritanceFactorVisitor>& returnStatus);

	void visit(TreeClassDescription const*) override;
	void visit(TreeInterfaceDescription const*) override;
	void visitBack(TreeClassDescription const*) override;
	void visitBack(TreeInterfaceDescription const*) override;

private:
	ReturnVisitorStatus<AttributeInheritanceFactorVisitor>& returnStatus;
	std::vector<uint64_t> stackOfNumbersOfInheritedAttributes;
	uint64_t sumOfCurrentInheritedAttributes;
};

}} // end of namespace JWB::details