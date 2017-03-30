#include "antlr4-runtime.h"
#include "JavaLexer.h"
#include "JavaParser.h"
#include <iostream>

#include "metrics.hpp"

using namespace antlr4;

int main(int argc, const char* argv[]) 
{
  std::ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  JavaLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  JavaParser parser(&tokens);
  tree::ParseTree *tree = parser.compilationUnit();
  semesterProject::treeMetrics(tree);
}