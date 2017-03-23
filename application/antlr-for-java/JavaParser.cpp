
// Generated from Java.g4 by ANTLR 4.6


#include "JavaListener.h"
#include "JavaVisitor.h"

#include "JavaParser.h"


using namespace antlrcpp;
using namespace antlr4;

JavaParser::JavaParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

JavaParser::~JavaParser() {
  delete _interpreter;
}

std::string JavaParser::getGrammarFileName() const {
  return "Java.g4";
}

const std::vector<std::string>& JavaParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& JavaParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

JavaParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::CompilationUnitContext::EOF() {
  return getToken(JavaParser::EOF, 0);
}

JavaParser::PackageDeclarationContext* JavaParser::CompilationUnitContext::packageDeclaration() {
  return getRuleContext<JavaParser::PackageDeclarationContext>(0);
}

std::vector<JavaParser::ImportDeclarationContext *> JavaParser::CompilationUnitContext::importDeclaration() {
  return getRuleContexts<JavaParser::ImportDeclarationContext>();
}

JavaParser::ImportDeclarationContext* JavaParser::CompilationUnitContext::importDeclaration(size_t i) {
  return getRuleContext<JavaParser::ImportDeclarationContext>(i);
}

std::vector<JavaParser::TypeDeclarationContext *> JavaParser::CompilationUnitContext::typeDeclaration() {
  return getRuleContexts<JavaParser::TypeDeclarationContext>();
}

JavaParser::TypeDeclarationContext* JavaParser::CompilationUnitContext::typeDeclaration(size_t i) {
  return getRuleContext<JavaParser::TypeDeclarationContext>(i);
}


size_t JavaParser::CompilationUnitContext::getRuleIndex() const {
  return JavaParser::RuleCompilationUnit;
}

void JavaParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void JavaParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any JavaParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::CompilationUnitContext* JavaParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, JavaParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(202);
      packageDeclaration();
      break;
    }

    }
    setState(208);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::IMPORT) {
      setState(205);
      importDeclaration();
      setState(210);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(214);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
      | (1ULL << JavaParser::CLASS)
      | (1ULL << JavaParser::ENUM)
      | (1ULL << JavaParser::FINAL)
      | (1ULL << JavaParser::INTERFACE)
      | (1ULL << JavaParser::PRIVATE)
      | (1ULL << JavaParser::PROTECTED)
      | (1ULL << JavaParser::PUBLIC)
      | (1ULL << JavaParser::STATIC)
      | (1ULL << JavaParser::STRICTFP)
      | (1ULL << JavaParser::SEMI))) != 0) || _la == JavaParser::AT) {
      setState(211);
      typeDeclaration();
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(217);
    match(JavaParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PackageDeclarationContext ------------------------------------------------------------------

JavaParser::PackageDeclarationContext::PackageDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::QualifiedNameContext* JavaParser::PackageDeclarationContext::qualifiedName() {
  return getRuleContext<JavaParser::QualifiedNameContext>(0);
}

std::vector<JavaParser::AnnotationContext *> JavaParser::PackageDeclarationContext::annotation() {
  return getRuleContexts<JavaParser::AnnotationContext>();
}

JavaParser::AnnotationContext* JavaParser::PackageDeclarationContext::annotation(size_t i) {
  return getRuleContext<JavaParser::AnnotationContext>(i);
}


size_t JavaParser::PackageDeclarationContext::getRuleIndex() const {
  return JavaParser::RulePackageDeclaration;
}

void JavaParser::PackageDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackageDeclaration(this);
}

void JavaParser::PackageDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackageDeclaration(this);
}


antlrcpp::Any JavaParser::PackageDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitPackageDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::PackageDeclarationContext* JavaParser::packageDeclaration() {
  PackageDeclarationContext *_localctx = _tracker.createInstance<PackageDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, JavaParser::RulePackageDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::AT) {
      setState(219);
      annotation();
      setState(224);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(225);
    match(JavaParser::PACKAGE);
    setState(226);
    qualifiedName();
    setState(227);
    match(JavaParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportDeclarationContext ------------------------------------------------------------------

JavaParser::ImportDeclarationContext::ImportDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::QualifiedNameContext* JavaParser::ImportDeclarationContext::qualifiedName() {
  return getRuleContext<JavaParser::QualifiedNameContext>(0);
}


size_t JavaParser::ImportDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleImportDeclaration;
}

void JavaParser::ImportDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportDeclaration(this);
}

void JavaParser::ImportDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportDeclaration(this);
}


antlrcpp::Any JavaParser::ImportDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitImportDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ImportDeclarationContext* JavaParser::importDeclaration() {
  ImportDeclarationContext *_localctx = _tracker.createInstance<ImportDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, JavaParser::RuleImportDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(JavaParser::IMPORT);
    setState(231);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::STATIC) {
      setState(230);
      match(JavaParser::STATIC);
    }
    setState(233);
    qualifiedName();
    setState(236);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::DOT) {
      setState(234);
      match(JavaParser::DOT);
      setState(235);
      match(JavaParser::MUL);
    }
    setState(238);
    match(JavaParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclarationContext ------------------------------------------------------------------

JavaParser::TypeDeclarationContext::TypeDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ClassDeclarationContext* JavaParser::TypeDeclarationContext::classDeclaration() {
  return getRuleContext<JavaParser::ClassDeclarationContext>(0);
}

std::vector<JavaParser::ClassOrInterfaceModifierContext *> JavaParser::TypeDeclarationContext::classOrInterfaceModifier() {
  return getRuleContexts<JavaParser::ClassOrInterfaceModifierContext>();
}

JavaParser::ClassOrInterfaceModifierContext* JavaParser::TypeDeclarationContext::classOrInterfaceModifier(size_t i) {
  return getRuleContext<JavaParser::ClassOrInterfaceModifierContext>(i);
}

JavaParser::EnumDeclarationContext* JavaParser::TypeDeclarationContext::enumDeclaration() {
  return getRuleContext<JavaParser::EnumDeclarationContext>(0);
}

JavaParser::InterfaceDeclarationContext* JavaParser::TypeDeclarationContext::interfaceDeclaration() {
  return getRuleContext<JavaParser::InterfaceDeclarationContext>(0);
}

JavaParser::AnnotationTypeDeclarationContext* JavaParser::TypeDeclarationContext::annotationTypeDeclaration() {
  return getRuleContext<JavaParser::AnnotationTypeDeclarationContext>(0);
}


size_t JavaParser::TypeDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleTypeDeclaration;
}

void JavaParser::TypeDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDeclaration(this);
}

void JavaParser::TypeDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDeclaration(this);
}


antlrcpp::Any JavaParser::TypeDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitTypeDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::TypeDeclarationContext* JavaParser::typeDeclaration() {
  TypeDeclarationContext *_localctx = _tracker.createInstance<TypeDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, JavaParser::RuleTypeDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(269);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(243);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
        | (1ULL << JavaParser::FINAL)
        | (1ULL << JavaParser::PRIVATE)
        | (1ULL << JavaParser::PROTECTED)
        | (1ULL << JavaParser::PUBLIC)
        | (1ULL << JavaParser::STATIC)
        | (1ULL << JavaParser::STRICTFP))) != 0) || _la == JavaParser::AT) {
        setState(240);
        classOrInterfaceModifier();
        setState(245);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(246);
      classDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(250);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
        | (1ULL << JavaParser::FINAL)
        | (1ULL << JavaParser::PRIVATE)
        | (1ULL << JavaParser::PROTECTED)
        | (1ULL << JavaParser::PUBLIC)
        | (1ULL << JavaParser::STATIC)
        | (1ULL << JavaParser::STRICTFP))) != 0) || _la == JavaParser::AT) {
        setState(247);
        classOrInterfaceModifier();
        setState(252);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(253);
      enumDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
        | (1ULL << JavaParser::FINAL)
        | (1ULL << JavaParser::PRIVATE)
        | (1ULL << JavaParser::PROTECTED)
        | (1ULL << JavaParser::PUBLIC)
        | (1ULL << JavaParser::STATIC)
        | (1ULL << JavaParser::STRICTFP))) != 0) || _la == JavaParser::AT) {
        setState(254);
        classOrInterfaceModifier();
        setState(259);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(260);
      interfaceDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(264);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(261);
          classOrInterfaceModifier(); 
        }
        setState(266);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(267);
      annotationTypeDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(268);
      match(JavaParser::SEMI);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierContext ------------------------------------------------------------------

JavaParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ClassOrInterfaceModifierContext* JavaParser::ModifierContext::classOrInterfaceModifier() {
  return getRuleContext<JavaParser::ClassOrInterfaceModifierContext>(0);
}


size_t JavaParser::ModifierContext::getRuleIndex() const {
  return JavaParser::RuleModifier;
}

void JavaParser::ModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModifier(this);
}

void JavaParser::ModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModifier(this);
}


antlrcpp::Any JavaParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ModifierContext* JavaParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 8, JavaParser::RuleModifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(273);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::ABSTRACT:
      case JavaParser::FINAL:
      case JavaParser::PRIVATE:
      case JavaParser::PROTECTED:
      case JavaParser::PUBLIC:
      case JavaParser::STATIC:
      case JavaParser::STRICTFP:
      case JavaParser::AT: {
        enterOuterAlt(_localctx, 1);
        setState(271);
        classOrInterfaceModifier();
        break;
      }

      case JavaParser::NATIVE:
      case JavaParser::SYNCHRONIZED:
      case JavaParser::TRANSIENT:
      case JavaParser::VOLATILE: {
        enterOuterAlt(_localctx, 2);
        setState(272);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << JavaParser::NATIVE)
          | (1ULL << JavaParser::SYNCHRONIZED)
          | (1ULL << JavaParser::TRANSIENT)
          | (1ULL << JavaParser::VOLATILE))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassOrInterfaceModifierContext ------------------------------------------------------------------

JavaParser::ClassOrInterfaceModifierContext::ClassOrInterfaceModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::AnnotationContext* JavaParser::ClassOrInterfaceModifierContext::annotation() {
  return getRuleContext<JavaParser::AnnotationContext>(0);
}


size_t JavaParser::ClassOrInterfaceModifierContext::getRuleIndex() const {
  return JavaParser::RuleClassOrInterfaceModifier;
}

void JavaParser::ClassOrInterfaceModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassOrInterfaceModifier(this);
}

void JavaParser::ClassOrInterfaceModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassOrInterfaceModifier(this);
}


antlrcpp::Any JavaParser::ClassOrInterfaceModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitClassOrInterfaceModifier(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ClassOrInterfaceModifierContext* JavaParser::classOrInterfaceModifier() {
  ClassOrInterfaceModifierContext *_localctx = _tracker.createInstance<ClassOrInterfaceModifierContext>(_ctx, getState());
  enterRule(_localctx, 10, JavaParser::RuleClassOrInterfaceModifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::AT: {
        enterOuterAlt(_localctx, 1);
        setState(275);
        annotation();
        break;
      }

      case JavaParser::ABSTRACT:
      case JavaParser::FINAL:
      case JavaParser::PRIVATE:
      case JavaParser::PROTECTED:
      case JavaParser::PUBLIC:
      case JavaParser::STATIC:
      case JavaParser::STRICTFP: {
        enterOuterAlt(_localctx, 2);
        setState(276);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
          | (1ULL << JavaParser::FINAL)
          | (1ULL << JavaParser::PRIVATE)
          | (1ULL << JavaParser::PROTECTED)
          | (1ULL << JavaParser::PUBLIC)
          | (1ULL << JavaParser::STATIC)
          | (1ULL << JavaParser::STRICTFP))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableModifierContext ------------------------------------------------------------------

JavaParser::VariableModifierContext::VariableModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::AnnotationContext* JavaParser::VariableModifierContext::annotation() {
  return getRuleContext<JavaParser::AnnotationContext>(0);
}


size_t JavaParser::VariableModifierContext::getRuleIndex() const {
  return JavaParser::RuleVariableModifier;
}

void JavaParser::VariableModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableModifier(this);
}

void JavaParser::VariableModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableModifier(this);
}


antlrcpp::Any JavaParser::VariableModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitVariableModifier(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::VariableModifierContext* JavaParser::variableModifier() {
  VariableModifierContext *_localctx = _tracker.createInstance<VariableModifierContext>(_ctx, getState());
  enterRule(_localctx, 12, JavaParser::RuleVariableModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(281);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::FINAL: {
        enterOuterAlt(_localctx, 1);
        setState(279);
        match(JavaParser::FINAL);
        break;
      }

      case JavaParser::AT: {
        enterOuterAlt(_localctx, 2);
        setState(280);
        annotation();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclarationContext ------------------------------------------------------------------

JavaParser::ClassDeclarationContext::ClassDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::ClassDeclarationContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::ClassBodyContext* JavaParser::ClassDeclarationContext::classBody() {
  return getRuleContext<JavaParser::ClassBodyContext>(0);
}

JavaParser::TypeParametersContext* JavaParser::ClassDeclarationContext::typeParameters() {
  return getRuleContext<JavaParser::TypeParametersContext>(0);
}

JavaParser::TypeTypeContext* JavaParser::ClassDeclarationContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::TypeListContext* JavaParser::ClassDeclarationContext::typeList() {
  return getRuleContext<JavaParser::TypeListContext>(0);
}


size_t JavaParser::ClassDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleClassDeclaration;
}

void JavaParser::ClassDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDeclaration(this);
}

void JavaParser::ClassDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDeclaration(this);
}


antlrcpp::Any JavaParser::ClassDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitClassDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ClassDeclarationContext* JavaParser::classDeclaration() {
  ClassDeclarationContext *_localctx = _tracker.createInstance<ClassDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, JavaParser::RuleClassDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(JavaParser::CLASS);
    setState(284);
    match(JavaParser::Identifier);
    setState(286);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::LT) {
      setState(285);
      typeParameters();
    }
    setState(290);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::EXTENDS) {
      setState(288);
      match(JavaParser::EXTENDS);
      setState(289);
      typeType();
    }
    setState(294);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::IMPLEMENTS) {
      setState(292);
      match(JavaParser::IMPLEMENTS);
      setState(293);
      typeList();
    }
    setState(296);
    classBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeParametersContext ------------------------------------------------------------------

JavaParser::TypeParametersContext::TypeParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::TypeParameterContext *> JavaParser::TypeParametersContext::typeParameter() {
  return getRuleContexts<JavaParser::TypeParameterContext>();
}

JavaParser::TypeParameterContext* JavaParser::TypeParametersContext::typeParameter(size_t i) {
  return getRuleContext<JavaParser::TypeParameterContext>(i);
}


size_t JavaParser::TypeParametersContext::getRuleIndex() const {
  return JavaParser::RuleTypeParameters;
}

void JavaParser::TypeParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeParameters(this);
}

void JavaParser::TypeParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeParameters(this);
}


antlrcpp::Any JavaParser::TypeParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitTypeParameters(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::TypeParametersContext* JavaParser::typeParameters() {
  TypeParametersContext *_localctx = _tracker.createInstance<TypeParametersContext>(_ctx, getState());
  enterRule(_localctx, 16, JavaParser::RuleTypeParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(298);
    match(JavaParser::LT);
    setState(299);
    typeParameter();
    setState(304);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::COMMA) {
      setState(300);
      match(JavaParser::COMMA);
      setState(301);
      typeParameter();
      setState(306);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(307);
    match(JavaParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeParameterContext ------------------------------------------------------------------

JavaParser::TypeParameterContext::TypeParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::TypeParameterContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::TypeBoundContext* JavaParser::TypeParameterContext::typeBound() {
  return getRuleContext<JavaParser::TypeBoundContext>(0);
}


size_t JavaParser::TypeParameterContext::getRuleIndex() const {
  return JavaParser::RuleTypeParameter;
}

void JavaParser::TypeParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeParameter(this);
}

void JavaParser::TypeParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeParameter(this);
}


antlrcpp::Any JavaParser::TypeParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitTypeParameter(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::TypeParameterContext* JavaParser::typeParameter() {
  TypeParameterContext *_localctx = _tracker.createInstance<TypeParameterContext>(_ctx, getState());
  enterRule(_localctx, 18, JavaParser::RuleTypeParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    match(JavaParser::Identifier);
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::EXTENDS) {
      setState(310);
      match(JavaParser::EXTENDS);
      setState(311);
      typeBound();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeBoundContext ------------------------------------------------------------------

JavaParser::TypeBoundContext::TypeBoundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::TypeTypeContext *> JavaParser::TypeBoundContext::typeType() {
  return getRuleContexts<JavaParser::TypeTypeContext>();
}

JavaParser::TypeTypeContext* JavaParser::TypeBoundContext::typeType(size_t i) {
  return getRuleContext<JavaParser::TypeTypeContext>(i);
}


size_t JavaParser::TypeBoundContext::getRuleIndex() const {
  return JavaParser::RuleTypeBound;
}

void JavaParser::TypeBoundContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeBound(this);
}

void JavaParser::TypeBoundContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeBound(this);
}


antlrcpp::Any JavaParser::TypeBoundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitTypeBound(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::TypeBoundContext* JavaParser::typeBound() {
  TypeBoundContext *_localctx = _tracker.createInstance<TypeBoundContext>(_ctx, getState());
  enterRule(_localctx, 20, JavaParser::RuleTypeBound);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    typeType();
    setState(319);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::BITAND) {
      setState(315);
      match(JavaParser::BITAND);
      setState(316);
      typeType();
      setState(321);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumDeclarationContext ------------------------------------------------------------------

JavaParser::EnumDeclarationContext::EnumDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::EnumDeclarationContext::ENUM() {
  return getToken(JavaParser::ENUM, 0);
}

tree::TerminalNode* JavaParser::EnumDeclarationContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::TypeListContext* JavaParser::EnumDeclarationContext::typeList() {
  return getRuleContext<JavaParser::TypeListContext>(0);
}

JavaParser::EnumConstantsContext* JavaParser::EnumDeclarationContext::enumConstants() {
  return getRuleContext<JavaParser::EnumConstantsContext>(0);
}

JavaParser::EnumBodyDeclarationsContext* JavaParser::EnumDeclarationContext::enumBodyDeclarations() {
  return getRuleContext<JavaParser::EnumBodyDeclarationsContext>(0);
}


size_t JavaParser::EnumDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleEnumDeclaration;
}

void JavaParser::EnumDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumDeclaration(this);
}

void JavaParser::EnumDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumDeclaration(this);
}


antlrcpp::Any JavaParser::EnumDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitEnumDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::EnumDeclarationContext* JavaParser::enumDeclaration() {
  EnumDeclarationContext *_localctx = _tracker.createInstance<EnumDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 22, JavaParser::RuleEnumDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    match(JavaParser::ENUM);
    setState(323);
    match(JavaParser::Identifier);
    setState(326);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::IMPLEMENTS) {
      setState(324);
      match(JavaParser::IMPLEMENTS);
      setState(325);
      typeList();
    }
    setState(328);
    match(JavaParser::LBRACE);
    setState(330);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::Identifier

    || _la == JavaParser::AT) {
      setState(329);
      enumConstants();
    }
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::COMMA) {
      setState(332);
      match(JavaParser::COMMA);
    }
    setState(336);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::SEMI) {
      setState(335);
      enumBodyDeclarations();
    }
    setState(338);
    match(JavaParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumConstantsContext ------------------------------------------------------------------

JavaParser::EnumConstantsContext::EnumConstantsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::EnumConstantContext *> JavaParser::EnumConstantsContext::enumConstant() {
  return getRuleContexts<JavaParser::EnumConstantContext>();
}

JavaParser::EnumConstantContext* JavaParser::EnumConstantsContext::enumConstant(size_t i) {
  return getRuleContext<JavaParser::EnumConstantContext>(i);
}


size_t JavaParser::EnumConstantsContext::getRuleIndex() const {
  return JavaParser::RuleEnumConstants;
}

void JavaParser::EnumConstantsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumConstants(this);
}

void JavaParser::EnumConstantsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumConstants(this);
}


antlrcpp::Any JavaParser::EnumConstantsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitEnumConstants(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::EnumConstantsContext* JavaParser::enumConstants() {
  EnumConstantsContext *_localctx = _tracker.createInstance<EnumConstantsContext>(_ctx, getState());
  enterRule(_localctx, 24, JavaParser::RuleEnumConstants);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(340);
    enumConstant();
    setState(345);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(341);
        match(JavaParser::COMMA);
        setState(342);
        enumConstant(); 
      }
      setState(347);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumConstantContext ------------------------------------------------------------------

JavaParser::EnumConstantContext::EnumConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::EnumConstantContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

std::vector<JavaParser::AnnotationContext *> JavaParser::EnumConstantContext::annotation() {
  return getRuleContexts<JavaParser::AnnotationContext>();
}

JavaParser::AnnotationContext* JavaParser::EnumConstantContext::annotation(size_t i) {
  return getRuleContext<JavaParser::AnnotationContext>(i);
}

JavaParser::ArgumentsContext* JavaParser::EnumConstantContext::arguments() {
  return getRuleContext<JavaParser::ArgumentsContext>(0);
}

JavaParser::ClassBodyContext* JavaParser::EnumConstantContext::classBody() {
  return getRuleContext<JavaParser::ClassBodyContext>(0);
}


size_t JavaParser::EnumConstantContext::getRuleIndex() const {
  return JavaParser::RuleEnumConstant;
}

void JavaParser::EnumConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumConstant(this);
}

void JavaParser::EnumConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumConstant(this);
}


antlrcpp::Any JavaParser::EnumConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitEnumConstant(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::EnumConstantContext* JavaParser::enumConstant() {
  EnumConstantContext *_localctx = _tracker.createInstance<EnumConstantContext>(_ctx, getState());
  enterRule(_localctx, 26, JavaParser::RuleEnumConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::AT) {
      setState(348);
      annotation();
      setState(353);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(354);
    match(JavaParser::Identifier);
    setState(356);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::LPAREN) {
      setState(355);
      arguments();
    }
    setState(359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::LBRACE) {
      setState(358);
      classBody();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumBodyDeclarationsContext ------------------------------------------------------------------

JavaParser::EnumBodyDeclarationsContext::EnumBodyDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::ClassBodyDeclarationContext *> JavaParser::EnumBodyDeclarationsContext::classBodyDeclaration() {
  return getRuleContexts<JavaParser::ClassBodyDeclarationContext>();
}

JavaParser::ClassBodyDeclarationContext* JavaParser::EnumBodyDeclarationsContext::classBodyDeclaration(size_t i) {
  return getRuleContext<JavaParser::ClassBodyDeclarationContext>(i);
}


size_t JavaParser::EnumBodyDeclarationsContext::getRuleIndex() const {
  return JavaParser::RuleEnumBodyDeclarations;
}

void JavaParser::EnumBodyDeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumBodyDeclarations(this);
}

void JavaParser::EnumBodyDeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumBodyDeclarations(this);
}


antlrcpp::Any JavaParser::EnumBodyDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitEnumBodyDeclarations(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::EnumBodyDeclarationsContext* JavaParser::enumBodyDeclarations() {
  EnumBodyDeclarationsContext *_localctx = _tracker.createInstance<EnumBodyDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 28, JavaParser::RuleEnumBodyDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    match(JavaParser::SEMI);
    setState(365);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
      | (1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::CLASS)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::ENUM)
      | (1ULL << JavaParser::FINAL)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::INTERFACE)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::NATIVE)
      | (1ULL << JavaParser::PRIVATE)
      | (1ULL << JavaParser::PROTECTED)
      | (1ULL << JavaParser::PUBLIC)
      | (1ULL << JavaParser::SHORT)
      | (1ULL << JavaParser::STATIC)
      | (1ULL << JavaParser::STRICTFP)
      | (1ULL << JavaParser::SYNCHRONIZED)
      | (1ULL << JavaParser::TRANSIENT)
      | (1ULL << JavaParser::VOID)
      | (1ULL << JavaParser::VOLATILE)
      | (1ULL << JavaParser::LBRACE)
      | (1ULL << JavaParser::SEMI))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
      | (1ULL << (JavaParser::Identifier - 68))
      | (1ULL << (JavaParser::AT - 68)))) != 0)) {
      setState(362);
      classBodyDeclaration();
      setState(367);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceDeclarationContext ------------------------------------------------------------------

JavaParser::InterfaceDeclarationContext::InterfaceDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::InterfaceDeclarationContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::InterfaceBodyContext* JavaParser::InterfaceDeclarationContext::interfaceBody() {
  return getRuleContext<JavaParser::InterfaceBodyContext>(0);
}

JavaParser::TypeParametersContext* JavaParser::InterfaceDeclarationContext::typeParameters() {
  return getRuleContext<JavaParser::TypeParametersContext>(0);
}

JavaParser::TypeListContext* JavaParser::InterfaceDeclarationContext::typeList() {
  return getRuleContext<JavaParser::TypeListContext>(0);
}


size_t JavaParser::InterfaceDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleInterfaceDeclaration;
}

void JavaParser::InterfaceDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceDeclaration(this);
}

void JavaParser::InterfaceDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceDeclaration(this);
}


antlrcpp::Any JavaParser::InterfaceDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitInterfaceDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::InterfaceDeclarationContext* JavaParser::interfaceDeclaration() {
  InterfaceDeclarationContext *_localctx = _tracker.createInstance<InterfaceDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 30, JavaParser::RuleInterfaceDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    match(JavaParser::INTERFACE);
    setState(369);
    match(JavaParser::Identifier);
    setState(371);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::LT) {
      setState(370);
      typeParameters();
    }
    setState(375);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::EXTENDS) {
      setState(373);
      match(JavaParser::EXTENDS);
      setState(374);
      typeList();
    }
    setState(377);
    interfaceBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListContext ------------------------------------------------------------------

JavaParser::TypeListContext::TypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::TypeTypeContext *> JavaParser::TypeListContext::typeType() {
  return getRuleContexts<JavaParser::TypeTypeContext>();
}

JavaParser::TypeTypeContext* JavaParser::TypeListContext::typeType(size_t i) {
  return getRuleContext<JavaParser::TypeTypeContext>(i);
}


size_t JavaParser::TypeListContext::getRuleIndex() const {
  return JavaParser::RuleTypeList;
}

void JavaParser::TypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeList(this);
}

void JavaParser::TypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeList(this);
}


antlrcpp::Any JavaParser::TypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitTypeList(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::TypeListContext* JavaParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 32, JavaParser::RuleTypeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    typeType();
    setState(384);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::COMMA) {
      setState(380);
      match(JavaParser::COMMA);
      setState(381);
      typeType();
      setState(386);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassBodyContext ------------------------------------------------------------------

JavaParser::ClassBodyContext::ClassBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::ClassBodyDeclarationContext *> JavaParser::ClassBodyContext::classBodyDeclaration() {
  return getRuleContexts<JavaParser::ClassBodyDeclarationContext>();
}

JavaParser::ClassBodyDeclarationContext* JavaParser::ClassBodyContext::classBodyDeclaration(size_t i) {
  return getRuleContext<JavaParser::ClassBodyDeclarationContext>(i);
}


size_t JavaParser::ClassBodyContext::getRuleIndex() const {
  return JavaParser::RuleClassBody;
}

void JavaParser::ClassBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassBody(this);
}

void JavaParser::ClassBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassBody(this);
}


antlrcpp::Any JavaParser::ClassBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitClassBody(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ClassBodyContext* JavaParser::classBody() {
  ClassBodyContext *_localctx = _tracker.createInstance<ClassBodyContext>(_ctx, getState());
  enterRule(_localctx, 34, JavaParser::RuleClassBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    match(JavaParser::LBRACE);
    setState(391);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
      | (1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::CLASS)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::ENUM)
      | (1ULL << JavaParser::FINAL)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::INTERFACE)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::NATIVE)
      | (1ULL << JavaParser::PRIVATE)
      | (1ULL << JavaParser::PROTECTED)
      | (1ULL << JavaParser::PUBLIC)
      | (1ULL << JavaParser::SHORT)
      | (1ULL << JavaParser::STATIC)
      | (1ULL << JavaParser::STRICTFP)
      | (1ULL << JavaParser::SYNCHRONIZED)
      | (1ULL << JavaParser::TRANSIENT)
      | (1ULL << JavaParser::VOID)
      | (1ULL << JavaParser::VOLATILE)
      | (1ULL << JavaParser::LBRACE)
      | (1ULL << JavaParser::SEMI))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
      | (1ULL << (JavaParser::Identifier - 68))
      | (1ULL << (JavaParser::AT - 68)))) != 0)) {
      setState(388);
      classBodyDeclaration();
      setState(393);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(394);
    match(JavaParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceBodyContext ------------------------------------------------------------------

JavaParser::InterfaceBodyContext::InterfaceBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::InterfaceBodyDeclarationContext *> JavaParser::InterfaceBodyContext::interfaceBodyDeclaration() {
  return getRuleContexts<JavaParser::InterfaceBodyDeclarationContext>();
}

JavaParser::InterfaceBodyDeclarationContext* JavaParser::InterfaceBodyContext::interfaceBodyDeclaration(size_t i) {
  return getRuleContext<JavaParser::InterfaceBodyDeclarationContext>(i);
}


size_t JavaParser::InterfaceBodyContext::getRuleIndex() const {
  return JavaParser::RuleInterfaceBody;
}

void JavaParser::InterfaceBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceBody(this);
}

void JavaParser::InterfaceBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceBody(this);
}


antlrcpp::Any JavaParser::InterfaceBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitInterfaceBody(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::InterfaceBodyContext* JavaParser::interfaceBody() {
  InterfaceBodyContext *_localctx = _tracker.createInstance<InterfaceBodyContext>(_ctx, getState());
  enterRule(_localctx, 36, JavaParser::RuleInterfaceBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    match(JavaParser::LBRACE);
    setState(400);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
      | (1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::CLASS)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::ENUM)
      | (1ULL << JavaParser::FINAL)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::INTERFACE)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::NATIVE)
      | (1ULL << JavaParser::PRIVATE)
      | (1ULL << JavaParser::PROTECTED)
      | (1ULL << JavaParser::PUBLIC)
      | (1ULL << JavaParser::SHORT)
      | (1ULL << JavaParser::STATIC)
      | (1ULL << JavaParser::STRICTFP)
      | (1ULL << JavaParser::SYNCHRONIZED)
      | (1ULL << JavaParser::TRANSIENT)
      | (1ULL << JavaParser::VOID)
      | (1ULL << JavaParser::VOLATILE)
      | (1ULL << JavaParser::SEMI))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
      | (1ULL << (JavaParser::Identifier - 68))
      | (1ULL << (JavaParser::AT - 68)))) != 0)) {
      setState(397);
      interfaceBodyDeclaration();
      setState(402);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(403);
    match(JavaParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassBodyDeclarationContext ------------------------------------------------------------------

JavaParser::ClassBodyDeclarationContext::ClassBodyDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::BlockContext* JavaParser::ClassBodyDeclarationContext::block() {
  return getRuleContext<JavaParser::BlockContext>(0);
}

JavaParser::MemberDeclarationContext* JavaParser::ClassBodyDeclarationContext::memberDeclaration() {
  return getRuleContext<JavaParser::MemberDeclarationContext>(0);
}

std::vector<JavaParser::ModifierContext *> JavaParser::ClassBodyDeclarationContext::modifier() {
  return getRuleContexts<JavaParser::ModifierContext>();
}

JavaParser::ModifierContext* JavaParser::ClassBodyDeclarationContext::modifier(size_t i) {
  return getRuleContext<JavaParser::ModifierContext>(i);
}


size_t JavaParser::ClassBodyDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleClassBodyDeclaration;
}

void JavaParser::ClassBodyDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassBodyDeclaration(this);
}

void JavaParser::ClassBodyDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassBodyDeclaration(this);
}


antlrcpp::Any JavaParser::ClassBodyDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitClassBodyDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ClassBodyDeclarationContext* JavaParser::classBodyDeclaration() {
  ClassBodyDeclarationContext *_localctx = _tracker.createInstance<ClassBodyDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 38, JavaParser::RuleClassBodyDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(417);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(405);
      match(JavaParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(407);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaParser::STATIC) {
        setState(406);
        match(JavaParser::STATIC);
      }
      setState(409);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(413);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(410);
          modifier(); 
        }
        setState(415);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
      }
      setState(416);
      memberDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberDeclarationContext ------------------------------------------------------------------

JavaParser::MemberDeclarationContext::MemberDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::MethodDeclarationContext* JavaParser::MemberDeclarationContext::methodDeclaration() {
  return getRuleContext<JavaParser::MethodDeclarationContext>(0);
}

JavaParser::GenericMethodDeclarationContext* JavaParser::MemberDeclarationContext::genericMethodDeclaration() {
  return getRuleContext<JavaParser::GenericMethodDeclarationContext>(0);
}

