
// Generated from Java.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"




class  JavaParser : public antlr4::Parser {
public:
  enum {
    ABSTRACT = 1, ASSERT = 2, BOOLEAN = 3, BREAK = 4, BYTE = 5, CASE = 6, 
    CATCH = 7, CHAR = 8, CLASS = 9, CONST = 10, CONTINUE = 11, DEFAULT = 12, 
    DO = 13, DOUBLE = 14, ELSE = 15, ENUM = 16, EXTENDS = 17, FINAL = 18, 
    FINALLY = 19, FLOAT = 20, FOR = 21, IF = 22, GOTO = 23, IMPLEMENTS = 24, 
    IMPORT = 25, INSTANCEOF = 26, INT = 27, INTERFACE = 28, LONG = 29, NATIVE = 30, 
    NEW = 31, PACKAGE = 32, PRIVATE = 33, PROTECTED = 34, PUBLIC = 35, RETURN = 36, 
    SHORT = 37, STATIC = 38, STRICTFP = 39, SUPER = 40, SWITCH = 41, SYNCHRONIZED = 42, 
    THIS = 43, THROW = 44, THROWS = 45, TRANSIENT = 46, TRY = 47, VOID = 48, 
    VOLATILE = 49, WHILE = 50, IntegerLiteral = 51, FloatingPointLiteral = 52, 
    BooleanLiteral = 53, CharacterLiteral = 54, StringLiteral = 55, NullLiteral = 56, 
    LPAREN = 57, RPAREN = 58, LBRACE = 59, RBRACE = 60, LBRACK = 61, RBRACK = 62, 
    SEMI = 63, COMMA = 64, DOT = 65, ASSIGN = 66, GT = 67, LT = 68, BANG = 69, 
    TILDE = 70, QUESTION = 71, COLON = 72, EQUAL = 73, LE = 74, GE = 75, 
    NOTEQUAL = 76, AND = 77, OR = 78, INC = 79, DEC = 80, ADD = 81, SUB = 82, 
    MUL = 83, DIV = 84, BITAND = 85, BITOR = 86, CARET = 87, MOD = 88, ADD_ASSIGN = 89, 
    SUB_ASSIGN = 90, MUL_ASSIGN = 91, DIV_ASSIGN = 92, AND_ASSIGN = 93, 
    OR_ASSIGN = 94, XOR_ASSIGN = 95, MOD_ASSIGN = 96, LSHIFT_ASSIGN = 97, 
    RSHIFT_ASSIGN = 98, URSHIFT_ASSIGN = 99, Identifier = 100, AT = 101, 
    ELLIPSIS = 102, WS = 103, COMMENT = 104, LINE_COMMENT = 105
  };

