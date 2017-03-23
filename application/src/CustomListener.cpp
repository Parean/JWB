#include <iostream>

#include "CustomListener.h"

using namespace std;

void CustomListener::enterClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *ctx)
{
  //if class has not modifier, we should stop
  if (ctx->modifier().empty() || !ctx->modifier()[0]->classOrInterfaceModifier())
  {
    return;
  }

  //if class has method modifier
  if (ctx->memberDeclaration()->methodDeclaration())
  {
    if (ctx->modifier()[0]->classOrInterfaceModifier()->getText() == "private")
    {
      auto classContext = classes.back();
      privateMethodesNumber.at(classContext) += 1;
    }
  }
}

void CustomListener::enterMethodDeclaration(JavaParser::MethodDeclarationContext *ctx)
{
  cout << ctx->Identifier()->getText() << endl;
  auto classContext = classes.back();
  methodesNumber.at(classContext) += 1;
};

void CustomListener::enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
  classes.push_back(ctx);
  methodesNumber.emplace(ctx, 0);
  privateMethodesNumber.emplace(ctx, 0);
}

void CustomListener::exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
    assert(classes.back() == ctx);
    classes.pop_back();
}

void CustomListener::show_method_number() const
{
  for (auto x : methodesNumber)
  {
    cout << "Class " << x.first->Identifier()->getText() << " has " << x.second << " methodes." << endl;
  }

  for (auto x : privateMethodesNumber)
  {
    cout << "Class " << x.first->Identifier()->getText() << " has " << x.second << " private methodes." << endl;
  }
}
