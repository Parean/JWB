#include <iostream>

#include "accessModifier.hpp"
#include "customListener.hpp"

using std::vector;
using std::string;
using std::shared_ptr;

namespace JWB {	namespace details {

CustomListener::CustomListener(MetricsCalculator *calculator):
	metricsCalculator(calculator)
{
	assert(calculator);
}

void CustomListener::enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	classesForTraversal.emplace_back(new ClassDescription(ctx->Identifier()->getText()));
	metricsCalculator->bumpNumberSourceLinesOfCode();
}

void CustomListener::enterInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx)
{
	interfacesForTraversal.emplace_back(new InterfaceDescription(ctx->Identifier()->getText()));
	metricsCalculator->bumpNumberSourceLinesOfCode();
}

void CustomListener::enterEnumDeclaration(JavaParser::EnumDeclarationContext *ctx)
{
	classesForTraversal.emplace_back(new ClassDescription(ctx->Identifier()->getText()));
	metricsCalculator->bumpNumberSourceLinesOfCode();
}

void CustomListener::exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	assert(!classesForTraversal.empty());
	metricsCalculator->addClass(classesForTraversal.back());
	classesForTraversal.pop_back();
}

void CustomListener::exitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx)
{
	assert(!interfacesForTraversal.empty());
	metricsCalculator->addInterface(interfacesForTraversal.back());
	interfacesForTraversal.pop_back();
}

void CustomListener::exitEnumDeclaration(JavaParser::EnumDeclarationContext *ctx)
{
	assert(!classesForTraversal.empty());
	metricsCalculator->addClass(classesForTraversal.back());
	classesForTraversal.pop_back();
}

void CustomListener::enterStatement(JavaParser::StatementContext *ctx)
{
	if (methodsForTraversal.empty())
		return;

	if (!ctx->getTokens(JavaParser::IF).empty() || !ctx->getTokens(JavaParser::FOR).empty() || !ctx->getTokens(JavaParser::WHILE).empty() ||
		!ctx->getTokens(JavaParser::DO).empty() || !ctx->getTokens(JavaParser::CATCH).empty())
	{
		methodsForTraversal.back()->bumpIndependentPaths();
	}

	if (!ctx->catchClause().empty())
	{
		methodsForTraversal.back()->bumpIndependentPaths(ctx->catchClause().size());
	}

	if (!ctx->getTokens(JavaParser::SWITCH).empty())
	{
		methodsForTraversal.back()->bumpIndependentPaths(ctx->switchBlockStatementGroup().size());
	}

	// If ctx has block, we will take it into account later
	if (ctx->block())
		return;

	metricsCalculator->bumpNumberSourceLinesOfCode();
}

void CustomListener::enterExpression(JavaParser::ExpressionContext *ctx)
{
	if (!ctx->getTokens(JavaParser::QUESTION).empty())
	{
		assert(!methodsForTraversal.empty());
		methodsForTraversal.back()->bumpIndependentPaths();
	}
}

void CustomListener::exitMethodDeclaration(JavaParser::MethodDeclarationContext *ctx)
{
	assert(!methodsForTraversal.empty());
	classesForTraversal.back()->addMethod(methodsForTraversal.back());
	methodsForTraversal.pop_back();
}

void CustomListener::exitConstructorDeclaration(JavaParser::ConstructorDeclarationContext *ctx)
{
	assert(!methodsForTraversal.empty());
	classesForTraversal.back()->addMethod(methodsForTraversal.back());
	methodsForTraversal.pop_back();
}

