#include "metrics.hpp"
#include "inheritanceTreeConstructorListener.hpp"

using std::move;

void semesterProject::treeMetrics(antlr4::tree::ParseTree* parseTree)
{
	CurrentlyBuildingTree hierarchyTreeTemplate;
	inheritanceTreeConstructorListener listener(hierarchyTreeTemplate);
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parseTree);
	InheritanceTree inheritanceTree = move(hierarchyTreeTemplate.buildTree());
}