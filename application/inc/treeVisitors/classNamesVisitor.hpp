#pragma once

#include "visitor.hpp"

#include <vector>
#include <string>

namespace JWB {	namespace details {
class ClassNamesVisitor;

/// @class ReturnVisitorStatus<ClassNamesVisitor>
/// @brief Contains names of all the components (classes/interfaces) in dfs order.
template <>
struct ReturnVisitorStatus<ClassNamesVisitor> 
{
	std::vector<std::string> namesList;
};

/// @class ClassNamesVisitor
/// @brief Visitor used to get vector of names from inheritance tree.
class ClassNamesVisitor : public Visitor
{
public:
	ClassNamesVisitor() = delete;
	ClassNamesVisitor(ClassNamesVisitor const&) = delete;
	ClassNamesVisitor(ClassNamesVisitor&&) = default;
	ClassNamesVisitor& operator=(ClassNamesVisitor const&) = delete;
	ClassNamesVisitor& operator=(ClassNamesVisitor&&) = delete;

	ClassNamesVisitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<ClassNamesVisitor>& result);

	void visit(TreeClassDescription const*) override;
	void visit(TreeInterfaceDescription const*) override;
	void visitBack(TreeClassDescription const*) override;
	void visitBack(TreeInterfaceDescription const*) override;

private:
	ReturnVisitorStatus<ClassNamesVisitor>& result;
};

}} // JWB::details