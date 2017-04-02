#include <iostream>

#include "accessModifier.hpp"
#include "customListener.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

namespace JWB {	namespace details {

CustomListener::CustomListener(MetricsCalculator *calculator):
	metricsCalculator(calculator)
{
	assert(calculator);
}

void CustomListener::enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	shared_ptr <ClassDescription> classPtr(new ClassDescription(ctx->Identifier()->getText()));
	metricsCalculator->addClass(classPtr);
	classesForTraversal.push_back(classPtr);
}

void CustomListener::enterInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx)
{
	shared_ptr <InterfaceDescription> interfacePtr(new InterfaceDescription(ctx->Identifier()->getText()));
	metricsCalculator->addInterface(interfacePtr);
	interfacesForTraversal.push_back(interfacePtr);
}

void CustomListener::exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	assert(!classesForTraversal.empty());
	classesForTraversal.pop_back();
}

void CustomListener::exitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx)
{
	assert(!interfacesForTraversal.empty());
	interfacesForTraversal.pop_back();
}

void CustomListener::enterClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *ctx)
{
	assert(!classesForTraversal.empty());

	//if ctx hasn`t memberDeclaration, we have nothing to add
	auto const memberDeclaration = ctx->memberDeclaration();
	if (!memberDeclaration)
		return;

	auto const modifier = getAccessModifier(ctx->modifier());

	if (memberDeclaration->methodDeclaration())
	{
		auto const name = memberDeclaration->methodDeclaration()->Identifier()->getText();;
		classesForTraversal.back()->addMethod(new MethodDescription (modifier, name,
			name + memberDeclaration->methodDeclaration()->formalParameters()->getText()));
	}

	if (memberDeclaration->constructorDeclaration())
	{
		auto const name = memberDeclaration->constructorDeclaration()->Identifier()->getText();
		classesForTraversal.back()->addMethod(new MethodDescription (modifier, name,
			name + memberDeclaration->constructorDeclaration()->formalParameters()->getText()));
	}

	if (memberDeclaration->genericMethodDeclaration())
	{
		auto const name = memberDeclaration->genericMethodDeclaration()->methodDeclaration()->Identifier()->getText();
		classesForTraversal.back()->addMethod(new MethodDescription (modifier, name,
			name + memberDeclaration->genericMethodDeclaration()->methodDeclaration()->formalParameters()->getText()));
	}

	if (memberDeclaration->genericConstructorDeclaration())
	{
		auto const name = memberDeclaration->genericConstructorDeclaration()->constructorDeclaration()->Identifier()->getText();
		classesForTraversal.back()->addMethod(new MethodDescription (modifier, name,
			name + memberDeclaration->genericConstructorDeclaration()->constructorDeclaration()->formalParameters()->getText()));
	}

	if (memberDeclaration->fieldDeclaration())
	{
		auto const variableDeclarators = memberDeclaration->fieldDeclaration()->variableDeclarators()->variableDeclarator();
		for (auto const m : variableDeclarators)
			classesForTraversal.back()->addAttribute(modifier, m->variableDeclaratorId()->Identifier()->getText());
	}
}

void CustomListener::enterInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext *ctx)
{
	assert(!interfacesForTraversal.empty());

	//if ctx hasn`t interfaceMemberDeclaration, we have nothing to add
	auto const interfaceMemberDeclaration = ctx->interfaceMemberDeclaration();
	if (!interfaceMemberDeclaration)
		return;

	auto const modifier = getAccessModifier(ctx->modifier());

	if (interfaceMemberDeclaration->interfaceMethodDeclaration())
	{
		auto const name = interfaceMemberDeclaration->interfaceMethodDeclaration()->Identifier()->getText();
		interfacesForTraversal.back()->addMethod(new MethodDescription (modifier, name,
			name + interfaceMemberDeclaration->interfaceMethodDeclaration()->formalParameters()->getText()));
	}

	if (interfaceMemberDeclaration->genericInterfaceMethodDeclaration())
	{
		auto const name = interfaceMemberDeclaration->genericInterfaceMethodDeclaration()->interfaceMethodDeclaration()->Identifier()->getText();
		interfacesForTraversal.back()->addMethod(new MethodDescription (modifier, name,
			name + interfaceMemberDeclaration->genericInterfaceMethodDeclaration()->interfaceMethodDeclaration()->formalParameters()->getText()));
	}
}

AccessModifier CustomListener::getAccessModifier(vector<JavaParser::ModifierContext *> modifiers) const
{
	for (auto const& m : modifiers)
	{
		auto const& modifier = m->classOrInterfaceModifier()->getText();

		if (modifier == "private")
			return AccessModifier::PRIVATE;

		if (modifier == "public")
			return AccessModifier::PUBLIC;

		if (modifier == "protected")
			return AccessModifier::PROTECTED;
	}

	return AccessModifier::PROTECTED;
}

}}
