#pragma once

#include "visitor.hpp"
#include "node.hpp"

namespace semesterProject
{
	class TreeDepthWidthVisitor : public Visitor
	{
	public:
		TreeDepthWidthVisitor() = delete;
		TreeDepthWidthVisitor(TreeDepthWidthVisitor const&) = delete;
		TreeDepthWidthVisitor(TreeDepthWidthVisitor&&) = delete;
		TreeDepthWidthVisitor& operator=(TreeDepthWidthVisitor const&) = delete;
		TreeDepthWidthVisitor& operator=(TreeDepthWidthVisitor&&) = delete;


		/// Takes filter that will contain visited nodes.
		TreeDepthWidthVisitor(std::unordered_set<Node const*>& filter);

		/// Takes ClassDescription and prints corresponding message.
		void visit(ClassDescription const* classDescription) override;

		/// Takes InterfaceDescription and prints corresponding message.
		void visit(InterfaceDescription const* interfaceDescription) override;
	};
}
