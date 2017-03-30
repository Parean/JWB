#include "metrics.hpp"
#include "inheritanceTreeConstructorListener.hpp"
#include "treeDepthWidthVisitor.hpp"

using std::move;

void semesterProject::treeMetrics(antlr4::tree::ParseTree* parseTree)
{
	CurrentlyBuildingTree hierarchyTreeTemplate;
	inheritanceTreeConstructorListener listener(hierarchyTreeTemplate);
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parseTree);
	InheritanceTree inheritanceTree = move(hierarchyTreeTemplate.buildTree());
	inheritanceTree.dfs<semesterProject::TreeDepthWidthVisitor>();
// 	auto a = [](){};
// 	inheritanceTree.lambdaDfs<decltype(a), a>();
}