  enum {
    RuleCompilationUnit = 0, RulePackageDeclaration = 1, RuleImportDeclaration = 2, 
    RuleTypeDeclaration = 3, RuleModifier = 4, RuleClassOrInterfaceModifier = 5, 
    RuleVariableModifier = 6, RuleClassDeclaration = 7, RuleTypeParameters = 8, 
    RuleTypeParameter = 9, RuleTypeBound = 10, RuleEnumDeclaration = 11, 
    RuleEnumConstants = 12, RuleEnumConstant = 13, RuleEnumBodyDeclarations = 14, 
    RuleInterfaceDeclaration = 15, RuleTypeList = 16, RuleClassBody = 17, 
    RuleInterfaceBody = 18, RuleClassBodyDeclaration = 19, RuleMemberDeclaration = 20, 
    RuleMethodDeclaration = 21, RuleGenericMethodDeclaration = 22, RuleConstructorDeclaration = 23, 
    RuleGenericConstructorDeclaration = 24, RuleFieldDeclaration = 25, RuleInterfaceBodyDeclaration = 26, 
    RuleInterfaceMemberDeclaration = 27, RuleConstDeclaration = 28, RuleConstantDeclarator = 29, 
    RuleInterfaceMethodDeclaration = 30, RuleGenericInterfaceMethodDeclaration = 31, 
    RuleVariableDeclarators = 32, RuleVariableDeclarator = 33, RuleVariableDeclaratorId = 34, 
    RuleVariableInitializer = 35, RuleArrayInitializer = 36, RuleEnumConstantName = 37, 
    RuleTypeType = 38, RuleClassOrInterfaceType = 39, RulePrimitiveType = 40, 
    RuleTypeArguments = 41, RuleTypeArgument = 42, RuleQualifiedNameList = 43, 
    RuleFormalParameters = 44, RuleFormalParameterList = 45, RuleFormalParameter = 46, 
    RuleLastFormalParameter = 47, RuleMethodBody = 48, RuleConstructorBody = 49, 
    RuleQualifiedName = 50, RuleLiteral = 51, RuleAnnotation = 52, RuleAnnotationName = 53, 
    RuleElementValuePairs = 54, RuleElementValuePair = 55, RuleElementValue = 56, 
    RuleElementValueArrayInitializer = 57, RuleAnnotationTypeDeclaration = 58, 
    RuleAnnotationTypeBody = 59, RuleAnnotationTypeElementDeclaration = 60, 
    RuleAnnotationTypeElementRest = 61, RuleAnnotationMethodOrConstantRest = 62, 
    RuleAnnotationMethodRest = 63, RuleAnnotationConstantRest = 64, RuleDefaultValue = 65, 
    RuleBlock = 66, RuleBlockStatement = 67, RuleLocalVariableDeclarationStatement = 68, 
    RuleLocalVariableDeclaration = 69, RuleStatement = 70, RuleCatchClause = 71, 
    RuleCatchType = 72, RuleFinallyBlock = 73, RuleResourceSpecification = 74, 
    RuleResources = 75, RuleResource = 76, RuleSwitchBlockStatementGroup = 77, 
    RuleSwitchLabel = 78, RuleForControl = 79, RuleForInit = 80, RuleEnhancedForControl = 81, 
    RuleForUpdate = 82, RuleParExpression = 83, RuleExpressionList = 84, 
    RuleStatementExpression = 85, RuleConstantExpression = 86, RuleExpression = 87, 
    RulePrimary = 88, RuleCreator = 89, RuleCreatedName = 90, RuleInnerCreator = 91, 
    RuleArrayCreatorRest = 92, RuleClassCreatorRest = 93, RuleExplicitGenericInvocation = 94, 
    RuleNonWildcardTypeArguments = 95, RuleTypeArgumentsOrDiamond = 96, 
    RuleNonWildcardTypeArgumentsOrDiamond = 97, RuleSuperSuffix = 98, RuleExplicitGenericInvocationSuffix = 99, 
    RuleArguments = 100
  };

  JavaParser(antlr4::TokenStream *input);
  ~JavaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompilationUnitContext;
  class PackageDeclarationContext;
  class ImportDeclarationContext;
  class TypeDeclarationContext;
  class ModifierContext;
  class ClassOrInterfaceModifierContext;
  class VariableModifierContext;
  class ClassDeclarationContext;
  class TypeParametersContext;
  class TypeParameterContext;
  class TypeBoundContext;
  class EnumDeclarationContext;
  class EnumConstantsContext;
  class EnumConstantContext;
  class EnumBodyDeclarationsContext;
  class InterfaceDeclarationContext;
  class TypeListContext;
  class ClassBodyContext;
  class InterfaceBodyContext;
  class ClassBodyDeclarationContext;
  class MemberDeclarationContext;
  class MethodDeclarationContext;
  class GenericMethodDeclarationContext;
  class ConstructorDeclarationContext;
  class GenericConstructorDeclarationContext;
  class FieldDeclarationContext;
  class InterfaceBodyDeclarationContext;
  class InterfaceMemberDeclarationContext;
  class ConstDeclarationContext;
  class ConstantDeclaratorContext;
  class InterfaceMethodDeclarationContext;
  class GenericInterfaceMethodDeclarationContext;
  class VariableDeclaratorsContext;
  class VariableDeclaratorContext;
  class VariableDeclaratorIdContext;
  class VariableInitializerContext;
  class ArrayInitializerContext;
  class EnumConstantNameContext;
  class TypeTypeContext;
  class ClassOrInterfaceTypeContext;
  class PrimitiveTypeContext;
  class TypeArgumentsContext;
  class TypeArgumentContext;
  class QualifiedNameListContext;
  class FormalParametersContext;
  class FormalParameterListContext;
  class FormalParameterContext;
  class LastFormalParameterContext;
  class MethodBodyContext;
  class ConstructorBodyContext;
  class QualifiedNameContext;
  class LiteralContext;
  class AnnotationContext;
  class AnnotationNameContext;
  class ElementValuePairsContext;
  class ElementValuePairContext;
  class ElementValueContext;
  class ElementValueArrayInitializerContext;
  class AnnotationTypeDeclarationContext;
  class AnnotationTypeBodyContext;
  class AnnotationTypeElementDeclarationContext;
  class AnnotationTypeElementRestContext;
  class AnnotationMethodOrConstantRestContext;
  class AnnotationMethodRestContext;
  class AnnotationConstantRestContext;
  class DefaultValueContext;
  class BlockContext;
  class BlockStatementContext;
  class LocalVariableDeclarationStatementContext;
  class LocalVariableDeclarationContext;
  class StatementContext;
  class CatchClauseContext;
  class CatchTypeContext;
  class FinallyBlockContext;
  class ResourceSpecificationContext;
  class ResourcesContext;
  class ResourceContext;
  class SwitchBlockStatementGroupContext;
  class SwitchLabelContext;
  class ForControlContext;
  class ForInitContext;
  class EnhancedForControlContext;
  class ForUpdateContext;
  class ParExpressionContext;
  class ExpressionListContext;
  class StatementExpressionContext;
  class ConstantExpressionContext;
  class ExpressionContext;
  class PrimaryContext;
  class CreatorContext;
  class CreatedNameContext;
  class InnerCreatorContext;
  class ArrayCreatorRestContext;
  class ClassCreatorRestContext;
  class ExplicitGenericInvocationContext;
  class NonWildcardTypeArgumentsContext;
  class TypeArgumentsOrDiamondContext;
  class NonWildcardTypeArgumentsOrDiamondContext;
  class SuperSuffixContext;
  class ExplicitGenericInvocationSuffixContext;
  class ArgumentsContext; 