JavaParser::FieldDeclarationContext* JavaParser::MemberDeclarationContext::fieldDeclaration() {
  return getRuleContext<JavaParser::FieldDeclarationContext>(0);
}

JavaParser::ConstructorDeclarationContext* JavaParser::MemberDeclarationContext::constructorDeclaration() {
  return getRuleContext<JavaParser::ConstructorDeclarationContext>(0);
}

JavaParser::GenericConstructorDeclarationContext* JavaParser::MemberDeclarationContext::genericConstructorDeclaration() {
  return getRuleContext<JavaParser::GenericConstructorDeclarationContext>(0);
}

JavaParser::InterfaceDeclarationContext* JavaParser::MemberDeclarationContext::interfaceDeclaration() {
  return getRuleContext<JavaParser::InterfaceDeclarationContext>(0);
}

JavaParser::AnnotationTypeDeclarationContext* JavaParser::MemberDeclarationContext::annotationTypeDeclaration() {
  return getRuleContext<JavaParser::AnnotationTypeDeclarationContext>(0);
}

JavaParser::ClassDeclarationContext* JavaParser::MemberDeclarationContext::classDeclaration() {
  return getRuleContext<JavaParser::ClassDeclarationContext>(0);
}

JavaParser::EnumDeclarationContext* JavaParser::MemberDeclarationContext::enumDeclaration() {
  return getRuleContext<JavaParser::EnumDeclarationContext>(0);
}


size_t JavaParser::MemberDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleMemberDeclaration;
}

void JavaParser::MemberDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberDeclaration(this);
}

void JavaParser::MemberDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberDeclaration(this);
}


antlrcpp::Any JavaParser::MemberDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitMemberDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::MemberDeclarationContext* JavaParser::memberDeclaration() {
  MemberDeclarationContext *_localctx = _tracker.createInstance<MemberDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 40, JavaParser::RuleMemberDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(428);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(419);
      methodDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(420);
      genericMethodDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(421);
      fieldDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(422);
      constructorDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(423);
      genericConstructorDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(424);
      interfaceDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(425);
      annotationTypeDeclaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(426);
      classDeclaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(427);
      enumDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclarationContext ------------------------------------------------------------------

JavaParser::MethodDeclarationContext::MethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::MethodDeclarationContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::FormalParametersContext* JavaParser::MethodDeclarationContext::formalParameters() {
  return getRuleContext<JavaParser::FormalParametersContext>(0);
}

JavaParser::TypeTypeContext* JavaParser::MethodDeclarationContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::MethodBodyContext* JavaParser::MethodDeclarationContext::methodBody() {
  return getRuleContext<JavaParser::MethodBodyContext>(0);
}

JavaParser::QualifiedNameListContext* JavaParser::MethodDeclarationContext::qualifiedNameList() {
  return getRuleContext<JavaParser::QualifiedNameListContext>(0);
}


size_t JavaParser::MethodDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleMethodDeclaration;
}

void JavaParser::MethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDeclaration(this);
}

void JavaParser::MethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDeclaration(this);
}


antlrcpp::Any JavaParser::MethodDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitMethodDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::MethodDeclarationContext* JavaParser::methodDeclaration() {
  MethodDeclarationContext *_localctx = _tracker.createInstance<MethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 42, JavaParser::RuleMethodDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::SHORT:
      case JavaParser::Identifier: {
        setState(430);
        typeType();
        break;
      }

      case JavaParser::VOID: {
        setState(431);
        match(JavaParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(434);
    match(JavaParser::Identifier);
    setState(435);
    formalParameters();
    setState(440);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::LBRACK) {
      setState(436);
      match(JavaParser::LBRACK);
      setState(437);
      match(JavaParser::RBRACK);
      setState(442);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(445);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::THROWS) {
      setState(443);
      match(JavaParser::THROWS);
      setState(444);
      qualifiedNameList();
    }
    setState(449);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::LBRACE: {
        setState(447);
        methodBody();
        break;
      }

      case JavaParser::SEMI: {
        setState(448);
        match(JavaParser::SEMI);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericMethodDeclarationContext ------------------------------------------------------------------

JavaParser::GenericMethodDeclarationContext::GenericMethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeParametersContext* JavaParser::GenericMethodDeclarationContext::typeParameters() {
  return getRuleContext<JavaParser::TypeParametersContext>(0);
}

JavaParser::MethodDeclarationContext* JavaParser::GenericMethodDeclarationContext::methodDeclaration() {
  return getRuleContext<JavaParser::MethodDeclarationContext>(0);
}


size_t JavaParser::GenericMethodDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleGenericMethodDeclaration;
}

void JavaParser::GenericMethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericMethodDeclaration(this);
}

void JavaParser::GenericMethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericMethodDeclaration(this);
}


antlrcpp::Any JavaParser::GenericMethodDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitGenericMethodDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::GenericMethodDeclarationContext* JavaParser::genericMethodDeclaration() {
  GenericMethodDeclarationContext *_localctx = _tracker.createInstance<GenericMethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 44, JavaParser::RuleGenericMethodDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    typeParameters();
    setState(452);
    methodDeclaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructorDeclarationContext ------------------------------------------------------------------

JavaParser::ConstructorDeclarationContext::ConstructorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::ConstructorDeclarationContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::FormalParametersContext* JavaParser::ConstructorDeclarationContext::formalParameters() {
  return getRuleContext<JavaParser::FormalParametersContext>(0);
}

JavaParser::ConstructorBodyContext* JavaParser::ConstructorDeclarationContext::constructorBody() {
  return getRuleContext<JavaParser::ConstructorBodyContext>(0);
}

JavaParser::QualifiedNameListContext* JavaParser::ConstructorDeclarationContext::qualifiedNameList() {
  return getRuleContext<JavaParser::QualifiedNameListContext>(0);
}


size_t JavaParser::ConstructorDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleConstructorDeclaration;
}

void JavaParser::ConstructorDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructorDeclaration(this);
}

void JavaParser::ConstructorDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructorDeclaration(this);
}


antlrcpp::Any JavaParser::ConstructorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitConstructorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ConstructorDeclarationContext* JavaParser::constructorDeclaration() {
  ConstructorDeclarationContext *_localctx = _tracker.createInstance<ConstructorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 46, JavaParser::RuleConstructorDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    match(JavaParser::Identifier);
    setState(455);
    formalParameters();
    setState(458);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::THROWS) {
      setState(456);
      match(JavaParser::THROWS);
      setState(457);
      qualifiedNameList();
    }
    setState(460);
    constructorBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericConstructorDeclarationContext ------------------------------------------------------------------

JavaParser::GenericConstructorDeclarationContext::GenericConstructorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeParametersContext* JavaParser::GenericConstructorDeclarationContext::typeParameters() {
  return getRuleContext<JavaParser::TypeParametersContext>(0);
}

JavaParser::ConstructorDeclarationContext* JavaParser::GenericConstructorDeclarationContext::constructorDeclaration() {
  return getRuleContext<JavaParser::ConstructorDeclarationContext>(0);
}


size_t JavaParser::GenericConstructorDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleGenericConstructorDeclaration;
}

void JavaParser::GenericConstructorDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericConstructorDeclaration(this);
}

void JavaParser::GenericConstructorDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericConstructorDeclaration(this);
}


antlrcpp::Any JavaParser::GenericConstructorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitGenericConstructorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::GenericConstructorDeclarationContext* JavaParser::genericConstructorDeclaration() {
  GenericConstructorDeclarationContext *_localctx = _tracker.createInstance<GenericConstructorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 48, JavaParser::RuleGenericConstructorDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    typeParameters();
    setState(463);
    constructorDeclaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldDeclarationContext ------------------------------------------------------------------

JavaParser::FieldDeclarationContext::FieldDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeTypeContext* JavaParser::FieldDeclarationContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::VariableDeclaratorsContext* JavaParser::FieldDeclarationContext::variableDeclarators() {
  return getRuleContext<JavaParser::VariableDeclaratorsContext>(0);
}


size_t JavaParser::FieldDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleFieldDeclaration;
}

void JavaParser::FieldDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFieldDeclaration(this);
}

void JavaParser::FieldDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFieldDeclaration(this);
}


antlrcpp::Any JavaParser::FieldDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitFieldDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::FieldDeclarationContext* JavaParser::fieldDeclaration() {
  FieldDeclarationContext *_localctx = _tracker.createInstance<FieldDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 50, JavaParser::RuleFieldDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(465);
    typeType();
    setState(466);
    variableDeclarators();
    setState(467);
    match(JavaParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceBodyDeclarationContext ------------------------------------------------------------------

JavaParser::InterfaceBodyDeclarationContext::InterfaceBodyDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::InterfaceMemberDeclarationContext* JavaParser::InterfaceBodyDeclarationContext::interfaceMemberDeclaration() {
  return getRuleContext<JavaParser::InterfaceMemberDeclarationContext>(0);
}

std::vector<JavaParser::ModifierContext *> JavaParser::InterfaceBodyDeclarationContext::modifier() {
  return getRuleContexts<JavaParser::ModifierContext>();
}

JavaParser::ModifierContext* JavaParser::InterfaceBodyDeclarationContext::modifier(size_t i) {
  return getRuleContext<JavaParser::ModifierContext>(i);
}


size_t JavaParser::InterfaceBodyDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleInterfaceBodyDeclaration;
}

void JavaParser::InterfaceBodyDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceBodyDeclaration(this);
}

void JavaParser::InterfaceBodyDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceBodyDeclaration(this);
}


antlrcpp::Any JavaParser::InterfaceBodyDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitInterfaceBodyDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::InterfaceBodyDeclarationContext* JavaParser::interfaceBodyDeclaration() {
  InterfaceBodyDeclarationContext *_localctx = _tracker.createInstance<InterfaceBodyDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 52, JavaParser::RuleInterfaceBodyDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(477);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::ABSTRACT:
      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::CLASS:
      case JavaParser::DOUBLE:
      case JavaParser::ENUM:
      case JavaParser::FINAL:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::INTERFACE:
      case JavaParser::LONG:
      case JavaParser::NATIVE:
      case JavaParser::PRIVATE:
      case JavaParser::PROTECTED:
      case JavaParser::PUBLIC:
      case JavaParser::SHORT:
      case JavaParser::STATIC:
      case JavaParser::STRICTFP:
      case JavaParser::SYNCHRONIZED:
      case JavaParser::TRANSIENT:
      case JavaParser::VOID:
      case JavaParser::VOLATILE:
      case JavaParser::LT:
      case JavaParser::Identifier:
      case JavaParser::AT: {
        enterOuterAlt(_localctx, 1);
        setState(472);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(469);
            modifier(); 
          }
          setState(474);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
        }
        setState(475);
        interfaceMemberDeclaration();
        break;
      }

      case JavaParser::SEMI: {
        enterOuterAlt(_localctx, 2);
        setState(476);
        match(JavaParser::SEMI);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceMemberDeclarationContext ------------------------------------------------------------------

JavaParser::InterfaceMemberDeclarationContext::InterfaceMemberDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ConstDeclarationContext* JavaParser::InterfaceMemberDeclarationContext::constDeclaration() {
  return getRuleContext<JavaParser::ConstDeclarationContext>(0);
}

JavaParser::InterfaceMethodDeclarationContext* JavaParser::InterfaceMemberDeclarationContext::interfaceMethodDeclaration() {
  return getRuleContext<JavaParser::InterfaceMethodDeclarationContext>(0);
}

JavaParser::GenericInterfaceMethodDeclarationContext* JavaParser::InterfaceMemberDeclarationContext::genericInterfaceMethodDeclaration() {
  return getRuleContext<JavaParser::GenericInterfaceMethodDeclarationContext>(0);
}

JavaParser::InterfaceDeclarationContext* JavaParser::InterfaceMemberDeclarationContext::interfaceDeclaration() {
  return getRuleContext<JavaParser::InterfaceDeclarationContext>(0);
}

JavaParser::AnnotationTypeDeclarationContext* JavaParser::InterfaceMemberDeclarationContext::annotationTypeDeclaration() {
  return getRuleContext<JavaParser::AnnotationTypeDeclarationContext>(0);
}

JavaParser::ClassDeclarationContext* JavaParser::InterfaceMemberDeclarationContext::classDeclaration() {
  return getRuleContext<JavaParser::ClassDeclarationContext>(0);
}

JavaParser::EnumDeclarationContext* JavaParser::InterfaceMemberDeclarationContext::enumDeclaration() {
  return getRuleContext<JavaParser::EnumDeclarationContext>(0);
}


size_t JavaParser::InterfaceMemberDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleInterfaceMemberDeclaration;
}

void JavaParser::InterfaceMemberDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceMemberDeclaration(this);
}

void JavaParser::InterfaceMemberDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceMemberDeclaration(this);
}


antlrcpp::Any JavaParser::InterfaceMemberDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitInterfaceMemberDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::InterfaceMemberDeclarationContext* JavaParser::interfaceMemberDeclaration() {
  InterfaceMemberDeclarationContext *_localctx = _tracker.createInstance<InterfaceMemberDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 54, JavaParser::RuleInterfaceMemberDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(486);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(479);
      constDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(480);
      interfaceMethodDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(481);
      genericInterfaceMethodDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(482);
      interfaceDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(483);
      annotationTypeDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(484);
      classDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(485);
      enumDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclarationContext ------------------------------------------------------------------

JavaParser::ConstDeclarationContext::ConstDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeTypeContext* JavaParser::ConstDeclarationContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

std::vector<JavaParser::ConstantDeclaratorContext *> JavaParser::ConstDeclarationContext::constantDeclarator() {
  return getRuleContexts<JavaParser::ConstantDeclaratorContext>();
}

JavaParser::ConstantDeclaratorContext* JavaParser::ConstDeclarationContext::constantDeclarator(size_t i) {
  return getRuleContext<JavaParser::ConstantDeclaratorContext>(i);
}


size_t JavaParser::ConstDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleConstDeclaration;
}

void JavaParser::ConstDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDeclaration(this);
}

void JavaParser::ConstDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDeclaration(this);
}


antlrcpp::Any JavaParser::ConstDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitConstDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ConstDeclarationContext* JavaParser::constDeclaration() {
  ConstDeclarationContext *_localctx = _tracker.createInstance<ConstDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 56, JavaParser::RuleConstDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(488);
    typeType();
    setState(489);
    constantDeclarator();
    setState(494);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::COMMA) {
      setState(490);
      match(JavaParser::COMMA);
      setState(491);
      constantDeclarator();
      setState(496);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(497);
    match(JavaParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDeclaratorContext ------------------------------------------------------------------

JavaParser::ConstantDeclaratorContext::ConstantDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::ConstantDeclaratorContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::VariableInitializerContext* JavaParser::ConstantDeclaratorContext::variableInitializer() {
  return getRuleContext<JavaParser::VariableInitializerContext>(0);
}


size_t JavaParser::ConstantDeclaratorContext::getRuleIndex() const {
  return JavaParser::RuleConstantDeclarator;
}

void JavaParser::ConstantDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantDeclarator(this);
}

void JavaParser::ConstantDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantDeclarator(this);
}


antlrcpp::Any JavaParser::ConstantDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitConstantDeclarator(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ConstantDeclaratorContext* JavaParser::constantDeclarator() {
  ConstantDeclaratorContext *_localctx = _tracker.createInstance<ConstantDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 58, JavaParser::RuleConstantDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
    match(JavaParser::Identifier);
    setState(504);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::LBRACK) {
      setState(500);
      match(JavaParser::LBRACK);
      setState(501);
      match(JavaParser::RBRACK);
      setState(506);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(507);
    match(JavaParser::ASSIGN);
    setState(508);
    variableInitializer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceMethodDeclarationContext ------------------------------------------------------------------

JavaParser::InterfaceMethodDeclarationContext::InterfaceMethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::InterfaceMethodDeclarationContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::FormalParametersContext* JavaParser::InterfaceMethodDeclarationContext::formalParameters() {
  return getRuleContext<JavaParser::FormalParametersContext>(0);
}

JavaParser::TypeTypeContext* JavaParser::InterfaceMethodDeclarationContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::QualifiedNameListContext* JavaParser::InterfaceMethodDeclarationContext::qualifiedNameList() {
  return getRuleContext<JavaParser::QualifiedNameListContext>(0);
}


size_t JavaParser::InterfaceMethodDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleInterfaceMethodDeclaration;
}

void JavaParser::InterfaceMethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceMethodDeclaration(this);
}

void JavaParser::InterfaceMethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceMethodDeclaration(this);
}


antlrcpp::Any JavaParser::InterfaceMethodDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitInterfaceMethodDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::InterfaceMethodDeclarationContext* JavaParser::interfaceMethodDeclaration() {
  InterfaceMethodDeclarationContext *_localctx = _tracker.createInstance<InterfaceMethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 60, JavaParser::RuleInterfaceMethodDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::SHORT:
      case JavaParser::Identifier: {
        setState(510);
        typeType();
        break;
      }

      case JavaParser::VOID: {
        setState(511);
        match(JavaParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(514);
    match(JavaParser::Identifier);
    setState(515);
    formalParameters();
    setState(520);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::LBRACK) {
      setState(516);
      match(JavaParser::LBRACK);
      setState(517);
      match(JavaParser::RBRACK);
      setState(522);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(525);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::THROWS) {
      setState(523);
      match(JavaParser::THROWS);
      setState(524);
      qualifiedNameList();
    }
    setState(527);
    match(JavaParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericInterfaceMethodDeclarationContext ------------------------------------------------------------------

JavaParser::GenericInterfaceMethodDeclarationContext::GenericInterfaceMethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeParametersContext* JavaParser::GenericInterfaceMethodDeclarationContext::typeParameters() {
  return getRuleContext<JavaParser::TypeParametersContext>(0);
}

JavaParser::InterfaceMethodDeclarationContext* JavaParser::GenericInterfaceMethodDeclarationContext::interfaceMethodDeclaration() {
  return getRuleContext<JavaParser::InterfaceMethodDeclarationContext>(0);
}


size_t JavaParser::GenericInterfaceMethodDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleGenericInterfaceMethodDeclaration;
}

void JavaParser::GenericInterfaceMethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericInterfaceMethodDeclaration(this);
}

void JavaParser::GenericInterfaceMethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericInterfaceMethodDeclaration(this);
}


antlrcpp::Any JavaParser::GenericInterfaceMethodDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitGenericInterfaceMethodDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::GenericInterfaceMethodDeclarationContext* JavaParser::genericInterfaceMethodDeclaration() {
  GenericInterfaceMethodDeclarationContext *_localctx = _tracker.createInstance<GenericInterfaceMethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 62, JavaParser::RuleGenericInterfaceMethodDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    typeParameters();
    setState(530);
    interfaceMethodDeclaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclaratorsContext ------------------------------------------------------------------

JavaParser::VariableDeclaratorsContext::VariableDeclaratorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::VariableDeclaratorContext *> JavaParser::VariableDeclaratorsContext::variableDeclarator() {
  return getRuleContexts<JavaParser::VariableDeclaratorContext>();
}

JavaParser::VariableDeclaratorContext* JavaParser::VariableDeclaratorsContext::variableDeclarator(size_t i) {
  return getRuleContext<JavaParser::VariableDeclaratorContext>(i);
}


size_t JavaParser::VariableDeclaratorsContext::getRuleIndex() const {
  return JavaParser::RuleVariableDeclarators;
}

void JavaParser::VariableDeclaratorsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclarators(this);
}

void JavaParser::VariableDeclaratorsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclarators(this);
}


antlrcpp::Any JavaParser::VariableDeclaratorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarators(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::VariableDeclaratorsContext* JavaParser::variableDeclarators() {
  VariableDeclaratorsContext *_localctx = _tracker.createInstance<VariableDeclaratorsContext>(_ctx, getState());
  enterRule(_localctx, 64, JavaParser::RuleVariableDeclarators);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(532);
    variableDeclarator();
    setState(537);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::COMMA) {
      setState(533);
      match(JavaParser::COMMA);
      setState(534);
      variableDeclarator();
      setState(539);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclaratorContext ------------------------------------------------------------------

JavaParser::VariableDeclaratorContext::VariableDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::VariableDeclaratorIdContext* JavaParser::VariableDeclaratorContext::variableDeclaratorId() {
  return getRuleContext<JavaParser::VariableDeclaratorIdContext>(0);
}

JavaParser::VariableInitializerContext* JavaParser::VariableDeclaratorContext::variableInitializer() {
  return getRuleContext<JavaParser::VariableInitializerContext>(0);
}


size_t JavaParser::VariableDeclaratorContext::getRuleIndex() const {
  return JavaParser::RuleVariableDeclarator;
}

void JavaParser::VariableDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclarator(this);
}

void JavaParser::VariableDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclarator(this);
}


antlrcpp::Any JavaParser::VariableDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarator(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::VariableDeclaratorContext* JavaParser::variableDeclarator() {
  VariableDeclaratorContext *_localctx = _tracker.createInstance<VariableDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 66, JavaParser::RuleVariableDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(540);
    variableDeclaratorId();
    setState(543);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::ASSIGN) {
      setState(541);
      match(JavaParser::ASSIGN);
      setState(542);
      variableInitializer();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclaratorIdContext ------------------------------------------------------------------

JavaParser::VariableDeclaratorIdContext::VariableDeclaratorIdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::VariableDeclaratorIdContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}


size_t JavaParser::VariableDeclaratorIdContext::getRuleIndex() const {
  return JavaParser::RuleVariableDeclaratorId;
}

void JavaParser::VariableDeclaratorIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaratorId(this);
}

void JavaParser::VariableDeclaratorIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaratorId(this);
}


antlrcpp::Any JavaParser::VariableDeclaratorIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaratorId(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::VariableDeclaratorIdContext* JavaParser::variableDeclaratorId() {
  VariableDeclaratorIdContext *_localctx = _tracker.createInstance<VariableDeclaratorIdContext>(_ctx, getState());
  enterRule(_localctx, 68, JavaParser::RuleVariableDeclaratorId);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(545);
    match(JavaParser::Identifier);
    setState(550);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::LBRACK) {
      setState(546);
      match(JavaParser::LBRACK);
      setState(547);
      match(JavaParser::RBRACK);
      setState(552);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableInitializerContext ------------------------------------------------------------------

JavaParser::VariableInitializerContext::VariableInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ArrayInitializerContext* JavaParser::VariableInitializerContext::arrayInitializer() {
  return getRuleContext<JavaParser::ArrayInitializerContext>(0);
}

JavaParser::ExpressionContext* JavaParser::VariableInitializerContext::expression() {
  return getRuleContext<JavaParser::ExpressionContext>(0);
}


size_t JavaParser::VariableInitializerContext::getRuleIndex() const {
  return JavaParser::RuleVariableInitializer;
}

void JavaParser::VariableInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableInitializer(this);
}

void JavaParser::VariableInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableInitializer(this);
}


antlrcpp::Any JavaParser::VariableInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitVariableInitializer(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::VariableInitializerContext* JavaParser::variableInitializer() {
  VariableInitializerContext *_localctx = _tracker.createInstance<VariableInitializerContext>(_ctx, getState());
  enterRule(_localctx, 70, JavaParser::RuleVariableInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(555);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(553);
        arrayInitializer();
        break;
      }

      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::NEW:
      case JavaParser::SHORT:
      case JavaParser::SUPER:
      case JavaParser::THIS:
      case JavaParser::VOID:
      case JavaParser::IntegerLiteral:
      case JavaParser::FloatingPointLiteral:
      case JavaParser::BooleanLiteral:
      case JavaParser::CharacterLiteral:
      case JavaParser::StringLiteral:
      case JavaParser::NullLiteral:
      case JavaParser::LPAREN:
      case JavaParser::LT:
      case JavaParser::BANG:
      case JavaParser::TILDE:
      case JavaParser::INC:
      case JavaParser::DEC:
      case JavaParser::ADD:
      case JavaParser::SUB:
      case JavaParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(554);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayInitializerContext ------------------------------------------------------------------

JavaParser::ArrayInitializerContext::ArrayInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::VariableInitializerContext *> JavaParser::ArrayInitializerContext::variableInitializer() {
  return getRuleContexts<JavaParser::VariableInitializerContext>();
}

JavaParser::VariableInitializerContext* JavaParser::ArrayInitializerContext::variableInitializer(size_t i) {
  return getRuleContext<JavaParser::VariableInitializerContext>(i);
}


size_t JavaParser::ArrayInitializerContext::getRuleIndex() const {
  return JavaParser::RuleArrayInitializer;
}

void JavaParser::ArrayInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayInitializer(this);
}

void JavaParser::ArrayInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayInitializer(this);
}


antlrcpp::Any JavaParser::ArrayInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitArrayInitializer(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ArrayInitializerContext* JavaParser::arrayInitializer() {
  ArrayInitializerContext *_localctx = _tracker.createInstance<ArrayInitializerContext>(_ctx, getState());
  enterRule(_localctx, 72, JavaParser::RuleArrayInitializer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(557);
    match(JavaParser::LBRACE);
    setState(569);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::NEW)
      | (1ULL << JavaParser::SHORT)
      | (1ULL << JavaParser::SUPER)
      | (1ULL << JavaParser::THIS)
      | (1ULL << JavaParser::VOID)
      | (1ULL << JavaParser::IntegerLiteral)
      | (1ULL << JavaParser::FloatingPointLiteral)
      | (1ULL << JavaParser::BooleanLiteral)
      | (1ULL << JavaParser::CharacterLiteral)
      | (1ULL << JavaParser::StringLiteral)
      | (1ULL << JavaParser::NullLiteral)
      | (1ULL << JavaParser::LPAREN)
      | (1ULL << JavaParser::LBRACE))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
      | (1ULL << (JavaParser::BANG - 68))
      | (1ULL << (JavaParser::TILDE - 68))
      | (1ULL << (JavaParser::INC - 68))
      | (1ULL << (JavaParser::DEC - 68))
      | (1ULL << (JavaParser::ADD - 68))
      | (1ULL << (JavaParser::SUB - 68))
      | (1ULL << (JavaParser::Identifier - 68)))) != 0)) {
      setState(558);
      variableInitializer();
      setState(563);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(559);
          match(JavaParser::COMMA);
          setState(560);
          variableInitializer(); 
        }
        setState(565);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
      }
      setState(567);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaParser::COMMA) {
        setState(566);
        match(JavaParser::COMMA);
      }
    }
    setState(571);
    match(JavaParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumConstantNameContext ------------------------------------------------------------------

JavaParser::EnumConstantNameContext::EnumConstantNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::EnumConstantNameContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}


size_t JavaParser::EnumConstantNameContext::getRuleIndex() const {
  return JavaParser::RuleEnumConstantName;
}

void JavaParser::EnumConstantNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumConstantName(this);
}

void JavaParser::EnumConstantNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumConstantName(this);
}


antlrcpp::Any JavaParser::EnumConstantNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitEnumConstantName(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::EnumConstantNameContext* JavaParser::enumConstantName() {
  EnumConstantNameContext *_localctx = _tracker.createInstance<EnumConstantNameContext>(_ctx, getState());
  enterRule(_localctx, 74, JavaParser::RuleEnumConstantName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    match(JavaParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeTypeContext ------------------------------------------------------------------

JavaParser::TypeTypeContext::TypeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ClassOrInterfaceTypeContext* JavaParser::TypeTypeContext::classOrInterfaceType() {
  return getRuleContext<JavaParser::ClassOrInterfaceTypeContext>(0);
}

JavaParser::PrimitiveTypeContext* JavaParser::TypeTypeContext::primitiveType() {
  return getRuleContext<JavaParser::PrimitiveTypeContext>(0);
}


size_t JavaParser::TypeTypeContext::getRuleIndex() const {
  return JavaParser::RuleTypeType;
}

void JavaParser::TypeTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeType(this);
}

void JavaParser::TypeTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeType(this);
}


antlrcpp::Any JavaParser::TypeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitTypeType(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::TypeTypeContext* JavaParser::typeType() {
  TypeTypeContext *_localctx = _tracker.createInstance<TypeTypeContext>(_ctx, getState());
  enterRule(_localctx, 76, JavaParser::RuleTypeType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(591);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(575);
        classOrInterfaceType();
        setState(580);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(576);
            match(JavaParser::LBRACK);
            setState(577);
            match(JavaParser::RBRACK); 
          }
          setState(582);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
        }
        break;
      }

      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::SHORT: {
        enterOuterAlt(_localctx, 2);
        setState(583);
        primitiveType();
        setState(588);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(584);
            match(JavaParser::LBRACK);
            setState(585);
            match(JavaParser::RBRACK); 
          }
          setState(590);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassOrInterfaceTypeContext ------------------------------------------------------------------

JavaParser::ClassOrInterfaceTypeContext::ClassOrInterfaceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> JavaParser::ClassOrInterfaceTypeContext::Identifier() {
  return getTokens(JavaParser::Identifier);
}

tree::TerminalNode* JavaParser::ClassOrInterfaceTypeContext::Identifier(size_t i) {
  return getToken(JavaParser::Identifier, i);
}

std::vector<JavaParser::TypeArgumentsContext *> JavaParser::ClassOrInterfaceTypeContext::typeArguments() {
  return getRuleContexts<JavaParser::TypeArgumentsContext>();
}

JavaParser::TypeArgumentsContext* JavaParser::ClassOrInterfaceTypeContext::typeArguments(size_t i) {
  return getRuleContext<JavaParser::TypeArgumentsContext>(i);
}


size_t JavaParser::ClassOrInterfaceTypeContext::getRuleIndex() const {
  return JavaParser::RuleClassOrInterfaceType;
}

void JavaParser::ClassOrInterfaceTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassOrInterfaceType(this);
}

void JavaParser::ClassOrInterfaceTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassOrInterfaceType(this);
}


antlrcpp::Any JavaParser::ClassOrInterfaceTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitClassOrInterfaceType(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ClassOrInterfaceTypeContext* JavaParser::classOrInterfaceType() {
  ClassOrInterfaceTypeContext *_localctx = _tracker.createInstance<ClassOrInterfaceTypeContext>(_ctx, getState());
  enterRule(_localctx, 78, JavaParser::RuleClassOrInterfaceType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(593);
    match(JavaParser::Identifier);
    setState(595);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      setState(594);
      typeArguments();
      break;
    }

    }
    setState(604);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(597);
        match(JavaParser::DOT);
        setState(598);
        match(JavaParser::Identifier);
        setState(600);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
        case 1: {
          setState(599);
          typeArguments();
          break;
        }

        } 
      }
      setState(606);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimitiveTypeContext ------------------------------------------------------------------

JavaParser::PrimitiveTypeContext::PrimitiveTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JavaParser::PrimitiveTypeContext::getRuleIndex() const {
  return JavaParser::RulePrimitiveType;
}

void JavaParser::PrimitiveTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimitiveType(this);
}

void JavaParser::PrimitiveTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimitiveType(this);
}


antlrcpp::Any JavaParser::PrimitiveTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitPrimitiveType(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::PrimitiveTypeContext* JavaParser::primitiveType() {
  PrimitiveTypeContext *_localctx = _tracker.createInstance<PrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 80, JavaParser::RulePrimitiveType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::SHORT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeArgumentsContext ------------------------------------------------------------------

JavaParser::TypeArgumentsContext::TypeArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::TypeArgumentContext *> JavaParser::TypeArgumentsContext::typeArgument() {
  return getRuleContexts<JavaParser::TypeArgumentContext>();
}

JavaParser::TypeArgumentContext* JavaParser::TypeArgumentsContext::typeArgument(size_t i) {
  return getRuleContext<JavaParser::TypeArgumentContext>(i);
}


size_t JavaParser::TypeArgumentsContext::getRuleIndex() const {
  return JavaParser::RuleTypeArguments;
}

void JavaParser::TypeArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeArguments(this);
}

void JavaParser::TypeArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeArguments(this);
}


antlrcpp::Any JavaParser::TypeArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitTypeArguments(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::TypeArgumentsContext* JavaParser::typeArguments() {
  TypeArgumentsContext *_localctx = _tracker.createInstance<TypeArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 82, JavaParser::RuleTypeArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(609);
    match(JavaParser::LT);
    setState(610);
    typeArgument();
    setState(615);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::COMMA) {
      setState(611);
      match(JavaParser::COMMA);
      setState(612);
      typeArgument();
      setState(617);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(618);
    match(JavaParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeArgumentContext ------------------------------------------------------------------

JavaParser::TypeArgumentContext::TypeArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeTypeContext* JavaParser::TypeArgumentContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}


size_t JavaParser::TypeArgumentContext::getRuleIndex() const {
  return JavaParser::RuleTypeArgument;
}

void JavaParser::TypeArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeArgument(this);
}

void JavaParser::TypeArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeArgument(this);
}