void CustomListener::enterClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *ctx)
{
	assert(!classesForTraversal.empty());

	//if ctx hasn`t memberDeclaration, we have nothing to add
	auto const memberDeclaration = ctx->memberDeclaration();
	if (!memberDeclaration)
		return;

	// These declarations are taken into account in another functions
	if (!(memberDeclaration->classDeclaration() || memberDeclaration->interfaceDeclaration() ||
		  memberDeclaration->annotationTypeDeclaration() || memberDeclaration->enumDeclaration()))
		{
			metricsCalculator->bumpNumberSourceLinesOfCode();
		}

	auto const modifier = getAccessModifier(ctx->modifier(), true);
	string name = "";
	string parameters = "";

	if (memberDeclaration->methodDeclaration())
	{
		name = memberDeclaration->methodDeclaration()->Identifier()->getText();;
		parameters = memberDeclaration->methodDeclaration()->formalParameters()->getText();
	}

	if (memberDeclaration->constructorDeclaration())
	{
		name = memberDeclaration->constructorDeclaration()->Identifier()->getText();
		parameters = memberDeclaration->constructorDeclaration()->formalParameters()->getText();
	}

	if (memberDeclaration->genericMethodDeclaration())
	{
		name = memberDeclaration->genericMethodDeclaration()->methodDeclaration()->Identifier()->getText();
		parameters = memberDeclaration->genericMethodDeclaration()->methodDeclaration()->formalParameters()->getText();
	}

	if (memberDeclaration->genericConstructorDeclaration())
	{
		name = memberDeclaration->genericConstructorDeclaration()->constructorDeclaration()->Identifier()->getText();
		parameters = memberDeclaration->genericConstructorDeclaration()->constructorDeclaration()->formalParameters()->getText();
	}

	if (memberDeclaration->fieldDeclaration())
	{
		auto const variableDeclarators = memberDeclaration->fieldDeclaration()->variableDeclarators()->variableDeclarator();
		for (auto const& v : variableDeclarators)
			classesForTraversal.back()->addAttribute(modifier, v->variableDeclaratorId()->Identifier()->getText());
	}

	if (!name.empty())
	{
		methodsForTraversal.emplace_back(new MethodDescription(modifier, name, name + parameters));
	}
}

void CustomListener::enterInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext *ctx)
{
	assert(!interfacesForTraversal.empty());

	//if ctx hasn`t interfaceMemberDeclaration, we have nothing to add
	auto const interfaceMemberDeclaration = ctx->interfaceMemberDeclaration();
	if (!interfaceMemberDeclaration)
		return;

	// These declarations are taken into account in another functions
	if (!(interfaceMemberDeclaration->interfaceDeclaration() || interfaceMemberDeclaration->interfaceDeclaration() ||
		  interfaceMemberDeclaration->annotationTypeDeclaration() || interfaceMemberDeclaration->enumDeclaration()))
	{
		metricsCalculator->bumpNumberSourceLinesOfCode();
	}

	auto const modifier = getAccessModifier(ctx->modifier(), false);
	string name = "";
	string parameters = "";

	if (interfaceMemberDeclaration->interfaceMethodDeclaration())
	{
		name = interfaceMemberDeclaration->interfaceMethodDeclaration()->Identifier()->getText();
		parameters = interfaceMemberDeclaration->interfaceMethodDeclaration()->formalParameters()->getText();
	}

	if (interfaceMemberDeclaration->genericInterfaceMethodDeclaration())
	{
		name = interfaceMemberDeclaration->genericInterfaceMethodDeclaration()->interfaceMethodDeclaration()->Identifier()->getText();
		parameters = interfaceMemberDeclaration->genericInterfaceMethodDeclaration()->interfaceMethodDeclaration()->formalParameters()->getText();
	}

	if (!name.empty())
	{
		std::shared_ptr<MethodDescription> methodPtr(new MethodDescription(modifier, name, name + parameters));
		interfacesForTraversal.back()->addMethod(methodPtr);
	}
}

void CustomListener::enterCompilationUnit(JavaParser::CompilationUnitContext *ctx)
{
	metricsCalculator->bumpNumberSourceLinesOfCode(ctx->importDeclaration().size());
	if (ctx->packageDeclaration())
		metricsCalculator->bumpNumberSourceLinesOfCode();
}

void CustomListener::enterLocalVariableDeclarationStatement(JavaParser::LocalVariableDeclarationStatementContext *ctx)
{
	metricsCalculator->bumpNumberSourceLinesOfCode();
}

void CustomListener::enterAnnotationName(JavaParser::AnnotationNameContext *ctx)
{
	metricsCalculator->bumpNumberSourceLinesOfCode();
}

void CustomListener::enterAnnotationMethodOrConstantRest(JavaParser::AnnotationMethodOrConstantRestContext *ctx)
{
	metricsCalculator->bumpNumberSourceLinesOfCode();
}

void CustomListener::enterAnnotationTypeDeclaration(JavaParser::AnnotationTypeDeclarationContext *ctx)
{
	metricsCalculator->bumpNumberSourceLinesOfCode();
}

AccessModifier CustomListener::getAccessModifier(vector<JavaParser::ModifierContext *> modifiers, bool isClass) const
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

	if (isClass)
		return AccessModifier::DEFAULT;
	else
		return AccessModifier::PUBLIC;
}

}}
