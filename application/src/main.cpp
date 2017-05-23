#include <iostream>
#include <memory>

#include "antlrComponentsKeeper.hpp"
#include "treeMetricsCalculator.hpp"
#include "simpleMetricsCalculator.hpp"
#include "clusteringMetricsCalculator.hpp"

using std::cout;
using std::endl;

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

// Clustering
JWB::details::ClusteringMetricsCalculator clusteringMetricsCalculator(keeper);

clusteringMetricsCalculator.showClusteringMetrics();
cout << endl << clusteringMetricsCalculator.cluster() << endl;

// Inheritance
/*	JWB::details::TreeMetricsCalculator treeMetricsCalculator(keeper);

	cout << "Polymorpism Factor after norming is " << treeMetricsCalculator.getInheritanceAndPolymorpismDegree() << endl;

	cout << "Method Inheritance Factor is " << treeMetricsCalculator.getMethodInheritanceFactor() << endl;
	cout << "Method Inheritance Degree is " << treeMetricsCalculator.getMethodInheritanceDegree() << endl;
	// cout << "Not satishfying number of classes is " << treeMetricsCalculator.scanMethodInheritanceFactor().first.size() << endl;

	// cout << "Attribute Inheritance Factor is " << treeMetricsCalculator.getAttributeInheritanceFactor() << endl;
	// cout << "Not satishfying number of classes is " << treeMetricsCalculator.scanAttributeInheritanceFactor().first.size() << endl;

	cout << "Polymorpism Factor is " << treeMetricsCalculator.getPolymorpismFactor() << endl;
	cout << "Polymorpism Degree is " << treeMetricsCalculator.getPolymorpismDegree() << endl;
	// cout << "Average polymorpism is " << treeMetricsCalculator.scanPolymorpismFactor().second << endl;
	// cout << "Not satishfying number of classes is " << treeMetricsCalculator.scanPolymorpismFactor().first.size() << endl;

	cout << "Average number of children is " << treeMetricsCalculator.getNumberOfChildrenMetric() << endl;
	// cout << "Not satishfying number of classes is " << treeMetricsCalculator.scanNumberOfChildrenMetric().first.size() << endl;

	cout << "Depth of Inheritance tree is " << treeMetricsCalculator.getDepthOfInheritanceTree() << endl;
	// cout << "Not satishfying number of classes is " << treeMetricsCalculator.scanDepthOfInheritanceTree().first.size() << endl;
	cout << "Average depth is " << treeMetricsCalculator.scanDepthOfInheritanceTree().second << endl;

	cout << "Width of Inheritance tree is " << treeMetricsCalculator.getWidthOfInheritanceTree() << endl;
	// cout << "Not satishfying number of classes is " << treeMetricsCalculator.scanWidthOfInheritanceTree().first.size() << endl;
	cout << "Average width is " << treeMetricsCalculator.scanWidthOfInheritanceTree().second << endl;

	// for (auto const& x :  treeMetricsCalculator.totalAnalyzisMethodInheritanceFactor().first)
	// {
	// 	cout << "\t" << x.first << " " << x.second << endl;
	// }

	// treeMetricsCalculator.printInheritanceTree();
*/
}