antlrcpp::Any JavaParser::TypeArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitTypeArgument(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::TypeArgumentContext* JavaParser::typeArgument() {
  TypeArgumentContext *_localctx = _tracker.createInstance<TypeArgumentContext>(_ctx, getState());
  enterRule(_localctx, 84, JavaParser::RuleTypeArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(626);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::SHORT:
      case JavaParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(620);
        typeType();
        break;
      }

      case JavaParser::QUESTION: {
        enterOuterAlt(_localctx, 2);
        setState(621);
        match(JavaParser::QUESTION);
        setState(624);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == JavaParser::EXTENDS

        || _la == JavaParser::SUPER) {
          setState(622);
          _la = _input->LA(1);
          if (!(_la == JavaParser::EXTENDS

          || _la == JavaParser::SUPER)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(623);
          typeType();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifiedNameListContext ------------------------------------------------------------------

JavaParser::QualifiedNameListContext::QualifiedNameListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::QualifiedNameContext *> JavaParser::QualifiedNameListContext::qualifiedName() {
  return getRuleContexts<JavaParser::QualifiedNameContext>();
}

JavaParser::QualifiedNameContext* JavaParser::QualifiedNameListContext::qualifiedName(size_t i) {
  return getRuleContext<JavaParser::QualifiedNameContext>(i);
}


size_t JavaParser::QualifiedNameListContext::getRuleIndex() const {
  return JavaParser::RuleQualifiedNameList;
}

void JavaParser::QualifiedNameListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifiedNameList(this);
}

void JavaParser::QualifiedNameListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifiedNameList(this);
}


antlrcpp::Any JavaParser::QualifiedNameListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitQualifiedNameList(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::QualifiedNameListContext* JavaParser::qualifiedNameList() {
  QualifiedNameListContext *_localctx = _tracker.createInstance<QualifiedNameListContext>(_ctx, getState());
  enterRule(_localctx, 86, JavaParser::RuleQualifiedNameList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(628);
    qualifiedName();
    setState(633);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::COMMA) {
      setState(629);
      match(JavaParser::COMMA);
      setState(630);
      qualifiedName();
      setState(635);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParametersContext ------------------------------------------------------------------

JavaParser::FormalParametersContext::FormalParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::FormalParameterListContext* JavaParser::FormalParametersContext::formalParameterList() {
  return getRuleContext<JavaParser::FormalParameterListContext>(0);
}


size_t JavaParser::FormalParametersContext::getRuleIndex() const {
  return JavaParser::RuleFormalParameters;
}

void JavaParser::FormalParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameters(this);
}

void JavaParser::FormalParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameters(this);
}


antlrcpp::Any JavaParser::FormalParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitFormalParameters(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::FormalParametersContext* JavaParser::formalParameters() {
  FormalParametersContext *_localctx = _tracker.createInstance<FormalParametersContext>(_ctx, getState());
  enterRule(_localctx, 88, JavaParser::RuleFormalParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(636);
    match(JavaParser::LPAREN);
    setState(638);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::FINAL)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::SHORT))) != 0) || _la == JavaParser::Identifier

    || _la == JavaParser::AT) {
      setState(637);
      formalParameterList();
    }
    setState(640);
    match(JavaParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterListContext ------------------------------------------------------------------

JavaParser::FormalParameterListContext::FormalParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::FormalParameterContext *> JavaParser::FormalParameterListContext::formalParameter() {
  return getRuleContexts<JavaParser::FormalParameterContext>();
}

JavaParser::FormalParameterContext* JavaParser::FormalParameterListContext::formalParameter(size_t i) {
  return getRuleContext<JavaParser::FormalParameterContext>(i);
}

JavaParser::LastFormalParameterContext* JavaParser::FormalParameterListContext::lastFormalParameter() {
  return getRuleContext<JavaParser::LastFormalParameterContext>(0);
}


size_t JavaParser::FormalParameterListContext::getRuleIndex() const {
  return JavaParser::RuleFormalParameterList;
}

void JavaParser::FormalParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameterList(this);
}

void JavaParser::FormalParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameterList(this);
}


antlrcpp::Any JavaParser::FormalParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitFormalParameterList(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::FormalParameterListContext* JavaParser::formalParameterList() {
  FormalParameterListContext *_localctx = _tracker.createInstance<FormalParameterListContext>(_ctx, getState());
  enterRule(_localctx, 90, JavaParser::RuleFormalParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(655);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(642);
      formalParameter();
      setState(647);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(643);
          match(JavaParser::COMMA);
          setState(644);
          formalParameter(); 
        }
        setState(649);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
      }
      setState(652);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaParser::COMMA) {
        setState(650);
        match(JavaParser::COMMA);
        setState(651);
        lastFormalParameter();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(654);
      lastFormalParameter();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterContext ------------------------------------------------------------------

JavaParser::FormalParameterContext::FormalParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeTypeContext* JavaParser::FormalParameterContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::VariableDeclaratorIdContext* JavaParser::FormalParameterContext::variableDeclaratorId() {
  return getRuleContext<JavaParser::VariableDeclaratorIdContext>(0);
}

std::vector<JavaParser::VariableModifierContext *> JavaParser::FormalParameterContext::variableModifier() {
  return getRuleContexts<JavaParser::VariableModifierContext>();
}

JavaParser::VariableModifierContext* JavaParser::FormalParameterContext::variableModifier(size_t i) {
  return getRuleContext<JavaParser::VariableModifierContext>(i);
}


size_t JavaParser::FormalParameterContext::getRuleIndex() const {
  return JavaParser::RuleFormalParameter;
}

void JavaParser::FormalParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameter(this);
}

void JavaParser::FormalParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameter(this);
}


antlrcpp::Any JavaParser::FormalParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitFormalParameter(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::FormalParameterContext* JavaParser::formalParameter() {
  FormalParameterContext *_localctx = _tracker.createInstance<FormalParameterContext>(_ctx, getState());
  enterRule(_localctx, 92, JavaParser::RuleFormalParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(660);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::FINAL || _la == JavaParser::AT) {
      setState(657);
      variableModifier();
      setState(662);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(663);
    typeType();
    setState(664);
    variableDeclaratorId();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LastFormalParameterContext ------------------------------------------------------------------

JavaParser::LastFormalParameterContext::LastFormalParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeTypeContext* JavaParser::LastFormalParameterContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::VariableDeclaratorIdContext* JavaParser::LastFormalParameterContext::variableDeclaratorId() {
  return getRuleContext<JavaParser::VariableDeclaratorIdContext>(0);
}

std::vector<JavaParser::VariableModifierContext *> JavaParser::LastFormalParameterContext::variableModifier() {
  return getRuleContexts<JavaParser::VariableModifierContext>();
}

JavaParser::VariableModifierContext* JavaParser::LastFormalParameterContext::variableModifier(size_t i) {
  return getRuleContext<JavaParser::VariableModifierContext>(i);
}


size_t JavaParser::LastFormalParameterContext::getRuleIndex() const {
  return JavaParser::RuleLastFormalParameter;
}

void JavaParser::LastFormalParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLastFormalParameter(this);
}

void JavaParser::LastFormalParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLastFormalParameter(this);
}


antlrcpp::Any JavaParser::LastFormalParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitLastFormalParameter(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::LastFormalParameterContext* JavaParser::lastFormalParameter() {
  LastFormalParameterContext *_localctx = _tracker.createInstance<LastFormalParameterContext>(_ctx, getState());
  enterRule(_localctx, 94, JavaParser::RuleLastFormalParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(669);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::FINAL || _la == JavaParser::AT) {
      setState(666);
      variableModifier();
      setState(671);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(672);
    typeType();
    setState(673);
    match(JavaParser::ELLIPSIS);
    setState(674);
    variableDeclaratorId();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodBodyContext ------------------------------------------------------------------

JavaParser::MethodBodyContext::MethodBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::BlockContext* JavaParser::MethodBodyContext::block() {
  return getRuleContext<JavaParser::BlockContext>(0);
}


size_t JavaParser::MethodBodyContext::getRuleIndex() const {
  return JavaParser::RuleMethodBody;
}

void JavaParser::MethodBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodBody(this);
}

void JavaParser::MethodBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodBody(this);
}


antlrcpp::Any JavaParser::MethodBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitMethodBody(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::MethodBodyContext* JavaParser::methodBody() {
  MethodBodyContext *_localctx = _tracker.createInstance<MethodBodyContext>(_ctx, getState());
  enterRule(_localctx, 96, JavaParser::RuleMethodBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(676);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructorBodyContext ------------------------------------------------------------------

JavaParser::ConstructorBodyContext::ConstructorBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::BlockContext* JavaParser::ConstructorBodyContext::block() {
  return getRuleContext<JavaParser::BlockContext>(0);
}


size_t JavaParser::ConstructorBodyContext::getRuleIndex() const {
  return JavaParser::RuleConstructorBody;
}

void JavaParser::ConstructorBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructorBody(this);
}

void JavaParser::ConstructorBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructorBody(this);
}


antlrcpp::Any JavaParser::ConstructorBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitConstructorBody(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ConstructorBodyContext* JavaParser::constructorBody() {
  ConstructorBodyContext *_localctx = _tracker.createInstance<ConstructorBodyContext>(_ctx, getState());
  enterRule(_localctx, 98, JavaParser::RuleConstructorBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(678);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifiedNameContext ------------------------------------------------------------------

JavaParser::QualifiedNameContext::QualifiedNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> JavaParser::QualifiedNameContext::Identifier() {
  return getTokens(JavaParser::Identifier);
}

tree::TerminalNode* JavaParser::QualifiedNameContext::Identifier(size_t i) {
  return getToken(JavaParser::Identifier, i);
}


size_t JavaParser::QualifiedNameContext::getRuleIndex() const {
  return JavaParser::RuleQualifiedName;
}

void JavaParser::QualifiedNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifiedName(this);
}

void JavaParser::QualifiedNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifiedName(this);
}


antlrcpp::Any JavaParser::QualifiedNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitQualifiedName(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::QualifiedNameContext* JavaParser::qualifiedName() {
  QualifiedNameContext *_localctx = _tracker.createInstance<QualifiedNameContext>(_ctx, getState());
  enterRule(_localctx, 100, JavaParser::RuleQualifiedName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(680);
    match(JavaParser::Identifier);
    setState(685);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(681);
        match(JavaParser::DOT);
        setState(682);
        match(JavaParser::Identifier); 
      }
      setState(687);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

JavaParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::LiteralContext::IntegerLiteral() {
  return getToken(JavaParser::IntegerLiteral, 0);
}

tree::TerminalNode* JavaParser::LiteralContext::FloatingPointLiteral() {
  return getToken(JavaParser::FloatingPointLiteral, 0);
}

tree::TerminalNode* JavaParser::LiteralContext::CharacterLiteral() {
  return getToken(JavaParser::CharacterLiteral, 0);
}

tree::TerminalNode* JavaParser::LiteralContext::StringLiteral() {
  return getToken(JavaParser::StringLiteral, 0);
}

tree::TerminalNode* JavaParser::LiteralContext::BooleanLiteral() {
  return getToken(JavaParser::BooleanLiteral, 0);
}


size_t JavaParser::LiteralContext::getRuleIndex() const {
  return JavaParser::RuleLiteral;
}

void JavaParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void JavaParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any JavaParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::LiteralContext* JavaParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 102, JavaParser::RuleLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(688);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::IntegerLiteral)
      | (1ULL << JavaParser::FloatingPointLiteral)
      | (1ULL << JavaParser::BooleanLiteral)
      | (1ULL << JavaParser::CharacterLiteral)
      | (1ULL << JavaParser::StringLiteral)
      | (1ULL << JavaParser::NullLiteral))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationContext ------------------------------------------------------------------

JavaParser::AnnotationContext::AnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::AnnotationNameContext* JavaParser::AnnotationContext::annotationName() {
  return getRuleContext<JavaParser::AnnotationNameContext>(0);
}

JavaParser::ElementValuePairsContext* JavaParser::AnnotationContext::elementValuePairs() {
  return getRuleContext<JavaParser::ElementValuePairsContext>(0);
}

JavaParser::ElementValueContext* JavaParser::AnnotationContext::elementValue() {
  return getRuleContext<JavaParser::ElementValueContext>(0);
}


size_t JavaParser::AnnotationContext::getRuleIndex() const {
  return JavaParser::RuleAnnotation;
}

void JavaParser::AnnotationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotation(this);
}

void JavaParser::AnnotationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotation(this);
}


antlrcpp::Any JavaParser::AnnotationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitAnnotation(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::AnnotationContext* JavaParser::annotation() {
  AnnotationContext *_localctx = _tracker.createInstance<AnnotationContext>(_ctx, getState());
  enterRule(_localctx, 104, JavaParser::RuleAnnotation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(690);
    match(JavaParser::AT);
    setState(691);
    annotationName();
    setState(698);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::LPAREN) {
      setState(692);
      match(JavaParser::LPAREN);
      setState(695);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
      case 1: {
        setState(693);
        elementValuePairs();
        break;
      }

      case 2: {
        setState(694);
        elementValue();
        break;
      }

      }
      setState(697);
      match(JavaParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationNameContext ------------------------------------------------------------------

JavaParser::AnnotationNameContext::AnnotationNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::QualifiedNameContext* JavaParser::AnnotationNameContext::qualifiedName() {
  return getRuleContext<JavaParser::QualifiedNameContext>(0);
}


size_t JavaParser::AnnotationNameContext::getRuleIndex() const {
  return JavaParser::RuleAnnotationName;
}

void JavaParser::AnnotationNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationName(this);
}

void JavaParser::AnnotationNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationName(this);
}


antlrcpp::Any JavaParser::AnnotationNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitAnnotationName(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::AnnotationNameContext* JavaParser::annotationName() {
  AnnotationNameContext *_localctx = _tracker.createInstance<AnnotationNameContext>(_ctx, getState());
  enterRule(_localctx, 106, JavaParser::RuleAnnotationName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    qualifiedName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementValuePairsContext ------------------------------------------------------------------

JavaParser::ElementValuePairsContext::ElementValuePairsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::ElementValuePairContext *> JavaParser::ElementValuePairsContext::elementValuePair() {
  return getRuleContexts<JavaParser::ElementValuePairContext>();
}

JavaParser::ElementValuePairContext* JavaParser::ElementValuePairsContext::elementValuePair(size_t i) {
  return getRuleContext<JavaParser::ElementValuePairContext>(i);
}


size_t JavaParser::ElementValuePairsContext::getRuleIndex() const {
  return JavaParser::RuleElementValuePairs;
}

void JavaParser::ElementValuePairsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementValuePairs(this);
}

void JavaParser::ElementValuePairsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementValuePairs(this);
}


antlrcpp::Any JavaParser::ElementValuePairsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitElementValuePairs(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ElementValuePairsContext* JavaParser::elementValuePairs() {
  ElementValuePairsContext *_localctx = _tracker.createInstance<ElementValuePairsContext>(_ctx, getState());
  enterRule(_localctx, 108, JavaParser::RuleElementValuePairs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(702);
    elementValuePair();
    setState(707);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::COMMA) {
      setState(703);
      match(JavaParser::COMMA);
      setState(704);
      elementValuePair();
      setState(709);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementValuePairContext ------------------------------------------------------------------

JavaParser::ElementValuePairContext::ElementValuePairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::ElementValuePairContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::ElementValueContext* JavaParser::ElementValuePairContext::elementValue() {
  return getRuleContext<JavaParser::ElementValueContext>(0);
}


size_t JavaParser::ElementValuePairContext::getRuleIndex() const {
  return JavaParser::RuleElementValuePair;
}

void JavaParser::ElementValuePairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementValuePair(this);
}

void JavaParser::ElementValuePairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementValuePair(this);
}


antlrcpp::Any JavaParser::ElementValuePairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitElementValuePair(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ElementValuePairContext* JavaParser::elementValuePair() {
  ElementValuePairContext *_localctx = _tracker.createInstance<ElementValuePairContext>(_ctx, getState());
  enterRule(_localctx, 110, JavaParser::RuleElementValuePair);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    match(JavaParser::Identifier);
    setState(711);
    match(JavaParser::ASSIGN);
    setState(712);
    elementValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementValueContext ------------------------------------------------------------------

JavaParser::ElementValueContext::ElementValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ExpressionContext* JavaParser::ElementValueContext::expression() {
  return getRuleContext<JavaParser::ExpressionContext>(0);
}

JavaParser::AnnotationContext* JavaParser::ElementValueContext::annotation() {
  return getRuleContext<JavaParser::AnnotationContext>(0);
}

JavaParser::ElementValueArrayInitializerContext* JavaParser::ElementValueContext::elementValueArrayInitializer() {
  return getRuleContext<JavaParser::ElementValueArrayInitializerContext>(0);
}


size_t JavaParser::ElementValueContext::getRuleIndex() const {
  return JavaParser::RuleElementValue;
}

void JavaParser::ElementValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementValue(this);
}

void JavaParser::ElementValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementValue(this);
}


antlrcpp::Any JavaParser::ElementValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitElementValue(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ElementValueContext* JavaParser::elementValue() {
  ElementValueContext *_localctx = _tracker.createInstance<ElementValueContext>(_ctx, getState());
  enterRule(_localctx, 112, JavaParser::RuleElementValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(717);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::NEW:
      case JavaParser::SHORT:
      case JavaParser::SUPER:
      case JavaParser::THIS:
      case JavaParser::VOID:
      case JavaParser::IntegerLiteral:
      case JavaParser::FloatingPointLiteral:
      case JavaParser::BooleanLiteral:
      case JavaParser::CharacterLiteral:
      case JavaParser::StringLiteral:
      case JavaParser::NullLiteral:
      case JavaParser::LPAREN:
      case JavaParser::LT:
      case JavaParser::BANG:
      case JavaParser::TILDE:
      case JavaParser::INC:
      case JavaParser::DEC:
      case JavaParser::ADD:
      case JavaParser::SUB:
      case JavaParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(714);
        expression(0);
        break;
      }

      case JavaParser::AT: {
        enterOuterAlt(_localctx, 2);
        setState(715);
        annotation();
        break;
      }

      case JavaParser::LBRACE: {
        enterOuterAlt(_localctx, 3);
        setState(716);
        elementValueArrayInitializer();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementValueArrayInitializerContext ------------------------------------------------------------------

JavaParser::ElementValueArrayInitializerContext::ElementValueArrayInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::ElementValueContext *> JavaParser::ElementValueArrayInitializerContext::elementValue() {
  return getRuleContexts<JavaParser::ElementValueContext>();
}

JavaParser::ElementValueContext* JavaParser::ElementValueArrayInitializerContext::elementValue(size_t i) {
  return getRuleContext<JavaParser::ElementValueContext>(i);
}


size_t JavaParser::ElementValueArrayInitializerContext::getRuleIndex() const {
  return JavaParser::RuleElementValueArrayInitializer;
}

void JavaParser::ElementValueArrayInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementValueArrayInitializer(this);
}

void JavaParser::ElementValueArrayInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementValueArrayInitializer(this);
}


antlrcpp::Any JavaParser::ElementValueArrayInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitElementValueArrayInitializer(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ElementValueArrayInitializerContext* JavaParser::elementValueArrayInitializer() {
  ElementValueArrayInitializerContext *_localctx = _tracker.createInstance<ElementValueArrayInitializerContext>(_ctx, getState());
  enterRule(_localctx, 114, JavaParser::RuleElementValueArrayInitializer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(719);
    match(JavaParser::LBRACE);
    setState(728);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::NEW)
      | (1ULL << JavaParser::SHORT)
      | (1ULL << JavaParser::SUPER)
      | (1ULL << JavaParser::THIS)
      | (1ULL << JavaParser::VOID)
      | (1ULL << JavaParser::IntegerLiteral)
      | (1ULL << JavaParser::FloatingPointLiteral)
      | (1ULL << JavaParser::BooleanLiteral)
      | (1ULL << JavaParser::CharacterLiteral)
      | (1ULL << JavaParser::StringLiteral)
      | (1ULL << JavaParser::NullLiteral)
      | (1ULL << JavaParser::LPAREN)
      | (1ULL << JavaParser::LBRACE))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
      | (1ULL << (JavaParser::BANG - 68))
      | (1ULL << (JavaParser::TILDE - 68))
      | (1ULL << (JavaParser::INC - 68))
      | (1ULL << (JavaParser::DEC - 68))
      | (1ULL << (JavaParser::ADD - 68))
      | (1ULL << (JavaParser::SUB - 68))
      | (1ULL << (JavaParser::Identifier - 68))
      | (1ULL << (JavaParser::AT - 68)))) != 0)) {
      setState(720);
      elementValue();
      setState(725);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(721);
          match(JavaParser::COMMA);
          setState(722);
          elementValue(); 
        }
        setState(727);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      }
    }
    setState(731);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::COMMA) {
      setState(730);
      match(JavaParser::COMMA);
    }
    setState(733);
    match(JavaParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationTypeDeclarationContext ------------------------------------------------------------------

JavaParser::AnnotationTypeDeclarationContext::AnnotationTypeDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::AnnotationTypeDeclarationContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::AnnotationTypeBodyContext* JavaParser::AnnotationTypeDeclarationContext::annotationTypeBody() {
  return getRuleContext<JavaParser::AnnotationTypeBodyContext>(0);
}


size_t JavaParser::AnnotationTypeDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleAnnotationTypeDeclaration;
}

void JavaParser::AnnotationTypeDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationTypeDeclaration(this);
}

void JavaParser::AnnotationTypeDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationTypeDeclaration(this);
}


antlrcpp::Any JavaParser::AnnotationTypeDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitAnnotationTypeDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::AnnotationTypeDeclarationContext* JavaParser::annotationTypeDeclaration() {
  AnnotationTypeDeclarationContext *_localctx = _tracker.createInstance<AnnotationTypeDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 116, JavaParser::RuleAnnotationTypeDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(735);
    match(JavaParser::AT);
    setState(736);
    match(JavaParser::INTERFACE);
    setState(737);
    match(JavaParser::Identifier);
    setState(738);
    annotationTypeBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationTypeBodyContext ------------------------------------------------------------------

JavaParser::AnnotationTypeBodyContext::AnnotationTypeBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::AnnotationTypeElementDeclarationContext *> JavaParser::AnnotationTypeBodyContext::annotationTypeElementDeclaration() {
  return getRuleContexts<JavaParser::AnnotationTypeElementDeclarationContext>();
}

JavaParser::AnnotationTypeElementDeclarationContext* JavaParser::AnnotationTypeBodyContext::annotationTypeElementDeclaration(size_t i) {
  return getRuleContext<JavaParser::AnnotationTypeElementDeclarationContext>(i);
}


size_t JavaParser::AnnotationTypeBodyContext::getRuleIndex() const {
  return JavaParser::RuleAnnotationTypeBody;
}

void JavaParser::AnnotationTypeBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationTypeBody(this);
}

void JavaParser::AnnotationTypeBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationTypeBody(this);
}


antlrcpp::Any JavaParser::AnnotationTypeBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitAnnotationTypeBody(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::AnnotationTypeBodyContext* JavaParser::annotationTypeBody() {
  AnnotationTypeBodyContext *_localctx = _tracker.createInstance<AnnotationTypeBodyContext>(_ctx, getState());
  enterRule(_localctx, 118, JavaParser::RuleAnnotationTypeBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(740);
    match(JavaParser::LBRACE);
    setState(744);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
      | (1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::CLASS)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::ENUM)
      | (1ULL << JavaParser::FINAL)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::INTERFACE)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::NATIVE)
      | (1ULL << JavaParser::PRIVATE)
      | (1ULL << JavaParser::PROTECTED)
      | (1ULL << JavaParser::PUBLIC)
      | (1ULL << JavaParser::SHORT)
      | (1ULL << JavaParser::STATIC)
      | (1ULL << JavaParser::STRICTFP)
      | (1ULL << JavaParser::SYNCHRONIZED)
      | (1ULL << JavaParser::TRANSIENT)
      | (1ULL << JavaParser::VOLATILE)
      | (1ULL << JavaParser::SEMI))) != 0) || _la == JavaParser::Identifier

    || _la == JavaParser::AT) {
      setState(741);
      annotationTypeElementDeclaration();
      setState(746);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(747);
    match(JavaParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationTypeElementDeclarationContext ------------------------------------------------------------------

JavaParser::AnnotationTypeElementDeclarationContext::AnnotationTypeElementDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::AnnotationTypeElementRestContext* JavaParser::AnnotationTypeElementDeclarationContext::annotationTypeElementRest() {
  return getRuleContext<JavaParser::AnnotationTypeElementRestContext>(0);
}

std::vector<JavaParser::ModifierContext *> JavaParser::AnnotationTypeElementDeclarationContext::modifier() {
  return getRuleContexts<JavaParser::ModifierContext>();
}

JavaParser::ModifierContext* JavaParser::AnnotationTypeElementDeclarationContext::modifier(size_t i) {
  return getRuleContext<JavaParser::ModifierContext>(i);
}


size_t JavaParser::AnnotationTypeElementDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleAnnotationTypeElementDeclaration;
}

void JavaParser::AnnotationTypeElementDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationTypeElementDeclaration(this);
}

void JavaParser::AnnotationTypeElementDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationTypeElementDeclaration(this);
}


antlrcpp::Any JavaParser::AnnotationTypeElementDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitAnnotationTypeElementDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::AnnotationTypeElementDeclarationContext* JavaParser::annotationTypeElementDeclaration() {
  AnnotationTypeElementDeclarationContext *_localctx = _tracker.createInstance<AnnotationTypeElementDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 120, JavaParser::RuleAnnotationTypeElementDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(757);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::ABSTRACT:
      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::CLASS:
      case JavaParser::DOUBLE:
      case JavaParser::ENUM:
      case JavaParser::FINAL:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::INTERFACE:
      case JavaParser::LONG:
      case JavaParser::NATIVE:
      case JavaParser::PRIVATE:
      case JavaParser::PROTECTED:
      case JavaParser::PUBLIC:
      case JavaParser::SHORT:
      case JavaParser::STATIC:
      case JavaParser::STRICTFP:
      case JavaParser::SYNCHRONIZED:
      case JavaParser::TRANSIENT:
      case JavaParser::VOLATILE:
      case JavaParser::Identifier:
      case JavaParser::AT: {
        enterOuterAlt(_localctx, 1);
        setState(752);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(749);
            modifier(); 
          }
          setState(754);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
        }
        setState(755);
        annotationTypeElementRest();
        break;
      }

      case JavaParser::SEMI: {
        enterOuterAlt(_localctx, 2);
        setState(756);
        match(JavaParser::SEMI);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationTypeElementRestContext ------------------------------------------------------------------

JavaParser::AnnotationTypeElementRestContext::AnnotationTypeElementRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeTypeContext* JavaParser::AnnotationTypeElementRestContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::AnnotationMethodOrConstantRestContext* JavaParser::AnnotationTypeElementRestContext::annotationMethodOrConstantRest() {
  return getRuleContext<JavaParser::AnnotationMethodOrConstantRestContext>(0);
}

JavaParser::ClassDeclarationContext* JavaParser::AnnotationTypeElementRestContext::classDeclaration() {
  return getRuleContext<JavaParser::ClassDeclarationContext>(0);
}

JavaParser::InterfaceDeclarationContext* JavaParser::AnnotationTypeElementRestContext::interfaceDeclaration() {
  return getRuleContext<JavaParser::InterfaceDeclarationContext>(0);
}

JavaParser::EnumDeclarationContext* JavaParser::AnnotationTypeElementRestContext::enumDeclaration() {
  return getRuleContext<JavaParser::EnumDeclarationContext>(0);
}

JavaParser::AnnotationTypeDeclarationContext* JavaParser::AnnotationTypeElementRestContext::annotationTypeDeclaration() {
  return getRuleContext<JavaParser::AnnotationTypeDeclarationContext>(0);
}


size_t JavaParser::AnnotationTypeElementRestContext::getRuleIndex() const {
  return JavaParser::RuleAnnotationTypeElementRest;
}

void JavaParser::AnnotationTypeElementRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationTypeElementRest(this);
}

void JavaParser::AnnotationTypeElementRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationTypeElementRest(this);
}


antlrcpp::Any JavaParser::AnnotationTypeElementRestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitAnnotationTypeElementRest(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::AnnotationTypeElementRestContext* JavaParser::annotationTypeElementRest() {
  AnnotationTypeElementRestContext *_localctx = _tracker.createInstance<AnnotationTypeElementRestContext>(_ctx, getState());
  enterRule(_localctx, 122, JavaParser::RuleAnnotationTypeElementRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(779);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::SHORT:
      case JavaParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(759);
        typeType();
        setState(760);
        annotationMethodOrConstantRest();
        setState(761);
        match(JavaParser::SEMI);
        break;
      }

      case JavaParser::CLASS: {
        enterOuterAlt(_localctx, 2);
        setState(763);
        classDeclaration();
        setState(765);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
        case 1: {
          setState(764);
          match(JavaParser::SEMI);
          break;
        }

        }
        break;
      }

      case JavaParser::INTERFACE: {
        enterOuterAlt(_localctx, 3);
        setState(767);
        interfaceDeclaration();
        setState(769);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
        case 1: {
          setState(768);
          match(JavaParser::SEMI);
          break;
        }

        }
        break;
      }

      case JavaParser::ENUM: {
        enterOuterAlt(_localctx, 4);
        setState(771);
        enumDeclaration();
        setState(773);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
        case 1: {
          setState(772);
          match(JavaParser::SEMI);
          break;
        }

        }
        break;
      }

      case JavaParser::AT: {
        enterOuterAlt(_localctx, 5);
        setState(775);
        annotationTypeDeclaration();
        setState(777);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
        case 1: {
          setState(776);
          match(JavaParser::SEMI);
          break;
        }

        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationMethodOrConstantRestContext ------------------------------------------------------------------

JavaParser::AnnotationMethodOrConstantRestContext::AnnotationMethodOrConstantRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::AnnotationMethodRestContext* JavaParser::AnnotationMethodOrConstantRestContext::annotationMethodRest() {
  return getRuleContext<JavaParser::AnnotationMethodRestContext>(0);
}

JavaParser::AnnotationConstantRestContext* JavaParser::AnnotationMethodOrConstantRestContext::annotationConstantRest() {
  return getRuleContext<JavaParser::AnnotationConstantRestContext>(0);
}


size_t JavaParser::AnnotationMethodOrConstantRestContext::getRuleIndex() const {
  return JavaParser::RuleAnnotationMethodOrConstantRest;
}

void JavaParser::AnnotationMethodOrConstantRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationMethodOrConstantRest(this);
}

void JavaParser::AnnotationMethodOrConstantRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationMethodOrConstantRest(this);
}


