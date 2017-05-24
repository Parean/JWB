#include <iostream>
#include <typeinfo>

#include "accessModifier.hpp"
#include "simpleMetricsListener.hpp"

using std::vector;
using std::string;
using std::shared_ptr;

namespace JWB {	namespace details {

SimpleMetricsListener::SimpleMetricsListener(SimpleMetricsCalculator *calculator):
	simpleMetricsCalculator(calculator)
{
	assert(calculator);
}

void SimpleMetricsListener::enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	string className = "";
	if (ctx->typeParameters())
		className = ctx->Identifier()->getText() + ctx->typeParameters()->getText();
	else
		className = ctx->Identifier()->getText();

	classesForTraversal.emplace_back(new ClusteringClassDescription(className));
	simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
}

void SimpleMetricsListener::enterInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx)
{
	interfacesForTraversal.emplace_back(new ClusteringInterfaceDescription(ctx->Identifier()->getText()));
	simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
}

void SimpleMetricsListener::enterEnumDeclaration(JavaParser::EnumDeclarationContext *ctx)
{
	classesForTraversal.emplace_back(new ClusteringClassDescription(ctx->Identifier()->getText()));
	simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
}

void SimpleMetricsListener::exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	assert(!classesForTraversal.empty());
	simpleMetricsCalculator->addClass(classesForTraversal.back());
	classesForTraversal.pop_back();
}

void SimpleMetricsListener::exitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx)
{
	assert(!interfacesForTraversal.empty());
	simpleMetricsCalculator->addInterface(interfacesForTraversal.back());
	interfacesForTraversal.pop_back();
}

void SimpleMetricsListener::exitEnumDeclaration(JavaParser::EnumDeclarationContext *ctx)
{
	assert(!classesForTraversal.empty());
	simpleMetricsCalculator->addClass(classesForTraversal.back());
	classesForTraversal.pop_back();
}

void SimpleMetricsListener::enterStatement(JavaParser::StatementContext *ctx)
{
	if (methodsForTraversal.empty());
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

	simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
}

void SimpleMetricsListener::enterExpression(JavaParser::ExpressionContext *ctx)
{
	if (!ctx->getTokens(JavaParser::QUESTION).empty())
	{
		assert(!methodsForTraversal.empty());
		methodsForTraversal.back()->bumpIndependentPaths();
	}
}

void SimpleMetricsListener::exitMethodDeclaration(JavaParser::MethodDeclarationContext *ctx)
{
	assert(!methodsForTraversal.empty());
	classesForTraversal.back()->addMethod(methodsForTraversal.back());
	methodsForTraversal.pop_back();
}

void SimpleMetricsListener::exitConstructorDeclaration(JavaParser::ConstructorDeclarationContext *ctx)
{
	assert(!methodsForTraversal.empty());
	classesForTraversal.back()->addMethod(methodsForTraversal.back());
	methodsForTraversal.pop_back();
}

void SimpleMetricsListener::enterClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *ctx)
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
			simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
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
		methodsForTraversal.emplace_back(new ClusteringMethodDescription(modifier, name, name + parameters));
	}
}

void SimpleMetricsListener::enterInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext *ctx)
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
		simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
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
		std::shared_ptr<ClusteringMethodDescription> methodPtr(new ClusteringMethodDescription(modifier, name, name + parameters));
		interfacesForTraversal.back()->addMethod(methodPtr);
	}
}

void SimpleMetricsListener::enterCompilationUnit(JavaParser::CompilationUnitContext *ctx)
{
	simpleMetricsCalculator->bumpNumberSourceLinesOfCode(ctx->importDeclaration().size());
	if (ctx->packageDeclaration())
		simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
}

void SimpleMetricsListener::enterLocalVariableDeclarationStatement(JavaParser::LocalVariableDeclarationStatementContext *ctx)
{
	simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
}

void SimpleMetricsListener::enterAnnotationName(JavaParser::AnnotationNameContext *ctx)
{
	simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
}

void SimpleMetricsListener::enterAnnotationMethodOrConstantRest(JavaParser::AnnotationMethodOrConstantRestContext *ctx)
{
	simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
}

void SimpleMetricsListener::enterAnnotationTypeDeclaration(JavaParser::AnnotationTypeDeclarationContext *ctx)
{
	simpleMetricsCalculator->bumpNumberSourceLinesOfCode();
}

AccessModifier SimpleMetricsListener::getAccessModifier(vector<JavaParser::ModifierContext *> modifiers, bool isClass) const
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

void SimpleMetricsListener::enterFormalParameters(JavaParser::FormalParametersContext *ctx)
{
	if (!ctx->formalParameterList() || typeid(JavaParser::InterfaceMethodDeclarationContext) == typeid(*ctx->parent))
		return;

	assert(!methodsForTraversal.empty());
	for (auto c : ctx->formalParameterList()->formalParameter())
	{
		methodsForTraversal.back()->addParameter(c->getText());
		methodsForTraversal.back()->addUsedLocalVariable(c->variableDeclaratorId()->getText());
	}
}

void SimpleMetricsListener::enterLocalVariableDeclaration(JavaParser::LocalVariableDeclarationContext *ctx)
{
	if(methodsForTraversal.empty());
		return;

	for (auto const& c : ctx->variableDeclarators()->variableDeclarator())
		methodsForTraversal.back()->addUsedLocalVariable(c->variableDeclaratorId()->getText());
}
}}
