#pragma once

#include "visitor.hpp"
#include "node.hpp"

namespace JWB {	namespace details {
class TreePrinterVisitor;

template <>
struct ReturnVisitorStatus<TreePrinterVisitor> {};

/// Prints tree in the following format: "Class/Interface visitied! name, methodes names".
class TreePrinterVisitor : public Visitor
{
public:
	TreePrinterVisitor() = delete;
	TreePrinterVisitor(TreePrinterVisitor const&) = delete;
	TreePrinterVisitor(TreePrinterVisitor&&) = delete;
	TreePrinterVisitor& operator=(TreePrinterVisitor const&) = delete;
	TreePrinterVisitor& operator=(TreePrinterVisitor&&) = delete;


	/// Takes filter that will contain visited nodes.
	TreePrinterVisitor(std::unordered_set<Node const*>& filter, ReturnVisitorStatus<TreePrinterVisitor>& result);

	/// Takes TreeClassDescription and prints corresponding message.
	void visit(TreeClassDescription const* TreeClassDescription) override;

	/// Takes TreeInterfaceDescription and prints corresponding message.
	void visit(TreeInterfaceDescription const* TreeInterfaceDescription) override;

	/// Does nothing
	void visitBack(TreeClassDescription const*) override;

	/// Does nothing
	void visitBack(TreeInterfaceDescription const*) override;

private:
	ReturnVisitorStatus<TreePrinterVisitor>& result;
};

}} // end of namespace JWB::details