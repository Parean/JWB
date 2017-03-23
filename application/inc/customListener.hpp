#pragma once

#include <vector>
#include <memory>

#include "JavaBaseListener.h"
#include "metricsCalculator.hpp"
#include "classDescription.hpp"
#include "interfaceDescription.hpp"
#include "methodDescription.hpp"

namespace JWB {	namespace details {

/// @class CustomListener
/// @brief This listener is used to calculate Method Hiding Factor, Attribute Hiding Factor, Comment Percentage and Source Lines of Code
class CustomListener : public JavaBaseListener
{
	public:
		CustomListener() = delete;
		CustomListener(CustomListener const&) = delete;
		CustomListener(CustomListener&&) = delete;
		CustomListener& operator=(CustomListener const&) = delete;
		CustomListener& operator=(CustomListener&&) = delete;

		CustomListener(MetricsCalculator *calculator);

	private:
		// In these methods we recognize class or interface, save it and increment numberSourceLinesOfCode
		// Also we add it to vector, so in program we always can get access to current class or interface
		void enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;
		void enterInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx) override;
		void enterEnumDeclaration(JavaParser::EnumDeclarationContext *ctx) override;

		// In these two methods we remove class or interface from vector to support the ability to access the current class or interface
		void exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;
		void exitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx) override;
		void exitEnumDeclaration(JavaParser::EnumDeclarationContext *ctx);


		// In these two methods we recognize class or interface method or field and save it
		// Also we increment numberSourceLinesOfCode if context has memberDeclaration
		void enterClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *ctx) override;
		void enterInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext *ctx) override;

		// If modifiers contain access modifier, it will be return
		// Otherwise, if isClass true – will be returned PROTECTED, if false – will be returned PUBLIC
		AccessModifier getAccessModifier(std::vector<JavaParser::ModifierContext *> modifiers, bool isClass) const;

		// These methods are used to increment numberSourceLinesOfCode
		void enterLocalVariableDeclarationStatement(JavaParser::LocalVariableDeclarationStatementContext *ctx) override;
		void enterStatement(JavaParser::StatementContext *ctx) override;
		void enterAnnotationName(JavaParser::AnnotationNameContext *ctx) override;
		void enterAnnotationTypeDeclaration(JavaParser::AnnotationTypeDeclarationContext *ctx) override;
		void enterAnnotationMethodOrConstantRest(JavaParser::AnnotationMethodOrConstantRestContext *ctx) override;
		void enterCompilationUnit(JavaParser::CompilationUnitContext *ctx) override;

		// MetricsCalculator is passed to the listener and stores all the data it needs during the tree traversal,
		// then it's used by the client code to calculate various metrics
		MetricsCalculator *metricsCalculator;

		// Used to access the current class or interface during the tree traversal
		std::vector <std::shared_ptr <ClassDescription> > classesForTraversal;
		std::vector <std::shared_ptr <InterfaceDescription> > interfacesForTraversal;
};

}}