  class  CompilationUnitContext : public antlr4::ParserRuleContext {
  public:
    CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    PackageDeclarationContext *packageDeclaration();
    std::vector<ImportDeclarationContext *> importDeclaration();
    ImportDeclarationContext* importDeclaration(size_t i);
    std::vector<TypeDeclarationContext *> typeDeclaration();
    TypeDeclarationContext* typeDeclaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompilationUnitContext* compilationUnit();

  class  PackageDeclarationContext : public antlr4::ParserRuleContext {
  public:
    PackageDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QualifiedNameContext *qualifiedName();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PackageDeclarationContext* packageDeclaration();

  class  ImportDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ImportDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QualifiedNameContext *qualifiedName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportDeclarationContext* importDeclaration();

  class  TypeDeclarationContext : public antlr4::ParserRuleContext {
  public:
    TypeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassDeclarationContext *classDeclaration();
    std::vector<ClassOrInterfaceModifierContext *> classOrInterfaceModifier();
    ClassOrInterfaceModifierContext* classOrInterfaceModifier(size_t i);
    EnumDeclarationContext *enumDeclaration();
    InterfaceDeclarationContext *interfaceDeclaration();
    AnnotationTypeDeclarationContext *annotationTypeDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDeclarationContext* typeDeclaration();

  class  ModifierContext : public antlr4::ParserRuleContext {
  public:
    ModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassOrInterfaceModifierContext *classOrInterfaceModifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModifierContext* modifier();

  class  ClassOrInterfaceModifierContext : public antlr4::ParserRuleContext {
  public:
    ClassOrInterfaceModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationContext *annotation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassOrInterfaceModifierContext* classOrInterfaceModifier();

  class  VariableModifierContext : public antlr4::ParserRuleContext {
  public:
    VariableModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationContext *annotation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableModifierContext* variableModifier();

  class  ClassDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ClassDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    ClassBodyContext *classBody();
    TypeParametersContext *typeParameters();
    TypeTypeContext *typeType();
    TypeListContext *typeList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassDeclarationContext* classDeclaration();

  class  TypeParametersContext : public antlr4::ParserRuleContext {
  public:
    TypeParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeParameterContext *> typeParameter();
    TypeParameterContext* typeParameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeParametersContext* typeParameters();

  class  TypeParameterContext : public antlr4::ParserRuleContext {
  public:
    TypeParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    TypeBoundContext *typeBound();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeParameterContext* typeParameter();

