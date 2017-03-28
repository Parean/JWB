#include "inheritanceTreeConstructorListener.hpp"

#include <vector>
#include <string>
#include <cassert>

using std::string;
using std::vector;
using std::move;

semesterProject::inheritanceTreeConstructorListener::inheritanceTreeConstructorListener(CurrentlyBuildingTree& currentlyBuildingTree) :
	currentlyBuildingTree(currentlyBuildingTree)
	{}

void semesterProject::inheritanceTreeConstructorListener::enterInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx)
{
	// Interface should contain a name. Otherwise it's a bag.
	assert(ctx->Identifier());
	assert(!ctx->Identifier()->getText().empty());
	const string inheritorName(ctx->Identifier()->getText());
	vector<string> parentNames;

	// Node is scaned for parent-interfaces and then a new mask for a future node is added to the future tree.
	if (ctx->typeList())
	{
		for (auto x : ctx->typeList()->typeType())
		{
			assert(x->classOrInterfaceType());
			assert(!x->classOrInterfaceType()->Identifier().empty());
			parentNames.push_back(x->classOrInterfaceType()->Identifier(0)->getText());
		}
	}
	currentlyBuildingTree.addNodeAndConnections(move(inheritorName), move(parentNames));
}

void semesterProject::inheritanceTreeConstructorListener::enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	const string inheritorName(ctx->Identifier()->getText());
	vector<string> parentNames;
	// Node is scaned for parent-class and then a new mask for a future node is added to the future tree.
	if (ctx->typeType())
	{
		assert(ctx->typeType()->classOrInterfaceType());
		assert(!ctx->typeType()->classOrInterfaceType()->Identifier().empty());
		parentNames.emplace_back(ctx->typeType()->classOrInterfaceType()->Identifier(0)->getText());
	}
	// Node is scaned for parent-interfaces and then a new mask for a future node is added to the future tree.
	if (ctx->typeList())
	{
		for (auto x : ctx->typeList()->typeType())
		{
			assert(x->classOrInterfaceType());
			assert(!x->classOrInterfaceType()->Identifier().empty());
			parentNames.emplace_back(x->classOrInterfaceType()->Identifier(0)->getText());
		}
	}
	currentlyBuildingTree.addNodeAndConnections(move(inheritorName), move(parentNames));
}