#include "inheritanceTreeConstructorListener.hpp"

#include <string>
#include <cassert>

using std::string;
using std::vector;
using std::move;

namespace JWB {	namespace details {

template <typename T>
struct DefaultAccessModifierGetter;

template<>
struct DefaultAccessModifierGetter<TreeClassDescription>
{
	AccessModifier constexpr static value = AccessModifier::DEFAULT;
};

template<>
struct DefaultAccessModifierGetter<TreeInterfaceDescription>
{
	AccessModifier constexpr static value = AccessModifier::PUBLIC;
};

template <typename T>
AccessModifier getAccessModifier(vector<JavaParser::ModifierContext *> const& modifiers)
{
	for (auto const m : modifiers)
	{
		assert(m->classOrInterfaceModifier());
		auto const modifier = m->classOrInterfaceModifier()->getText();

		if (modifier == "private")
			return AccessModifier::PRIVATE;
		else if (modifier == "public")
			return AccessModifier::PUBLIC;
		else if (modifier == "protected")
			return AccessModifier::PROTECTED;
		else if (modifier == "default")
			return AccessModifier::DEFAULT;
	}
	return DefaultAccessModifierGetter<T>::value;
}

void addParams(TreeMethodDescription* method, JavaParser::FormalParameterContext *ctx)
{
	assert(ctx);
	assert(ctx->typeType());
	if (ctx->typeType()->classOrInterfaceType())
	{
		method->addParam(ctx->typeType()->classOrInterfaceType()->getText());
	}
	else if (ctx->typeType()->primitiveType())
	{
		method->addParam(ctx->typeType()->primitiveType()->getText());
	}
}

void addMethod(TreeClassDescription* treeClassDescription, JavaParser::ClassBodyDeclarationContext *ctx)
{
	assert(ctx);
	assert(treeClassDescription);
	auto const memberDeclaration = ctx->memberDeclaration();
	if (memberDeclaration && memberDeclaration->methodDeclaration())
	{
		auto const modifier = getAccessModifier<TreeClassDescription>(ctx->modifier());
		string name = memberDeclaration->methodDeclaration()->Identifier()->getText();
		string returnType;
		if (!memberDeclaration->methodDeclaration()->typeType())
		{
			returnType = "void";
		}
		else if (memberDeclaration->methodDeclaration()->typeType()->classOrInterfaceType())
		{
			returnType = memberDeclaration->methodDeclaration()->typeType()->classOrInterfaceType()->getText();
		}
		else if(memberDeclaration->methodDeclaration()->typeType()->primitiveType())
		{
			returnType = memberDeclaration->methodDeclaration()->typeType()->primitiveType()->getText();
		}
		else
		{
			assert(false);
		}
		auto method = new TreeMethodDescription (move(name), modifier, move(returnType));
		if (memberDeclaration->methodDeclaration()->formalParameters()
		 && memberDeclaration->methodDeclaration()->formalParameters()->formalParameterList())
		{
			for (auto x : memberDeclaration->methodDeclaration()->formalParameters()->formalParameterList()->formalParameter())
			{
				addParams(method, x);
			}
		}
		treeClassDescription->addMethod(method);
	}
	else if (memberDeclaration && memberDeclaration->constructorDeclaration())
	{
		auto const modifier = getAccessModifier<TreeClassDescription>(ctx->modifier());
		string name = memberDeclaration->constructorDeclaration()->Identifier()->getText();
		treeClassDescription->addMethod(new TreeMethodDescription (name, modifier, move(name)));
	}
}

void addMethod(TreeInterfaceDescription* interface, JavaParser::InterfaceBodyDeclarationContext *ctx)
{
	assert(ctx);
	assert(interface);
	auto const memberDeclaration = ctx->interfaceMemberDeclaration();
	if (memberDeclaration && memberDeclaration->interfaceMethodDeclaration())
	{
		auto const modifier = getAccessModifier<TreeInterfaceDescription>(ctx->modifier());
		string name = memberDeclaration->interfaceMethodDeclaration()->Identifier()->getText();
		string returnType;
		if (!memberDeclaration->interfaceMethodDeclaration()->typeType())
		{
			returnType = "void";
		}
		else if (memberDeclaration->interfaceMethodDeclaration()->typeType()->classOrInterfaceType())
		{
			returnType = memberDeclaration->interfaceMethodDeclaration()->typeType()->classOrInterfaceType()->getText();
		}
		else if(memberDeclaration->interfaceMethodDeclaration()->typeType()->primitiveType())
		{
			returnType = memberDeclaration->interfaceMethodDeclaration()->typeType()->primitiveType()->getText();
		}
		else
		{
			assert(false);
		}
		auto method = new TreeMethodDescription (move(name), modifier, move(returnType));
		if (memberDeclaration->interfaceMethodDeclaration()->formalParameters()
		 && memberDeclaration->interfaceMethodDeclaration()->formalParameters()->formalParameterList())
		{
			for (auto x : memberDeclaration->interfaceMethodDeclaration()->formalParameters()->formalParameterList()->formalParameter())
			{
				addParams(method, x);
			}
		}
		interface->addMethod(method);
	}
}

inheritanceTreeConstructorListener::inheritanceTreeConstructorListener(CurrentlyBuildingTree& currentlyBuildingTree) :
	currentlyBuildingTree(currentlyBuildingTree)
	{}

void inheritanceTreeConstructorListener::enterInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx)
{
	// Interface should contain a name. Otherwise it's a bag.
	assert(ctx->Identifier());
	assert(!ctx->Identifier()->getText().empty());

	// inheritorName should not be empty. Assert is in TreeInterfaceDescription(string).
	string inheritorName(ctx->Identifier()->getText());

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

	auto* treeInterfaceDescription = new TreeInterfaceDescription(move(inheritorName));
	if (ctx->interfaceBody() && !ctx->interfaceBody()->interfaceBodyDeclaration().empty())
	{
		for (auto x : ctx->interfaceBody()->interfaceBodyDeclaration())
		{
			addMethod(treeInterfaceDescription, x);
		}
	}

	currentlyBuildingTree.addNodeAndConnections(treeInterfaceDescription, move(parentNames));
}

void inheritanceTreeConstructorListener::enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	// inheritorName should not be empty. Assert is in TreeClassDescription::TreeInterfaceDescription(string).
	string inheritorName(ctx->Identifier()->getText());

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

	auto* treeClassDescription = new TreeClassDescription(move(inheritorName));
	if (ctx->classBody() && !ctx->classBody()->classBodyDeclaration().empty())
	{
		for (auto x : ctx->classBody()->classBodyDeclaration())
		{
			addMethod(treeClassDescription, x);
		}
	}

	currentlyBuildingTree.addNodeAndConnections(treeClassDescription, move(parentNames));
}

}}