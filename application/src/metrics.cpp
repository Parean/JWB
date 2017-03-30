#include "metrics.hpp"
#include "inheritanceTreeConstructorListener.hpp"
#include "treeDepthWidthVisitor.hpp"
#include "dfsFunctions.hpp"
#include <functional>

using std::cin;
using std::endl;
using std::cout;
using std::move;

void semesterProject::treeMetrics(antlr4::tree::ParseTree* parseTree)
{
	CurrentlyBuildingTree hierarchyTreeTemplate;
	inheritanceTreeConstructorListener listener(hierarchyTreeTemplate);
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parseTree);
	InheritanceTree inheritanceTree = move(hierarchyTreeTemplate.buildTree());
	cout << endl << "Visiting all classes and interfaces" << endl;
	inheritanceTree.dfs<semesterProject::TreeDepthWidthVisitor>();
	cout << endl << "All interfaces and class names" << endl;
	inheritanceTree.lambdaDfs(dfsFunctions::printer());
	cout << endl << "Checking correctness on the same output" << endl;
	inheritanceTree.lambdaDfs(dfsFunctions::printer());
	size_t depth = 0;
	size_t width = 0;
	for (auto x : inheritanceTree.lambdaDfs(dfsFunctions::depthCounter()))
	{
		depth = std::max(x, depth);
	}
	for (auto x : inheritanceTree.lambdaDfs(dfsFunctions::widthCounter()))
	{
		width = std::max(x, width);
	}
	cout << endl << "Depth of inheritance tree is " << depth << endl;
	cout << "Width of inheritance tree is " << width << endl;
}