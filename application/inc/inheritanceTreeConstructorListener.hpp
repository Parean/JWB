#pragma once

#include "JavaBaseListener.h"
#include "currentlyBuildingTree.hpp"

#include <vector>

namespace JWB {	namespace details {
/// Listener of the Antlr4 tree that construst inherintence tree.
class inheritanceTreeConstructorListener : public JavaBaseListener
{
public:
	inheritanceTreeConstructorListener(CurrentlyBuildingTree& currentlyBuildingTree);

private:
	/// Extractes info for future InterfaceDesription object.
	void enterInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx) override;


	/// Extractes info for future ClassDecsription object.
	void enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;

	CurrentlyBuildingTree& currentlyBuildingTree;
};

}} // end of namespace JWB::details