antlrcpp::Any JavaParser::AnnotationMethodOrConstantRestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitAnnotationMethodOrConstantRest(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::AnnotationMethodOrConstantRestContext* JavaParser::annotationMethodOrConstantRest() {
  AnnotationMethodOrConstantRestContext *_localctx = _tracker.createInstance<AnnotationMethodOrConstantRestContext>(_ctx, getState());
  enterRule(_localctx, 124, JavaParser::RuleAnnotationMethodOrConstantRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(783);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(781);
      annotationMethodRest();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(782);
      annotationConstantRest();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationMethodRestContext ------------------------------------------------------------------

JavaParser::AnnotationMethodRestContext::AnnotationMethodRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::AnnotationMethodRestContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::DefaultValueContext* JavaParser::AnnotationMethodRestContext::defaultValue() {
  return getRuleContext<JavaParser::DefaultValueContext>(0);
}


size_t JavaParser::AnnotationMethodRestContext::getRuleIndex() const {
  return JavaParser::RuleAnnotationMethodRest;
}

void JavaParser::AnnotationMethodRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationMethodRest(this);
}

void JavaParser::AnnotationMethodRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationMethodRest(this);
}


antlrcpp::Any JavaParser::AnnotationMethodRestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitAnnotationMethodRest(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::AnnotationMethodRestContext* JavaParser::annotationMethodRest() {
  AnnotationMethodRestContext *_localctx = _tracker.createInstance<AnnotationMethodRestContext>(_ctx, getState());
  enterRule(_localctx, 126, JavaParser::RuleAnnotationMethodRest);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(785);
    match(JavaParser::Identifier);
    setState(786);
    match(JavaParser::LPAREN);
    setState(787);
    match(JavaParser::RPAREN);
    setState(789);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::DEFAULT) {
      setState(788);
      defaultValue();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationConstantRestContext ------------------------------------------------------------------

JavaParser::AnnotationConstantRestContext::AnnotationConstantRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::VariableDeclaratorsContext* JavaParser::AnnotationConstantRestContext::variableDeclarators() {
  return getRuleContext<JavaParser::VariableDeclaratorsContext>(0);
}


size_t JavaParser::AnnotationConstantRestContext::getRuleIndex() const {
  return JavaParser::RuleAnnotationConstantRest;
}

void JavaParser::AnnotationConstantRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationConstantRest(this);
}

void JavaParser::AnnotationConstantRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationConstantRest(this);
}


antlrcpp::Any JavaParser::AnnotationConstantRestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitAnnotationConstantRest(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::AnnotationConstantRestContext* JavaParser::annotationConstantRest() {
  AnnotationConstantRestContext *_localctx = _tracker.createInstance<AnnotationConstantRestContext>(_ctx, getState());
  enterRule(_localctx, 128, JavaParser::RuleAnnotationConstantRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(791);
    variableDeclarators();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefaultValueContext ------------------------------------------------------------------

JavaParser::DefaultValueContext::DefaultValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ElementValueContext* JavaParser::DefaultValueContext::elementValue() {
  return getRuleContext<JavaParser::ElementValueContext>(0);
}


size_t JavaParser::DefaultValueContext::getRuleIndex() const {
  return JavaParser::RuleDefaultValue;
}

void JavaParser::DefaultValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultValue(this);
}

void JavaParser::DefaultValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultValue(this);
}


antlrcpp::Any JavaParser::DefaultValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitDefaultValue(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::DefaultValueContext* JavaParser::defaultValue() {
  DefaultValueContext *_localctx = _tracker.createInstance<DefaultValueContext>(_ctx, getState());
  enterRule(_localctx, 130, JavaParser::RuleDefaultValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(793);
    match(JavaParser::DEFAULT);
    setState(794);
    elementValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

JavaParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::BlockStatementContext *> JavaParser::BlockContext::blockStatement() {
  return getRuleContexts<JavaParser::BlockStatementContext>();
}

JavaParser::BlockStatementContext* JavaParser::BlockContext::blockStatement(size_t i) {
  return getRuleContext<JavaParser::BlockStatementContext>(i);
}


size_t JavaParser::BlockContext::getRuleIndex() const {
  return JavaParser::RuleBlock;
}

void JavaParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void JavaParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any JavaParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::BlockContext* JavaParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 132, JavaParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(796);
    match(JavaParser::LBRACE);
    setState(800);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
      | (1ULL << JavaParser::ASSERT)
      | (1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BREAK)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::CLASS)
      | (1ULL << JavaParser::CONTINUE)
      | (1ULL << JavaParser::DO)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::ENUM)
      | (1ULL << JavaParser::FINAL)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::FOR)
      | (1ULL << JavaParser::IF)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::INTERFACE)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::NEW)
      | (1ULL << JavaParser::PRIVATE)
      | (1ULL << JavaParser::PROTECTED)
      | (1ULL << JavaParser::PUBLIC)
      | (1ULL << JavaParser::RETURN)
      | (1ULL << JavaParser::SHORT)
      | (1ULL << JavaParser::STATIC)
      | (1ULL << JavaParser::STRICTFP)
      | (1ULL << JavaParser::SUPER)
      | (1ULL << JavaParser::SWITCH)
      | (1ULL << JavaParser::SYNCHRONIZED)
      | (1ULL << JavaParser::THIS)
      | (1ULL << JavaParser::THROW)
      | (1ULL << JavaParser::TRY)
      | (1ULL << JavaParser::VOID)
      | (1ULL << JavaParser::WHILE)
      | (1ULL << JavaParser::IntegerLiteral)
      | (1ULL << JavaParser::FloatingPointLiteral)
      | (1ULL << JavaParser::BooleanLiteral)
      | (1ULL << JavaParser::CharacterLiteral)
      | (1ULL << JavaParser::StringLiteral)
      | (1ULL << JavaParser::NullLiteral)
      | (1ULL << JavaParser::LPAREN)
      | (1ULL << JavaParser::LBRACE)
      | (1ULL << JavaParser::SEMI))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
      | (1ULL << (JavaParser::BANG - 68))
      | (1ULL << (JavaParser::TILDE - 68))
      | (1ULL << (JavaParser::INC - 68))
      | (1ULL << (JavaParser::DEC - 68))
      | (1ULL << (JavaParser::ADD - 68))
      | (1ULL << (JavaParser::SUB - 68))
      | (1ULL << (JavaParser::Identifier - 68))
      | (1ULL << (JavaParser::AT - 68)))) != 0)) {
      setState(797);
      blockStatement();
      setState(802);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(803);
    match(JavaParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockStatementContext ------------------------------------------------------------------

JavaParser::BlockStatementContext::BlockStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::LocalVariableDeclarationStatementContext* JavaParser::BlockStatementContext::localVariableDeclarationStatement() {
  return getRuleContext<JavaParser::LocalVariableDeclarationStatementContext>(0);
}

JavaParser::StatementContext* JavaParser::BlockStatementContext::statement() {
  return getRuleContext<JavaParser::StatementContext>(0);
}

JavaParser::TypeDeclarationContext* JavaParser::BlockStatementContext::typeDeclaration() {
  return getRuleContext<JavaParser::TypeDeclarationContext>(0);
}


size_t JavaParser::BlockStatementContext::getRuleIndex() const {
  return JavaParser::RuleBlockStatement;
}

void JavaParser::BlockStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStatement(this);
}

void JavaParser::BlockStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStatement(this);
}


antlrcpp::Any JavaParser::BlockStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitBlockStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::BlockStatementContext* JavaParser::blockStatement() {
  BlockStatementContext *_localctx = _tracker.createInstance<BlockStatementContext>(_ctx, getState());
  enterRule(_localctx, 134, JavaParser::RuleBlockStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(808);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(805);
      localVariableDeclarationStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(806);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(807);
      typeDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalVariableDeclarationStatementContext ------------------------------------------------------------------

JavaParser::LocalVariableDeclarationStatementContext::LocalVariableDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::LocalVariableDeclarationContext* JavaParser::LocalVariableDeclarationStatementContext::localVariableDeclaration() {
  return getRuleContext<JavaParser::LocalVariableDeclarationContext>(0);
}


size_t JavaParser::LocalVariableDeclarationStatementContext::getRuleIndex() const {
  return JavaParser::RuleLocalVariableDeclarationStatement;
}

void JavaParser::LocalVariableDeclarationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalVariableDeclarationStatement(this);
}

void JavaParser::LocalVariableDeclarationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalVariableDeclarationStatement(this);
}


antlrcpp::Any JavaParser::LocalVariableDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitLocalVariableDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::LocalVariableDeclarationStatementContext* JavaParser::localVariableDeclarationStatement() {
  LocalVariableDeclarationStatementContext *_localctx = _tracker.createInstance<LocalVariableDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, JavaParser::RuleLocalVariableDeclarationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(810);
    localVariableDeclaration();
    setState(811);
    match(JavaParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalVariableDeclarationContext ------------------------------------------------------------------

JavaParser::LocalVariableDeclarationContext::LocalVariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeTypeContext* JavaParser::LocalVariableDeclarationContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::VariableDeclaratorsContext* JavaParser::LocalVariableDeclarationContext::variableDeclarators() {
  return getRuleContext<JavaParser::VariableDeclaratorsContext>(0);
}

std::vector<JavaParser::VariableModifierContext *> JavaParser::LocalVariableDeclarationContext::variableModifier() {
  return getRuleContexts<JavaParser::VariableModifierContext>();
}

JavaParser::VariableModifierContext* JavaParser::LocalVariableDeclarationContext::variableModifier(size_t i) {
  return getRuleContext<JavaParser::VariableModifierContext>(i);
}


size_t JavaParser::LocalVariableDeclarationContext::getRuleIndex() const {
  return JavaParser::RuleLocalVariableDeclaration;
}

void JavaParser::LocalVariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalVariableDeclaration(this);
}

void JavaParser::LocalVariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalVariableDeclaration(this);
}


antlrcpp::Any JavaParser::LocalVariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitLocalVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::LocalVariableDeclarationContext* JavaParser::localVariableDeclaration() {
  LocalVariableDeclarationContext *_localctx = _tracker.createInstance<LocalVariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 138, JavaParser::RuleLocalVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(816);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::FINAL || _la == JavaParser::AT) {
      setState(813);
      variableModifier();
      setState(818);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(819);
    typeType();
    setState(820);
    variableDeclarators();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

JavaParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::BlockContext* JavaParser::StatementContext::block() {
  return getRuleContext<JavaParser::BlockContext>(0);
}

tree::TerminalNode* JavaParser::StatementContext::ASSERT() {
  return getToken(JavaParser::ASSERT, 0);
}

std::vector<JavaParser::ExpressionContext *> JavaParser::StatementContext::expression() {
  return getRuleContexts<JavaParser::ExpressionContext>();
}

JavaParser::ExpressionContext* JavaParser::StatementContext::expression(size_t i) {
  return getRuleContext<JavaParser::ExpressionContext>(i);
}

JavaParser::ParExpressionContext* JavaParser::StatementContext::parExpression() {
  return getRuleContext<JavaParser::ParExpressionContext>(0);
}

std::vector<JavaParser::StatementContext *> JavaParser::StatementContext::statement() {
  return getRuleContexts<JavaParser::StatementContext>();
}

JavaParser::StatementContext* JavaParser::StatementContext::statement(size_t i) {
  return getRuleContext<JavaParser::StatementContext>(i);
}

JavaParser::ForControlContext* JavaParser::StatementContext::forControl() {
  return getRuleContext<JavaParser::ForControlContext>(0);
}

JavaParser::FinallyBlockContext* JavaParser::StatementContext::finallyBlock() {
  return getRuleContext<JavaParser::FinallyBlockContext>(0);
}

std::vector<JavaParser::CatchClauseContext *> JavaParser::StatementContext::catchClause() {
  return getRuleContexts<JavaParser::CatchClauseContext>();
}

JavaParser::CatchClauseContext* JavaParser::StatementContext::catchClause(size_t i) {
  return getRuleContext<JavaParser::CatchClauseContext>(i);
}

JavaParser::ResourceSpecificationContext* JavaParser::StatementContext::resourceSpecification() {
  return getRuleContext<JavaParser::ResourceSpecificationContext>(0);
}

std::vector<JavaParser::SwitchBlockStatementGroupContext *> JavaParser::StatementContext::switchBlockStatementGroup() {
  return getRuleContexts<JavaParser::SwitchBlockStatementGroupContext>();
}

JavaParser::SwitchBlockStatementGroupContext* JavaParser::StatementContext::switchBlockStatementGroup(size_t i) {
  return getRuleContext<JavaParser::SwitchBlockStatementGroupContext>(i);
}

std::vector<JavaParser::SwitchLabelContext *> JavaParser::StatementContext::switchLabel() {
  return getRuleContexts<JavaParser::SwitchLabelContext>();
}

JavaParser::SwitchLabelContext* JavaParser::StatementContext::switchLabel(size_t i) {
  return getRuleContext<JavaParser::SwitchLabelContext>(i);
}

tree::TerminalNode* JavaParser::StatementContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::StatementExpressionContext* JavaParser::StatementContext::statementExpression() {
  return getRuleContext<JavaParser::StatementExpressionContext>(0);
}


size_t JavaParser::StatementContext::getRuleIndex() const {
  return JavaParser::RuleStatement;
}

void JavaParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void JavaParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any JavaParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::StatementContext* JavaParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 140, JavaParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(926);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(822);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(823);
      match(JavaParser::ASSERT);
      setState(824);
      expression(0);
      setState(827);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaParser::COLON) {
        setState(825);
        match(JavaParser::COLON);
        setState(826);
        expression(0);
      }
      setState(829);
      match(JavaParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(831);
      match(JavaParser::IF);
      setState(832);
      parExpression();
      setState(833);
      statement();
      setState(836);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
      case 1: {
        setState(834);
        match(JavaParser::ELSE);
        setState(835);
        statement();
        break;
      }

      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(838);
      match(JavaParser::FOR);
      setState(839);
      match(JavaParser::LPAREN);
      setState(840);
      forControl();
      setState(841);
      match(JavaParser::RPAREN);
      setState(842);
      statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(844);
      match(JavaParser::WHILE);
      setState(845);
      parExpression();
      setState(846);
      statement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(848);
      match(JavaParser::DO);
      setState(849);
      statement();
      setState(850);
      match(JavaParser::WHILE);
      setState(851);
      parExpression();
      setState(852);
      match(JavaParser::SEMI);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(854);
      match(JavaParser::TRY);
      setState(855);
      block();
      setState(865);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case JavaParser::CATCH: {
          setState(857); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(856);
            catchClause();
            setState(859); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == JavaParser::CATCH);
          setState(862);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == JavaParser::FINALLY) {
            setState(861);
            finallyBlock();
          }
          break;
        }

        case JavaParser::FINALLY: {
          setState(864);
          finallyBlock();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(867);
      match(JavaParser::TRY);
      setState(868);
      resourceSpecification();
      setState(869);
      block();
      setState(873);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == JavaParser::CATCH) {
        setState(870);
        catchClause();
        setState(875);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(877);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaParser::FINALLY) {
        setState(876);
        finallyBlock();
      }
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(879);
      match(JavaParser::SWITCH);
      setState(880);
      parExpression();
      setState(881);
      match(JavaParser::LBRACE);
      setState(885);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(882);
          switchBlockStatementGroup(); 
        }
        setState(887);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
      }
      setState(891);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == JavaParser::CASE

      || _la == JavaParser::DEFAULT) {
        setState(888);
        switchLabel();
        setState(893);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(894);
      match(JavaParser::RBRACE);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(896);
      match(JavaParser::SYNCHRONIZED);
      setState(897);
      parExpression();
      setState(898);
      block();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(900);
      match(JavaParser::RETURN);
      setState(902);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
        | (1ULL << JavaParser::BYTE)
        | (1ULL << JavaParser::CHAR)
        | (1ULL << JavaParser::DOUBLE)
        | (1ULL << JavaParser::FLOAT)
        | (1ULL << JavaParser::INT)
        | (1ULL << JavaParser::LONG)
        | (1ULL << JavaParser::NEW)
        | (1ULL << JavaParser::SHORT)
        | (1ULL << JavaParser::SUPER)
        | (1ULL << JavaParser::THIS)
        | (1ULL << JavaParser::VOID)
        | (1ULL << JavaParser::IntegerLiteral)
        | (1ULL << JavaParser::FloatingPointLiteral)
        | (1ULL << JavaParser::BooleanLiteral)
        | (1ULL << JavaParser::CharacterLiteral)
        | (1ULL << JavaParser::StringLiteral)
        | (1ULL << JavaParser::NullLiteral)
        | (1ULL << JavaParser::LPAREN))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
        | (1ULL << (JavaParser::BANG - 68))
        | (1ULL << (JavaParser::TILDE - 68))
        | (1ULL << (JavaParser::INC - 68))
        | (1ULL << (JavaParser::DEC - 68))
        | (1ULL << (JavaParser::ADD - 68))
        | (1ULL << (JavaParser::SUB - 68))
        | (1ULL << (JavaParser::Identifier - 68)))) != 0)) {
        setState(901);
        expression(0);
      }
      setState(904);
      match(JavaParser::SEMI);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(905);
      match(JavaParser::THROW);
      setState(906);
      expression(0);
      setState(907);
      match(JavaParser::SEMI);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(909);
      match(JavaParser::BREAK);
      setState(911);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaParser::Identifier) {
        setState(910);
        match(JavaParser::Identifier);
      }
      setState(913);
      match(JavaParser::SEMI);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(914);
      match(JavaParser::CONTINUE);
      setState(916);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaParser::Identifier) {
        setState(915);
        match(JavaParser::Identifier);
      }
      setState(918);
      match(JavaParser::SEMI);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(919);
      match(JavaParser::SEMI);
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(920);
      statementExpression();
      setState(921);
      match(JavaParser::SEMI);
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(923);
      match(JavaParser::Identifier);
      setState(924);
      match(JavaParser::COLON);
      setState(925);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchClauseContext ------------------------------------------------------------------

JavaParser::CatchClauseContext::CatchClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::CatchTypeContext* JavaParser::CatchClauseContext::catchType() {
  return getRuleContext<JavaParser::CatchTypeContext>(0);
}

tree::TerminalNode* JavaParser::CatchClauseContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::BlockContext* JavaParser::CatchClauseContext::block() {
  return getRuleContext<JavaParser::BlockContext>(0);
}

std::vector<JavaParser::VariableModifierContext *> JavaParser::CatchClauseContext::variableModifier() {
  return getRuleContexts<JavaParser::VariableModifierContext>();
}

JavaParser::VariableModifierContext* JavaParser::CatchClauseContext::variableModifier(size_t i) {
  return getRuleContext<JavaParser::VariableModifierContext>(i);
}


size_t JavaParser::CatchClauseContext::getRuleIndex() const {
  return JavaParser::RuleCatchClause;
}

void JavaParser::CatchClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchClause(this);
}

void JavaParser::CatchClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchClause(this);
}


antlrcpp::Any JavaParser::CatchClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitCatchClause(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::CatchClauseContext* JavaParser::catchClause() {
  CatchClauseContext *_localctx = _tracker.createInstance<CatchClauseContext>(_ctx, getState());
  enterRule(_localctx, 142, JavaParser::RuleCatchClause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(928);
    match(JavaParser::CATCH);
    setState(929);
    match(JavaParser::LPAREN);
    setState(933);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::FINAL || _la == JavaParser::AT) {
      setState(930);
      variableModifier();
      setState(935);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(936);
    catchType();
    setState(937);
    match(JavaParser::Identifier);
    setState(938);
    match(JavaParser::RPAREN);
    setState(939);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchTypeContext ------------------------------------------------------------------

JavaParser::CatchTypeContext::CatchTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::QualifiedNameContext *> JavaParser::CatchTypeContext::qualifiedName() {
  return getRuleContexts<JavaParser::QualifiedNameContext>();
}

JavaParser::QualifiedNameContext* JavaParser::CatchTypeContext::qualifiedName(size_t i) {
  return getRuleContext<JavaParser::QualifiedNameContext>(i);
}


size_t JavaParser::CatchTypeContext::getRuleIndex() const {
  return JavaParser::RuleCatchType;
}

void JavaParser::CatchTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchType(this);
}

void JavaParser::CatchTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchType(this);
}


antlrcpp::Any JavaParser::CatchTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitCatchType(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::CatchTypeContext* JavaParser::catchType() {
  CatchTypeContext *_localctx = _tracker.createInstance<CatchTypeContext>(_ctx, getState());
  enterRule(_localctx, 144, JavaParser::RuleCatchType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(941);
    qualifiedName();
    setState(946);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::BITOR) {
      setState(942);
      match(JavaParser::BITOR);
      setState(943);
      qualifiedName();
      setState(948);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FinallyBlockContext ------------------------------------------------------------------

JavaParser::FinallyBlockContext::FinallyBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::BlockContext* JavaParser::FinallyBlockContext::block() {
  return getRuleContext<JavaParser::BlockContext>(0);
}


size_t JavaParser::FinallyBlockContext::getRuleIndex() const {
  return JavaParser::RuleFinallyBlock;
}

void JavaParser::FinallyBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFinallyBlock(this);
}

void JavaParser::FinallyBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFinallyBlock(this);
}


antlrcpp::Any JavaParser::FinallyBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitFinallyBlock(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::FinallyBlockContext* JavaParser::finallyBlock() {
  FinallyBlockContext *_localctx = _tracker.createInstance<FinallyBlockContext>(_ctx, getState());
  enterRule(_localctx, 146, JavaParser::RuleFinallyBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(949);
    match(JavaParser::FINALLY);
    setState(950);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResourceSpecificationContext ------------------------------------------------------------------

JavaParser::ResourceSpecificationContext::ResourceSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ResourcesContext* JavaParser::ResourceSpecificationContext::resources() {
  return getRuleContext<JavaParser::ResourcesContext>(0);
}


size_t JavaParser::ResourceSpecificationContext::getRuleIndex() const {
  return JavaParser::RuleResourceSpecification;
}

void JavaParser::ResourceSpecificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResourceSpecification(this);
}

void JavaParser::ResourceSpecificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResourceSpecification(this);
}


antlrcpp::Any JavaParser::ResourceSpecificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitResourceSpecification(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ResourceSpecificationContext* JavaParser::resourceSpecification() {
  ResourceSpecificationContext *_localctx = _tracker.createInstance<ResourceSpecificationContext>(_ctx, getState());
  enterRule(_localctx, 148, JavaParser::RuleResourceSpecification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(952);
    match(JavaParser::LPAREN);
    setState(953);
    resources();
    setState(955);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::SEMI) {
      setState(954);
      match(JavaParser::SEMI);
    }
    setState(957);
    match(JavaParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResourcesContext ------------------------------------------------------------------

JavaParser::ResourcesContext::ResourcesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::ResourceContext *> JavaParser::ResourcesContext::resource() {
  return getRuleContexts<JavaParser::ResourceContext>();
}

JavaParser::ResourceContext* JavaParser::ResourcesContext::resource(size_t i) {
  return getRuleContext<JavaParser::ResourceContext>(i);
}


size_t JavaParser::ResourcesContext::getRuleIndex() const {
  return JavaParser::RuleResources;
}

void JavaParser::ResourcesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResources(this);
}

void JavaParser::ResourcesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResources(this);
}


antlrcpp::Any JavaParser::ResourcesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitResources(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ResourcesContext* JavaParser::resources() {
  ResourcesContext *_localctx = _tracker.createInstance<ResourcesContext>(_ctx, getState());
  enterRule(_localctx, 150, JavaParser::RuleResources);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(959);
    resource();
    setState(964);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(960);
        match(JavaParser::SEMI);
        setState(961);
        resource(); 
      }
      setState(966);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResourceContext ------------------------------------------------------------------

JavaParser::ResourceContext::ResourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ClassOrInterfaceTypeContext* JavaParser::ResourceContext::classOrInterfaceType() {
  return getRuleContext<JavaParser::ClassOrInterfaceTypeContext>(0);
}

JavaParser::VariableDeclaratorIdContext* JavaParser::ResourceContext::variableDeclaratorId() {
  return getRuleContext<JavaParser::VariableDeclaratorIdContext>(0);
}

JavaParser::ExpressionContext* JavaParser::ResourceContext::expression() {
  return getRuleContext<JavaParser::ExpressionContext>(0);
}

std::vector<JavaParser::VariableModifierContext *> JavaParser::ResourceContext::variableModifier() {
  return getRuleContexts<JavaParser::VariableModifierContext>();
}

JavaParser::VariableModifierContext* JavaParser::ResourceContext::variableModifier(size_t i) {
  return getRuleContext<JavaParser::VariableModifierContext>(i);
}


size_t JavaParser::ResourceContext::getRuleIndex() const {
  return JavaParser::RuleResource;
}

void JavaParser::ResourceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResource(this);
}

void JavaParser::ResourceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResource(this);
}


antlrcpp::Any JavaParser::ResourceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitResource(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ResourceContext* JavaParser::resource() {
  ResourceContext *_localctx = _tracker.createInstance<ResourceContext>(_ctx, getState());
  enterRule(_localctx, 152, JavaParser::RuleResource);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(970);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::FINAL || _la == JavaParser::AT) {
      setState(967);
      variableModifier();
      setState(972);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(973);
    classOrInterfaceType();
    setState(974);
    variableDeclaratorId();
    setState(975);
    match(JavaParser::ASSIGN);
    setState(976);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchBlockStatementGroupContext ------------------------------------------------------------------

JavaParser::SwitchBlockStatementGroupContext::SwitchBlockStatementGroupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::SwitchLabelContext *> JavaParser::SwitchBlockStatementGroupContext::switchLabel() {
  return getRuleContexts<JavaParser::SwitchLabelContext>();
}

JavaParser::SwitchLabelContext* JavaParser::SwitchBlockStatementGroupContext::switchLabel(size_t i) {
  return getRuleContext<JavaParser::SwitchLabelContext>(i);
}

std::vector<JavaParser::BlockStatementContext *> JavaParser::SwitchBlockStatementGroupContext::blockStatement() {
  return getRuleContexts<JavaParser::BlockStatementContext>();
}

JavaParser::BlockStatementContext* JavaParser::SwitchBlockStatementGroupContext::blockStatement(size_t i) {
  return getRuleContext<JavaParser::BlockStatementContext>(i);
}


size_t JavaParser::SwitchBlockStatementGroupContext::getRuleIndex() const {
  return JavaParser::RuleSwitchBlockStatementGroup;
}

void JavaParser::SwitchBlockStatementGroupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchBlockStatementGroup(this);
}

void JavaParser::SwitchBlockStatementGroupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchBlockStatementGroup(this);
}


antlrcpp::Any JavaParser::SwitchBlockStatementGroupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitSwitchBlockStatementGroup(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::SwitchBlockStatementGroupContext* JavaParser::switchBlockStatementGroup() {
  SwitchBlockStatementGroupContext *_localctx = _tracker.createInstance<SwitchBlockStatementGroupContext>(_ctx, getState());
  enterRule(_localctx, 154, JavaParser::RuleSwitchBlockStatementGroup);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(979); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(978);
      switchLabel();
      setState(981); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == JavaParser::CASE

    || _la == JavaParser::DEFAULT);
    setState(984); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(983);
      blockStatement();
      setState(986); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::ABSTRACT)
      | (1ULL << JavaParser::ASSERT)
      | (1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BREAK)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::CLASS)
      | (1ULL << JavaParser::CONTINUE)
      | (1ULL << JavaParser::DO)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::ENUM)
      | (1ULL << JavaParser::FINAL)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::FOR)
      | (1ULL << JavaParser::IF)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::INTERFACE)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::NEW)
      | (1ULL << JavaParser::PRIVATE)
      | (1ULL << JavaParser::PROTECTED)
      | (1ULL << JavaParser::PUBLIC)
      | (1ULL << JavaParser::RETURN)
      | (1ULL << JavaParser::SHORT)
      | (1ULL << JavaParser::STATIC)
      | (1ULL << JavaParser::STRICTFP)
      | (1ULL << JavaParser::SUPER)
      | (1ULL << JavaParser::SWITCH)
      | (1ULL << JavaParser::SYNCHRONIZED)
      | (1ULL << JavaParser::THIS)
      | (1ULL << JavaParser::THROW)
      | (1ULL << JavaParser::TRY)
      | (1ULL << JavaParser::VOID)
      | (1ULL << JavaParser::WHILE)
      | (1ULL << JavaParser::IntegerLiteral)
      | (1ULL << JavaParser::FloatingPointLiteral)
      | (1ULL << JavaParser::BooleanLiteral)
      | (1ULL << JavaParser::CharacterLiteral)
      | (1ULL << JavaParser::StringLiteral)
      | (1ULL << JavaParser::NullLiteral)
      | (1ULL << JavaParser::LPAREN)
      | (1ULL << JavaParser::LBRACE)
      | (1ULL << JavaParser::SEMI))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
      | (1ULL << (JavaParser::BANG - 68))
      | (1ULL << (JavaParser::TILDE - 68))
      | (1ULL << (JavaParser::INC - 68))
      | (1ULL << (JavaParser::DEC - 68))
      | (1ULL << (JavaParser::ADD - 68))
      | (1ULL << (JavaParser::SUB - 68))
      | (1ULL << (JavaParser::Identifier - 68))
      | (1ULL << (JavaParser::AT - 68)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchLabelContext ------------------------------------------------------------------

JavaParser::SwitchLabelContext::SwitchLabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ConstantExpressionContext* JavaParser::SwitchLabelContext::constantExpression() {
  return getRuleContext<JavaParser::ConstantExpressionContext>(0);
}

JavaParser::EnumConstantNameContext* JavaParser::SwitchLabelContext::enumConstantName() {
  return getRuleContext<JavaParser::EnumConstantNameContext>(0);
}


size_t JavaParser::SwitchLabelContext::getRuleIndex() const {
  return JavaParser::RuleSwitchLabel;
}

void JavaParser::SwitchLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchLabel(this);
}

void JavaParser::SwitchLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchLabel(this);
}


antlrcpp::Any JavaParser::SwitchLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitSwitchLabel(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::SwitchLabelContext* JavaParser::switchLabel() {
  SwitchLabelContext *_localctx = _tracker.createInstance<SwitchLabelContext>(_ctx, getState());
  enterRule(_localctx, 156, JavaParser::RuleSwitchLabel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(998);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(988);
      match(JavaParser::CASE);
      setState(989);
      constantExpression();
      setState(990);
      match(JavaParser::COLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(992);
      match(JavaParser::CASE);
      setState(993);
      enumConstantName();
      setState(994);
      match(JavaParser::COLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(996);
      match(JavaParser::DEFAULT);
      setState(997);
      match(JavaParser::COLON);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForControlContext ------------------------------------------------------------------

JavaParser::ForControlContext::ForControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::EnhancedForControlContext* JavaParser::ForControlContext::enhancedForControl() {
  return getRuleContext<JavaParser::EnhancedForControlContext>(0);
}

JavaParser::ForInitContext* JavaParser::ForControlContext::forInit() {
  return getRuleContext<JavaParser::ForInitContext>(0);
}

JavaParser::ExpressionContext* JavaParser::ForControlContext::expression() {
  return getRuleContext<JavaParser::ExpressionContext>(0);
}

JavaParser::ForUpdateContext* JavaParser::ForControlContext::forUpdate() {
  return getRuleContext<JavaParser::ForUpdateContext>(0);
}


size_t JavaParser::ForControlContext::getRuleIndex() const {
  return JavaParser::RuleForControl;
}

void JavaParser::ForControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForControl(this);
}

void JavaParser::ForControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForControl(this);
}


antlrcpp::Any JavaParser::ForControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitForControl(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ForControlContext* JavaParser::forControl() {
  ForControlContext *_localctx = _tracker.createInstance<ForControlContext>(_ctx, getState());
  enterRule(_localctx, 158, JavaParser::RuleForControl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1012);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1000);
      enhancedForControl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1002);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
        | (1ULL << JavaParser::BYTE)
        | (1ULL << JavaParser::CHAR)
        | (1ULL << JavaParser::DOUBLE)
        | (1ULL << JavaParser::FINAL)
        | (1ULL << JavaParser::FLOAT)
        | (1ULL << JavaParser::INT)
        | (1ULL << JavaParser::LONG)
        | (1ULL << JavaParser::NEW)
        | (1ULL << JavaParser::SHORT)
        | (1ULL << JavaParser::SUPER)
        | (1ULL << JavaParser::THIS)
        | (1ULL << JavaParser::VOID)
        | (1ULL << JavaParser::IntegerLiteral)
        | (1ULL << JavaParser::FloatingPointLiteral)
        | (1ULL << JavaParser::BooleanLiteral)
        | (1ULL << JavaParser::CharacterLiteral)
        | (1ULL << JavaParser::StringLiteral)
        | (1ULL << JavaParser::NullLiteral)
        | (1ULL << JavaParser::LPAREN))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
        | (1ULL << (JavaParser::BANG - 68))
        | (1ULL << (JavaParser::TILDE - 68))
        | (1ULL << (JavaParser::INC - 68))
        | (1ULL << (JavaParser::DEC - 68))
        | (1ULL << (JavaParser::ADD - 68))
        | (1ULL << (JavaParser::SUB - 68))
        | (1ULL << (JavaParser::Identifier - 68))
        | (1ULL << (JavaParser::AT - 68)))) != 0)) {
        setState(1001);
        forInit();
      }
      setState(1004);
      match(JavaParser::SEMI);
      setState(1006);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
        | (1ULL << JavaParser::BYTE)
        | (1ULL << JavaParser::CHAR)
        | (1ULL << JavaParser::DOUBLE)
        | (1ULL << JavaParser::FLOAT)
        | (1ULL << JavaParser::INT)
        | (1ULL << JavaParser::LONG)
        | (1ULL << JavaParser::NEW)
        | (1ULL << JavaParser::SHORT)
        | (1ULL << JavaParser::SUPER)
        | (1ULL << JavaParser::THIS)
        | (1ULL << JavaParser::VOID)
        | (1ULL << JavaParser::IntegerLiteral)
        | (1ULL << JavaParser::FloatingPointLiteral)
        | (1ULL << JavaParser::BooleanLiteral)
        | (1ULL << JavaParser::CharacterLiteral)
        | (1ULL << JavaParser::StringLiteral)
        | (1ULL << JavaParser::NullLiteral)
        | (1ULL << JavaParser::LPAREN))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
        | (1ULL << (JavaParser::BANG - 68))
        | (1ULL << (JavaParser::TILDE - 68))
        | (1ULL << (JavaParser::INC - 68))
        | (1ULL << (JavaParser::DEC - 68))
        | (1ULL << (JavaParser::ADD - 68))
        | (1ULL << (JavaParser::SUB - 68))
        | (1ULL << (JavaParser::Identifier - 68)))) != 0)) {
        setState(1005);
        expression(0);
      }
      setState(1008);
      match(JavaParser::SEMI);
      setState(1010);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
        | (1ULL << JavaParser::BYTE)
        | (1ULL << JavaParser::CHAR)
        | (1ULL << JavaParser::DOUBLE)
        | (1ULL << JavaParser::FLOAT)
        | (1ULL << JavaParser::INT)
        | (1ULL << JavaParser::LONG)
        | (1ULL << JavaParser::NEW)
        | (1ULL << JavaParser::SHORT)
        | (1ULL << JavaParser::SUPER)
        | (1ULL << JavaParser::THIS)
        | (1ULL << JavaParser::VOID)
        | (1ULL << JavaParser::IntegerLiteral)
        | (1ULL << JavaParser::FloatingPointLiteral)
        | (1ULL << JavaParser::BooleanLiteral)
        | (1ULL << JavaParser::CharacterLiteral)
        | (1ULL << JavaParser::StringLiteral)
        | (1ULL << JavaParser::NullLiteral)
        | (1ULL << JavaParser::LPAREN))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
        | (1ULL << (JavaParser::BANG - 68))
        | (1ULL << (JavaParser::TILDE - 68))
        | (1ULL << (JavaParser::INC - 68))
        | (1ULL << (JavaParser::DEC - 68))
        | (1ULL << (JavaParser::ADD - 68))
        | (1ULL << (JavaParser::SUB - 68))
        | (1ULL << (JavaParser::Identifier - 68)))) != 0)) {
        setState(1009);
        forUpdate();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForInitContext ------------------------------------------------------------------

JavaParser::ForInitContext::ForInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::LocalVariableDeclarationContext* JavaParser::ForInitContext::localVariableDeclaration() {
  return getRuleContext<JavaParser::LocalVariableDeclarationContext>(0);
}

JavaParser::ExpressionListContext* JavaParser::ForInitContext::expressionList() {
  return getRuleContext<JavaParser::ExpressionListContext>(0);
}


size_t JavaParser::ForInitContext::getRuleIndex() const {
  return JavaParser::RuleForInit;
}

void JavaParser::ForInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInit(this);
}

