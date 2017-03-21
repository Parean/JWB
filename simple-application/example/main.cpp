#include <iostream>
#include <string>

#include "antlr4-runtime.h"
#include "JavaLexer.h"
#include "JavaParser.h"
#include "JavaBaseListener.h"

using namespace std;
using namespace antlr4;

class ExtractInterfaceListener : public JavaBaseListener {

  public:

  ExtractInterfaceListener(JavaParser *p) : parser(p){}

  void enterClassDeclaration(JavaParser::ClassDeclarationContext *ctx){
      cout <<"interface" << ctx->Identifier()->getSymbol()->getText()<< " {\n";
  }

  void exitClassDeclaration(JavaParser::ClassDeclarationContext *ctx) {
      cout << "}\n";
  }

    /** Listen to matches of methodDeclaration */
  void enterMethodDeclaration(
      JavaParser::MethodDeclarationContext* ctx
  )
  {
      // need parser to get tokens
      TokenStream *tokens = parser->getTokenStream();
      string type = "void";
      if ( ctx->typeType()!=nullptr ) {
          type = tokens->getText(ctx->typeType());
      }
      string args = tokens->getText(ctx->formalParameters());
      cout <<"\t"<<type<<" "<<ctx->Identifier()->getText()<<args<<";\n";
  }
  private:
  JavaParser *parser = nullptr;

};

int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  JavaLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  JavaParser parser(&tokens);
  tree::ParseTree *tree = parser.compilationUnit();
  ExtractInterfaceListener *listener = new ExtractInterfaceListener(&parser);
  tree::ParseTreeWalker::DEFAULT.walk(listener, tree);

// std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
}
