#pragma once

#include "JavaBaseListener.h"
#include "currentlyBuildingTree.hpp"

namespace semesterProject
{
	/// Listener of the Antlr4 tree that construst inherintence tree.
	class inheritanceTreeConstructorListener : public JavaBaseListener
	{
	public:
		inheritanceTreeConstructorListener(CurrentlyBuildingTree& currentlyBuildingTree);

		/// Enters InterfaceDeclarationContext Node in the tree and creates new mask for future InterfaceDesription.
		void enterInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx) override;


		/// Enters InterfaceDeclarationContext Node in the tree and creates new mask for future InterfaceDesription.
		/// Should be rewriten to fit classes, not interfaces.
		void enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;

	private:
		CurrentlyBuildingTree& currentlyBuildingTree;
	};
}