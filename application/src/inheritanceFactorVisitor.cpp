#include "inheritanceFactorVisitor.hpp"
#include "node.hpp"

#include <vector>
#include <cassert>
#include <functional>
#include <cassert>

using std::unordered_set;
using std::vector;
using std::pair;
using std::function;
using std::hash;
using std::unordered_map;

namespace JWB {	namespace details {

InheritanceAndPolymorphismFactorVisitor::InheritanceAndPolymorphismFactorVisitor(unordered_set<Node const*>& filter, ReturnVisitorStatus<InheritanceAndPolymorphismFactorVisitor>& result) :
	Visitor(filter),
	inheritedMethodsRealSize(0),
	result(result)
{}

size_t InheritanceAndPolymorphismFactorVisitor::hash_for_TreeMethodDescription::operator()(TreeMethodDescription const* p) const
{
	assert(p);
	return p->getId();
}

bool InheritanceAndPolymorphismFactorVisitor::equal_to_for_TreeMethodDescription::operator()(TreeMethodDescription const* lhs, TreeMethodDescription const* rhs) const
{
	return *lhs == *rhs;
}

void InheritanceAndPolymorphismFactorVisitor::visit(TreeClassDescription const* treeClassDescription)
{
	// Seems that Node garantes notemptyness of TreeClassDescription, but still.
	assert(treeClassDescription);

	/// Maximum number of possibly inherited methods. It is decremented when override found.
	int64_t possibleInheritanceNumber = inheritedMethodsRealSize;

	result.overridenMethodNumber += possibleInheritanceNumber;

	for (auto const x : treeClassDescription->getMethods())
	{

		// If method is in inheritedMethods, then it is overriden and not inherited. 
		// If it is not private, it can be inherited.
		auto iter = inheritedMethods.find(x.get());
		if (iter != inheritedMethods.cend())
		{
			iter->second++;
			possibleInheritanceNumber--;
		}
		else if (x.get()->getName() != treeClassDescription->getName())
		{
			inheritedMethods.insert({x.get(), 1});
			inheritedMethodsRealSize++;
			result.totalMethodNumber++;
		}
	}
	result.inheritedMethodNumber += possibleInheritanceNumber;
	result.overridenMethodNumber -= possibleInheritanceNumber;
}

void InheritanceAndPolymorphismFactorVisitor::visit(TreeInterfaceDescription const* TreeInterfaceDescription)
{
	// This class should be ran only on classes, its cannot get into interfaces. Otherwise it's a bug.
	assert(true);
}

void InheritanceAndPolymorphismFactorVisitor::visitBack(TreeClassDescription const* treeClassDescription) 
{
	for (auto const x : treeClassDescription->getMethods())
	{
		auto iter = inheritedMethods.find(x.get());
		if (iter != inheritedMethods.cend())
		{
			iter->second--;
			if (!iter->second)
			{
				inheritedMethodsRealSize--;
				inheritedMethods.erase(iter);
			}
		}
	}
}

void InheritanceAndPolymorphismFactorVisitor::visitBack(TreeInterfaceDescription const*) 
{
	// This class should be ran only on classes, its cannot get into interfaces. Otherwise it's a bug.
	assert(true);
}

}} // end of namespace JWB::details