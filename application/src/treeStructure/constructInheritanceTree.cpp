#include "constructInheritanceTree.hpp"
#include "inheritanceTreeConstructorListener.hpp"

using namespace antlr4;
using std::move;

namespace JWB {	namespace details { namespace treeConstruction {

InheritanceTree constructInheritanceTree(AntlrComponentsKeeper &keeper)
{
	CurrentlyBuildingTree hierarchyTreeTemplate;
	inheritanceTreeConstructorListener listener(hierarchyTreeTemplate);
	for (auto const& t : keeper.getTrees())
	{
		antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, t);
	}
	assert(!hierarchyTreeTemplate.isEmpty());
	InheritanceTree inheritanceTree = move(hierarchyTreeTemplate.buildTree());
	return move(inheritanceTree);
}

}}} // end of namespace JWB::details::treeConstruction