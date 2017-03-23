#include <iostream>

#include "CustomListener.h"

using std::cout;
using std::endl;

void CustomListener::enterClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *ctx)
{

  //if class hasn't method modifier, modifier() will return empty vector
  //if class hasn't interface modifier, classOrInterfaceModifier() will return nullptr
  //In both these cases we should stop
  if (ctx->modifier().empty() || !ctx->modifier().front()->classOrInterfaceModifier())
  {
    return;
  }

  //if class has method modifier
  if (ctx->memberDeclaration()->methodDeclaration())
  {
    if (ctx->modifier().front()->classOrInterfaceModifier()->getText() == "private")
    {
      auto classContext = classes.back();
      privateMethodesNumber[classContext] += 1;
    }
  }
}

void CustomListener::enterMethodDeclaration(JavaParser::MethodDeclarationContext *ctx)
{
  auto classContext = classes.back();
  methodesNumber[classContext] += 1;
}

void CustomListener::enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
  classes.push_back(ctx);
  methodesNumber[ctx] = 0;
  privateMethodesNumber[ctx] = 0;
}

void CustomListener::exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx)
{
  assert(classes.back() == ctx);
  classes.pop_back();
}

void CustomListener::showNumberOfMethodes() const
{
  for (auto m = methodesNumber.begin(), p = privateMethodesNumber.begin(); m != methodesNumber.end() && p != privateMethodesNumber.end(); m++, p++)
  {
    cout << "Class " << m->first->Identifier()->getText() << " has " << m->second << " methodes, " << p->second << " of which is private." << endl;
  }
}
