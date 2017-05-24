#include "clusteringMetricsListener.hpp"

#include <typeinfo>
#include <iterator>
#include <sstream>
#include <algorithm>

using namespace std;
namespace JWB {	namespace details {

using std::string;
using std::stringstream;
using std::vector;
using std::list;
using std::shared_ptr;

// It used to split one string into a vector of strings, using as a delimiter in the starting string the character passed as parameter
vector<string> split(const string &s, char delim)
{
	stringstream ss;
	ss.str(s);

	vector<string> elems;
	auto result = std::back_inserter(elems);
	string item;

	while (std::getline(ss, item, delim))
		*(result++) = item;

	return elems;
}

ClusteringMetricsListener::ClusteringMetricsListener(list <shared_ptr < ClusteringClassDescription> > &classes)
{
	for (auto const& c : classes)
	{
		customClasses.insert({c->getName(), c.get()});
	}
}

void ClusteringMetricsListener::enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	string className = "";
	if (ctx->typeParameters())
		className = ctx->Identifier()->getText() + ctx->typeParameters()->getText();
	else
		className = ctx->Identifier()->getText();

	classesForTraversal.push_back(className);
}

void ClusteringMetricsListener::exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
	assert(!classesForTraversal.empty());
	classesForTraversal.pop_back();
}


void ClusteringMetricsListener::enterEnumDeclaration(JavaParser::EnumDeclarationContext *ctx)
{
	classesForTraversal.push_back(ctx->Identifier()->getText());
}

void ClusteringMetricsListener::exitEnumDeclaration(JavaParser::EnumDeclarationContext *ctx)
{
	assert(!classesForTraversal.empty());
	classesForTraversal.pop_back();
}

void ClusteringMetricsListener::enterMethodDeclaration(JavaParser::MethodDeclarationContext *ctx)
{
	methodsForTraversal.push_back(ctx->Identifier()->getText());
}

void ClusteringMetricsListener::exitMethodDeclaration(JavaParser::MethodDeclarationContext *ctx)
{
	assert(!methodsForTraversal.empty());
	methodsForTraversal.pop_back();
}

void ClusteringMetricsListener::enterConstructorDeclaration(JavaParser::ConstructorDeclarationContext *ctx)
{
	methodsForTraversal.push_back(ctx->Identifier()->getText());
}

void ClusteringMetricsListener::exitConstructorDeclaration(JavaParser::ConstructorDeclarationContext *ctx)
{
	assert(!methodsForTraversal.empty());
	methodsForTraversal.pop_back();
}


void ClusteringMetricsListener::enterClassOrInterfaceType(JavaParser::ClassOrInterfaceTypeContext *ctx)
{
	if (classesForTraversal.empty() ||
		(typeid(JavaParser::FormalParameterContext) != typeid(*ctx->parent->parent)) &&
		(typeid(JavaParser::FieldDeclarationContext) != typeid(*ctx->parent->parent)) &&
		(typeid(JavaParser::LocalVariableDeclarationContext) != typeid(*ctx->parent->parent)))
			return;

	auto const& currentClass = customClasses.find(classesForTraversal.back());
	assert(currentClass != customClasses.end());

	//We shouldn't add in class coupling with it ourselves
	if (currentClass->first == ctx->getText())
		return;

	auto usedClass = split(ctx->getText(), '.').back();
	currentClass->second->addUsedClass(usedClass, getCouplingType(ctx));

	auto usingClass = customClasses.find(usedClass);
	if (usingClass != customClasses.end())
	{
		usingClass->second->addUsingClass(currentClass->first, getCouplingType(ctx));
	}

}

