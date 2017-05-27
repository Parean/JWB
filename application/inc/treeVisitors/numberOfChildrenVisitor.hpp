#pragma once

#include "visitor.hpp"
#include <vector>

namespace JWB {	namespace details {

class NumberOfChildrenVisitor;

/// @class ReturnVisitorStatus<NumberOfChildrenVisitor>
/// @brief Helper structure for NumberOfChildrenVisitor.
template <>
struct ReturnVisitorStatus<NumberOfChildrenVisitor>
{
	uint64_t sumOfChildren = 0;
	uint64_t numberOfInterfacesThatHaveChildren = 0;
	std::vector<uint64_t> numberOfChildrenOfEveryClass; // dfs order.
};

/// @class NumberOfChildrenVisitor
/// @brief Counts average number of children, if there are some.
class NumberOfChildrenVisitor : public Visitor
{
public:
	NumberOfChildrenVisitor() = delete;
	NumberOfChildrenVisitor(NumberOfChildrenVisitor const&) = delete;
	NumberOfChildrenVisitor(NumberOfChildrenVisitor&&) = default;
	NumberOfChildrenVisitor& operator=(NumberOfChildrenVisitor const&) = delete;
	NumberOfChildrenVisitor& operator=(NumberOfChildrenVisitor&&) = delete;

	NumberOfChildrenVisitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<NumberOfChildrenVisitor>& returnStatus);

	/// Updates returnStatus.
	void visit(TreeInterfaceDescription const* treeInterfaceDescription) override;
	void visit(TreeClassDescription const* treeClassDescription) override;

	/// Does nothing.
	void visitBack(TreeInterfaceDescription const* treeInterfaceDescription) override;
	void visitBack(TreeClassDescription const* treeClassDescription) override;

private:
	ReturnVisitorStatus<NumberOfChildrenVisitor>& returnStatus;

	void updateResult();
};

}} //end of namespace JWB::details