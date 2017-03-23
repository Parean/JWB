#include "antlr4-runtime.h"
#include "JavaLexer.h"
#include "JavaParser.h"
#include "CustomListener.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  JavaLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  JavaParser parser(&tokens);
  tree::ParseTree *tree = parser.compilationUnit();
  CustomListener *listener = new CustomListener();
  tree::ParseTreeWalker::DEFAULT.walk(listener, tree);
  listener->show_method_number();

// std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
}
