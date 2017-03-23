
// Generated from Java.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "JavaParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by JavaParser.
 */
class  JavaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by JavaParser.
   */
    virtual antlrcpp::Any visitCompilationUnit(JavaParser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitPackageDeclaration(JavaParser::PackageDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitImportDeclaration(JavaParser::ImportDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitTypeDeclaration(JavaParser::TypeDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitModifier(JavaParser::ModifierContext *context) = 0;

    virtual antlrcpp::Any visitClassOrInterfaceModifier(JavaParser::ClassOrInterfaceModifierContext *context) = 0;

    virtual antlrcpp::Any visitVariableModifier(JavaParser::VariableModifierContext *context) = 0;

    virtual antlrcpp::Any visitClassDeclaration(JavaParser::ClassDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitTypeParameters(JavaParser::TypeParametersContext *context) = 0;

    virtual antlrcpp::Any visitTypeParameter(JavaParser::TypeParameterContext *context) = 0;

    virtual antlrcpp::Any visitTypeBound(JavaParser::TypeBoundContext *context) = 0;

    virtual antlrcpp::Any visitEnumDeclaration(JavaParser::EnumDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitEnumConstants(JavaParser::EnumConstantsContext *context) = 0;

    virtual antlrcpp::Any visitEnumConstant(JavaParser::EnumConstantContext *context) = 0;

    virtual antlrcpp::Any visitEnumBodyDeclarations(JavaParser::EnumBodyDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitTypeList(JavaParser::TypeListContext *context) = 0;

    virtual antlrcpp::Any visitClassBody(JavaParser::ClassBodyContext *context) = 0;

    virtual antlrcpp::Any visitInterfaceBody(JavaParser::InterfaceBodyContext *context) = 0;

    virtual antlrcpp::Any visitClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitMemberDeclaration(JavaParser::MemberDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitMethodDeclaration(JavaParser::MethodDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitGenericMethodDeclaration(JavaParser::GenericMethodDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitConstructorDeclaration(JavaParser::ConstructorDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitGenericConstructorDeclaration(JavaParser::GenericConstructorDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFieldDeclaration(JavaParser::FieldDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitInterfaceMemberDeclaration(JavaParser::InterfaceMemberDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitConstDeclaration(JavaParser::ConstDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitConstantDeclarator(JavaParser::ConstantDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitInterfaceMethodDeclaration(JavaParser::InterfaceMethodDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitGenericInterfaceMethodDeclaration(JavaParser::GenericInterfaceMethodDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarators(JavaParser::VariableDeclaratorsContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarator(JavaParser::VariableDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaratorId(JavaParser::VariableDeclaratorIdContext *context) = 0;

    virtual antlrcpp::Any visitVariableInitializer(JavaParser::VariableInitializerContext *context) = 0;

    virtual antlrcpp::Any visitArrayInitializer(JavaParser::ArrayInitializerContext *context) = 0;

    virtual antlrcpp::Any visitEnumConstantName(JavaParser::EnumConstantNameContext *context) = 0;

    virtual antlrcpp::Any visitTypeType(JavaParser::TypeTypeContext *context) = 0;

    virtual antlrcpp::Any visitClassOrInterfaceType(JavaParser::ClassOrInterfaceTypeContext *context) = 0;

    virtual antlrcpp::Any visitPrimitiveType(JavaParser::PrimitiveTypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeArguments(JavaParser::TypeArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitTypeArgument(JavaParser::TypeArgumentContext *context) = 0;

    virtual antlrcpp::Any visitQualifiedNameList(JavaParser::QualifiedNameListContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameters(JavaParser::FormalParametersContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameterList(JavaParser::FormalParameterListContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameter(JavaParser::FormalParameterContext *context) = 0;

    virtual antlrcpp::Any visitLastFormalParameter(JavaParser::LastFormalParameterContext *context) = 0;

    virtual antlrcpp::Any visitMethodBody(JavaParser::MethodBodyContext *context) = 0;

    virtual antlrcpp::Any visitConstructorBody(JavaParser::ConstructorBodyContext *context) = 0;

    virtual antlrcpp::Any visitQualifiedName(JavaParser::QualifiedNameContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(JavaParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitAnnotation(JavaParser::AnnotationContext *context) = 0;

    virtual antlrcpp::Any visitAnnotationName(JavaParser::AnnotationNameContext *context) = 0;

    virtual antlrcpp::Any visitElementValuePairs(JavaParser::ElementValuePairsContext *context) = 0;

    virtual antlrcpp::Any visitElementValuePair(JavaParser::ElementValuePairContext *context) = 0;

    virtual antlrcpp::Any visitElementValue(JavaParser::ElementValueContext *context) = 0;

    virtual antlrcpp::Any visitElementValueArrayInitializer(JavaParser::ElementValueArrayInitializerContext *context) = 0;

    virtual antlrcpp::Any visitAnnotationTypeDeclaration(JavaParser::AnnotationTypeDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitAnnotationTypeBody(JavaParser::AnnotationTypeBodyContext *context) = 0;

    virtual antlrcpp::Any visitAnnotationTypeElementDeclaration(JavaParser::AnnotationTypeElementDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitAnnotationTypeElementRest(JavaParser::AnnotationTypeElementRestContext *context) = 0;

    virtual antlrcpp::Any visitAnnotationMethodOrConstantRest(JavaParser::AnnotationMethodOrConstantRestContext *context) = 0;

    virtual antlrcpp::Any visitAnnotationMethodRest(JavaParser::AnnotationMethodRestContext *context) = 0;

    virtual antlrcpp::Any visitAnnotationConstantRest(JavaParser::AnnotationConstantRestContext *context) = 0;

    virtual antlrcpp::Any visitDefaultValue(JavaParser::DefaultValueContext *context) = 0;

    virtual antlrcpp::Any visitBlock(JavaParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitBlockStatement(JavaParser::BlockStatementContext *context) = 0;

    virtual antlrcpp::Any visitLocalVariableDeclarationStatement(JavaParser::LocalVariableDeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitLocalVariableDeclaration(JavaParser::LocalVariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitStatement(JavaParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitCatchClause(JavaParser::CatchClauseContext *context) = 0;

    virtual antlrcpp::Any visitCatchType(JavaParser::CatchTypeContext *context) = 0;

    virtual antlrcpp::Any visitFinallyBlock(JavaParser::FinallyBlockContext *context) = 0;

    virtual antlrcpp::Any visitResourceSpecification(JavaParser::ResourceSpecificationContext *context) = 0;

    virtual antlrcpp::Any visitResources(JavaParser::ResourcesContext *context) = 0;

    virtual antlrcpp::Any visitResource(JavaParser::ResourceContext *context) = 0;

    virtual antlrcpp::Any visitSwitchBlockStatementGroup(JavaParser::SwitchBlockStatementGroupContext *context) = 0;

    virtual antlrcpp::Any visitSwitchLabel(JavaParser::SwitchLabelContext *context) = 0;

    virtual antlrcpp::Any visitForControl(JavaParser::ForControlContext *context) = 0;

    virtual antlrcpp::Any visitForInit(JavaParser::ForInitContext *context) = 0;

    virtual antlrcpp::Any visitEnhancedForControl(JavaParser::EnhancedForControlContext *context) = 0;

    virtual antlrcpp::Any visitForUpdate(JavaParser::ForUpdateContext *context) = 0;

    virtual antlrcpp::Any visitParExpression(JavaParser::ParExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExpressionList(JavaParser::ExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitStatementExpression(JavaParser::StatementExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConstantExpression(JavaParser::ConstantExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExpression(JavaParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(JavaParser::PrimaryContext *context) = 0;

    virtual antlrcpp::Any visitCreator(JavaParser::CreatorContext *context) = 0;

    virtual antlrcpp::Any visitCreatedName(JavaParser::CreatedNameContext *context) = 0;

    virtual antlrcpp::Any visitInnerCreator(JavaParser::InnerCreatorContext *context) = 0;

    virtual antlrcpp::Any visitArrayCreatorRest(JavaParser::ArrayCreatorRestContext *context) = 0;

    virtual antlrcpp::Any visitClassCreatorRest(JavaParser::ClassCreatorRestContext *context) = 0;

    virtual antlrcpp::Any visitExplicitGenericInvocation(JavaParser::ExplicitGenericInvocationContext *context) = 0;

    virtual antlrcpp::Any visitNonWildcardTypeArguments(JavaParser::NonWildcardTypeArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitTypeArgumentsOrDiamond(JavaParser::TypeArgumentsOrDiamondContext *context) = 0;

    virtual antlrcpp::Any visitNonWildcardTypeArgumentsOrDiamond(JavaParser::NonWildcardTypeArgumentsOrDiamondContext *context) = 0;

    virtual antlrcpp::Any visitSuperSuffix(JavaParser::SuperSuffixContext *context) = 0;

    virtual antlrcpp::Any visitExplicitGenericInvocationSuffix(JavaParser::ExplicitGenericInvocationSuffixContext *context) = 0;

    virtual antlrcpp::Any visitArguments(JavaParser::ArgumentsContext *context) = 0;


};