void JavaParser::ForInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInit(this);
}


antlrcpp::Any JavaParser::ForInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitForInit(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ForInitContext* JavaParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 160, JavaParser::RuleForInit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1016);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 120, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1014);
      localVariableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1015);
      expressionList();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnhancedForControlContext ------------------------------------------------------------------

JavaParser::EnhancedForControlContext::EnhancedForControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeTypeContext* JavaParser::EnhancedForControlContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::VariableDeclaratorIdContext* JavaParser::EnhancedForControlContext::variableDeclaratorId() {
  return getRuleContext<JavaParser::VariableDeclaratorIdContext>(0);
}

JavaParser::ExpressionContext* JavaParser::EnhancedForControlContext::expression() {
  return getRuleContext<JavaParser::ExpressionContext>(0);
}

std::vector<JavaParser::VariableModifierContext *> JavaParser::EnhancedForControlContext::variableModifier() {
  return getRuleContexts<JavaParser::VariableModifierContext>();
}

JavaParser::VariableModifierContext* JavaParser::EnhancedForControlContext::variableModifier(size_t i) {
  return getRuleContext<JavaParser::VariableModifierContext>(i);
}


size_t JavaParser::EnhancedForControlContext::getRuleIndex() const {
  return JavaParser::RuleEnhancedForControl;
}

void JavaParser::EnhancedForControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnhancedForControl(this);
}

void JavaParser::EnhancedForControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnhancedForControl(this);
}


antlrcpp::Any JavaParser::EnhancedForControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitEnhancedForControl(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::EnhancedForControlContext* JavaParser::enhancedForControl() {
  EnhancedForControlContext *_localctx = _tracker.createInstance<EnhancedForControlContext>(_ctx, getState());
  enterRule(_localctx, 162, JavaParser::RuleEnhancedForControl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1021);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::FINAL || _la == JavaParser::AT) {
      setState(1018);
      variableModifier();
      setState(1023);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1024);
    typeType();
    setState(1025);
    variableDeclaratorId();
    setState(1026);
    match(JavaParser::COLON);
    setState(1027);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForUpdateContext ------------------------------------------------------------------

JavaParser::ForUpdateContext::ForUpdateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ExpressionListContext* JavaParser::ForUpdateContext::expressionList() {
  return getRuleContext<JavaParser::ExpressionListContext>(0);
}


size_t JavaParser::ForUpdateContext::getRuleIndex() const {
  return JavaParser::RuleForUpdate;
}

void JavaParser::ForUpdateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForUpdate(this);
}

void JavaParser::ForUpdateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForUpdate(this);
}


antlrcpp::Any JavaParser::ForUpdateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitForUpdate(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ForUpdateContext* JavaParser::forUpdate() {
  ForUpdateContext *_localctx = _tracker.createInstance<ForUpdateContext>(_ctx, getState());
  enterRule(_localctx, 164, JavaParser::RuleForUpdate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1029);
    expressionList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParExpressionContext ------------------------------------------------------------------

JavaParser::ParExpressionContext::ParExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ExpressionContext* JavaParser::ParExpressionContext::expression() {
  return getRuleContext<JavaParser::ExpressionContext>(0);
}


size_t JavaParser::ParExpressionContext::getRuleIndex() const {
  return JavaParser::RuleParExpression;
}

void JavaParser::ParExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParExpression(this);
}

void JavaParser::ParExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParExpression(this);
}


antlrcpp::Any JavaParser::ParExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitParExpression(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ParExpressionContext* JavaParser::parExpression() {
  ParExpressionContext *_localctx = _tracker.createInstance<ParExpressionContext>(_ctx, getState());
  enterRule(_localctx, 166, JavaParser::RuleParExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1031);
    match(JavaParser::LPAREN);
    setState(1032);
    expression(0);
    setState(1033);
    match(JavaParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

JavaParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaParser::ExpressionContext *> JavaParser::ExpressionListContext::expression() {
  return getRuleContexts<JavaParser::ExpressionContext>();
}

JavaParser::ExpressionContext* JavaParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<JavaParser::ExpressionContext>(i);
}


size_t JavaParser::ExpressionListContext::getRuleIndex() const {
  return JavaParser::RuleExpressionList;
}

void JavaParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void JavaParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}


antlrcpp::Any JavaParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ExpressionListContext* JavaParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 168, JavaParser::RuleExpressionList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1035);
    expression(0);
    setState(1040);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaParser::COMMA) {
      setState(1036);
      match(JavaParser::COMMA);
      setState(1037);
      expression(0);
      setState(1042);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementExpressionContext ------------------------------------------------------------------

JavaParser::StatementExpressionContext::StatementExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ExpressionContext* JavaParser::StatementExpressionContext::expression() {
  return getRuleContext<JavaParser::ExpressionContext>(0);
}


size_t JavaParser::StatementExpressionContext::getRuleIndex() const {
  return JavaParser::RuleStatementExpression;
}

void JavaParser::StatementExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementExpression(this);
}

void JavaParser::StatementExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementExpression(this);
}


antlrcpp::Any JavaParser::StatementExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitStatementExpression(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::StatementExpressionContext* JavaParser::statementExpression() {
  StatementExpressionContext *_localctx = _tracker.createInstance<StatementExpressionContext>(_ctx, getState());
  enterRule(_localctx, 170, JavaParser::RuleStatementExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1043);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantExpressionContext ------------------------------------------------------------------

JavaParser::ConstantExpressionContext::ConstantExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ExpressionContext* JavaParser::ConstantExpressionContext::expression() {
  return getRuleContext<JavaParser::ExpressionContext>(0);
}


size_t JavaParser::ConstantExpressionContext::getRuleIndex() const {
  return JavaParser::RuleConstantExpression;
}

void JavaParser::ConstantExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantExpression(this);
}

void JavaParser::ConstantExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantExpression(this);
}


antlrcpp::Any JavaParser::ConstantExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitConstantExpression(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ConstantExpressionContext* JavaParser::constantExpression() {
  ConstantExpressionContext *_localctx = _tracker.createInstance<ConstantExpressionContext>(_ctx, getState());
  enterRule(_localctx, 172, JavaParser::RuleConstantExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1045);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

JavaParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::PrimaryContext* JavaParser::ExpressionContext::primary() {
  return getRuleContext<JavaParser::PrimaryContext>(0);
}

JavaParser::CreatorContext* JavaParser::ExpressionContext::creator() {
  return getRuleContext<JavaParser::CreatorContext>(0);
}

JavaParser::TypeTypeContext* JavaParser::ExpressionContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

std::vector<JavaParser::ExpressionContext *> JavaParser::ExpressionContext::expression() {
  return getRuleContexts<JavaParser::ExpressionContext>();
}

JavaParser::ExpressionContext* JavaParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<JavaParser::ExpressionContext>(i);
}

tree::TerminalNode* JavaParser::ExpressionContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::InnerCreatorContext* JavaParser::ExpressionContext::innerCreator() {
  return getRuleContext<JavaParser::InnerCreatorContext>(0);
}

JavaParser::NonWildcardTypeArgumentsContext* JavaParser::ExpressionContext::nonWildcardTypeArguments() {
  return getRuleContext<JavaParser::NonWildcardTypeArgumentsContext>(0);
}

JavaParser::SuperSuffixContext* JavaParser::ExpressionContext::superSuffix() {
  return getRuleContext<JavaParser::SuperSuffixContext>(0);
}

JavaParser::ExplicitGenericInvocationContext* JavaParser::ExpressionContext::explicitGenericInvocation() {
  return getRuleContext<JavaParser::ExplicitGenericInvocationContext>(0);
}

JavaParser::ExpressionListContext* JavaParser::ExpressionContext::expressionList() {
  return getRuleContext<JavaParser::ExpressionListContext>(0);
}


size_t JavaParser::ExpressionContext::getRuleIndex() const {
  return JavaParser::RuleExpression;
}

void JavaParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void JavaParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any JavaParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


JavaParser::ExpressionContext* JavaParser::expression() {
   return expression(0);
}

JavaParser::ExpressionContext* JavaParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  JavaParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  JavaParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 174;
  enterRecursionRule(_localctx, 174, JavaParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1060);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx)) {
    case 1: {
      setState(1048);
      primary();
      break;
    }

    case 2: {
      setState(1049);
      match(JavaParser::NEW);
      setState(1050);
      creator();
      break;
    }

    case 3: {
      setState(1051);
      match(JavaParser::LPAREN);
      setState(1052);
      typeType();
      setState(1053);
      match(JavaParser::RPAREN);
      setState(1054);
      expression(17);
      break;
    }

    case 4: {
      setState(1056);
      _la = _input->LA(1);
      if (!(((((_la - 79) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 79)) & ((1ULL << (JavaParser::INC - 79))
        | (1ULL << (JavaParser::DEC - 79))
        | (1ULL << (JavaParser::ADD - 79))
        | (1ULL << (JavaParser::SUB - 79)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1057);
      expression(15);
      break;
    }

    case 5: {
      setState(1058);
      _la = _input->LA(1);
      if (!(_la == JavaParser::BANG

      || _la == JavaParser::TILDE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1059);
      expression(14);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(1147);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1145);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1062);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(1063);
          _la = _input->LA(1);
          if (!(((((_la - 83) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 83)) & ((1ULL << (JavaParser::MUL - 83))
            | (1ULL << (JavaParser::DIV - 83))
            | (1ULL << (JavaParser::MOD - 83)))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1064);
          expression(14);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1065);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(1066);
          _la = _input->LA(1);
          if (!(_la == JavaParser::ADD

          || _la == JavaParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1067);
          expression(13);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1068);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(1076);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 124, _ctx)) {
          case 1: {
            setState(1069);
            match(JavaParser::LT);
            setState(1070);
            match(JavaParser::LT);
            break;
          }

          case 2: {
            setState(1071);
            match(JavaParser::GT);
            setState(1072);
            match(JavaParser::GT);
            setState(1073);
            match(JavaParser::GT);
            break;
          }

          case 3: {
            setState(1074);
            match(JavaParser::GT);
            setState(1075);
            match(JavaParser::GT);
            break;
          }

          }
          setState(1078);
          expression(12);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1079);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(1080);
          _la = _input->LA(1);
          if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 67)) & ((1ULL << (JavaParser::GT - 67))
            | (1ULL << (JavaParser::LT - 67))
            | (1ULL << (JavaParser::LE - 67))
            | (1ULL << (JavaParser::GE - 67)))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1081);
          expression(11);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1082);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(1083);
          _la = _input->LA(1);
          if (!(_la == JavaParser::EQUAL

          || _la == JavaParser::NOTEQUAL)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1084);
          expression(9);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1085);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(1086);
          match(JavaParser::BITAND);
          setState(1087);
          expression(8);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1088);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(1089);
          match(JavaParser::CARET);
          setState(1090);
          expression(7);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1091);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(1092);
          match(JavaParser::BITOR);
          setState(1093);
          expression(6);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1094);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1095);
          match(JavaParser::AND);
          setState(1096);
          expression(5);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1097);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1098);
          match(JavaParser::OR);
          setState(1099);
          expression(4);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1100);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1101);
          match(JavaParser::QUESTION);
          setState(1102);
          expression(0);
          setState(1103);
          match(JavaParser::COLON);
          setState(1104);
          expression(3);
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1106);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1107);
          _la = _input->LA(1);
          if (!(((((_la - 66) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 66)) & ((1ULL << (JavaParser::ASSIGN - 66))
            | (1ULL << (JavaParser::ADD_ASSIGN - 66))
            | (1ULL << (JavaParser::SUB_ASSIGN - 66))
            | (1ULL << (JavaParser::MUL_ASSIGN - 66))
            | (1ULL << (JavaParser::DIV_ASSIGN - 66))
            | (1ULL << (JavaParser::AND_ASSIGN - 66))
            | (1ULL << (JavaParser::OR_ASSIGN - 66))
            | (1ULL << (JavaParser::XOR_ASSIGN - 66))
            | (1ULL << (JavaParser::MOD_ASSIGN - 66))
            | (1ULL << (JavaParser::LSHIFT_ASSIGN - 66))
            | (1ULL << (JavaParser::RSHIFT_ASSIGN - 66))
            | (1ULL << (JavaParser::URSHIFT_ASSIGN - 66)))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1108);
          expression(1);
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1109);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(1110);
          match(JavaParser::DOT);
          setState(1111);
          match(JavaParser::Identifier);
          break;
        }

        case 14: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1112);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(1113);
          match(JavaParser::DOT);
          setState(1114);
          match(JavaParser::THIS);
          break;
        }

        case 15: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1115);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(1116);
          match(JavaParser::DOT);
          setState(1117);
          match(JavaParser::NEW);
          setState(1119);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == JavaParser::LT) {
            setState(1118);
            nonWildcardTypeArguments();
          }
          setState(1121);
          innerCreator();
          break;
        }

        case 16: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1122);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(1123);
          match(JavaParser::DOT);
          setState(1124);
          match(JavaParser::SUPER);
          setState(1125);
          superSuffix();
          break;
        }

        case 17: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1126);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(1127);
          match(JavaParser::DOT);
          setState(1128);
          explicitGenericInvocation();
          break;
        }

        case 18: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1129);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(1130);
          match(JavaParser::LBRACK);
          setState(1131);
          expression(0);
          setState(1132);
          match(JavaParser::RBRACK);
          break;
        }

        case 19: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1134);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(1135);
          match(JavaParser::LPAREN);
          setState(1137);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
            | (1ULL << JavaParser::BYTE)
            | (1ULL << JavaParser::CHAR)
            | (1ULL << JavaParser::DOUBLE)
            | (1ULL << JavaParser::FLOAT)
            | (1ULL << JavaParser::INT)
            | (1ULL << JavaParser::LONG)
            | (1ULL << JavaParser::NEW)
            | (1ULL << JavaParser::SHORT)
            | (1ULL << JavaParser::SUPER)
            | (1ULL << JavaParser::THIS)
            | (1ULL << JavaParser::VOID)
            | (1ULL << JavaParser::IntegerLiteral)
            | (1ULL << JavaParser::FloatingPointLiteral)
            | (1ULL << JavaParser::BooleanLiteral)
            | (1ULL << JavaParser::CharacterLiteral)
            | (1ULL << JavaParser::StringLiteral)
            | (1ULL << JavaParser::NullLiteral)
            | (1ULL << JavaParser::LPAREN))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
            | (1ULL << (JavaParser::BANG - 68))
            | (1ULL << (JavaParser::TILDE - 68))
            | (1ULL << (JavaParser::INC - 68))
            | (1ULL << (JavaParser::DEC - 68))
            | (1ULL << (JavaParser::ADD - 68))
            | (1ULL << (JavaParser::SUB - 68))
            | (1ULL << (JavaParser::Identifier - 68)))) != 0)) {
            setState(1136);
            expressionList();
          }
          setState(1139);
          match(JavaParser::RPAREN);
          break;
        }

        case 20: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1140);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(1141);
          _la = _input->LA(1);
          if (!(_la == JavaParser::INC

          || _la == JavaParser::DEC)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case 21: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1142);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(1143);
          match(JavaParser::INSTANCEOF);
          setState(1144);
          typeType();
          break;
        }

        } 
      }
      setState(1149);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

JavaParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ExpressionContext* JavaParser::PrimaryContext::expression() {
  return getRuleContext<JavaParser::ExpressionContext>(0);
}

JavaParser::LiteralContext* JavaParser::PrimaryContext::literal() {
  return getRuleContext<JavaParser::LiteralContext>(0);
}

tree::TerminalNode* JavaParser::PrimaryContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::TypeTypeContext* JavaParser::PrimaryContext::typeType() {
  return getRuleContext<JavaParser::TypeTypeContext>(0);
}

JavaParser::NonWildcardTypeArgumentsContext* JavaParser::PrimaryContext::nonWildcardTypeArguments() {
  return getRuleContext<JavaParser::NonWildcardTypeArgumentsContext>(0);
}

JavaParser::ExplicitGenericInvocationSuffixContext* JavaParser::PrimaryContext::explicitGenericInvocationSuffix() {
  return getRuleContext<JavaParser::ExplicitGenericInvocationSuffixContext>(0);
}

JavaParser::ArgumentsContext* JavaParser::PrimaryContext::arguments() {
  return getRuleContext<JavaParser::ArgumentsContext>(0);
}


size_t JavaParser::PrimaryContext::getRuleIndex() const {
  return JavaParser::RulePrimary;
}

void JavaParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void JavaParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


antlrcpp::Any JavaParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::PrimaryContext* JavaParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 176, JavaParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1150);
      match(JavaParser::LPAREN);
      setState(1151);
      expression(0);
      setState(1152);
      match(JavaParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1154);
      match(JavaParser::THIS);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1155);
      match(JavaParser::SUPER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1156);
      literal();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1157);
      match(JavaParser::Identifier);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1158);
      typeType();
      setState(1159);
      match(JavaParser::DOT);
      setState(1160);
      match(JavaParser::CLASS);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1162);
      match(JavaParser::VOID);
      setState(1163);
      match(JavaParser::DOT);
      setState(1164);
      match(JavaParser::CLASS);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1165);
      nonWildcardTypeArguments();
      setState(1169);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case JavaParser::SUPER:
        case JavaParser::Identifier: {
          setState(1166);
          explicitGenericInvocationSuffix();
          break;
        }

        case JavaParser::THIS: {
          setState(1167);
          match(JavaParser::THIS);
          setState(1168);
          arguments();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreatorContext ------------------------------------------------------------------

JavaParser::CreatorContext::CreatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::NonWildcardTypeArgumentsContext* JavaParser::CreatorContext::nonWildcardTypeArguments() {
  return getRuleContext<JavaParser::NonWildcardTypeArgumentsContext>(0);
}

JavaParser::CreatedNameContext* JavaParser::CreatorContext::createdName() {
  return getRuleContext<JavaParser::CreatedNameContext>(0);
}

JavaParser::ClassCreatorRestContext* JavaParser::CreatorContext::classCreatorRest() {
  return getRuleContext<JavaParser::ClassCreatorRestContext>(0);
}

JavaParser::ArrayCreatorRestContext* JavaParser::CreatorContext::arrayCreatorRest() {
  return getRuleContext<JavaParser::ArrayCreatorRestContext>(0);
}


size_t JavaParser::CreatorContext::getRuleIndex() const {
  return JavaParser::RuleCreator;
}

void JavaParser::CreatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreator(this);
}

void JavaParser::CreatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreator(this);
}


antlrcpp::Any JavaParser::CreatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitCreator(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::CreatorContext* JavaParser::creator() {
  CreatorContext *_localctx = _tracker.createInstance<CreatorContext>(_ctx, getState());
  enterRule(_localctx, 178, JavaParser::RuleCreator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::LT: {
        enterOuterAlt(_localctx, 1);
        setState(1173);
        nonWildcardTypeArguments();
        setState(1174);
        createdName();
        setState(1175);
        classCreatorRest();
        break;
      }

      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::SHORT:
      case JavaParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(1177);
        createdName();
        setState(1180);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case JavaParser::LBRACK: {
            setState(1178);
            arrayCreatorRest();
            break;
          }

          case JavaParser::LPAREN: {
            setState(1179);
            classCreatorRest();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreatedNameContext ------------------------------------------------------------------

JavaParser::CreatedNameContext::CreatedNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> JavaParser::CreatedNameContext::Identifier() {
  return getTokens(JavaParser::Identifier);
}

tree::TerminalNode* JavaParser::CreatedNameContext::Identifier(size_t i) {
  return getToken(JavaParser::Identifier, i);
}

std::vector<JavaParser::TypeArgumentsOrDiamondContext *> JavaParser::CreatedNameContext::typeArgumentsOrDiamond() {
  return getRuleContexts<JavaParser::TypeArgumentsOrDiamondContext>();
}

JavaParser::TypeArgumentsOrDiamondContext* JavaParser::CreatedNameContext::typeArgumentsOrDiamond(size_t i) {
  return getRuleContext<JavaParser::TypeArgumentsOrDiamondContext>(i);
}

JavaParser::PrimitiveTypeContext* JavaParser::CreatedNameContext::primitiveType() {
  return getRuleContext<JavaParser::PrimitiveTypeContext>(0);
}


size_t JavaParser::CreatedNameContext::getRuleIndex() const {
  return JavaParser::RuleCreatedName;
}

void JavaParser::CreatedNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreatedName(this);
}

void JavaParser::CreatedNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreatedName(this);
}


antlrcpp::Any JavaParser::CreatedNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitCreatedName(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::CreatedNameContext* JavaParser::createdName() {
  CreatedNameContext *_localctx = _tracker.createInstance<CreatedNameContext>(_ctx, getState());
  enterRule(_localctx, 180, JavaParser::RuleCreatedName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1199);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(1184);
        match(JavaParser::Identifier);
        setState(1186);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == JavaParser::LT) {
          setState(1185);
          typeArgumentsOrDiamond();
        }
        setState(1195);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == JavaParser::DOT) {
          setState(1188);
          match(JavaParser::DOT);
          setState(1189);
          match(JavaParser::Identifier);
          setState(1191);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == JavaParser::LT) {
            setState(1190);
            typeArgumentsOrDiamond();
          }
          setState(1197);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::SHORT: {
        enterOuterAlt(_localctx, 2);
        setState(1198);
        primitiveType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InnerCreatorContext ------------------------------------------------------------------

JavaParser::InnerCreatorContext::InnerCreatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaParser::InnerCreatorContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::ClassCreatorRestContext* JavaParser::InnerCreatorContext::classCreatorRest() {
  return getRuleContext<JavaParser::ClassCreatorRestContext>(0);
}

JavaParser::NonWildcardTypeArgumentsOrDiamondContext* JavaParser::InnerCreatorContext::nonWildcardTypeArgumentsOrDiamond() {
  return getRuleContext<JavaParser::NonWildcardTypeArgumentsOrDiamondContext>(0);
}


size_t JavaParser::InnerCreatorContext::getRuleIndex() const {
  return JavaParser::RuleInnerCreator;
}

void JavaParser::InnerCreatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInnerCreator(this);
}

void JavaParser::InnerCreatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInnerCreator(this);
}


antlrcpp::Any JavaParser::InnerCreatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitInnerCreator(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::InnerCreatorContext* JavaParser::innerCreator() {
  InnerCreatorContext *_localctx = _tracker.createInstance<InnerCreatorContext>(_ctx, getState());
  enterRule(_localctx, 182, JavaParser::RuleInnerCreator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1201);
    match(JavaParser::Identifier);
    setState(1203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaParser::LT) {
      setState(1202);
      nonWildcardTypeArgumentsOrDiamond();
    }
    setState(1205);
    classCreatorRest();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayCreatorRestContext ------------------------------------------------------------------

JavaParser::ArrayCreatorRestContext::ArrayCreatorRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ArrayInitializerContext* JavaParser::ArrayCreatorRestContext::arrayInitializer() {
  return getRuleContext<JavaParser::ArrayInitializerContext>(0);
}

std::vector<JavaParser::ExpressionContext *> JavaParser::ArrayCreatorRestContext::expression() {
  return getRuleContexts<JavaParser::ExpressionContext>();
}

JavaParser::ExpressionContext* JavaParser::ArrayCreatorRestContext::expression(size_t i) {
  return getRuleContext<JavaParser::ExpressionContext>(i);
}


size_t JavaParser::ArrayCreatorRestContext::getRuleIndex() const {
  return JavaParser::RuleArrayCreatorRest;
}

void JavaParser::ArrayCreatorRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayCreatorRest(this);
}

void JavaParser::ArrayCreatorRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayCreatorRest(this);
}


antlrcpp::Any JavaParser::ArrayCreatorRestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitArrayCreatorRest(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ArrayCreatorRestContext* JavaParser::arrayCreatorRest() {
  ArrayCreatorRestContext *_localctx = _tracker.createInstance<ArrayCreatorRestContext>(_ctx, getState());
  enterRule(_localctx, 184, JavaParser::RuleArrayCreatorRest);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1207);
    match(JavaParser::LBRACK);
    setState(1235);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::RBRACK: {
        setState(1208);
        match(JavaParser::RBRACK);
        setState(1213);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == JavaParser::LBRACK) {
          setState(1209);
          match(JavaParser::LBRACK);
          setState(1210);
          match(JavaParser::RBRACK);
          setState(1215);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1216);
        arrayInitializer();
        break;
      }

      case JavaParser::BOOLEAN:
      case JavaParser::BYTE:
      case JavaParser::CHAR:
      case JavaParser::DOUBLE:
      case JavaParser::FLOAT:
      case JavaParser::INT:
      case JavaParser::LONG:
      case JavaParser::NEW:
      case JavaParser::SHORT:
      case JavaParser::SUPER:
      case JavaParser::THIS:
      case JavaParser::VOID:
      case JavaParser::IntegerLiteral:
      case JavaParser::FloatingPointLiteral:
      case JavaParser::BooleanLiteral:
      case JavaParser::CharacterLiteral:
      case JavaParser::StringLiteral:
      case JavaParser::NullLiteral:
      case JavaParser::LPAREN:
      case JavaParser::LT:
      case JavaParser::BANG:
      case JavaParser::TILDE:
      case JavaParser::INC:
      case JavaParser::DEC:
      case JavaParser::ADD:
      case JavaParser::SUB:
      case JavaParser::Identifier: {
        setState(1217);
        expression(0);
        setState(1218);
        match(JavaParser::RBRACK);
        setState(1225);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1219);
            match(JavaParser::LBRACK);
            setState(1220);
            expression(0);
            setState(1221);
            match(JavaParser::RBRACK); 
          }
          setState(1227);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx);
        }
        setState(1232);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 140, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1228);
            match(JavaParser::LBRACK);
            setState(1229);
            match(JavaParser::RBRACK); 
          }
          setState(1234);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 140, _ctx);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassCreatorRestContext ------------------------------------------------------------------

JavaParser::ClassCreatorRestContext::ClassCreatorRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ArgumentsContext* JavaParser::ClassCreatorRestContext::arguments() {
  return getRuleContext<JavaParser::ArgumentsContext>(0);
}

JavaParser::ClassBodyContext* JavaParser::ClassCreatorRestContext::classBody() {
  return getRuleContext<JavaParser::ClassBodyContext>(0);
}


size_t JavaParser::ClassCreatorRestContext::getRuleIndex() const {
  return JavaParser::RuleClassCreatorRest;
}

void JavaParser::ClassCreatorRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassCreatorRest(this);
}

void JavaParser::ClassCreatorRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassCreatorRest(this);
}


antlrcpp::Any JavaParser::ClassCreatorRestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitClassCreatorRest(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ClassCreatorRestContext* JavaParser::classCreatorRest() {
  ClassCreatorRestContext *_localctx = _tracker.createInstance<ClassCreatorRestContext>(_ctx, getState());
  enterRule(_localctx, 186, JavaParser::RuleClassCreatorRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1237);
    arguments();
    setState(1239);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 142, _ctx)) {
    case 1: {
      setState(1238);
      classBody();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExplicitGenericInvocationContext ------------------------------------------------------------------

JavaParser::ExplicitGenericInvocationContext::ExplicitGenericInvocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::NonWildcardTypeArgumentsContext* JavaParser::ExplicitGenericInvocationContext::nonWildcardTypeArguments() {
  return getRuleContext<JavaParser::NonWildcardTypeArgumentsContext>(0);
}

JavaParser::ExplicitGenericInvocationSuffixContext* JavaParser::ExplicitGenericInvocationContext::explicitGenericInvocationSuffix() {
  return getRuleContext<JavaParser::ExplicitGenericInvocationSuffixContext>(0);
}


size_t JavaParser::ExplicitGenericInvocationContext::getRuleIndex() const {
  return JavaParser::RuleExplicitGenericInvocation;
}

void JavaParser::ExplicitGenericInvocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplicitGenericInvocation(this);
}

void JavaParser::ExplicitGenericInvocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplicitGenericInvocation(this);
}


antlrcpp::Any JavaParser::ExplicitGenericInvocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitExplicitGenericInvocation(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ExplicitGenericInvocationContext* JavaParser::explicitGenericInvocation() {
  ExplicitGenericInvocationContext *_localctx = _tracker.createInstance<ExplicitGenericInvocationContext>(_ctx, getState());
  enterRule(_localctx, 188, JavaParser::RuleExplicitGenericInvocation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1241);
    nonWildcardTypeArguments();
    setState(1242);
    explicitGenericInvocationSuffix();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonWildcardTypeArgumentsContext ------------------------------------------------------------------

JavaParser::NonWildcardTypeArgumentsContext::NonWildcardTypeArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeListContext* JavaParser::NonWildcardTypeArgumentsContext::typeList() {
  return getRuleContext<JavaParser::TypeListContext>(0);
}


size_t JavaParser::NonWildcardTypeArgumentsContext::getRuleIndex() const {
  return JavaParser::RuleNonWildcardTypeArguments;
}

void JavaParser::NonWildcardTypeArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonWildcardTypeArguments(this);
}

void JavaParser::NonWildcardTypeArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonWildcardTypeArguments(this);
}


antlrcpp::Any JavaParser::NonWildcardTypeArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitNonWildcardTypeArguments(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::NonWildcardTypeArgumentsContext* JavaParser::nonWildcardTypeArguments() {
  NonWildcardTypeArgumentsContext *_localctx = _tracker.createInstance<NonWildcardTypeArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 190, JavaParser::RuleNonWildcardTypeArguments);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1244);
    match(JavaParser::LT);
    setState(1245);
    typeList();
    setState(1246);
    match(JavaParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeArgumentsOrDiamondContext ------------------------------------------------------------------

JavaParser::TypeArgumentsOrDiamondContext::TypeArgumentsOrDiamondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::TypeArgumentsContext* JavaParser::TypeArgumentsOrDiamondContext::typeArguments() {
  return getRuleContext<JavaParser::TypeArgumentsContext>(0);
}


size_t JavaParser::TypeArgumentsOrDiamondContext::getRuleIndex() const {
  return JavaParser::RuleTypeArgumentsOrDiamond;
}

void JavaParser::TypeArgumentsOrDiamondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeArgumentsOrDiamond(this);
}

void JavaParser::TypeArgumentsOrDiamondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeArgumentsOrDiamond(this);
}


