#pragma once

#include <unordered_map>
#include <string>
#include <forward_list>
#include <vector>

#include "JavaBaseListener.h"
#include "clusteringClassDescription.hpp"

namespace JWB {	namespace details {

/// @class ClusteringMetricsListener
/// @brief This listener is used for clustering metrics
class ClusteringMetricsListener : public JavaBaseListener
{
public:
	ClusteringMetricsListener() = delete;
	ClusteringMetricsListener(ClusteringMetricsListener const&) = delete;
	ClusteringMetricsListener(ClusteringMetricsListener&&) = delete;
	ClusteringMetricsListener& operator=(ClusteringMetricsListener const&) = delete;
	ClusteringMetricsListener& operator=(ClusteringMetricsListener&&) = delete;

	// Takes a list from all existing classes and creates a map consisting of a class name and a pointer to clusteringClassDescription
	ClusteringMetricsListener(std::list <std::shared_ptr < ClusteringClassDescription> > &classes);

private:

	// In these methods we add class to vector, so in program we always can get access to current class
	void enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;
	void enterEnumDeclaration(JavaParser::EnumDeclarationContext *ctx) override;

	// In these methods we remove current class from vector to support the ability to access the current class
	void exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;
	void exitEnumDeclaration(JavaParser::EnumDeclarationContext *ctx);

	// In these methods we add method to vector, so in program we always can get access to current method
	void enterMethodDeclaration(JavaParser::MethodDeclarationContext *ctx) override;
	void enterConstructorDeclaration(JavaParser::ConstructorDeclarationContext *ctx) override;

	// In these methods we remove current method from vector to support the ability to access the current method
	void exitMethodDeclaration(JavaParser::MethodDeclarationContext *ctx) override;
	void exitConstructorDeclaration(JavaParser::ConstructorDeclarationContext *ctx) override;

	// It used to add called method or used attribute of current class (if they exist) to current method
	// Also it add static coupling into current class if it exists
	void enterPrimary(JavaParser::PrimaryContext *ctx) override;

	// It used to add called method of different class (if it exists) to current method
	void enterExpression(JavaParser::ExpressionContext *ctx) override;

	// In this method we check if there is a coupling between the different classes and if so, add it
	void enterClassOrInterfaceType(JavaParser::ClassOrInterfaceTypeContext *ctx) override;

	CouplingType getCouplingType(antlr4::ParserRuleContext *ctx) const;

	// It stores classes of project
	std::unordered_map<std::string, ClusteringClassDescription*> customClasses;

	// Used to access the current class during the tree traversal
	std::vector<std::string> classesForTraversal;

	// Used to access the current method during the tree traversal
	std::vector<std::string> methodsForTraversal;
};

}}
