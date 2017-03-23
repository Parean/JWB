#pragma once
#include <vector>
#include <unordered_map>

#include "JavaBaseListener.h"
using namespace antlr4;

class CustomListener : public JavaBaseListener {

  public:
    void enterClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *ctx) override;
    void enterMethodDeclaration(JavaParser::MethodDeclarationContext *ctx) override;
    void enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;
    void exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override;
    void showNumberOfMethodes() const;

  private:
    std::vector<JavaParser::ClassDeclarationContext*> classes;
    std::unordered_map<JavaParser::ClassDeclarationContext*, uint64_t> methodesNumber;
    std::unordered_map<JavaParser::ClassDeclarationContext*, uint64_t> privateMethodesNumber;
};
