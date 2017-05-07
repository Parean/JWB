#include <iostream>

#include "antlrComponentsKeeper.hpp"
#include "metricsCalculator.hpp"
#include "treeMetricsCalculator.hpp"

using std::cout;
using std::endl;
using std::vector;

int main(int argc, const char* argv[])
{
	if (argc < 2)
	{
	   cout << "You must specify the path to file or project directory" << endl;
	   return 0;
	}

	JWB::details::AntlrComponentsKeeper keeper(argv[1]);

	if (keeper.getTrees().empty())
	{
		cout << "There is no files with .java extension in the given path" << endl;
		return 0;
	}

	JWB::details::MetricsCalculator metricsCalculator(keeper);

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
