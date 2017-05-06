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
  cout << "Method Inheritance Hiding Factor is " << treeMetricsCalculator.getMethodInheritanceHidingFactor() << endl;
  cout << "Attribute Inheritance Hiding Factor is " <<treeMetricsCalculator.getAttributeInheritanceHidingFactor() << endl;
  cout << "Polymorpism Factor is " <<treeMetricsCalculator.getPolymorpismFactor() << endl;
  cout << "Depth of Inheritance tree is " <<treeMetricsCalculator.getDepthOfInheritanceTree() << endl;
  cout << "Width of Inheritance tree is " <<treeMetricsCalculator.getWidthOfInheritanceTree() << endl;
  cout << "Average number of children is " <<treeMetricsCalculator.getNumberOfChildrenMetric() << endl;
  // treeMetricsCalculator.printInheritanceTree();
}