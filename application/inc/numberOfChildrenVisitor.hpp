#pragma once

#include "visitor.hpp"

namespace JWB {	namespace details {

class NumberOfChildrenVisitor;

template <>
struct ReturnVisitorStatus<NumberOfChildrenVisitor>
{
	uint64_t sumOfChildren = 0;
	uint64_t numberOfInterfacesThatHaveChildren = 0;
};

class NumberOfChildrenVisitor : public Visitor
{
public:
	NumberOfChildrenVisitor() = delete;
	NumberOfChildrenVisitor(NumberOfChildrenVisitor const&) = delete;
	NumberOfChildrenVisitor(NumberOfChildrenVisitor&&) = default;
	NumberOfChildrenVisitor& operator=(NumberOfChildrenVisitor const&) = delete;
	NumberOfChildrenVisitor& operator=(NumberOfChildrenVisitor&&) = delete;

	NumberOfChildrenVisitor(std::unordered_set<Node const*> filter, ReturnVisitorStatus<NumberOfChildrenVisitor>& returnStatus);

	void visit(TreeInterfaceDescription const* treeInterfaceDescription) override;
	void visit(TreeClassDescription const* treeClassDescription) override;
	void visitBack(TreeInterfaceDescription const* treeInterfaceDescription) override;
	void visitBack(TreeClassDescription const* treeClassDescription) override;

private:
	ReturnVisitorStatus<NumberOfChildrenVisitor>& returnStatus;

	void updateResult();
};

}} //end of namespace JWB::details