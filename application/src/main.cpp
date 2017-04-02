#include <iostream>

#include "antlr4-runtime.h"
#include "JavaLexer.h"
#include "JavaParser.h"
#include "customListener.hpp"
#include "metricsCalculator.hpp"

using std::cout;
using std::ifstream;
using std::endl;

using namespace antlr4;

int main(int argc, const char* argv[]) {
	ifstream stream;
	stream.open(argv[1]);
	ANTLRInputStream input(stream);
	JavaLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	JavaParser parser(&tokens);
	tree::ParseTree *tree = parser.compilationUnit();
	JWB::details::MetricsCalculator metricsCalculator;
	JWB::details::CustomListener listener(&metricsCalculator);
	tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

	metricsCalculator.showNumberOfMethods();
	metricsCalculator.showNumberOfFields();

	cout << metricsCalculator.getMethodHidingFactor() << endl;
	cout << metricsCalculator.getAttributeHidingFactor() << endl;
}