void ClusteringMetricsListener::enterPrimary(JavaParser::PrimaryContext *ctx)
{
	if (classesForTraversal.empty())
		return;

	auto const& currentClass = customClasses.find(classesForTraversal.back());
	assert(currentClass != customClasses.end());

	// We must add static coupling if it exists
	if (currentClass->first != ctx->getText())
	{
		auto usingClass = customClasses.find(ctx->getText());
		if (usingClass != customClasses.end())
		{
			currentClass->second->addUsedClass(ctx->getText(), CouplingType::STATIC);
			usingClass->second->addUsingClass(currentClass->first, CouplingType::STATIC);

			// if in current method there is a reference to a static attribute of another class, we want to add it
			if (typeid(JavaParser::ExpressionContext) == typeid(*ctx->parent->parent) &&
				typeid(JavaParser::ExpressionContext) == typeid(*ctx->parent->parent->parent) &&
				dynamic_cast<JavaParser::ExpressionContext*>(ctx->parent->parent->parent)->getTokens(JavaParser::LPAREN).empty() &&
				!methodsForTraversal.empty())
				{
					auto const& methods = currentClass->second->getMethods();
					auto const& currentMethod = methods.find(methodsForTraversal.back());
					assert(currentMethod != methods.end());

					currentMethod->second->addStaticAttribute(
						dynamic_cast<JavaParser::ExpressionContext*>(ctx->parent->parent)->Identifier()->getText());
				}

			return;
		}
	}

	if (methodsForTraversal.empty())
		return;

	auto const& methods = currentClass->second->getMethods();
	auto const& currentMethod = methods.find(methodsForTraversal.back());
	assert(currentMethod != methods.end());

	// If in class there is a method with ctx->getText() name, we add it to calledMethods in current method
	if (methods.find(ctx->getText()) != methods.end())
	{
		currentMethod->second->addCalledMethod(ctx->getText(), TypeOfCalledMethod::CURRENT_CLASS_METHOD);
		return;
	}

	// If in code there is a class method that called as this.methodName() we also must add it
	if (ctx->getText() == "this")
	{
		if (typeid(JavaParser::ExpressionContext) == typeid(*ctx->parent->parent) &&
			methods.find(dynamic_cast<JavaParser::ExpressionContext*>(ctx->parent->parent)->Identifier()->getText()) != methods.end())
		{
			currentMethod->second->addCalledMethod(dynamic_cast<JavaParser::ExpressionContext*>(ctx->parent->parent)->
			Identifier()->getText(), TypeOfCalledMethod::CURRENT_CLASS_METHOD);
			return;
		}
	}

	// If in class there is an attribute with ctx->getText() name, we add it to usedAttributes in current method
	auto const& attributes = currentClass->second->getAttributes();
	if (attributes.find(ctx->getText()) != attributes.end())
	{
		currentMethod->second->addUsedAttribute(ctx->getText());
		return;
	}

	// If in code there is a class attribute that used as this.attributeName we also must add it
	if (ctx->getText() == "this")
	{
		if (typeid(JavaParser::ExpressionContext) == typeid(*ctx->parent->parent) &&
			attributes.find(dynamic_cast<JavaParser::ExpressionContext*>(ctx->parent->parent)->Identifier()->getText()) != attributes.end())
		{
			currentMethod->second->addUsedAttribute(dynamic_cast<JavaParser::ExpressionContext*>(ctx->parent->parent)->Identifier()->getText());
			return;
		}
	}
}

void ClusteringMetricsListener::enterExpression(JavaParser::ExpressionContext *ctx)
{
	if(!ctx->Identifier() ||
		typeid(JavaParser::ExpressionContext) != typeid(*ctx->parent) ||
		dynamic_cast<JavaParser::ExpressionContext*>(ctx->parent)->getTokens(JavaParser::LPAREN).empty() ||
		ctx->expression(0) && ctx->expression(0)->primary() && ctx->expression(0)->primary()->getText() == "this")
	{
		return;
	}

	assert(!classesForTraversal.empty());
	auto const& currentClass = customClasses.find(classesForTraversal.back());
	assert(currentClass != customClasses.end());

	if (methodsForTraversal.empty())
		return;

	auto const& methods = currentClass->second->getMethods();
	auto currentMethod = methods.find(methodsForTraversal.back());
	assert(currentMethod != methods.end());

	currentMethod->second->addCalledMethod(ctx->Identifier()->getText(), TypeOfCalledMethod::DIFFERENT_CLASS_METHOD);
}

CouplingType ClusteringMetricsListener::getCouplingType(antlr4::ParserRuleContext *ctx) const
{
	if(typeid(JavaParser::FormalParameterContext) == typeid(*ctx->parent->parent))
		return CouplingType::PARAMETER;

	if(typeid(JavaParser::FieldDeclarationContext) == typeid(*ctx->parent->parent))
		return CouplingType::ATTRIBUTE;

	return CouplingType::VARIABLE;
}

}}
