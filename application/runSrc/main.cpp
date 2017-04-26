#include "antlr4-runtime.h"
#include "JavaLexer.h"
#include "JavaParser.h"
#include <iostream>

#include "treeMetricsCalculator.hpp"

using namespace antlr4;
using namespace std;

int main(int argc, const char* argv[]) 
{
  std::ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  JavaLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  JavaParser parser(&tokens);
  tree::ParseTree *tree = parser.compilationUnit();
  JWB::details::TreeMetricsCalculator treeMetricsCalculator(tree);
  cout << treeMetricsCalculator.getMethodInheritanceHidingFactor() << endl;
  cout << treeMetricsCalculator.getDepthOfInheritanceTree() << endl;
  cout << treeMetricsCalculator.getWidthOfInheritanceTree() << endl;
  // treeMetricsCalculator.printInheritanceTree();
}