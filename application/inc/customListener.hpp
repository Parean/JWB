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
/// @brief This listener is used to сollect data for Method Hiding Factor and Attribute Hiding Factor metrics
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
		// In this two methods we recognize class or interface and save it
		// Also we add it to vector, so in program we always can get access to current class or interface
		void enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;
		void enterInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx) override;

		// In this two methods we remove class or interface from vector to support the ability to access the current class or interface
		void exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;
		void exitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx) override;

		// In this two methods we recognize class or interface method or field and save it
		void enterClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *ctx) override;
		void enterInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext *ctx) override;

		// If modifiers contain access modifier, it will be return
		// Otherwise will be return PROTECTED
		AccessModifier getAccessModifier(std::vector<JavaParser::ModifierContext *> modifiers) const;

		// MetricsCalculator is passed to the listener and stores all the data it needs during the tree traversal,
		// then it's used by the client code to calculate various metrics
		MetricsCalculator *metricsCalculator;

		// Used to access the current class or interface during the tree traversal
		std::vector <std::shared_ptr <ClassDescription> > classesForTraversal;
		std::vector <std::shared_ptr <InterfaceDescription> > interfacesForTraversal;
};

}}
