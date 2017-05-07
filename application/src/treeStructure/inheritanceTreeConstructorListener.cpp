#include "inheritanceTreeConstructorListener.hpp"

#include <string>
#include <cassert>
#include <unordered_map>
#include <utility>

using std::string;
using std::vector;
using std::move;
using std::unordered_map;

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

void addParams(TreeMethodDescription* method, JavaParser::FormalParameterContext *ctx, unordered_map<string, size_t> const& genericTypes)
{
	assert(ctx);
	assert(ctx->typeType());
	if (ctx->typeType()->classOrInterfaceType())
	{
		auto addedType = ctx->typeType()->classOrInterfaceType()->getText();
		
		// Generic types are mapped into template "#n", where n is number of appearence type in generic type list.
		if (genericTypes.count(addedType))
		{
			addedType = {'#',(char)genericTypes.find(addedType)->second, 0};
		}
		method->addParam(move(addedType));
	}
	else if (ctx->typeType()->primitiveType())
	{
		method->addParam(ctx->typeType()->primitiveType()->getText());
	}
}

void addMethod(TreeClassDescription* treeClassDescription, JavaParser::ClassBodyDeclarationContext *ctx, unordered_map<string, size_t> const& genericTypes)
{
	assert(ctx);
	assert(treeClassDescription);
	auto const memberDeclaration = ctx->memberDeclaration();
	if (memberDeclaration && memberDeclaration->methodDeclaration())
	{
		auto const modifier = getAccessModifier<TreeClassDescription>(ctx->modifier());
		assert(memberDeclaration->methodDeclaration()->Identifier());
		string name = memberDeclaration->methodDeclaration()->Identifier()->getText();
		string returnType;
		if (!memberDeclaration->methodDeclaration()->typeType())
		{
			returnType = "void";
		}
		else if (memberDeclaration->methodDeclaration()->typeType()->classOrInterfaceType())
		{
			returnType = memberDeclaration->methodDeclaration()->typeType()->classOrInterfaceType()->getText();

			// We map generic type name to "#$NUMBER", where $NUMBER is number of this generic type in type list.
			if (genericTypes.count(returnType))
			{
				returnType = {'#',(char)genericTypes.find(returnType)->second, 0};
			}
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
				addParams(method, x, genericTypes);
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

void addMethod(TreeInterfaceDescription* interface, JavaParser::InterfaceBodyDeclarationContext *ctx, unordered_map<string, size_t> const& genericTypes)
{
	assert(ctx);
	assert(interface);
	auto const memberDeclaration = ctx->interfaceMemberDeclaration();
	if (memberDeclaration && memberDeclaration->interfaceMethodDeclaration())
	{
		auto const modifier = getAccessModifier<TreeInterfaceDescription>(ctx->modifier());
		assert(memberDeclaration->interfaceMethodDeclaration()->Identifier());
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
				addParams(method, x, genericTypes);
			}
		}
		interface->addMethod(method);
	}
}

void addAttribute(TreeClassDescription* treeClassDescription, JavaParser::ClassBodyDeclarationContext *ctx, unordered_map<string, size_t> const& genericTypes)
{
	assert(ctx);
	assert(treeClassDescription);
	auto const memberDeclaration = ctx->memberDeclaration();
	if (memberDeclaration && memberDeclaration->fieldDeclaration())
	{
		auto const modifier = getAccessModifier<TreeInterfaceDescription>(ctx->modifier());
		assert(memberDeclaration->fieldDeclaration()->variableDeclarators());
		assert(!memberDeclaration->fieldDeclaration()->variableDeclarators()->variableDeclarator().empty());
		assert(memberDeclaration->fieldDeclaration()->variableDeclarators()->variableDeclarator(0)->variableDeclaratorId());
		assert(memberDeclaration->fieldDeclaration()->variableDeclarators()->variableDeclarator(0)->variableDeclaratorId()->Identifier());
		string name = memberDeclaration->fieldDeclaration()->variableDeclarators()->variableDeclarator(0)->variableDeclaratorId()->Identifier()->getText();
		string type;
		if (!memberDeclaration->fieldDeclaration()->typeType())
		{
			type = "void";
		}
		else if (memberDeclaration->fieldDeclaration()->typeType()->classOrInterfaceType())
		{
			type = memberDeclaration->fieldDeclaration()->typeType()->classOrInterfaceType()->getText();

			// We map generic type name to "#$NUMBER", where $NUMBER is number of this generic type in type list.
			if (genericTypes.count(type))
			{
				type = {'#',(char)genericTypes.find(type)->second, 0};
			}
		}
		else if(memberDeclaration->fieldDeclaration()->typeType()->primitiveType())
		{
			type = memberDeclaration->fieldDeclaration()->typeType()->primitiveType()->getText();
		}
		else
		{
			assert(false);
		}
		treeClassDescription->addAttribute(new TreeAttributeDescription(move(type), move(name), modifier));
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

	// Map of generic name to number in typeLists.
	unordered_map<string, size_t> genericTypes;

	// Scanning list of generic types.
	if (ctx->typeParameters())
	{
		for (auto x : ctx->typeParameters()->typeParameter())
		{
			assert(x->Identifier());
			assert(!x->Identifier()->getText().empty());
			assert(!genericTypes.count(x->Identifier()->getText()));
			// We add CHAR_MAX + 1 so we could cast size_t to char without problems meaning we wouldn't get 0 as a char.
			genericTypes.emplace(x->Identifier()->getText(), genericTypes.size() + CHAR_MAX + 1);
		}
	}

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
			addMethod(treeInterfaceDescription, x, genericTypes);
		}
	}

	currentlyBuildingTree.addNodeAndConnections(treeInterfaceDescription, move(parentNames));
}

void inheritanceTreeConstructorListener::enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	// inheritorName should not be empty. Assert is in TreeClassDescription::TreeInterfaceDescription(string).
	string inheritorName(ctx->Identifier()->getText());

	vector<string> parentNames;

	// Map of generic name to number in typeLists.
	unordered_map<string, size_t> genericTypes;

	// Scanning list of generic types.
	if (ctx->typeParameters())
	{
		for (auto x : ctx->typeParameters()->typeParameter())
		{
			assert(x->Identifier());
			assert(!x->Identifier()->getText().empty());
			assert(!genericTypes.count(x->Identifier()->getText()));
			// We add CHAR_MAX + 1 so we could cast size_t to char without problems meaning we wouldn't get 0 as a char.
			genericTypes.emplace(x->Identifier()->getText(), genericTypes.size() + CHAR_MAX + 1);
		}
	}

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
			addMethod(treeClassDescription, x, genericTypes);
			addAttribute(treeClassDescription, x, genericTypes);
		}
	}

	currentlyBuildingTree.addNodeAndConnections(treeClassDescription, move(parentNames));
}

}}