antlrcpp::Any JavaParser::TypeArgumentsOrDiamondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitTypeArgumentsOrDiamond(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::TypeArgumentsOrDiamondContext* JavaParser::typeArgumentsOrDiamond() {
  TypeArgumentsOrDiamondContext *_localctx = _tracker.createInstance<TypeArgumentsOrDiamondContext>(_ctx, getState());
  enterRule(_localctx, 192, JavaParser::RuleTypeArgumentsOrDiamond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1251);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1248);
      match(JavaParser::LT);
      setState(1249);
      match(JavaParser::GT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1250);
      typeArguments();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonWildcardTypeArgumentsOrDiamondContext ------------------------------------------------------------------

JavaParser::NonWildcardTypeArgumentsOrDiamondContext::NonWildcardTypeArgumentsOrDiamondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::NonWildcardTypeArgumentsContext* JavaParser::NonWildcardTypeArgumentsOrDiamondContext::nonWildcardTypeArguments() {
  return getRuleContext<JavaParser::NonWildcardTypeArgumentsContext>(0);
}


size_t JavaParser::NonWildcardTypeArgumentsOrDiamondContext::getRuleIndex() const {
  return JavaParser::RuleNonWildcardTypeArgumentsOrDiamond;
}

void JavaParser::NonWildcardTypeArgumentsOrDiamondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonWildcardTypeArgumentsOrDiamond(this);
}

void JavaParser::NonWildcardTypeArgumentsOrDiamondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonWildcardTypeArgumentsOrDiamond(this);
}


antlrcpp::Any JavaParser::NonWildcardTypeArgumentsOrDiamondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitNonWildcardTypeArgumentsOrDiamond(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::NonWildcardTypeArgumentsOrDiamondContext* JavaParser::nonWildcardTypeArgumentsOrDiamond() {
  NonWildcardTypeArgumentsOrDiamondContext *_localctx = _tracker.createInstance<NonWildcardTypeArgumentsOrDiamondContext>(_ctx, getState());
  enterRule(_localctx, 194, JavaParser::RuleNonWildcardTypeArgumentsOrDiamond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1256);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1253);
      match(JavaParser::LT);
      setState(1254);
      match(JavaParser::GT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1255);
      nonWildcardTypeArguments();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuperSuffixContext ------------------------------------------------------------------

JavaParser::SuperSuffixContext::SuperSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ArgumentsContext* JavaParser::SuperSuffixContext::arguments() {
  return getRuleContext<JavaParser::ArgumentsContext>(0);
}

tree::TerminalNode* JavaParser::SuperSuffixContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}


size_t JavaParser::SuperSuffixContext::getRuleIndex() const {
  return JavaParser::RuleSuperSuffix;
}

void JavaParser::SuperSuffixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuperSuffix(this);
}

void JavaParser::SuperSuffixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuperSuffix(this);
}


antlrcpp::Any JavaParser::SuperSuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitSuperSuffix(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::SuperSuffixContext* JavaParser::superSuffix() {
  SuperSuffixContext *_localctx = _tracker.createInstance<SuperSuffixContext>(_ctx, getState());
  enterRule(_localctx, 196, JavaParser::RuleSuperSuffix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(1258);
        arguments();
        break;
      }

      case JavaParser::DOT: {
        enterOuterAlt(_localctx, 2);
        setState(1259);
        match(JavaParser::DOT);
        setState(1260);
        match(JavaParser::Identifier);
        setState(1262);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx)) {
        case 1: {
          setState(1261);
          arguments();
          break;
        }

        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExplicitGenericInvocationSuffixContext ------------------------------------------------------------------

JavaParser::ExplicitGenericInvocationSuffixContext::ExplicitGenericInvocationSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::SuperSuffixContext* JavaParser::ExplicitGenericInvocationSuffixContext::superSuffix() {
  return getRuleContext<JavaParser::SuperSuffixContext>(0);
}

tree::TerminalNode* JavaParser::ExplicitGenericInvocationSuffixContext::Identifier() {
  return getToken(JavaParser::Identifier, 0);
}

JavaParser::ArgumentsContext* JavaParser::ExplicitGenericInvocationSuffixContext::arguments() {
  return getRuleContext<JavaParser::ArgumentsContext>(0);
}


size_t JavaParser::ExplicitGenericInvocationSuffixContext::getRuleIndex() const {
  return JavaParser::RuleExplicitGenericInvocationSuffix;
}

void JavaParser::ExplicitGenericInvocationSuffixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplicitGenericInvocationSuffix(this);
}

void JavaParser::ExplicitGenericInvocationSuffixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplicitGenericInvocationSuffix(this);
}


antlrcpp::Any JavaParser::ExplicitGenericInvocationSuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitExplicitGenericInvocationSuffix(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ExplicitGenericInvocationSuffixContext* JavaParser::explicitGenericInvocationSuffix() {
  ExplicitGenericInvocationSuffixContext *_localctx = _tracker.createInstance<ExplicitGenericInvocationSuffixContext>(_ctx, getState());
  enterRule(_localctx, 198, JavaParser::RuleExplicitGenericInvocationSuffix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1270);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaParser::SUPER: {
        enterOuterAlt(_localctx, 1);
        setState(1266);
        match(JavaParser::SUPER);
        setState(1267);
        superSuffix();
        break;
      }

      case JavaParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(1268);
        match(JavaParser::Identifier);
        setState(1269);
        arguments();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

JavaParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaParser::ExpressionListContext* JavaParser::ArgumentsContext::expressionList() {
  return getRuleContext<JavaParser::ExpressionListContext>(0);
}


size_t JavaParser::ArgumentsContext::getRuleIndex() const {
  return JavaParser::RuleArguments;
}

void JavaParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void JavaParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


antlrcpp::Any JavaParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

JavaParser::ArgumentsContext* JavaParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 200, JavaParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1272);
    match(JavaParser::LPAREN);
    setState(1274);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaParser::BOOLEAN)
      | (1ULL << JavaParser::BYTE)
      | (1ULL << JavaParser::CHAR)
      | (1ULL << JavaParser::DOUBLE)
      | (1ULL << JavaParser::FLOAT)
      | (1ULL << JavaParser::INT)
      | (1ULL << JavaParser::LONG)
      | (1ULL << JavaParser::NEW)
      | (1ULL << JavaParser::SHORT)
      | (1ULL << JavaParser::SUPER)
      | (1ULL << JavaParser::THIS)
      | (1ULL << JavaParser::VOID)
      | (1ULL << JavaParser::IntegerLiteral)
      | (1ULL << JavaParser::FloatingPointLiteral)
      | (1ULL << JavaParser::BooleanLiteral)
      | (1ULL << JavaParser::CharacterLiteral)
      | (1ULL << JavaParser::StringLiteral)
      | (1ULL << JavaParser::NullLiteral)
      | (1ULL << JavaParser::LPAREN))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (JavaParser::LT - 68))
      | (1ULL << (JavaParser::BANG - 68))
      | (1ULL << (JavaParser::TILDE - 68))
      | (1ULL << (JavaParser::INC - 68))
      | (1ULL << (JavaParser::DEC - 68))
      | (1ULL << (JavaParser::ADD - 68))
      | (1ULL << (JavaParser::SUB - 68))
      | (1ULL << (JavaParser::Identifier - 68)))) != 0)) {
      setState(1273);
      expressionList();
    }
    setState(1276);
    match(JavaParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool JavaParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 87: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool JavaParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);
    case 4: return precpred(_ctx, 8);
    case 5: return precpred(_ctx, 7);
    case 6: return precpred(_ctx, 6);
    case 7: return precpred(_ctx, 5);
    case 8: return precpred(_ctx, 4);
    case 9: return precpred(_ctx, 3);
    case 10: return precpred(_ctx, 2);
    case 11: return precpred(_ctx, 1);
    case 12: return precpred(_ctx, 25);
    case 13: return precpred(_ctx, 24);
    case 14: return precpred(_ctx, 23);
    case 15: return precpred(_ctx, 22);
    case 16: return precpred(_ctx, 21);
    case 17: return precpred(_ctx, 20);
    case 18: return precpred(_ctx, 19);
    case 19: return precpred(_ctx, 16);
    case 20: return precpred(_ctx, 9);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> JavaParser::_decisionToDFA;
atn::PredictionContextCache JavaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN JavaParser::_atn;
std::vector<uint16_t> JavaParser::_serializedATN;

std::vector<std::string> JavaParser::_ruleNames = {
  "compilationUnit", "packageDeclaration", "importDeclaration", "typeDeclaration", 
  "modifier", "classOrInterfaceModifier", "variableModifier", "classDeclaration", 
  "typeParameters", "typeParameter", "typeBound", "enumDeclaration", "enumConstants", 
  "enumConstant", "enumBodyDeclarations", "interfaceDeclaration", "typeList", 
  "classBody", "interfaceBody", "classBodyDeclaration", "memberDeclaration", 
  "methodDeclaration", "genericMethodDeclaration", "constructorDeclaration", 
  "genericConstructorDeclaration", "fieldDeclaration", "interfaceBodyDeclaration", 
  "interfaceMemberDeclaration", "constDeclaration", "constantDeclarator", 
  "interfaceMethodDeclaration", "genericInterfaceMethodDeclaration", "variableDeclarators", 
  "variableDeclarator", "variableDeclaratorId", "variableInitializer", "arrayInitializer", 
  "enumConstantName", "typeType", "classOrInterfaceType", "primitiveType", 
  "typeArguments", "typeArgument", "qualifiedNameList", "formalParameters", 
  "formalParameterList", "formalParameter", "lastFormalParameter", "methodBody", 
  "constructorBody", "qualifiedName", "literal", "annotation", "annotationName", 
  "elementValuePairs", "elementValuePair", "elementValue", "elementValueArrayInitializer", 
  "annotationTypeDeclaration", "annotationTypeBody", "annotationTypeElementDeclaration", 
  "annotationTypeElementRest", "annotationMethodOrConstantRest", "annotationMethodRest", 
  "annotationConstantRest", "defaultValue", "block", "blockStatement", "localVariableDeclarationStatement", 
  "localVariableDeclaration", "statement", "catchClause", "catchType", "finallyBlock", 
  "resourceSpecification", "resources", "resource", "switchBlockStatementGroup", 
  "switchLabel", "forControl", "forInit", "enhancedForControl", "forUpdate", 
  "parExpression", "expressionList", "statementExpression", "constantExpression", 
  "expression", "primary", "creator", "createdName", "innerCreator", "arrayCreatorRest", 
  "classCreatorRest", "explicitGenericInvocation", "nonWildcardTypeArguments", 
  "typeArgumentsOrDiamond", "nonWildcardTypeArgumentsOrDiamond", "superSuffix", 
  "explicitGenericInvocationSuffix", "arguments"
};

std::vector<std::string> JavaParser::_literalNames = {
  "", "'abstract'", "'assert'", "'boolean'", "'break'", "'byte'", "'case'", 
  "'catch'", "'char'", "'class'", "'const'", "'continue'", "'default'", 
  "'do'", "'double'", "'else'", "'enum'", "'extends'", "'final'", "'finally'", 
  "'float'", "'for'", "'if'", "'goto'", "'implements'", "'import'", "'instanceof'", 
  "'int'", "'interface'", "'long'", "'native'", "'new'", "'package'", "'private'", 
  "'protected'", "'public'", "'return'", "'short'", "'static'", "'strictfp'", 
  "'super'", "'switch'", "'synchronized'", "'this'", "'throw'", "'throws'", 
  "'transient'", "'try'", "'void'", "'volatile'", "'while'", "", "", "", 
  "", "", "'null'", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", 
  "'.'", "'='", "'>'", "'<'", "'!'", "'~'", "'?'", "':'", "'=='", "'<='", 
  "'>='", "'!='", "'&&'", "'||'", "'++'", "'--'", "'+'", "'-'", "'*'", "'/'", 
  "'&'", "'|'", "'^'", "'%'", "'+='", "'-='", "'*='", "'/='", "'&='", "'|='", 
  "'^='", "'%='", "'<<='", "'>>='", "'>>>='", "", "'@'", "'...'"
};

std::vector<std::string> JavaParser::_symbolicNames = {
  "", "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK", "BYTE", "CASE", "CATCH", 
  "CHAR", "CLASS", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", 
  "ENUM", "EXTENDS", "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "GOTO", "IMPLEMENTS", 
  "IMPORT", "INSTANCEOF", "INT", "INTERFACE", "LONG", "NATIVE", "NEW", "PACKAGE", 
  "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", "SHORT", "STATIC", "STRICTFP", 
  "SUPER", "SWITCH", "SYNCHRONIZED", "THIS", "THROW", "THROWS", "TRANSIENT", 
  "TRY", "VOID", "VOLATILE", "WHILE", "IntegerLiteral", "FloatingPointLiteral", 
  "BooleanLiteral", "CharacterLiteral", "StringLiteral", "NullLiteral", 
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", 
  "DOT", "ASSIGN", "GT", "LT", "BANG", "TILDE", "QUESTION", "COLON", "EQUAL", 
  "LE", "GE", "NOTEQUAL", "AND", "OR", "INC", "DEC", "ADD", "SUB", "MUL", 
  "DIV", "BITAND", "BITOR", "CARET", "MOD", "ADD_ASSIGN", "SUB_ASSIGN", 
  "MUL_ASSIGN", "DIV_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "MOD_ASSIGN", 
  "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "URSHIFT_ASSIGN", "Identifier", "AT", 
  "ELLIPSIS", "WS", "COMMENT", "LINE_COMMENT"
};

dfa::Vocabulary JavaParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> JavaParser::_tokenNames;

JavaParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x430, 0xd6d1, 0x8206, 0xad2d, 0x4417, 0xaef1, 0x8d80, 0xaadd, 
    0x3, 0x6b, 0x501, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x4, 0x63, 
    0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 0x9, 0x65, 0x4, 0x66, 0x9, 
    0x66, 0x3, 0x2, 0x5, 0x2, 0xce, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 0xd1, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xd4, 0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0xd7, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xda, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x7, 0x3, 0xdf, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0xe2, 0xb, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xea, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xef, 0xa, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x7, 0x5, 0xf4, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0xf7, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0xfb, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0xfe, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x102, 0xa, 
    0x5, 0xc, 0x5, 0xe, 0x5, 0x105, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x109, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x10c, 0xb, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x110, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x114, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x118, 0xa, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x11c, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x121, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x125, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0x129, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x131, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0x134, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0x13b, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x140, 
    0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x143, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0x149, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0x14d, 0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0x150, 0xa, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0x153, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x7, 0xe, 0x15a, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x15d, 0xb, 0xe, 0x3, 
    0xf, 0x7, 0xf, 0x160, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x163, 0xb, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x167, 0xa, 0xf, 0x3, 0xf, 0x5, 0xf, 0x16a, 
    0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x16e, 0xa, 0x10, 0xc, 0x10, 
    0xe, 0x10, 0x171, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x176, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x17a, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x181, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x184, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x7, 0x13, 0x188, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x18b, 0xb, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x191, 0xa, 0x14, 
    0xc, 0x14, 0xe, 0x14, 0x194, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0x19a, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 
    0x19e, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x1a1, 0xb, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0x1a4, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x1af, 
    0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1b3, 0xa, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x1b9, 0xa, 0x17, 0xc, 0x17, 
    0xe, 0x17, 0x1bc, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1c0, 
    0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1c4, 0xa, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 
    0x19, 0x1cd, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x7, 
    0x1c, 0x1d9, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x1dc, 0xb, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1e0, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x1e9, 
    0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x1ef, 
    0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x1f2, 0xb, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x1f9, 0xa, 0x1f, 0xc, 0x1f, 
    0xe, 0x1f, 0x1fc, 0xb, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x203, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x7, 0x20, 0x209, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x20c, 
    0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x210, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x7, 0x22, 0x21a, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x21d, 0xb, 
    0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x222, 0xa, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x227, 0xa, 0x24, 0xc, 0x24, 
    0xe, 0x24, 0x22a, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x22e, 
    0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x234, 
    0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x237, 0xb, 0x26, 0x3, 0x26, 0x5, 0x26, 
    0x23a, 0xa, 0x26, 0x5, 0x26, 0x23c, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x245, 
    0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x248, 0xb, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x7, 0x28, 0x24d, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x250, 
    0xb, 0x28, 0x5, 0x28, 0x252, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 
    0x256, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x25b, 
    0xa, 0x29, 0x7, 0x29, 0x25d, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x260, 
    0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x7, 0x2b, 0x268, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x26b, 0xb, 
    0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x5, 0x2c, 0x273, 0xa, 0x2c, 0x5, 0x2c, 0x275, 0xa, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x27a, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
    0x27d, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x281, 0xa, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x288, 
    0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x28b, 0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x5, 0x2f, 0x28f, 0xa, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x292, 0xa, 0x2f, 
    0x3, 0x30, 0x7, 0x30, 0x295, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x298, 
    0xb, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x7, 0x31, 0x29e, 
    0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x2a1, 0xb, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x2ae, 0xa, 0x34, 0xc, 0x34, 
    0xe, 0x34, 0x2b1, 0xb, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x2ba, 0xa, 0x36, 0x3, 0x36, 
    0x5, 0x36, 0x2bd, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x7, 0x38, 0x2c4, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x2c7, 
    0xb, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x2d0, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x2d6, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 
    0x2d9, 0xb, 0x3b, 0x5, 0x3b, 0x2db, 0xa, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 
    0x2de, 0xa, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x2e9, 0xa, 0x3d, 
    0xc, 0x3d, 0xe, 0x3d, 0x2ec, 0xb, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 
    0x7, 0x3e, 0x2f1, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x2f4, 0xb, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x2f8, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x300, 0xa, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x304, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x5, 0x3f, 0x308, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x30c, 
    0xa, 0x3f, 0x5, 0x3f, 0x30e, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 
    0x312, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 
    0x318, 0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x44, 0x3, 0x44, 0x7, 0x44, 0x321, 0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 
    0x324, 0xb, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 
    0x5, 0x45, 0x32b, 0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 
    0x7, 0x47, 0x331, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x334, 0xb, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x5, 0x48, 0x33e, 0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x347, 
    0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x6, 0x48, 0x35c, 0xa, 0x48, 0xd, 0x48, 0xe, 0x48, 0x35d, 0x3, 
    0x48, 0x5, 0x48, 0x361, 0xa, 0x48, 0x3, 0x48, 0x5, 0x48, 0x364, 0xa, 
    0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 0x48, 0x36a, 
    0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x36d, 0xb, 0x48, 0x3, 0x48, 0x5, 0x48, 
    0x370, 0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 0x48, 
    0x376, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x379, 0xb, 0x48, 0x3, 0x48, 
    0x7, 0x48, 0x37c, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x37f, 0xb, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x5, 0x48, 0x389, 0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x392, 
    0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x397, 0xa, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x5, 0x48, 0x3a1, 0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x7, 0x49, 0x3a6, 0xa, 0x49, 0xc, 0x49, 0xe, 0x49, 0x3a9, 
    0xb, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 0x3b3, 0xa, 0x4a, 0xc, 0x4a, 
    0xe, 0x4a, 0x3b6, 0xb, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x3be, 0xa, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x3c5, 0xa, 0x4d, 0xc, 0x4d, 
    0xe, 0x4d, 0x3c8, 0xb, 0x4d, 0x3, 0x4e, 0x7, 0x4e, 0x3cb, 0xa, 0x4e, 
    0xc, 0x4e, 0xe, 0x4e, 0x3ce, 0xb, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x6, 0x4f, 0x3d6, 0xa, 0x4f, 0xd, 0x4f, 
    0xe, 0x4f, 0x3d7, 0x3, 0x4f, 0x6, 0x4f, 0x3db, 0xa, 0x4f, 0xd, 0x4f, 
    0xe, 0x4f, 0x3dc, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x3e9, 
    0xa, 0x50, 0x3, 0x51, 0x3, 0x51, 0x5, 0x51, 0x3ed, 0xa, 0x51, 0x3, 0x51, 
    0x3, 0x51, 0x5, 0x51, 0x3f1, 0xa, 0x51, 0x3, 0x51, 0x3, 0x51, 0x5, 0x51, 
    0x3f5, 0xa, 0x51, 0x5, 0x51, 0x3f7, 0xa, 0x51, 0x3, 0x52, 0x3, 0x52, 
    0x5, 0x52, 0x3fb, 0xa, 0x52, 0x3, 0x53, 0x7, 0x53, 0x3fe, 0xa, 0x53, 
    0xc, 0x53, 0xe, 0x53, 0x401, 0xb, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x3, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x7, 0x56, 0x411, 
    0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 0x414, 0xb, 0x56, 0x3, 0x57, 0x3, 0x57, 
    0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 0x427, 0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 
    0x437, 0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 0x462, 0xa, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 0x474, 0xa, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x7, 0x59, 0x47c, 
    0xa, 0x59, 0xc, 0x59, 0xe, 0x59, 0x47f, 0xb, 0x59, 0x3, 0x5a, 0x3, 0x5a, 
    0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 
    0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 
    0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x494, 0xa, 0x5a, 
    0x5, 0x5a, 0x496, 0xa, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 
    0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x49f, 0xa, 0x5b, 0x5, 0x5b, 
    0x4a1, 0xa, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x4a5, 0xa, 0x5c, 
    0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x4aa, 0xa, 0x5c, 0x7, 0x5c, 
    0x4ac, 0xa, 0x5c, 0xc, 0x5c, 0xe, 0x5c, 0x4af, 0xb, 0x5c, 0x3, 0x5c, 
    0x5, 0x5c, 0x4b2, 0xa, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x4b6, 
    0xa, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 
    0x5e, 0x7, 0x5e, 0x4be, 0xa, 0x5e, 0xc, 0x5e, 0xe, 0x5e, 0x4c1, 0xb, 
    0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 
    0x3, 0x5e, 0x7, 0x5e, 0x4ca, 0xa, 0x5e, 0xc, 0x5e, 0xe, 0x5e, 0x4cd, 
    0xb, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x7, 0x5e, 0x4d1, 0xa, 0x5e, 0xc, 0x5e, 
    0xe, 0x5e, 0x4d4, 0xb, 0x5e, 0x5, 0x5e, 0x4d6, 0xa, 0x5e, 0x3, 0x5f, 
    0x3, 0x5f, 0x5, 0x5f, 0x4da, 0xa, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 
    0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x62, 0x3, 0x62, 0x3, 
    0x62, 0x5, 0x62, 0x4e6, 0xa, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 
    0x5, 0x63, 0x4eb, 0xa, 0x63, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 
    0x5, 0x64, 0x4f1, 0xa, 0x64, 0x5, 0x64, 0x4f3, 0xa, 0x64, 0x3, 0x65, 
    0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x5, 0x65, 0x4f9, 0xa, 0x65, 0x3, 0x66, 
    0x3, 0x66, 0x5, 0x66, 0x4fd, 0xa, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 
    0x2, 0x3, 0xb0, 0x67, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 
    0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 
    0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 
    0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 
    0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 
    0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 
    0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0x2, 0xf, 0x6, 0x2, 
    0x20, 0x20, 0x2c, 0x2c, 0x30, 0x30, 0x33, 0x33, 0x6, 0x2, 0x3, 0x3, 
    0x14, 0x14, 0x23, 0x25, 0x28, 0x29, 0xa, 0x2, 0x5, 0x5, 0x7, 0x7, 0xa, 
    0xa, 0x10, 0x10, 0x16, 0x16, 0x1d, 0x1d, 0x1f, 0x1f, 0x27, 0x27, 0x4, 
    0x2, 0x13, 0x13, 0x2a, 0x2a, 0x3, 0x2, 0x35, 0x3a, 0x3, 0x2, 0x51, 0x54, 
    0x3, 0x2, 0x47, 0x48, 0x4, 0x2, 0x55, 0x56, 0x5a, 0x5a, 0x3, 0x2, 0x53, 
    0x54, 0x4, 0x2, 0x45, 0x46, 0x4c, 0x4d, 0x4, 0x2, 0x4b, 0x4b, 0x4e, 
    0x4e, 0x4, 0x2, 0x44, 0x44, 0x5b, 0x65, 0x3, 0x2, 0x51, 0x52, 0x573, 
    0x2, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x4, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x6, 0xe7, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x10f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x113, 0x3, 
    0x2, 0x2, 0x2, 0xc, 0x117, 0x3, 0x2, 0x2, 0x2, 0xe, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x12, 0x12c, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x137, 0x3, 0x2, 0x2, 0x2, 0x16, 0x13c, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x144, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x156, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x161, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x20, 0x172, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x24, 0x185, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1a3, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1b2, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1c8, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x34, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x1df, 0x3, 0x2, 0x2, 0x2, 0x38, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1ea, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x202, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x213, 0x3, 0x2, 0x2, 0x2, 0x42, 0x216, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x46, 0x223, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x22f, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x251, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x253, 0x3, 0x2, 0x2, 0x2, 0x52, 0x261, 0x3, 0x2, 0x2, 0x2, 0x54, 0x263, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x274, 0x3, 0x2, 0x2, 0x2, 0x58, 0x276, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x291, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x296, 0x3, 0x2, 0x2, 0x2, 0x60, 0x29f, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x64, 0x2a8, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0x2b4, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x2c0, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x72, 0x2cf, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x76, 0x2e1, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x2f7, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x311, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x313, 0x3, 0x2, 0x2, 0x2, 0x82, 0x319, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x31b, 0x3, 0x2, 0x2, 0x2, 0x86, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x88, 0x32a, 
    0x3, 0x2, 0x2, 0x2, 0x8a, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x332, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x90, 0x3a2, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x94, 0x3b7, 0x3, 0x2, 0x2, 
    0x2, 0x96, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x98, 0x3c1, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0x3e8, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x3fa, 
    0x3, 0x2, 0x2, 0x2, 0xa4, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x407, 0x3, 
    0x2, 0x2, 0x2, 0xa8, 0x409, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x40d, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0x415, 0x3, 0x2, 0x2, 0x2, 0xae, 0x417, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0x426, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x495, 0x3, 0x2, 0x2, 0x2, 
    0xb4, 0x4a0, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x4b1, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0x4b3, 0x3, 0x2, 0x2, 0x2, 0xba, 0x4b9, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x4d7, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0x4db, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x4de, 0x3, 
    0x2, 0x2, 0x2, 0xc2, 0x4e5, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x4ea, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0x4f2, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x4f8, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0x4fa, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x5, 0x4, 0x3, 0x2, 
    0xcd, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd1, 0x5, 0x6, 0x4, 0x2, 0xd0, 0xcf, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd7, 0x5, 0x8, 0x5, 
    0x2, 0xd6, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xda, 0x3, 0x2, 0x2, 0x2, 
    0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 
    0x7, 0x2, 0x2, 0x3, 0xdc, 0x3, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x5, 
    0x6a, 0x36, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xe4, 0x7, 0x22, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x66, 0x34, 0x2, 0xe5, 
    0xe6, 0x7, 0x41, 0x2, 0x2, 0xe6, 0x5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe9, 
    0x7, 0x1b, 0x2, 0x2, 0xe8, 0xea, 0x7, 0x28, 0x2, 0x2, 0xe9, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 0x2, 
    0x2, 0x2, 0xeb, 0xee, 0x5, 0x66, 0x34, 0x2, 0xec, 0xed, 0x7, 0x43, 0x2, 
    0x2, 0xed, 0xef, 0x7, 0x55, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 
    0xee, 0xef, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xf1, 0x7, 0x41, 0x2, 0x2, 0xf1, 0x7, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf4, 
    0x5, 0xc, 0x7, 0x2, 0xf3, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 0x3, 
    0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0xf8, 0x110, 0x5, 0x10, 0x9, 0x2, 0xf9, 0xfb, 0x5, 0xc, 0x7, 0x2, 
    0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xff, 
    0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xff, 0x110, 0x5, 
    0x18, 0xd, 0x2, 0x100, 0x102, 0x5, 0xc, 0x7, 0x2, 0x101, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x102, 0x105, 0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 0x106, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x103, 0x3, 0x2, 0x2, 0x2, 0x106, 0x110, 0x5, 
    0x20, 0x11, 0x2, 0x107, 0x109, 0x5, 0xc, 0x7, 0x2, 0x108, 0x107, 0x3, 
    0x2, 0x2, 0x2, 0x109, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10d, 0x3, 
    0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x5, 
    0x76, 0x3c, 0x2, 0x10e, 0x110, 0x7, 0x41, 0x2, 0x2, 0x10f, 0xf5, 0x3, 
    0x2, 0x2, 0x2, 0x10f, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x103, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x9, 0x3, 0x2, 0x2, 0x2, 0x111, 0x114, 0x5, 0xc, 0x7, 
    0x2, 0x112, 0x114, 0x9, 0x2, 0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0x112, 0x3, 0x2, 0x2, 0x2, 0x114, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x115, 0x118, 0x5, 0x6a, 0x36, 0x2, 0x116, 0x118, 0x9, 0x3, 0x2, 0x2, 
    0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x116, 0x3, 0x2, 0x2, 0x2, 
    0x118, 0xd, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11c, 0x7, 0x14, 0x2, 0x2, 0x11a, 
    0x11c, 0x5, 0x6a, 0x36, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11b, 
    0x11a, 0x3, 0x2, 0x2, 0x2, 0x11c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 
    0x7, 0xb, 0x2, 0x2, 0x11e, 0x120, 0x7, 0x66, 0x2, 0x2, 0x11f, 0x121, 
    0x5, 0x12, 0xa, 0x2, 0x120, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x121, 0x124, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 
    0x7, 0x13, 0x2, 0x2, 0x123, 0x125, 0x5, 0x4e, 0x28, 0x2, 0x124, 0x122, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x128, 
    0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 0x1a, 0x2, 0x2, 0x127, 0x129, 
    0x5, 0x22, 0x12, 0x2, 0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 
    0x5, 0x24, 0x13, 0x2, 0x12b, 0x11, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 
    0x7, 0x46, 0x2, 0x2, 0x12d, 0x132, 0x5, 0x14, 0xb, 0x2, 0x12e, 0x12f, 
    0x7, 0x42, 0x2, 0x2, 0x12f, 0x131, 0x5, 0x14, 0xb, 0x2, 0x130, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x134, 0x3, 0x2, 0x2, 0x2, 0x132, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 
    0x3, 0x2, 0x2, 0x2, 0x134, 0x132, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 
    0x7, 0x45, 0x2, 0x2, 0x136, 0x13, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 
    0x7, 0x66, 0x2, 0x2, 0x138, 0x139, 0x7, 0x13, 0x2, 0x2, 0x139, 0x13b, 
    0x5, 0x16, 0xc, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x13b, 0x15, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x141, 0x5, 
    0x4e, 0x28, 0x2, 0x13d, 0x13e, 0x7, 0x57, 0x2, 0x2, 0x13e, 0x140, 0x5, 
    0x4e, 0x28, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 
    0x2, 0x2, 0x2, 0x142, 0x17, 0x3, 0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 
    0x2, 0x2, 0x144, 0x145, 0x7, 0x12, 0x2, 0x2, 0x145, 0x148, 0x7, 0x66, 
    0x2, 0x2, 0x146, 0x147, 0x7, 0x1a, 0x2, 0x2, 0x147, 0x149, 0x5, 0x22, 
    0x12, 0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14c, 0x7, 0x3d, 
    0x2, 0x2, 0x14b, 0x14d, 0x5, 0x1a, 0xe, 0x2, 0x14c, 0x14b, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x150, 0x7, 0x42, 0x2, 0x2, 0x14f, 0x14e, 0x3, 0x2, 
    0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x152, 0x3, 0x2, 
    0x2, 0x2, 0x151, 0x153, 0x5, 0x1e, 0x10, 0x2, 0x152, 0x151, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x153, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x154, 0x155, 0x7, 0x3e, 0x2, 0x2, 0x155, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x156, 0x15b, 0x5, 0x1c, 0xf, 0x2, 0x157, 0x158, 0x7, 0x42, 
    0x2, 0x2, 0x158, 0x15a, 0x5, 0x1c, 0xf, 0x2, 0x159, 0x157, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x15d, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x160, 0x5, 0x6a, 0x36, 
    0x2, 0x15f, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x163, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x3, 0x2, 0x2, 
    0x2, 0x162, 0x164, 0x3, 0x2, 0x2, 0x2, 0x163, 0x161, 0x3, 0x2, 0x2, 
    0x2, 0x164, 0x166, 0x7, 0x66, 0x2, 0x2, 0x165, 0x167, 0x5, 0xca, 0x66, 
    0x2, 0x166, 0x165, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x169, 0x3, 0x2, 0x2, 0x2, 0x168, 0x16a, 0x5, 0x24, 0x13, 
    0x2, 0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 
    0x2, 0x16a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16f, 0x7, 0x41, 0x2, 
    0x2, 0x16c, 0x16e, 0x5, 0x28, 0x15, 0x2, 0x16d, 0x16c, 0x3, 0x2, 0x2, 
    0x2, 0x16e, 0x171, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x171, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x7, 0x1e, 0x2, 0x2, 
    0x173, 0x175, 0x7, 0x66, 0x2, 0x2, 0x174, 0x176, 0x5, 0x12, 0xa, 0x2, 
    0x175, 0x174, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x3, 0x2, 0x2, 0x2, 
    0x176, 0x179, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x7, 0x13, 0x2, 0x2, 
    0x178, 0x17a, 0x5, 0x22, 0x12, 0x2, 0x179, 0x177, 0x3, 0x2, 0x2, 0x2, 
    0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 
    0x17b, 0x17c, 0x5, 0x26, 0x14, 0x2, 0x17c, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x17d, 0x182, 0x5, 0x4e, 0x28, 0x2, 0x17e, 0x17f, 0x7, 0x42, 0x2, 0x2, 
    0x17f, 0x181, 0x5, 0x4e, 0x28, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 
    0x181, 0x184, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 0x2, 
    0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 0x23, 0x3, 0x2, 0x2, 0x2, 0x184, 
    0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x189, 0x7, 0x3d, 0x2, 0x2, 0x186, 
    0x188, 0x5, 0x28, 0x15, 0x2, 0x187, 0x186, 0x3, 0x2, 0x2, 0x2, 0x188, 
    0x18b, 0x3, 0x2, 0x2, 0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 
    0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18b, 
    0x189, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x7, 0x3e, 0x2, 0x2, 0x18d, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x192, 0x7, 0x3d, 0x2, 0x2, 0x18f, 
    0x191, 0x5, 0x36, 0x1c, 0x2, 0x190, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 
    0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 0x2, 0x192, 
    0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x195, 0x3, 0x2, 0x2, 0x2, 0x194, 
    0x192, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x7, 0x3e, 0x2, 0x2, 0x196, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x197, 0x1a4, 0x7, 0x41, 0x2, 0x2, 0x198, 
    0x19a, 0x7, 0x28, 0x2, 0x2, 0x199, 0x198, 0x3, 0x2, 0x2, 0x2, 0x199, 
    0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 
    0x1a4, 0x5, 0x86, 0x44, 0x2, 0x19c, 0x19e, 0x5, 0xa, 0x6, 0x2, 0x19d, 
    0x19c, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x19f, 
    0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 
    0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a2, 
    0x1a4, 0x5, 0x2a, 0x16, 0x2, 0x1a3, 0x197, 0x3, 0x2, 0x2, 0x2, 0x1a3, 
    0x199, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a4, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1af, 0x5, 0x2c, 0x17, 0x2, 0x1a6, 
    0x1af, 0x5, 0x2e, 0x18, 0x2, 0x1a7, 0x1af, 0x5, 0x34, 0x1b, 0x2, 0x1a8, 
    0x1af, 0x5, 0x30, 0x19, 0x2, 0x1a9, 0x1af, 0x5, 0x32, 0x1a, 0x2, 0x1aa, 
    0x1af, 0x5, 0x20, 0x11, 0x2, 0x1ab, 0x1af, 0x5, 0x76, 0x3c, 0x2, 0x1ac, 
    0x1af, 0x5, 0x10, 0x9, 0x2, 0x1ad, 0x1af, 0x5, 0x18, 0xd, 0x2, 0x1ae, 
    0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b3, 
    0x5, 0x4e, 0x28, 0x2, 0x1b1, 0x1b3, 0x7, 0x32, 0x2, 0x2, 0x1b2, 0x1b0, 
    0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 
    0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x7, 0x66, 0x2, 0x2, 0x1b5, 0x1ba, 
    0x5, 0x5a, 0x2e, 0x2, 0x1b6, 0x1b7, 0x7, 0x3f, 0x2, 0x2, 0x1b7, 0x1b9, 
    0x7, 0x40, 0x2, 0x2, 0x1b8, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1bc, 
    0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 
    0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1ba, 
    0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x7, 0x2f, 0x2, 0x2, 0x1be, 0x1c0, 
    0x5, 0x58, 0x2d, 0x2, 0x1bf, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 
    0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c4, 
    0x5, 0x62, 0x32, 0x2, 0x1c2, 0x1c4, 0x7, 0x41, 0x2, 0x2, 0x1c3, 0x1c1, 
    0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x5, 0x12, 0xa, 0x2, 0x1c6, 0x1c7, 0x5, 
    0x2c, 0x17, 0x2, 0x1c7, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x7, 
    0x66, 0x2, 0x2, 0x1c9, 0x1cc, 0x5, 0x5a, 0x2e, 0x2, 0x1ca, 0x1cb, 0x7, 
    0x2f, 0x2, 0x2, 0x1cb, 0x1cd, 0x5, 0x58, 0x2d, 0x2, 0x1cc, 0x1ca, 0x3, 
    0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x3, 
    0x2, 0x2, 0x2, 0x1ce, 0x1cf, 0x5, 0x64, 0x33, 0x2, 0x1cf, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x5, 0x12, 0xa, 0x2, 0x1d1, 0x1d2, 0x5, 
    0x30, 0x19, 0x2, 0x1d2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x5, 
    0x4e, 0x28, 0x2, 0x1d4, 0x1d5, 0x5, 0x42, 0x22, 0x2, 0x1d5, 0x1d6, 0x7, 
    0x41, 0x2, 0x2, 0x1d6, 0x35, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d9, 0x5, 
    0xa, 0x6, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1dc, 0x3, 
    0x2, 0x2, 0x2, 0x1da, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1db, 0x3, 
    0x2, 0x2, 0x2, 0x1db, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1da, 0x3, 
    0x2, 0x2, 0x2, 0x1dd, 0x1e0, 0x5, 0x38, 0x1d, 0x2, 0x1de, 0x1e0, 0x7, 
    0x41, 0x2, 0x2, 0x1df, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1de, 0x3, 
    0x2, 0x2, 0x2, 0x1e0, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e9, 0x5, 0x3a, 
    0x1e, 0x2, 0x1e2, 0x1e9, 0x5, 0x3e, 0x20, 0x2, 0x1e3, 0x1e9, 0x5, 0x40, 
    0x21, 0x2, 0x1e4, 0x1e9, 0x5, 0x20, 0x11, 0x2, 0x1e5, 0x1e9, 0x5, 0x76, 
    0x3c, 0x2, 0x1e6, 0x1e9, 0x5, 0x10, 0x9, 0x2, 0x1e7, 0x1e9, 0x5, 0x18, 
    0xd, 0x2, 0x1e8, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e2, 0x3, 0x2, 
    0x2, 0x2, 0x1e8, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e4, 0x3, 0x2, 
    0x2, 0x2, 0x1e8, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e6, 0x3, 0x2, 
    0x2, 0x2, 0x1e8, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x1ea, 0x1eb, 0x5, 0x4e, 0x28, 0x2, 0x1eb, 0x1f0, 0x5, 0x3c, 0x1f, 
    0x2, 0x1ec, 0x1ed, 0x7, 0x42, 0x2, 0x2, 0x1ed, 0x1ef, 0x5, 0x3c, 0x1f, 
    0x2, 0x1ee, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f2, 0x3, 0x2, 0x2, 
    0x2, 0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0x3, 0x2, 0x2, 
    0x2, 0x1f1, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f0, 0x3, 0x2, 0x2, 
    0x2, 0x1f3, 0x1f4, 0x7, 0x41, 0x2, 0x2, 0x1f4, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x1f5, 0x1fa, 0x7, 0x66, 0x2, 0x2, 0x1f6, 0x1f7, 0x7, 0x3f, 0x2, 
    0x2, 0x1f7, 0x1f9, 0x7, 0x40, 0x2, 0x2, 0x1f8, 0x1f6, 0x3, 0x2, 0x2, 
    0x2, 0x1f9, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1f8, 0x3, 0x2, 0x2, 
    0x2, 0x1fa, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fd, 0x3, 0x2, 0x2, 
    0x2, 0x1fc, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x7, 0x44, 0x2, 
    0x2, 0x1fe, 0x1ff, 0x5, 0x48, 0x25, 0x2, 0x1ff, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x200, 0x203, 0x5, 0x4e, 0x28, 0x2, 0x201, 0x203, 0x7, 0x32, 0x2, 
    0x2, 0x202, 0x200, 0x3, 0x2, 0x2, 0x2, 0x202, 0x201, 0x3, 0x2, 0x2, 
    0x2, 0x203, 0x204, 0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 0x7, 0x66, 0x2, 
    0x2, 0x205, 0x20a, 0x5, 0x5a, 0x2e, 0x2, 0x206, 0x207, 0x7, 0x3f, 0x2, 
    0x2, 0x207, 0x209, 0x7, 0x40, 0x2, 0x2, 0x208, 0x206, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x208, 0x3, 0x2, 0x2, 
    0x2, 0x20a, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20f, 0x3, 0x2, 0x2, 
    0x2, 0x20c, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 0x7, 0x2f, 0x2, 
    0x2, 0x20e, 0x210, 0x5, 0x58, 0x2d, 0x2, 0x20f, 0x20d, 0x3, 0x2, 0x2, 
    0x2, 0x20f, 0x210, 0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 0x3, 0x2, 0x2, 
    0x2, 0x211, 0x212, 0x7, 0x41, 0x2, 0x2, 0x212, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x213, 0x214, 0x5, 0x12, 0xa, 0x2, 0x214, 0x215, 0x5, 0x3e, 0x20, 
    0x2, 0x215, 0x41, 0x3, 0x2, 0x2, 0x2, 0x216, 0x21b, 0x5, 0x44, 0x23, 
    0x2, 0x217, 0x218, 0x7, 0x42, 0x2, 0x2, 0x218, 0x21a, 0x5, 0x44, 0x23, 
    0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21d, 0x3, 0x2, 0x2, 
    0x2, 0x21b, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x3, 0x2, 0x2, 
    0x2, 0x21c, 0x43, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 
    0x21e, 0x221, 0x5, 0x46, 0x24, 0x2, 0x21f, 0x220, 0x7, 0x44, 0x2, 0x2, 
    0x220, 0x222, 0x5, 0x48, 0x25, 0x2, 0x221, 0x21f, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x222, 0x3, 0x2, 0x2, 0x2, 0x222, 0x45, 0x3, 0x2, 0x2, 0x2, 0x223, 
    0x228, 0x7, 0x66, 0x2, 0x2, 0x224, 0x225, 0x7, 0x3f, 0x2, 0x2, 0x225, 
    0x227, 0x7, 0x40, 0x2, 0x2, 0x226, 0x224, 0x3, 0x2, 0x2, 0x2, 0x227, 
    0x22a, 0x3, 0x2, 0x2, 0x2, 0x228, 0x226, 0x3, 0x2, 0x2, 0x2, 0x228, 
    0x229, 0x3, 0x2, 0x2, 0x2, 0x229, 0x47, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x228, 
    0x3, 0x2, 0x2, 0x2, 0x22b, 0x22e, 0x5, 0x4a, 0x26, 0x2, 0x22c, 0x22e, 
    0x5, 0xb0, 0x59, 0x2, 0x22d, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22c, 
    0x3, 0x2, 0x2, 0x2, 0x22e, 0x49, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x23b, 0x7, 
    0x3d, 0x2, 0x2, 0x230, 0x235, 0x5, 0x48, 0x25, 0x2, 0x231, 0x232, 0x7, 
    0x42, 0x2, 0x2, 0x232, 0x234, 0x5, 0x48, 0x25, 0x2, 0x233, 0x231, 0x3, 
    0x2, 0x2, 0x2, 0x234, 0x237, 0x3, 0x2, 0x2, 0x2, 0x235, 0x233, 0x3, 
    0x2, 0x2, 0x2, 0x235, 0x236, 0x3, 0x2, 0x2, 0x2, 0x236, 0x239, 0x3, 
    0x2, 0x2, 0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x238, 0x23a, 0x7, 
    0x42, 0x2, 0x2, 0x239, 0x238, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x3, 
    0x2, 0x2, 0x2, 0x23a, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x230, 0x3, 
    0x2, 0x2, 0x2, 0x23b, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23d, 0x3, 
    0x2, 0x2, 0x2, 0x23d, 0x23e, 0x7, 0x3e, 0x2, 0x2, 0x23e, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x23f, 0x240, 0x7, 0x66, 0x2, 0x2, 0x240, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x241, 0x246, 0x5, 0x50, 0x29, 0x2, 0x242, 0x243, 0x7, 
    0x3f, 0x2, 0x2, 0x243, 0x245, 0x7, 0x40, 0x2, 0x2, 0x244, 0x242, 0x3, 
    0x2, 0x2, 0x2, 0x245, 0x248, 0x3, 0x2, 0x2, 0x2, 0x246, 0x244, 0x3, 
    0x2, 0x2, 0x2, 0x246, 0x247, 0x3, 0x2, 0x2, 0x2, 0x247, 0x252, 0x3, 
    0x2, 0x2, 0x2, 0x248, 0x246, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24e, 0x5, 
    0x52, 0x2a, 0x2, 0x24a, 0x24b, 0x7, 0x3f, 0x2, 0x2, 0x24b, 0x24d, 0x7, 
    0x40, 0x2, 0x2, 0x24c, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x250, 0x3, 
    0x2, 0x2, 0x2, 0x24e, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x3, 
    0x2, 0x2, 0x2, 0x24f, 0x252, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 0x3, 
    0x2, 0x2, 0x2, 0x251, 0x241, 0x3, 0x2, 0x2, 0x2, 0x251, 0x249, 0x3, 
    0x2, 0x2, 0x2, 0x252, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x253, 0x255, 0x7, 0x66, 
    0x2, 0x2, 0x254, 0x256, 0x5, 0x54, 0x2b, 0x2, 0x255, 0x254, 0x3, 0x2, 
    0x2, 0x2, 0x255, 0x256, 0x3, 0x2, 0x2, 0x2, 0x256, 0x25e, 0x3, 0x2, 
    0x2, 0x2, 0x257, 0x258, 0x7, 0x43, 0x2, 0x2, 0x258, 0x25a, 0x7, 0x66, 
    0x2, 0x2, 0x259, 0x25b, 0x5, 0x54, 0x2b, 0x2, 0x25a, 0x259, 0x3, 0x2, 
    0x2, 0x2, 0x25a, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25d, 0x3, 0x2, 
    0x2, 0x2, 0x25c, 0x257, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x260, 0x3, 0x2, 
    0x2, 0x2, 0x25e, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25f, 0x3, 0x2, 
    0x2, 0x2, 0x25f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x260, 0x25e, 0x3, 0x2, 0x2, 
    0x2, 0x261, 0x262, 0x9, 0x4, 0x2, 0x2, 0x262, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x263, 0x264, 0x7, 0x46, 0x2, 0x2, 0x264, 0x269, 0x5, 0x56, 0x2c, 0x2, 
    0x265, 0x266, 0x7, 0x42, 0x2, 0x2, 0x266, 0x268, 0x5, 0x56, 0x2c, 0x2, 
    0x267, 0x265, 0x3, 0x2, 0x2, 0x2, 0x268, 0x26b, 0x3, 0x2, 0x2, 0x2, 
    0x269, 0x267, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x3, 0x2, 0x2, 0x2, 
    0x26a, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 0x2, 
    0x26c, 0x26d, 0x7, 0x45, 0x2, 0x2, 0x26d, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x26e, 0x275, 0x5, 0x4e, 0x28, 0x2, 0x26f, 0x272, 0x7, 0x49, 0x2, 0x2, 
    0x270, 0x271, 0x9, 0x5, 0x2, 0x2, 0x271, 0x273, 0x5, 0x4e, 0x28, 0x2, 
    0x272, 0x270, 0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x275, 0x3, 0x2, 0x2, 0x2, 0x274, 0x26e, 0x3, 0x2, 0x2, 0x2, 
    0x274, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x275, 0x57, 0x3, 0x2, 0x2, 0x2, 0x276, 
    0x27b, 0x5, 0x66, 0x34, 0x2, 0x277, 0x278, 0x7, 0x42, 0x2, 0x2, 0x278, 
    0x27a, 0x5, 0x66, 0x34, 0x2, 0x279, 0x277, 0x3, 0x2, 0x2, 0x2, 0x27a, 
    0x27d, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27b, 
    0x27c, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x59, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27b, 
    0x3, 0x2, 0x2, 0x2, 0x27e, 0x280, 0x7, 0x3b, 0x2, 0x2, 0x27f, 0x281, 
    0x5, 0x5c, 0x2f, 0x2, 0x280, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x280, 0x281, 
    0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x3, 0x2, 0x2, 0x2, 0x282, 0x283, 
    0x7, 0x3c, 0x2, 0x2, 0x283, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x284, 0x289, 
    0x5, 0x5e, 0x30, 0x2, 0x285, 0x286, 0x7, 0x42, 0x2, 0x2, 0x286, 0x288, 
    0x5, 0x5e, 0x30, 0x2, 0x287, 0x285, 0x3, 0x2, 0x2, 0x2, 0x288, 0x28b, 
    0x3, 0x2, 0x2, 0x2, 0x289, 0x287, 0x3, 0x2, 0x2, 0x2, 0x289, 0x28a, 
    0x3, 0x2, 0x2, 0x2, 0x28a, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x289, 
    0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 0x7, 0x42, 0x2, 0x2, 0x28d, 0x28f, 
    0x5, 0x60, 0x31, 0x2, 0x28e, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 
    0x3, 0x2, 0x2, 0x2, 0x28f, 0x292, 0x3, 0x2, 0x2, 0x2, 0x290, 0x292, 
    0x5, 0x60, 0x31, 0x2, 0x291, 0x284, 0x3, 0x2, 0x2, 0x2, 0x291, 0x290, 
    0x3, 0x2, 0x2, 0x2, 0x292, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x293, 0x295, 0x5, 
    0xe, 0x8, 0x2, 0x294, 0x293, 0x3, 0x2, 0x2, 0x2, 0x295, 0x298, 0x3, 
    0x2, 0x2, 0x2, 0x296, 0x294, 0x3, 0x2, 0x2, 0x2, 0x296, 0x297, 0x3, 
    0x2, 0x2, 0x2, 0x297, 0x299, 0x3, 0x2, 0x2, 0x2, 0x298, 0x296, 0x3, 
    0x2, 0x2, 0x2, 0x299, 0x29a, 0x5, 0x4e, 0x28, 0x2, 0x29a, 0x29b, 0x5, 
    0x46, 0x24, 0x2, 0x29b, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29e, 0x5, 
    0xe, 0x8, 0x2, 0x29d, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x2a1, 0x3, 
    0x2, 0x2, 0x2, 0x29f, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a0, 0x3, 
    0x2, 0x2, 0x2, 0x2a0, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x29f, 0x3, 
    0x2, 0x2, 0x2, 0x2a2, 0x2a3, 0x5, 0x4e, 0x28, 0x2, 0x2a3, 0x2a4, 0x7, 
    0x68, 0x2, 0x2, 0x2a4, 0x2a5, 0x5, 0x46, 0x24, 0x2, 0x2a5, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x2a6, 0x2a7, 0x5, 0x86, 0x44, 0x2, 0x2a7, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x2a8, 0x2a9, 0x5, 0x86, 0x44, 0x2, 0x2a9, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x2aa, 0x2af, 0x7, 0x66, 0x2, 0x2, 0x2ab, 0x2ac, 0x7, 
    0x43, 0x2, 0x2, 0x2ac, 0x2ae, 0x7, 0x66, 0x2, 0x2, 0x2ad, 0x2ab, 0x3, 
    0x2, 0x2, 0x2, 0x2ae, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2ad, 0x3, 
    0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x9, 0x6, 
    0x2, 0x2, 0x2b3, 0x69, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x7, 0x67, 
    0x2, 0x2, 0x2b5, 0x2bc, 0x5, 0x6c, 0x37, 0x2, 0x2b6, 0x2b9, 0x7, 0x3b, 
    0x2, 0x2, 0x2b7, 0x2ba, 0x5, 0x6e, 0x38, 0x2, 0x2b8, 0x2ba, 0x5, 0x72, 
    0x3a, 0x2, 0x2b9, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2b8, 0x3, 0x2, 
    0x2, 0x2, 0x2b9, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 0x3, 0x2, 
    0x2, 0x2, 0x2bb, 0x2bd, 0x7, 0x3c, 0x2, 0x2, 0x2bc, 0x2b6, 0x3, 0x2, 
    0x2, 0x2, 0x2bc, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x2be, 0x2bf, 0x5, 0x66, 0x34, 0x2, 0x2bf, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x2c0, 0x2c5, 0x5, 0x70, 0x39, 0x2, 0x2c1, 0x2c2, 0x7, 0x42, 0x2, 
    0x2, 0x2c2, 0x2c4, 0x5, 0x70, 0x39, 0x2, 0x2c3, 0x2c1, 0x3, 0x2, 0x2, 
    0x2, 0x2c4, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c3, 0x3, 0x2, 0x2, 
    0x2, 0x2c5, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x2c7, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x7, 0x66, 0x2, 0x2, 
    0x2c9, 0x2ca, 0x7, 0x44, 0x2, 0x2, 0x2ca, 0x2cb, 0x5, 0x72, 0x3a, 0x2, 
    0x2cb, 0x71, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2d0, 0x5, 0xb0, 0x59, 0x2, 
    0x2cd, 0x2d0, 0x5, 0x6a, 0x36, 0x2, 0x2ce, 0x2d0, 0x5, 0x74, 0x3b, 0x2, 
    0x2cf, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2cd, 0x3, 0x2, 0x2, 0x2, 
    0x2cf, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x73, 0x3, 0x2, 0x2, 0x2, 0x2d1, 
    0x2da, 0x7, 0x3d, 0x2, 0x2, 0x2d2, 0x2d7, 0x5, 0x72, 0x3a, 0x2, 0x2d3, 
    0x2d4, 0x7, 0x42, 0x2, 0x2, 0x2d4, 0x2d6, 0x5, 0x72, 0x3a, 0x2, 0x2d5, 
    0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2d7, 
    0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d8, 
    0x2db, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2da, 
    0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2db, 
    0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2de, 0x7, 0x42, 0x2, 0x2, 0x2dd, 
    0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2de, 
    0x2df, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x7, 0x3e, 0x2, 0x2, 0x2e0, 
    0x75, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x67, 0x2, 0x2, 0x2e2, 
    0x2e3, 0x7, 0x1e, 0x2, 0x2, 0x2e3, 0x2e4, 0x7, 0x66, 0x2, 0x2, 0x2e4, 
    0x2e5, 0x5, 0x78, 0x3d, 0x2, 0x2e5, 0x77, 0x3, 0x2, 0x2, 0x2, 0x2e6, 
    0x2ea, 0x7, 0x3d, 0x2, 0x2, 0x2e7, 0x2e9, 0x5, 0x7a, 0x3e, 0x2, 0x2e8, 
    0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ea, 
    0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2eb, 
    0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ed, 
    0x2ee, 0x7, 0x3e, 0x2, 0x2, 0x2ee, 0x79, 0x3, 0x2, 0x2, 0x2, 0x2ef, 
    0x2f1, 0x5, 0xa, 0x6, 0x2, 0x2f0, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2f1, 
    0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f2, 
    0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f4, 
    0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f8, 0x5, 0x7c, 0x3f, 0x2, 0x2f6, 
    0x2f8, 0x7, 0x41, 0x2, 0x2, 0x2f7, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f7, 
    0x2f6, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fa, 
    0x5, 0x4e, 0x28, 0x2, 0x2fa, 0x2fb, 0x5, 0x7e, 0x40, 0x2, 0x2fb, 0x2fc, 
    0x7, 0x41, 0x2, 0x2, 0x2fc, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2ff, 
    0x5, 0x10, 0x9, 0x2, 0x2fe, 0x300, 0x7, 0x41, 0x2, 0x2, 0x2ff, 0x2fe, 
    0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 0x3, 0x2, 0x2, 0x2, 0x300, 0x30e, 
    0x3, 0x2, 0x2, 0x2, 0x301, 0x303, 0x5, 0x20, 0x11, 0x2, 0x302, 0x304, 
    0x7, 0x41, 0x2, 0x2, 0x303, 0x302, 0x3, 0x2, 0x2, 0x2, 0x303, 0x304, 
    0x3, 0x2, 0x2, 0x2, 0x304, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x305, 0x307, 
    0x5, 0x18, 0xd, 0x2, 0x306, 0x308, 0x7, 0x41, 0x2, 0x2, 0x307, 0x306, 
    0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 0x3, 0x2, 0x2, 0x2, 0x308, 0x30e, 
    0x3, 0x2, 0x2, 0x2, 0x309, 0x30b, 0x5, 0x76, 0x3c, 0x2, 0x30a, 0x30c, 
    0x7, 0x41, 0x2, 0x2, 0x30b, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x30c, 
    0x3, 0x2, 0x2, 0x2, 0x30c, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x2f9, 
    0x3, 0x2, 0x2, 0x2, 0x30d, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x301, 
    0x3, 0x2, 0x2, 0x2, 0x30d, 0x305, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x309, 
    0x3, 0x2, 0x2, 0x2, 0x30e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x312, 0x5, 
    0x80, 0x41, 0x2, 0x310, 0x312, 0x5, 0x82, 0x42, 0x2, 0x311, 0x30f, 0x3, 
    0x2, 0x2, 0x2, 0x311, 0x310, 0x3, 0x2, 0x2, 0x2, 0x312, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x313, 0x314, 0x7, 0x66, 0x2, 0x2, 0x314, 0x315, 0x7, 0x3b, 
    0x2, 0x2, 0x315, 0x317, 0x7, 0x3c, 0x2, 0x2, 0x316, 0x318, 0x5, 0x84, 
    0x43, 0x2, 0x317, 0x316, 0x3, 0x2, 0x2, 0x2, 0x317, 0x318, 0x3, 0x2, 
    0x2, 0x2, 0x318, 0x81, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31a, 0x5, 0x42, 
    0x22, 0x2, 0x31a, 0x83, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 0x7, 0xe, 
    0x2, 0x2, 0x31c, 0x31d, 0x5, 0x72, 0x3a, 0x2, 0x31d, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x31e, 0x322, 0x7, 0x3d, 0x2, 0x2, 0x31f, 0x321, 0x5, 0x88, 
    0x45, 0x2, 0x320, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x321, 0x324, 0x3, 0x2, 
    0x2, 0x2, 0x322, 0x320, 0x3, 0x2, 0x2, 0x2, 0x322, 0x323, 0x3, 0x2, 
    0x2, 0x2, 0x323, 0x325, 0x3, 0x2, 0x2, 0x2, 0x324, 0x322, 0x3, 0x2, 
    0x2, 0x2, 0x325, 0x326, 0x7, 0x3e, 0x2, 0x2, 0x326, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x327, 0x32b, 0x5, 0x8a, 0x46, 0x2, 0x328, 0x32b, 0x5, 0x8e, 
    0x48, 0x2, 0x329, 0x32b, 0x5, 0x8, 0x5, 0x2, 0x32a, 0x327, 0x3, 0x2, 
    0x2, 0x2, 0x32a, 0x328, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x329, 0x3, 0x2, 
    0x2, 0x2, 0x32b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32d, 0x5, 0x8c, 
    0x47, 0x2, 0x32d, 0x32e, 0x7, 0x41, 0x2, 0x2, 0x32e, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x32f, 0x331, 0x5, 0xe, 0x8, 0x2, 0x330, 0x32f, 0x3, 0x2, 
    0x2, 0x2, 0x331, 0x334, 0x3, 0x2, 0x2, 0x2, 0x332, 0x330, 0x3, 0x2, 
    0x2, 0x2, 0x332, 0x333, 0x3, 0x2, 0x2, 0x2, 0x333, 0x335, 0x3, 0x2, 
    0x2, 0x2, 0x334, 0x332, 0x3, 0x2, 0x2, 0x2, 0x335, 0x336, 0x5, 0x4e, 
    0x28, 0x2, 0x336, 0x337, 0x5, 0x42, 0x22, 0x2, 0x337, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x338, 0x3a1, 0x5, 0x86, 0x44, 0x2, 0x339, 0x33a, 0x7, 0x4, 
    0x2, 0x2, 0x33a, 0x33d, 0x5, 0xb0, 0x59, 0x2, 0x33b, 0x33c, 0x7, 0x4a, 
    0x2, 0x2, 0x33c, 0x33e, 0x5, 0xb0, 0x59, 0x2, 0x33d, 0x33b, 0x3, 0x2, 
    0x2, 0x2, 0x33d, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 0x3, 0x2, 
    0x2, 0x2, 0x33f, 0x340, 0x7, 0x41, 0x2, 0x2, 0x340, 0x3a1, 0x3, 0x2, 
    0x2, 0x2, 0x341, 0x342, 0x7, 0x18, 0x2, 0x2, 0x342, 0x343, 0x5, 0xa8, 
    0x55, 0x2, 0x343, 0x346, 0x5, 0x8e, 0x48, 0x2, 0x344, 0x345, 0x7, 0x11, 
    0x2, 0x2, 0x345, 0x347, 0x5, 0x8e, 0x48, 0x2, 0x346, 0x344, 0x3, 0x2, 
    0x2, 0x2, 0x346, 0x347, 0x3, 0x2, 0x2, 0x2, 0x347, 0x3a1, 0x3, 0x2, 
    0x2, 0x2, 0x348, 0x349, 0x7, 0x17, 0x2, 0x2, 0x349, 0x34a, 0x7, 0x3b, 
    0x2, 0x2, 0x34a, 0x34b, 0x5, 0xa0, 0x51, 0x2, 0x34b, 0x34c, 0x7, 0x3c, 
    0x2, 0x2, 0x34c, 0x34d, 0x5, 0x8e, 0x48, 0x2, 0x34d, 0x3a1, 0x3, 0x2, 
    0x2, 0x2, 0x34e, 0x34f, 0x7, 0x34, 0x2, 0x2, 0x34f, 0x350, 0x5, 0xa8, 
    0x55, 0x2, 0x350, 0x351, 0x5, 0x8e, 0x48, 0x2, 0x351, 0x3a1, 0x3, 0x2, 
    0x2, 0x2, 0x352, 0x353, 0x7, 0xf, 0x2, 0x2, 0x353, 0x354, 0x5, 0x8e, 
    0x48, 0x2, 0x354, 0x355, 0x7, 0x34, 0x2, 0x2, 0x355, 0x356, 0x5, 0xa8, 
    0x55, 0x2, 0x356, 0x357, 0x7, 0x41, 0x2, 0x2, 0x357, 0x3a1, 0x3, 0x2, 
    0x2, 0x2, 0x358, 0x359, 0x7, 0x31, 0x2, 0x2, 0x359, 0x363, 0x5, 0x86, 
    0x44, 0x2, 0x35a, 0x35c, 0x5, 0x90, 0x49, 0x2, 0x35b, 0x35a, 0x3, 0x2, 
    0x2, 0x2, 0x35c, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x35b, 0x3, 0x2, 
    0x2, 0x2, 0x35d, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x360, 0x3, 0x2, 
    0x2, 0x2, 0x35f, 0x361, 0x5, 0x94, 0x4b, 0x2, 0x360, 0x35f, 0x3, 0x2, 
    0x2, 0x2, 0x360, 0x361, 0x3, 0x2, 0x2, 0x2, 0x361, 0x364, 0x3, 0x2, 
    0x2, 0x2, 0x362, 0x364, 0x5, 0x94, 0x4b, 0x2, 0x363, 0x35b, 0x3, 0x2, 
    0x2, 0x2, 0x363, 0x362, 0x3, 0x2, 0x2, 0x2, 0x364, 0x3a1, 0x3, 0x2, 
    0x2, 0x2, 0x365, 0x366, 0x7, 0x31, 0x2, 0x2, 0x366, 0x367, 0x5, 0x96, 
    0x4c, 0x2, 0x367, 0x36b, 0x5, 0x86, 0x44, 0x2, 0x368, 0x36a, 0x5, 0x90, 
    0x49, 0x2, 0x369, 0x368, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x36d, 0x3, 0x2, 
    0x2, 0x2, 0x36b, 0x369, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36c, 0x3, 0x2, 
    0x2, 0x2, 0x36c, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36b, 0x3, 0x2, 
    0x2, 0x2, 0x36e, 0x370, 0x5, 0x94, 0x4b, 0x2, 0x36f, 0x36e, 0x3, 0x2, 
    0x2, 0x2, 0x36f, 0x370, 0x3, 0x2, 0x2, 0x2, 0x370, 0x3a1, 0x3, 0x2, 
    0x2, 0x2, 0x371, 0x372, 0x7, 0x2b, 0x2, 0x2, 0x372, 0x373, 0x5, 0xa8, 
    0x55, 0x2, 0x373, 0x377, 0x7, 0x3d, 0x2, 0x2, 0x374, 0x376, 0x5, 0x9c, 
    0x4f, 0x2, 0x375, 0x374, 0x3, 0x2, 0x2, 0x2, 0x376, 0x379, 0x3, 0x2, 
    0x2, 0x2, 0x377, 0x375, 0x3, 0x2, 0x2, 0x2, 0x377, 0x378, 0x3, 0x2, 
    0x2, 0x2, 0x378, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x379, 0x377, 0x3, 0x2, 
    0x2, 0x2, 0x37a, 0x37c, 0x5, 0x9e, 0x50, 0x2, 0x37b, 0x37a, 0x3, 0x2, 
    0x2, 0x2, 0x37c, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x37b, 0x3, 0x2, 
    0x2, 0x2, 0x37d, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x380, 0x3, 0x2, 
    0x2, 0x2, 0x37f, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x380, 0x381, 0x7, 0x3e, 
    0x2, 0x2, 0x381, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x382, 0x383, 0x7, 0x2c, 
    0x2, 0x2, 0x383, 0x384, 0x5, 0xa8, 0x55, 0x2, 0x384, 0x385, 0x5, 0x86, 
    0x44, 0x2, 0x385, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x386, 0x388, 0x7, 0x26, 
    0x2, 0x2, 0x387, 0x389, 0x5, 0xb0, 0x59, 0x2, 0x388, 0x387, 0x3, 0x2, 
    0x2, 0x2, 0x388, 0x389, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38a, 0x3, 0x2, 
    0x2, 0x2, 0x38a, 0x3a1, 0x7, 0x41, 0x2, 0x2, 0x38b, 0x38c, 0x7, 0x2e, 
    0x2, 0x2, 0x38c, 0x38d, 0x5, 0xb0, 0x59, 0x2, 0x38d, 0x38e, 0x7, 0x41, 
    0x2, 0x2, 0x38e, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x391, 0x7, 0x6, 
    0x2, 0x2, 0x390, 0x392, 0x7, 0x66, 0x2, 0x2, 0x391, 0x390, 0x3, 0x2, 
    0x2, 0x2, 0x391, 0x392, 0x3, 0x2, 0x2, 0x2, 0x392, 0x393, 0x3, 0x2, 
    0x2, 0x2, 0x393, 0x3a1, 0x7, 0x41, 0x2, 0x2, 0x394, 0x396, 0x7, 0xd, 
    0x2, 0x2, 0x395, 0x397, 0x7, 0x66, 0x2, 0x2, 0x396, 0x395, 0x3, 0x2, 
    0x2, 0x2, 0x396, 0x397, 0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 0x3, 0x2, 
    0x2, 0x2, 0x398, 0x3a1, 0x7, 0x41, 0x2, 0x2, 0x399, 0x3a1, 0x7, 0x41, 
    0x2, 0x2, 0x39a, 0x39b, 0x5, 0xac, 0x57, 0x2, 0x39b, 0x39c, 0x7, 0x41, 
    0x2, 0x2, 0x39c, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x7, 0x66, 
    0x2, 0x2, 0x39e, 0x39f, 0x7, 0x4a, 0x2, 0x2, 0x39f, 0x3a1, 0x5, 0x8e, 
    0x48, 0x2, 0x3a0, 0x338, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x339, 0x3, 0x2, 
    0x2, 0x2, 0x3a0, 0x341, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x348, 0x3, 0x2, 
    0x2, 0x2, 0x3a0, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x352, 0x3, 0x2, 
    0x2, 0x2, 0x3a0, 0x358, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x365, 0x3, 0x2, 
    0x2, 0x2, 0x3a0, 0x371, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x382, 0x3, 0x2, 
    0x2, 0x2, 0x3a0, 0x386, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x38b, 0x3, 0x2, 
    0x2, 0x2, 0x3a0, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x394, 0x3, 0x2, 
    0x2, 0x2, 0x3a0, 0x399, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x39a, 0x3, 0x2, 
    0x2, 0x2, 0x3a0, 0x39d, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x3a2, 0x3a3, 0x7, 0x9, 0x2, 0x2, 0x3a3, 0x3a7, 0x7, 0x3b, 0x2, 
    0x2, 0x3a4, 0x3a6, 0x5, 0xe, 0x8, 0x2, 0x3a5, 0x3a4, 0x3, 0x2, 0x2, 
    0x2, 0x3a6, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a5, 0x3, 0x2, 0x2, 
    0x2, 0x3a7, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3aa, 0x3, 0x2, 0x2, 
    0x2, 0x3a9, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ab, 0x5, 0x92, 0x4a, 
    0x2, 0x3ab, 0x3ac, 0x7, 0x66, 0x2, 0x2, 0x3ac, 0x3ad, 0x7, 0x3c, 0x2, 
    0x2, 0x3ad, 0x3ae, 0x5, 0x86, 0x44, 0x2, 0x3ae, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x3af, 0x3b4, 0x5, 0x66, 0x34, 0x2, 0x3b0, 0x3b1, 0x7, 0x58, 0x2, 
    0x2, 0x3b1, 0x3b3, 0x5, 0x66, 0x34, 0x2, 0x3b2, 0x3b0, 0x3, 0x2, 0x2, 
    0x2, 0x3b3, 0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b2, 0x3, 0x2, 0x2, 
    0x2, 0x3b4, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x3b6, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3b8, 0x7, 0x15, 0x2, 0x2, 
    0x3b8, 0x3b9, 0x5, 0x86, 0x44, 0x2, 0x3b9, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x3ba, 0x3bb, 0x7, 0x3b, 0x2, 0x2, 0x3bb, 0x3bd, 0x5, 0x98, 0x4d, 0x2, 
    0x3bc, 0x3be, 0x7, 0x41, 0x2, 0x2, 0x3bd, 0x3bc, 0x3, 0x2, 0x2, 0x2, 
    0x3bd, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x3be, 0x3bf, 0x3, 0x2, 0x2, 0x2, 
    0x3bf, 0x3c0, 0x7, 0x3c, 0x2, 0x2, 0x3c0, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x3c1, 0x3c6, 0x5, 0x9a, 0x4e, 0x2, 0x3c2, 0x3c3, 0x7, 0x41, 0x2, 0x2, 
    0x3c3, 0x3c5, 0x5, 0x9a, 0x4e, 0x2, 0x3c4, 0x3c2, 0x3, 0x2, 0x2, 0x2, 
    0x3c5, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c4, 0x3, 0x2, 0x2, 0x2, 
    0x3c6, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x99, 0x3, 0x2, 0x2, 0x2, 0x3c8, 
    0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3cb, 0x5, 0xe, 0x8, 0x2, 0x3ca, 
    0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3cb, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3cc, 
    0x3ca, 0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3cd, 
    0x3cf, 0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3cf, 
    0x3d0, 0x5, 0x50, 0x29, 0x2, 0x3d0, 0x3d1, 0x5, 0x46, 0x24, 0x2, 0x3d1, 
    0x3d2, 0x7, 0x44, 0x2, 0x2, 0x3d2, 0x3d3, 0x5, 0xb0, 0x59, 0x2, 0x3d3, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0x3d4, 0x3d6, 0x5, 0x9e, 0x50, 0x2, 0x3d5, 
    0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d7, 
    0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d8, 0x3, 0x2, 0x2, 0x2, 0x3d8, 
    0x3da, 0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3db, 0x5, 0x88, 0x45, 0x2, 0x3da, 
    0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3dc, 
    0x3da, 0x3, 0x2, 0x2, 0x2, 0x3dc, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3dd, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x3de, 0x3df, 0x7, 0x8, 0x2, 0x2, 0x3df, 0x3e0, 
    0x5, 0xae, 0x58, 0x2, 0x3e0, 0x3e1, 0x7, 0x4a, 0x2, 0x2, 0x3e1, 0x3e9, 
    0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3e3, 0x7, 0x8, 0x2, 0x2, 0x3e3, 0x3e4, 
    0x5, 0x4c, 0x27, 0x2, 0x3e4, 0x3e5, 0x7, 0x4a, 0x2, 0x2, 0x3e5, 0x3e9, 
    0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3e7, 0x7, 0xe, 0x2, 0x2, 0x3e7, 0x3e9, 
    0x7, 0x4a, 0x2, 0x2, 0x3e8, 0x3de, 0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3e2, 
    0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0x3ea, 0x3f7, 0x5, 0xa4, 0x53, 0x2, 0x3eb, 0x3ed, 0x5, 
    0xa2, 0x52, 0x2, 0x3ec, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ed, 0x3, 
    0x2, 0x2, 0x2, 0x3ed, 0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3f0, 0x7, 
    0x41, 0x2, 0x2, 0x3ef, 0x3f1, 0x5, 0xb0, 0x59, 0x2, 0x3f0, 0x3ef, 0x3, 
    0x2, 0x2, 0x2, 0x3f0, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f2, 0x3, 
    0x2, 0x2, 0x2, 0x3f2, 0x3f4, 0x7, 0x41, 0x2, 0x2, 0x3f3, 0x3f5, 0x5, 
    0xa6, 0x54, 0x2, 0x3f4, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f5, 0x3, 
    0x2, 0x2, 0x2, 0x3f5, 0x3f7, 0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3ea, 0x3, 
    0x2, 0x2, 0x2, 0x3f6, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0x3f8, 0x3fb, 0x5, 0x8c, 0x47, 0x2, 0x3f9, 0x3fb, 0x5, 0xaa, 
    0x56, 0x2, 0x3fa, 0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3f9, 0x3, 0x2, 
    0x2, 0x2, 0x3fb, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fe, 0x5, 0xe, 0x8, 
    0x2, 0x3fd, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x401, 0x3, 0x2, 0x2, 
    0x2, 0x3ff, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3ff, 0x400, 0x3, 0x2, 0x2, 
    0x2, 0x400, 0x402, 0x3, 0x2, 0x2, 0x2, 0x401, 0x3ff, 0x3, 0x2, 0x2, 
    0x2, 0x402, 0x403, 0x5, 0x4e, 0x28, 0x2, 0x403, 0x404, 0x5, 0x46, 0x24, 
    0x2, 0x404, 0x405, 0x7, 0x4a, 0x2, 0x2, 0x405, 0x406, 0x5, 0xb0, 0x59, 
    0x2, 0x406, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x407, 0x408, 0x5, 0xaa, 0x56, 
    0x2, 0x408, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x409, 0x40a, 0x7, 0x3b, 0x2, 
    0x2, 0x40a, 0x40b, 0x5, 0xb0, 0x59, 0x2, 0x40b, 0x40c, 0x7, 0x3c, 0x2, 
    0x2, 0x40c, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x412, 0x5, 0xb0, 0x59, 
    0x2, 0x40e, 0x40f, 0x7, 0x42, 0x2, 0x2, 0x40f, 0x411, 0x5, 0xb0, 0x59, 
    0x2, 0x410, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x411, 0x414, 0x3, 0x2, 0x2, 
    0x2, 0x412, 0x410, 0x3, 0x2, 0x2, 0x2, 0x412, 0x413, 0x3, 0x2, 0x2, 
    0x2, 0x413, 0xab, 0x3, 0x2, 0x2, 0x2, 0x414, 0x412, 0x3, 0x2, 0x2, 0x2, 
    0x415, 0x416, 0x5, 0xb0, 0x59, 0x2, 0x416, 0xad, 0x3, 0x2, 0x2, 0x2, 
    0x417, 0x418, 0x5, 0xb0, 0x59, 0x2, 0x418, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0x419, 0x41a, 0x8, 0x59, 0x1, 0x2, 0x41a, 0x427, 0x5, 0xb2, 0x5a, 0x2, 
    0x41b, 0x41c, 0x7, 0x21, 0x2, 0x2, 0x41c, 0x427, 0x5, 0xb4, 0x5b, 0x2, 
    0x41d, 0x41e, 0x7, 0x3b, 0x2, 0x2, 0x41e, 0x41f, 0x5, 0x4e, 0x28, 0x2, 
    0x41f, 0x420, 0x7, 0x3c, 0x2, 0x2, 0x420, 0x421, 0x5, 0xb0, 0x59, 0x13, 
    0x421, 0x427, 0x3, 0x2, 0x2, 0x2, 0x422, 0x423, 0x9, 0x7, 0x2, 0x2, 
    0x423, 0x427, 0x5, 0xb0, 0x59, 0x11, 0x424, 0x425, 0x9, 0x8, 0x2, 0x2, 
    0x425, 0x427, 0x5, 0xb0, 0x59, 0x10, 0x426, 0x419, 0x3, 0x2, 0x2, 0x2, 
    0x426, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x426, 0x41d, 0x3, 0x2, 0x2, 0x2, 
    0x426, 0x422, 0x3, 0x2, 0x2, 0x2, 0x426, 0x424, 0x3, 0x2, 0x2, 0x2, 
    0x427, 0x47d, 0x3, 0x2, 0x2, 0x2, 0x428, 0x429, 0xc, 0xf, 0x2, 0x2, 
    0x429, 0x42a, 0x9, 0x9, 0x2, 0x2, 0x42a, 0x47c, 0x5, 0xb0, 0x59, 0x10, 
    0x42b, 0x42c, 0xc, 0xe, 0x2, 0x2, 0x42c, 0x42d, 0x9, 0xa, 0x2, 0x2, 
    0x42d, 0x47c, 0x5, 0xb0, 0x59, 0xf, 0x42e, 0x436, 0xc, 0xd, 0x2, 0x2, 
    0x42f, 0x430, 0x7, 0x46, 0x2, 0x2, 0x430, 0x437, 0x7, 0x46, 0x2, 0x2, 
    0x431, 0x432, 0x7, 0x45, 0x2, 0x2, 0x432, 0x433, 0x7, 0x45, 0x2, 0x2, 
    0x433, 0x437, 0x7, 0x45, 0x2, 0x2, 0x434, 0x435, 0x7, 0x45, 0x2, 0x2, 
    0x435, 0x437, 0x7, 0x45, 0x2, 0x2, 0x436, 0x42f, 0x3, 0x2, 0x2, 0x2, 
    0x436, 0x431, 0x3, 0x2, 0x2, 0x2, 0x436, 0x434, 0x3, 0x2, 0x2, 0x2, 
    0x437, 0x438, 0x3, 0x2, 0x2, 0x2, 0x438, 0x47c, 0x5, 0xb0, 0x59, 0xe, 
    0x439, 0x43a, 0xc, 0xc, 0x2, 0x2, 0x43a, 0x43b, 0x9, 0xb, 0x2, 0x2, 
    0x43b, 0x47c, 0x5, 0xb0, 0x59, 0xd, 0x43c, 0x43d, 0xc, 0xa, 0x2, 0x2, 
    0x43d, 0x43e, 0x9, 0xc, 0x2, 0x2, 0x43e, 0x47c, 0x5, 0xb0, 0x59, 0xb, 
    0x43f, 0x440, 0xc, 0x9, 0x2, 0x2, 0x440, 0x441, 0x7, 0x57, 0x2, 0x2, 
    0x441, 0x47c, 0x5, 0xb0, 0x59, 0xa, 0x442, 0x443, 0xc, 0x8, 0x2, 0x2, 
    0x443, 0x444, 0x7, 0x59, 0x2, 0x2, 0x444, 0x47c, 0x5, 0xb0, 0x59, 0x9, 
    0x445, 0x446, 0xc, 0x7, 0x2, 0x2, 0x446, 0x447, 0x7, 0x58, 0x2, 0x2, 
    0x447, 0x47c, 0x5, 0xb0, 0x59, 0x8, 0x448, 0x449, 0xc, 0x6, 0x2, 0x2, 
    0x449, 0x44a, 0x7, 0x4f, 0x2, 0x2, 0x44a, 0x47c, 0x5, 0xb0, 0x59, 0x7, 
    0x44b, 0x44c, 0xc, 0x5, 0x2, 0x2, 0x44c, 0x44d, 0x7, 0x50, 0x2, 0x2, 
    0x44d, 0x47c, 0x5, 0xb0, 0x59, 0x6, 0x44e, 0x44f, 0xc, 0x4, 0x2, 0x2, 
    0x44f, 0x450, 0x7, 0x49, 0x2, 0x2, 0x450, 0x451, 0x5, 0xb0, 0x59, 0x2, 
    0x451, 0x452, 0x7, 0x4a, 0x2, 0x2, 0x452, 0x453, 0x5, 0xb0, 0x59, 0x5, 
    0x453, 0x47c, 0x3, 0x2, 0x2, 0x2, 0x454, 0x455, 0xc, 0x3, 0x2, 0x2, 
    0x455, 0x456, 0x9, 0xd, 0x2, 0x2, 0x456, 0x47c, 0x5, 0xb0, 0x59, 0x3, 
    0x457, 0x458, 0xc, 0x1b, 0x2, 0x2, 0x458, 0x459, 0x7, 0x43, 0x2, 0x2, 
    0x459, 0x47c, 0x7, 0x66, 0x2, 0x2, 0x45a, 0x45b, 0xc, 0x1a, 0x2, 0x2, 
    0x45b, 0x45c, 0x7, 0x43, 0x2, 0x2, 0x45c, 0x47c, 0x7, 0x2d, 0x2, 0x2, 
    0x45d, 0x45e, 0xc, 0x19, 0x2, 0x2, 0x45e, 0x45f, 0x7, 0x43, 0x2, 0x2, 
    0x45f, 0x461, 0x7, 0x21, 0x2, 0x2, 0x460, 0x462, 0x5, 0xc0, 0x61, 0x2, 
    0x461, 0x460, 0x3, 0x2, 0x2, 0x2, 0x461, 0x462, 0x3, 0x2, 0x2, 0x2, 
    0x462, 0x463, 0x3, 0x2, 0x2, 0x2, 0x463, 0x47c, 0x5, 0xb8, 0x5d, 0x2, 
    0x464, 0x465, 0xc, 0x18, 0x2, 0x2, 0x465, 0x466, 0x7, 0x43, 0x2, 0x2, 
    0x466, 0x467, 0x7, 0x2a, 0x2, 0x2, 0x467, 0x47c, 0x5, 0xc6, 0x64, 0x2, 
    0x468, 0x469, 0xc, 0x17, 0x2, 0x2, 0x469, 0x46a, 0x7, 0x43, 0x2, 0x2, 
    0x46a, 0x47c, 0x5, 0xbe, 0x60, 0x2, 0x46b, 0x46c, 0xc, 0x16, 0x2, 0x2, 
    0x46c, 0x46d, 0x7, 0x3f, 0x2, 0x2, 0x46d, 0x46e, 0x5, 0xb0, 0x59, 0x2, 
    0x46e, 0x46f, 0x7, 0x40, 0x2, 0x2, 0x46f, 0x47c, 0x3, 0x2, 0x2, 0x2, 
    0x470, 0x471, 0xc, 0x15, 0x2, 0x2, 0x471, 0x473, 0x7, 0x3b, 0x2, 0x2, 
    0x472, 0x474, 0x5, 0xaa, 0x56, 0x2, 0x473, 0x472, 0x3, 0x2, 0x2, 0x2, 
    0x473, 0x474, 0x3, 0x2, 0x2, 0x2, 0x474, 0x475, 0x3, 0x2, 0x2, 0x2, 
    0x475, 0x47c, 0x7, 0x3c, 0x2, 0x2, 0x476, 0x477, 0xc, 0x12, 0x2, 0x2, 
    0x477, 0x47c, 0x9, 0xe, 0x2, 0x2, 0x478, 0x479, 0xc, 0xb, 0x2, 0x2, 
    0x479, 0x47a, 0x7, 0x1c, 0x2, 0x2, 0x47a, 0x47c, 0x5, 0x4e, 0x28, 0x2, 
    0x47b, 0x428, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x42b, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x42e, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x439, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x43f, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x442, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x445, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x448, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x44b, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x44e, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x454, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x457, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x45a, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x45d, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x464, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x468, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x46b, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x470, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x476, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x478, 0x3, 0x2, 0x2, 0x2, 0x47c, 0x47f, 0x3, 0x2, 0x2, 0x2, 
    0x47d, 0x47b, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x47e, 0x3, 0x2, 0x2, 0x2, 
    0x47e, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x47f, 0x47d, 0x3, 0x2, 0x2, 0x2, 0x480, 
    0x481, 0x7, 0x3b, 0x2, 0x2, 0x481, 0x482, 0x5, 0xb0, 0x59, 0x2, 0x482, 
    0x483, 0x7, 0x3c, 0x2, 0x2, 0x483, 0x496, 0x3, 0x2, 0x2, 0x2, 0x484, 
    0x496, 0x7, 0x2d, 0x2, 0x2, 0x485, 0x496, 0x7, 0x2a, 0x2, 0x2, 0x486, 
    0x496, 0x5, 0x68, 0x35, 0x2, 0x487, 0x496, 0x7, 0x66, 0x2, 0x2, 0x488, 
    0x489, 0x5, 0x4e, 0x28, 0x2, 0x489, 0x48a, 0x7, 0x43, 0x2, 0x2, 0x48a, 
    0x48b, 0x7, 0xb, 0x2, 0x2, 0x48b, 0x496, 0x3, 0x2, 0x2, 0x2, 0x48c, 
    0x48d, 0x7, 0x32, 0x2, 0x2, 0x48d, 0x48e, 0x7, 0x43, 0x2, 0x2, 0x48e, 
    0x496, 0x7, 0xb, 0x2, 0x2, 0x48f, 0x493, 0x5, 0xc0, 0x61, 0x2, 0x490, 
    0x494, 0x5, 0xc8, 0x65, 0x2, 0x491, 0x492, 0x7, 0x2d, 0x2, 0x2, 0x492, 
    0x494, 0x5, 0xca, 0x66, 0x2, 0x493, 0x490, 0x3, 0x2, 0x2, 0x2, 0x493, 
    0x491, 0x3, 0x2, 0x2, 0x2, 0x494, 0x496, 0x3, 0x2, 0x2, 0x2, 0x495, 
    0x480, 0x3, 0x2, 0x2, 0x2, 0x495, 0x484, 0x3, 0x2, 0x2, 0x2, 0x495, 
    0x485, 0x3, 0x2, 0x2, 0x2, 0x495, 0x486, 0x3, 0x2, 0x2, 0x2, 0x495, 
    0x487, 0x3, 0x2, 0x2, 0x2, 0x495, 0x488, 0x3, 0x2, 0x2, 0x2, 0x495, 
    0x48c, 0x3, 0x2, 0x2, 0x2, 0x495, 0x48f, 0x3, 0x2, 0x2, 0x2, 0x496, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0x497, 0x498, 0x5, 0xc0, 0x61, 0x2, 0x498, 
    0x499, 0x5, 0xb6, 0x5c, 0x2, 0x499, 0x49a, 0x5, 0xbc, 0x5f, 0x2, 0x49a, 
    0x4a1, 0x3, 0x2, 0x2, 0x2, 0x49b, 0x49e, 0x5, 0xb6, 0x5c, 0x2, 0x49c, 
    0x49f, 0x5, 0xba, 0x5e, 0x2, 0x49d, 0x49f, 0x5, 0xbc, 0x5f, 0x2, 0x49e, 
    0x49c, 0x3, 0x2, 0x2, 0x2, 0x49e, 0x49d, 0x3, 0x2, 0x2, 0x2, 0x49f, 
    0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x497, 0x3, 0x2, 0x2, 0x2, 0x4a0, 
    0x49b, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x4a2, 0x4a4, 
    0x7, 0x66, 0x2, 0x2, 0x4a3, 0x4a5, 0x5, 0xc2, 0x62, 0x2, 0x4a4, 0x4a3, 
    0x3, 0x2, 0x2, 0x2, 0x4a4, 0x4a5, 0x3, 0x2, 0x2, 0x2, 0x4a5, 0x4ad, 
    0x3, 0x2, 0x2, 0x2, 0x4a6, 0x4a7, 0x7, 0x43, 0x2, 0x2, 0x4a7, 0x4a9, 
    0x7, 0x66, 0x2, 0x2, 0x4a8, 0x4aa, 0x5, 0xc2, 0x62, 0x2, 0x4a9, 0x4a8, 
    0x3, 0x2, 0x2, 0x2, 0x4a9, 0x4aa, 0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4ac, 
    0x3, 0x2, 0x2, 0x2, 0x4ab, 0x4a6, 0x3, 0x2, 0x2, 0x2, 0x4ac, 0x4af, 
    0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ae, 
    0x3, 0x2, 0x2, 0x2, 0x4ae, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x4af, 0x4ad, 
    0x3, 0x2, 0x2, 0x2, 0x4b0, 0x4b2, 0x5, 0x52, 0x2a, 0x2, 0x4b1, 0x4a2, 
    0x3, 0x2, 0x2, 0x2, 0x4b1, 0x4b0, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0x4b3, 0x4b5, 0x7, 0x66, 0x2, 0x2, 0x4b4, 0x4b6, 0x5, 
    0xc4, 0x63, 0x2, 0x4b5, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4b5, 0x4b6, 0x3, 
    0x2, 0x2, 0x2, 0x4b6, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4b8, 0x5, 
    0xbc, 0x5f, 0x2, 0x4b8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x4b9, 0x4d5, 0x7, 
    0x3f, 0x2, 0x2, 0x4ba, 0x4bf, 0x7, 0x40, 0x2, 0x2, 0x4bb, 0x4bc, 0x7, 
    0x3f, 0x2, 0x2, 0x4bc, 0x4be, 0x7, 0x40, 0x2, 0x2, 0x4bd, 0x4bb, 0x3, 
    0x2, 0x2, 0x2, 0x4be, 0x4c1, 0x3, 0x2, 0x2, 0x2, 0x4bf, 0x4bd, 0x3, 
    0x2, 0x2, 0x2, 0x4bf, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4c2, 0x3, 
    0x2, 0x2, 0x2, 0x4c1, 0x4bf, 0x3, 0x2, 0x2, 0x2, 0x4c2, 0x4d6, 0x5, 
    0x4a, 0x26, 0x2, 0x4c3, 0x4c4, 0x5, 0xb0, 0x59, 0x2, 0x4c4, 0x4cb, 0x7, 
    0x40, 0x2, 0x2, 0x4c5, 0x4c6, 0x7, 0x3f, 0x2, 0x2, 0x4c6, 0x4c7, 0x5, 
    0xb0, 0x59, 0x2, 0x4c7, 0x4c8, 0x7, 0x40, 0x2, 0x2, 0x4c8, 0x4ca, 0x3, 
    0x2, 0x2, 0x2, 0x4c9, 0x4c5, 0x3, 0x2, 0x2, 0x2, 0x4ca, 0x4cd, 0x3, 
    0x2, 0x2, 0x2, 0x4cb, 0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0x4cc, 0x3, 
    0x2, 0x2, 0x2, 0x4cc, 0x4d2, 0x3, 0x2, 0x2, 0x2, 0x4cd, 0x4cb, 0x3, 
    0x2, 0x2, 0x2, 0x4ce, 0x4cf, 0x7, 0x3f, 0x2, 0x2, 0x4cf, 0x4d1, 0x7, 
    0x40, 0x2, 0x2, 0x4d0, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4d1, 0x4d4, 0x3, 
    0x2, 0x2, 0x2, 0x4d2, 0x4d0, 0x3, 0x2, 0x2, 0x2, 0x4d2, 0x4d3, 0x3, 
    0x2, 0x2, 0x2, 0x4d3, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d2, 0x3, 
    0x2, 0x2, 0x2, 0x4d5, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4d5, 0x4c3, 0x3, 
    0x2, 0x2, 0x2, 0x4d6, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x4d7, 0x4d9, 0x5, 0xca, 
    0x66, 0x2, 0x4d8, 0x4da, 0x5, 0x24, 0x13, 0x2, 0x4d9, 0x4d8, 0x3, 0x2, 
    0x2, 0x2, 0x4d9, 0x4da, 0x3, 0x2, 0x2, 0x2, 0x4da, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0x4db, 0x4dc, 0x5, 0xc0, 0x61, 0x2, 0x4dc, 0x4dd, 0x5, 0xc8, 0x65, 
    0x2, 0x4dd, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x4de, 0x4df, 0x7, 0x46, 0x2, 
    0x2, 0x4df, 0x4e0, 0x5, 0x22, 0x12, 0x2, 0x4e0, 0x4e1, 0x7, 0x45, 0x2, 
    0x2, 0x4e1, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x4e2, 0x4e3, 0x7, 0x46, 0x2, 
    0x2, 0x4e3, 0x4e6, 0x7, 0x45, 0x2, 0x2, 0x4e4, 0x4e6, 0x5, 0x54, 0x2b, 
    0x2, 0x4e5, 0x4e2, 0x3, 0x2, 0x2, 0x2, 0x4e5, 0x4e4, 0x3, 0x2, 0x2, 
    0x2, 0x4e6, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x4e7, 0x4e8, 0x7, 0x46, 0x2, 
    0x2, 0x4e8, 0x4eb, 0x7, 0x45, 0x2, 0x2, 0x4e9, 0x4eb, 0x5, 0xc0, 0x61, 
    0x2, 0x4ea, 0x4e7, 0x3, 0x2, 0x2, 0x2, 0x4ea, 0x4e9, 0x3, 0x2, 0x2, 
    0x2, 0x4eb, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4f3, 0x5, 0xca, 0x66, 
    0x2, 0x4ed, 0x4ee, 0x7, 0x43, 0x2, 0x2, 0x4ee, 0x4f0, 0x7, 0x66, 0x2, 
    0x2, 0x4ef, 0x4f1, 0x5, 0xca, 0x66, 0x2, 0x4f0, 0x4ef, 0x3, 0x2, 0x2, 
    0x2, 0x4f0, 0x4f1, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4f3, 0x3, 0x2, 0x2, 
    0x2, 0x4f2, 0x4ec, 0x3, 0x2, 0x2, 0x2, 0x4f2, 0x4ed, 0x3, 0x2, 0x2, 
    0x2, 0x4f3, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4f5, 0x7, 0x2a, 0x2, 
    0x2, 0x4f5, 0x4f9, 0x5, 0xc6, 0x64, 0x2, 0x4f6, 0x4f7, 0x7, 0x66, 0x2, 
    0x2, 0x4f7, 0x4f9, 0x5, 0xca, 0x66, 0x2, 0x4f8, 0x4f4, 0x3, 0x2, 0x2, 
    0x2, 0x4f8, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0x4fa, 0x4fc, 0x7, 0x3b, 0x2, 0x2, 0x4fb, 0x4fd, 0x5, 0xaa, 0x56, 0x2, 
    0x4fc, 0x4fb, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fd, 0x3, 0x2, 0x2, 0x2, 
    0x4fd, 0x4fe, 0x3, 0x2, 0x2, 0x2, 0x4fe, 0x4ff, 0x7, 0x3c, 0x2, 0x2, 
    0x4ff, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x97, 0xcd, 0xd2, 0xd8, 0xe0, 0xe9, 
    0xee, 0xf5, 0xfc, 0x103, 0x10a, 0x10f, 0x113, 0x117, 0x11b, 0x120, 0x124, 
    0x128, 0x132, 0x13a, 0x141, 0x148, 0x14c, 0x14f, 0x152, 0x15b, 0x161, 
    0x166, 0x169, 0x16f, 0x175, 0x179, 0x182, 0x189, 0x192, 0x199, 0x19f, 
    0x1a3, 0x1ae, 0x1b2, 0x1ba, 0x1bf, 0x1c3, 0x1cc, 0x1da, 0x1df, 0x1e8, 
    0x1f0, 0x1fa, 0x202, 0x20a, 0x20f, 0x21b, 0x221, 0x228, 0x22d, 0x235, 
    0x239, 0x23b, 0x246, 0x24e, 0x251, 0x255, 0x25a, 0x25e, 0x269, 0x272, 
    0x274, 0x27b, 0x280, 0x289, 0x28e, 0x291, 0x296, 0x29f, 0x2af, 0x2b9, 
    0x2bc, 0x2c5, 0x2cf, 0x2d7, 0x2da, 0x2dd, 0x2ea, 0x2f2, 0x2f7, 0x2ff, 
    0x303, 0x307, 0x30b, 0x30d, 0x311, 0x317, 0x322, 0x32a, 0x332, 0x33d, 
    0x346, 0x35d, 0x360, 0x363, 0x36b, 0x36f, 0x377, 0x37d, 0x388, 0x391, 
    0x396, 0x3a0, 0x3a7, 0x3b4, 0x3bd, 0x3c6, 0x3cc, 0x3d7, 0x3dc, 0x3e8, 
    0x3ec, 0x3f0, 0x3f4, 0x3f6, 0x3fa, 0x3ff, 0x412, 0x426, 0x436, 0x461, 
    0x473, 0x47b, 0x47d, 0x493, 0x495, 0x49e, 0x4a0, 0x4a4, 0x4a9, 0x4ad, 
    0x4b1, 0x4b5, 0x4bf, 0x4cb, 0x4d2, 0x4d5, 0x4d9, 0x4e5, 0x4ea, 0x4f0, 
    0x4f2, 0x4f8, 0x4fc, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

JavaParser::Initializer JavaParser::_init;
