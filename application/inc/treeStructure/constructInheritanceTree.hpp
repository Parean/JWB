#pragma once

#include "inheritanceTree.hpp"
#include "antlrComponentsKeeper.hpp"

namespace JWB {	namespace details { namespace treeConstruction {

// Constructs InheritanceTree from AntlrComponentsKeeper. Is used for TreeMetricsCalculator().
InheritanceTree constructInheritanceTree(AntlrComponentsKeeper &keeper);

}}} // end of namespace JWB::details::treeConstruction