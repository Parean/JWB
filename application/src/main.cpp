#include <iostream>

#include "antlr4-runtime.h"
#include "JavaLexer.h"
#include "JavaParser.h"
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
	JWB::details::MetricsCalculator metricsCalculator(&tokens, tree);

	metricsCalculator.showNumberOfMethods();
	metricsCalculator.showNumberOfFields();

	cout << "Method hiding factor: " << metricsCalculator.getMethodHidingFactor() << endl;
	cout << "Attribute hiding factor: " << metricsCalculator.getAttributeHidingFactor() << endl << endl;

	cout << "Number of comment lines: " << metricsCalculator.getNumberOfCommentLines() << endl;
	cout << "Source lines of code: " << metricsCalculator.getSourceLinesOfCode() << endl;
	cout << "Comment percentage: " << metricsCalculator.getCommentPercentage() << endl << endl;

	metricsCalculator.showCyclomaticComplexities();
	cout << endl << "Average cyclomatic complexity for all classes: " << metricsCalculator.getAverageCyclomaticComplexity() << endl;
}