  class  TypeBoundContext : public antlr4::ParserRuleContext {
  public:
    TypeBoundContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeTypeContext *> typeType();
    TypeTypeContext* typeType(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeBoundContext* typeBound();

  class  EnumDeclarationContext : public antlr4::ParserRuleContext {
  public:
    EnumDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUM();
    antlr4::tree::TerminalNode *Identifier();
    TypeListContext *typeList();
    EnumConstantsContext *enumConstants();
    EnumBodyDeclarationsContext *enumBodyDeclarations();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumDeclarationContext* enumDeclaration();

  class  EnumConstantsContext : public antlr4::ParserRuleContext {
  public:
    EnumConstantsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EnumConstantContext *> enumConstant();
    EnumConstantContext* enumConstant(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumConstantsContext* enumConstants();

  class  EnumConstantContext : public antlr4::ParserRuleContext {
  public:
    EnumConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    ArgumentsContext *arguments();
    ClassBodyContext *classBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumConstantContext* enumConstant();

  class  EnumBodyDeclarationsContext : public antlr4::ParserRuleContext {
  public:
    EnumBodyDeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ClassBodyDeclarationContext *> classBodyDeclaration();
    ClassBodyDeclarationContext* classBodyDeclaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumBodyDeclarationsContext* enumBodyDeclarations();

  class  InterfaceDeclarationContext : public antlr4::ParserRuleContext {
  public:
    InterfaceDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    InterfaceBodyContext *interfaceBody();
    TypeParametersContext *typeParameters();
    TypeListContext *typeList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceDeclarationContext* interfaceDeclaration();

  class  TypeListContext : public antlr4::ParserRuleContext {
  public:
    TypeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeTypeContext *> typeType();
    TypeTypeContext* typeType(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeListContext* typeList();

  class  ClassBodyContext : public antlr4::ParserRuleContext {
  public:
    ClassBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ClassBodyDeclarationContext *> classBodyDeclaration();
    ClassBodyDeclarationContext* classBodyDeclaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassBodyContext* classBody();

  class  InterfaceBodyContext : public antlr4::ParserRuleContext {
  public:
    InterfaceBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InterfaceBodyDeclarationContext *> interfaceBodyDeclaration();
    InterfaceBodyDeclarationContext* interfaceBodyDeclaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceBodyContext* interfaceBody();

  class  ClassBodyDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ClassBodyDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    MemberDeclarationContext *memberDeclaration();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassBodyDeclarationContext* classBodyDeclaration();

  class  MemberDeclarationContext : public antlr4::ParserRuleContext {
  public:
    MemberDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MethodDeclarationContext *methodDeclaration();
    GenericMethodDeclarationContext *genericMethodDeclaration();
    FieldDeclarationContext *fieldDeclaration();
    ConstructorDeclarationContext *constructorDeclaration();
    GenericConstructorDeclarationContext *genericConstructorDeclaration();
    InterfaceDeclarationContext *interfaceDeclaration();
    AnnotationTypeDeclarationContext *annotationTypeDeclaration();
    ClassDeclarationContext *classDeclaration();
    EnumDeclarationContext *enumDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MemberDeclarationContext* memberDeclaration();

  class  MethodDeclarationContext : public antlr4::ParserRuleContext {
  public:
    MethodDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    FormalParametersContext *formalParameters();
    TypeTypeContext *typeType();
    MethodBodyContext *methodBody();
    QualifiedNameListContext *qualifiedNameList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodDeclarationContext* methodDeclaration();

  class  GenericMethodDeclarationContext : public antlr4::ParserRuleContext {
  public:
    GenericMethodDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeParametersContext *typeParameters();
    MethodDeclarationContext *methodDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenericMethodDeclarationContext* genericMethodDeclaration();

  class  ConstructorDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ConstructorDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    FormalParametersContext *formalParameters();
    ConstructorBodyContext *constructorBody();
    QualifiedNameListContext *qualifiedNameList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstructorDeclarationContext* constructorDeclaration();

  class  GenericConstructorDeclarationContext : public antlr4::ParserRuleContext {
  public:
    GenericConstructorDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeParametersContext *typeParameters();
    ConstructorDeclarationContext *constructorDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenericConstructorDeclarationContext* genericConstructorDeclaration();

  class  FieldDeclarationContext : public antlr4::ParserRuleContext {
  public:
    FieldDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    VariableDeclaratorsContext *variableDeclarators();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldDeclarationContext* fieldDeclaration();

  class  InterfaceBodyDeclarationContext : public antlr4::ParserRuleContext {
  public:
    InterfaceBodyDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InterfaceMemberDeclarationContext *interfaceMemberDeclaration();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceBodyDeclarationContext* interfaceBodyDeclaration();

  class  InterfaceMemberDeclarationContext : public antlr4::ParserRuleContext {
  public:
    InterfaceMemberDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclarationContext *constDeclaration();
    InterfaceMethodDeclarationContext *interfaceMethodDeclaration();
    GenericInterfaceMethodDeclarationContext *genericInterfaceMethodDeclaration();
    InterfaceDeclarationContext *interfaceDeclaration();
    AnnotationTypeDeclarationContext *annotationTypeDeclaration();
    ClassDeclarationContext *classDeclaration();
    EnumDeclarationContext *enumDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceMemberDeclarationContext* interfaceMemberDeclaration();

  class  ConstDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    std::vector<ConstantDeclaratorContext *> constantDeclarator();
    ConstantDeclaratorContext* constantDeclarator(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDeclarationContext* constDeclaration();

  class  ConstantDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    ConstantDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    VariableInitializerContext *variableInitializer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantDeclaratorContext* constantDeclarator();

  class  InterfaceMethodDeclarationContext : public antlr4::ParserRuleContext {
  public:
    InterfaceMethodDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    FormalParametersContext *formalParameters();
    TypeTypeContext *typeType();
    QualifiedNameListContext *qualifiedNameList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceMethodDeclarationContext* interfaceMethodDeclaration();

  class  GenericInterfaceMethodDeclarationContext : public antlr4::ParserRuleContext {
  public:
    GenericInterfaceMethodDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeParametersContext *typeParameters();
    InterfaceMethodDeclarationContext *interfaceMethodDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenericInterfaceMethodDeclarationContext* genericInterfaceMethodDeclaration();

  class  VariableDeclaratorsContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclaratorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableDeclaratorContext *> variableDeclarator();
    VariableDeclaratorContext* variableDeclarator(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclaratorsContext* variableDeclarators();

  class  VariableDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclaratorIdContext *variableDeclaratorId();
    VariableInitializerContext *variableInitializer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclaratorContext* variableDeclarator();

  class  VariableDeclaratorIdContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclaratorIdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclaratorIdContext* variableDeclaratorId();

  class  VariableInitializerContext : public antlr4::ParserRuleContext {
  public:
    VariableInitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayInitializerContext *arrayInitializer();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableInitializerContext* variableInitializer();

  class  ArrayInitializerContext : public antlr4::ParserRuleContext {
  public:
    ArrayInitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableInitializerContext *> variableInitializer();
    VariableInitializerContext* variableInitializer(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayInitializerContext* arrayInitializer();

  class  EnumConstantNameContext : public antlr4::ParserRuleContext {
  public:
    EnumConstantNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumConstantNameContext* enumConstantName();

  class  TypeTypeContext : public antlr4::ParserRuleContext {
  public:
    TypeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassOrInterfaceTypeContext *classOrInterfaceType();
    PrimitiveTypeContext *primitiveType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeTypeContext* typeType();

  class  ClassOrInterfaceTypeContext : public antlr4::ParserRuleContext {
  public:
    ClassOrInterfaceTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<TypeArgumentsContext *> typeArguments();
    TypeArgumentsContext* typeArguments(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassOrInterfaceTypeContext* classOrInterfaceType();

  class  PrimitiveTypeContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveTypeContext* primitiveType();

  class  TypeArgumentsContext : public antlr4::ParserRuleContext {
  public:
    TypeArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeArgumentContext *> typeArgument();
    TypeArgumentContext* typeArgument(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeArgumentsContext* typeArguments();

  class  TypeArgumentContext : public antlr4::ParserRuleContext {
  public:
    TypeArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeArgumentContext* typeArgument();

  class  QualifiedNameListContext : public antlr4::ParserRuleContext {
  public:
    QualifiedNameListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QualifiedNameContext *> qualifiedName();
    QualifiedNameContext* qualifiedName(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QualifiedNameListContext* qualifiedNameList();

  class  FormalParametersContext : public antlr4::ParserRuleContext {
  public:
    FormalParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FormalParameterListContext *formalParameterList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParametersContext* formalParameters();

  class  FormalParameterListContext : public antlr4::ParserRuleContext {
  public:
    FormalParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FormalParameterContext *> formalParameter();
    FormalParameterContext* formalParameter(size_t i);
    LastFormalParameterContext *lastFormalParameter();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParameterListContext* formalParameterList();

  class  FormalParameterContext : public antlr4::ParserRuleContext {
  public:
    FormalParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    VariableDeclaratorIdContext *variableDeclaratorId();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParameterContext* formalParameter();

  class  LastFormalParameterContext : public antlr4::ParserRuleContext {
  public:
    LastFormalParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    VariableDeclaratorIdContext *variableDeclaratorId();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LastFormalParameterContext* lastFormalParameter();

  class  MethodBodyContext : public antlr4::ParserRuleContext {
  public:
    MethodBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodBodyContext* methodBody();

  class  ConstructorBodyContext : public antlr4::ParserRuleContext {
  public:
    ConstructorBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstructorBodyContext* constructorBody();

  class  QualifiedNameContext : public antlr4::ParserRuleContext {
  public:
    QualifiedNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QualifiedNameContext* qualifiedName();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntegerLiteral();
    antlr4::tree::TerminalNode *FloatingPointLiteral();
    antlr4::tree::TerminalNode *CharacterLiteral();
    antlr4::tree::TerminalNode *StringLiteral();
    antlr4::tree::TerminalNode *BooleanLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  AnnotationContext : public antlr4::ParserRuleContext {
  public:
    AnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationNameContext *annotationName();
    ElementValuePairsContext *elementValuePairs();
    ElementValueContext *elementValue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationContext* annotation();

  class  AnnotationNameContext : public antlr4::ParserRuleContext {
  public:
    AnnotationNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QualifiedNameContext *qualifiedName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationNameContext* annotationName();

  class  ElementValuePairsContext : public antlr4::ParserRuleContext {
  public:
    ElementValuePairsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ElementValuePairContext *> elementValuePair();
    ElementValuePairContext* elementValuePair(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementValuePairsContext* elementValuePairs();

  class  ElementValuePairContext : public antlr4::ParserRuleContext {
  public:
    ElementValuePairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    ElementValueContext *elementValue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementValuePairContext* elementValuePair();

  class  ElementValueContext : public antlr4::ParserRuleContext {
  public:
    ElementValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    AnnotationContext *annotation();
    ElementValueArrayInitializerContext *elementValueArrayInitializer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementValueContext* elementValue();

  class  ElementValueArrayInitializerContext : public antlr4::ParserRuleContext {
  public:
    ElementValueArrayInitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ElementValueContext *> elementValue();
    ElementValueContext* elementValue(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementValueArrayInitializerContext* elementValueArrayInitializer();

  class  AnnotationTypeDeclarationContext : public antlr4::ParserRuleContext {
  public:
    AnnotationTypeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    AnnotationTypeBodyContext *annotationTypeBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationTypeDeclarationContext* annotationTypeDeclaration();

  class  AnnotationTypeBodyContext : public antlr4::ParserRuleContext {
  public:
    AnnotationTypeBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AnnotationTypeElementDeclarationContext *> annotationTypeElementDeclaration();
    AnnotationTypeElementDeclarationContext* annotationTypeElementDeclaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationTypeBodyContext* annotationTypeBody();

  class  AnnotationTypeElementDeclarationContext : public antlr4::ParserRuleContext {
  public:
    AnnotationTypeElementDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationTypeElementRestContext *annotationTypeElementRest();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationTypeElementDeclarationContext* annotationTypeElementDeclaration();

  class  AnnotationTypeElementRestContext : public antlr4::ParserRuleContext {
  public:
    AnnotationTypeElementRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    AnnotationMethodOrConstantRestContext *annotationMethodOrConstantRest();
    ClassDeclarationContext *classDeclaration();
    InterfaceDeclarationContext *interfaceDeclaration();
    EnumDeclarationContext *enumDeclaration();
    AnnotationTypeDeclarationContext *annotationTypeDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationTypeElementRestContext* annotationTypeElementRest();

  class  AnnotationMethodOrConstantRestContext : public antlr4::ParserRuleContext {
  public:
    AnnotationMethodOrConstantRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationMethodRestContext *annotationMethodRest();
    AnnotationConstantRestContext *annotationConstantRest();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationMethodOrConstantRestContext* annotationMethodOrConstantRest();

  class  AnnotationMethodRestContext : public antlr4::ParserRuleContext {
  public:
    AnnotationMethodRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    DefaultValueContext *defaultValue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationMethodRestContext* annotationMethodRest();

  class  AnnotationConstantRestContext : public antlr4::ParserRuleContext {
  public:
    AnnotationConstantRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclaratorsContext *variableDeclarators();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationConstantRestContext* annotationConstantRest();

  class  DefaultValueContext : public antlr4::ParserRuleContext {
  public:
    DefaultValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ElementValueContext *elementValue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefaultValueContext* defaultValue();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockStatementContext *> blockStatement();
    BlockStatementContext* blockStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  BlockStatementContext : public antlr4::ParserRuleContext {
  public:
    BlockStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LocalVariableDeclarationStatementContext *localVariableDeclarationStatement();
    StatementContext *statement();
    TypeDeclarationContext *typeDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockStatementContext* blockStatement();

  class  LocalVariableDeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    LocalVariableDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LocalVariableDeclarationContext *localVariableDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocalVariableDeclarationStatementContext* localVariableDeclarationStatement();

  class  LocalVariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    LocalVariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    VariableDeclaratorsContext *variableDeclarators();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocalVariableDeclarationContext* localVariableDeclaration();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *ASSERT();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    ParExpressionContext *parExpression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    ForControlContext *forControl();
    FinallyBlockContext *finallyBlock();
    std::vector<CatchClauseContext *> catchClause();
    CatchClauseContext* catchClause(size_t i);
    ResourceSpecificationContext *resourceSpecification();
    std::vector<SwitchBlockStatementGroupContext *> switchBlockStatementGroup();
    SwitchBlockStatementGroupContext* switchBlockStatementGroup(size_t i);
    std::vector<SwitchLabelContext *> switchLabel();
    SwitchLabelContext* switchLabel(size_t i);
    antlr4::tree::TerminalNode *Identifier();
    StatementExpressionContext *statementExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  CatchClauseContext : public antlr4::ParserRuleContext {
  public:
    CatchClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CatchTypeContext *catchType();
    antlr4::tree::TerminalNode *Identifier();
    BlockContext *block();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatchClauseContext* catchClause();

  class  CatchTypeContext : public antlr4::ParserRuleContext {
  public:
    CatchTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QualifiedNameContext *> qualifiedName();
    QualifiedNameContext* qualifiedName(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatchTypeContext* catchType();

  class  FinallyBlockContext : public antlr4::ParserRuleContext {
  public:
    FinallyBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FinallyBlockContext* finallyBlock();

  class  ResourceSpecificationContext : public antlr4::ParserRuleContext {
  public:
    ResourceSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ResourcesContext *resources();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResourceSpecificationContext* resourceSpecification();

  class  ResourcesContext : public antlr4::ParserRuleContext {
  public:
    ResourcesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ResourceContext *> resource();
    ResourceContext* resource(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResourcesContext* resources();

  class  ResourceContext : public antlr4::ParserRuleContext {
  public:
    ResourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassOrInterfaceTypeContext *classOrInterfaceType();
    VariableDeclaratorIdContext *variableDeclaratorId();
    ExpressionContext *expression();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResourceContext* resource();

  class  SwitchBlockStatementGroupContext : public antlr4::ParserRuleContext {
  public:
    SwitchBlockStatementGroupContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SwitchLabelContext *> switchLabel();
    SwitchLabelContext* switchLabel(size_t i);
    std::vector<BlockStatementContext *> blockStatement();
    BlockStatementContext* blockStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchBlockStatementGroupContext* switchBlockStatementGroup();

  class  SwitchLabelContext : public antlr4::ParserRuleContext {
  public:
    SwitchLabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantExpressionContext *constantExpression();
    EnumConstantNameContext *enumConstantName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchLabelContext* switchLabel();

  class  ForControlContext : public antlr4::ParserRuleContext {
  public:
    ForControlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EnhancedForControlContext *enhancedForControl();
    ForInitContext *forInit();
    ExpressionContext *expression();
    ForUpdateContext *forUpdate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForControlContext* forControl();

  class  ForInitContext : public antlr4::ParserRuleContext {
  public:
    ForInitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LocalVariableDeclarationContext *localVariableDeclaration();
    ExpressionListContext *expressionList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForInitContext* forInit();

  class  EnhancedForControlContext : public antlr4::ParserRuleContext {
  public:
    EnhancedForControlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    VariableDeclaratorIdContext *variableDeclaratorId();
    ExpressionContext *expression();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnhancedForControlContext* enhancedForControl();

  class  ForUpdateContext : public antlr4::ParserRuleContext {
  public:
    ForUpdateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionListContext *expressionList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForUpdateContext* forUpdate();

  class  ParExpressionContext : public antlr4::ParserRuleContext {
  public:
    ParExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParExpressionContext* parExpression();

  class  ExpressionListContext : public antlr4::ParserRuleContext {
  public:
    ExpressionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionListContext* expressionList();

  class  StatementExpressionContext : public antlr4::ParserRuleContext {
  public:
    StatementExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementExpressionContext* statementExpression();

  class  ConstantExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConstantExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantExpressionContext* constantExpression();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    CreatorContext *creator();
    TypeTypeContext *typeType();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Identifier();
    InnerCreatorContext *innerCreator();
    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();
    SuperSuffixContext *superSuffix();
    ExplicitGenericInvocationContext *explicitGenericInvocation();
    ExpressionListContext *expressionList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    LiteralContext *literal();
    antlr4::tree::TerminalNode *Identifier();
    TypeTypeContext *typeType();
    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();
    ExplicitGenericInvocationSuffixContext *explicitGenericInvocationSuffix();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();

  class  CreatorContext : public antlr4::ParserRuleContext {
  public:
    CreatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();
    CreatedNameContext *createdName();
    ClassCreatorRestContext *classCreatorRest();
    ArrayCreatorRestContext *arrayCreatorRest();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CreatorContext* creator();

  class  CreatedNameContext : public antlr4::ParserRuleContext {
  public:
    CreatedNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<TypeArgumentsOrDiamondContext *> typeArgumentsOrDiamond();
    TypeArgumentsOrDiamondContext* typeArgumentsOrDiamond(size_t i);
    PrimitiveTypeContext *primitiveType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CreatedNameContext* createdName();

  class  InnerCreatorContext : public antlr4::ParserRuleContext {
  public:
    InnerCreatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    ClassCreatorRestContext *classCreatorRest();
    NonWildcardTypeArgumentsOrDiamondContext *nonWildcardTypeArgumentsOrDiamond();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InnerCreatorContext* innerCreator();

  class  ArrayCreatorRestContext : public antlr4::ParserRuleContext {
  public:
    ArrayCreatorRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayInitializerContext *arrayInitializer();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayCreatorRestContext* arrayCreatorRest();

  class  ClassCreatorRestContext : public antlr4::ParserRuleContext {
  public:
    ClassCreatorRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();
    ClassBodyContext *classBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassCreatorRestContext* classCreatorRest();

  class  ExplicitGenericInvocationContext : public antlr4::ParserRuleContext {
  public:
    ExplicitGenericInvocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();
    ExplicitGenericInvocationSuffixContext *explicitGenericInvocationSuffix();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExplicitGenericInvocationContext* explicitGenericInvocation();

  class  NonWildcardTypeArgumentsContext : public antlr4::ParserRuleContext {
  public:
    NonWildcardTypeArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeListContext *typeList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonWildcardTypeArgumentsContext* nonWildcardTypeArguments();

  class  TypeArgumentsOrDiamondContext : public antlr4::ParserRuleContext {
  public:
    TypeArgumentsOrDiamondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeArgumentsContext *typeArguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeArgumentsOrDiamondContext* typeArgumentsOrDiamond();

  class  NonWildcardTypeArgumentsOrDiamondContext : public antlr4::ParserRuleContext {
  public:
    NonWildcardTypeArgumentsOrDiamondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonWildcardTypeArgumentsOrDiamondContext* nonWildcardTypeArgumentsOrDiamond();

  class  SuperSuffixContext : public antlr4::ParserRuleContext {
  public:
    SuperSuffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SuperSuffixContext* superSuffix();

  class  ExplicitGenericInvocationSuffixContext : public antlr4::ParserRuleContext {
  public:
    ExplicitGenericInvocationSuffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SuperSuffixContext *superSuffix();
    antlr4::tree::TerminalNode *Identifier();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExplicitGenericInvocationSuffixContext* explicitGenericInvocationSuffix();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionListContext *expressionList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

