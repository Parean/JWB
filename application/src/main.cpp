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

	// JWB::details::MetricsCalculator metricsCalculator(keeper);
	JWB::details::TreeMetricsCalculator treeMetricsCalculator(keeper);

	// metricsCalculator.showNumberOfMethods();
	// metricsCalculator.showNumberOfFields();

	// cout << "Method hiding factor: " << metricsCalculator.getMethodHidingFactor() << endl;
	// cout << "Attribute hiding factor: " << metricsCalculator.getAttributeHidingFactor() << endl << endl;

	// cout << "Number of comment lines: " << metricsCalculator.getNumberOfCommentLines() << endl;
	// cout << "Source lines of code: " << metricsCalculator.getSourceLinesOfCode() << endl;
	// cout << "Comment percentage: " << metricsCalculator.getCommentPercentage() << endl << endl;

	// metricsCalculator.showCyclomaticComplexities();
	// cout << endl << "Average cyclomatic complexity for all classes: " << metricsCalculator.getAverageCyclomaticComplexity() << endl;
	
	cout << "Method Inheritance Hiding Factor is " << treeMetricsCalculator.getMethodInheritanceHidingFactor() << endl;
	cout << "Attribute Inheritance Hiding Factor is " << treeMetricsCalculator.getAttributeInheritanceHidingFactor() << endl;
	cout << "Polymorpism Factor is " << treeMetricsCalculator.getPolymorpismFactor() << endl;
	cout << "Depth of Inheritance tree is " << treeMetricsCalculator.getDepthOfInheritanceTree() << endl;
	cout << "Width of Inheritance tree is " << treeMetricsCalculator.getWidthOfInheritanceTree() << endl;
	cout << "Average number of children is " << treeMetricsCalculator.getNumberOfChildrenMetric() << endl;

	auto p = treeMetricsCalculator.scanMethodInheritanceHidingFactor();
	cout << "Scanning for not satishfying classes MIHF. Average is " << p.second << endl;
	cout << "Not satishfying number is " << p.first.size() << endl;
	cout << "Not satishfying number is " << treeMetricsCalculator.totalAnalyzisMethodInheritanceHidingFactor().first.size() << endl;
	cout << treeMetricsCalculator.scanAttributeInheritanceHidingFactor().first.size() << endl;
	cout << treeMetricsCalculator.totalAnalyzisAttributeInheritanceHidingFactor().first.size() << endl;
	cout << treeMetricsCalculator.scanPolymorpismFactor().first.size() << endl;
	cout << treeMetricsCalculator.totalAnalyzisPolymorpismFactor().first.size() << endl;
	cout << treeMetricsCalculator.scanNumberOfChildrenMetric().first.size() << endl;
	cout << treeMetricsCalculator.totalAnalyzisNumberOfChildrenMetric().first.size() << endl;

	cout << treeMetricsCalculator.scanDepthOfInheritanceTree().second << endl;
	cout << treeMetricsCalculator.scanDepthOfInheritanceTree().first.size() << endl;
	cout << treeMetricsCalculator.totalAnalyzisDepthOfInheritanceTree().first.size() << endl;
	cout << treeMetricsCalculator.scanWidthOfInheritanceTree().second << endl;
	cout << treeMetricsCalculator.scanWidthOfInheritanceTree().first.size() << endl;
	cout << treeMetricsCalculator.totalAnalyzisWidthOfInheritanceTree().first.size() << endl;
	// for (auto const& x : p.first)
	// {
	// 	cout << "\t" << x.first << " " << x.second << endl;
	// }
	// treeMetricsCalculator.printInheritanceTree();
}
