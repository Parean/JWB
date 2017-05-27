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
	numberOfEveryMethodThatWasFoundOnTheWay(0),
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

	// Maximum number of possibly inherited methods. It is decremented when override found.
	int64_t possibleInheritanceNumber = inheritedMethodsRealSize;

	result.overridenMethodNumber += possibleInheritanceNumber;
	result.overridenMethodOfEveryClass.push_back(possibleInheritanceNumber);
	result.totalMethodNumberThatCouldBeInherited += numberOfEveryMethodThatWasFoundOnTheWay;
	stackOfAddedGenericMethods.emplace_back();

	// Counts every last one of the methods. If there is a method - it could be inherited.
	numberOfEveryMethodThatWasFoundOnTheWay += treeClassDescription->getMethods().size();

	for (auto const x : treeClassDescription->getMethods())
	{
		// If method is generic, things get messy.
		if (x->getIsGeneric())
		{
			bool overridesGeneric = false;
			bool gotWide = false;
			// Find if x can override one of generics.
			for (auto y = genericMethods.crbegin(); y != genericMethods.crend() && !overridesGeneric; ++y)
			{
				overridesGeneric = methodComparison::compare(*x,*(y->first));
				if (overridesGeneric && methodComparison::isWider(*x,*(y->first)))
				{
					gotWide = true;
				}
			}
			if (!gotWide)
			{
				if (!overridesGeneric)
				{
					// Method is added and marks as a new one (inheritedMethodsRealSize is succed).
					genericMethods.push_back({x.get(), true});
					// Marks that method needs to be popped on the leave from the node.
					stackOfAddedGenericMethods.back()++;
					inheritedMethodsRealSize++;
					result.totalMethodNumber++;
				}
				else
				{
					// Method is overridden.
					possibleInheritanceNumber--;
				}
			}
			// If method is wider (y may be reduced to x) then x is added to the end but inheritedMethodsRealSize is not succed.
			// That is why if any one inherites y, it inherites its most common form - x.
			else
			{
				// Add method to the end so it would be found earlier than its partial case.
				// Mark with false that it does not increment inheritedMethodsRealSize.
				genericMethods.push_back({x.get(),false});
				// Marks that when leaving this node method must be popped from genericMethods.
				stackOfAddedGenericMethods.back()++;
				// If we found more common method, it means that it is "overridden".
				possibleInheritanceNumber--;
			}
		}
		else
		{
			// If method is in inheritedMethods, then it is overridden and not inherited. 
			// If it is not private, it can be inherited.
			auto iter = inheritedMethods.find(x.get());
			if (iter != inheritedMethods.cend())
			{
				// If found, increase number of appearences.
				iter->second++;
				// If found, it is overridden -> there is a method that cannot be inherited.
				possibleInheritanceNumber--;
			}
			// Check if there is a generic method that we could override.
			else if (x.get()->getName() != treeClassDescription->getName())
			{
				bool overridesGeneric = false;
				for (auto y = genericMethods.crbegin(); y != genericMethods.crend() && !overridesGeneric; ++y)
				{
					overridesGeneric = methodComparison::compare(*x,*(y->first));
				}
				if (!overridesGeneric)
				{
					inheritedMethods.insert({x.get(), 1});
					inheritedMethodsRealSize++;
					result.totalMethodNumber++;
				}
				else
				{
					possibleInheritanceNumber--;
				}
			}
		}
	}
	result.inheritedMethodOfEveryClass.push_back(possibleInheritanceNumber);
	result.overridenMethodOfEveryClass.back() -= possibleInheritanceNumber;
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
	assert(!stackOfAddedGenericMethods.empty());
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
	for (size_t i = 0; i < stackOfAddedGenericMethods.back(); ++i)
	{
		assert(!genericMethods.empty());
		if (genericMethods.back().second)
			inheritedMethodsRealSize--;
		genericMethods.pop_back();
	}
	numberOfEveryMethodThatWasFoundOnTheWay -= treeClassDescription->getMethods().size();
	stackOfAddedGenericMethods.pop_back();
}

void InheritanceAndPolymorphismFactorVisitor::visitBack(TreeInterfaceDescription const*) 
{
	// This class should be ran only on classes, its cannot get into interfaces. Otherwise it's a bug.
	assert(true);
}

}} // end of namespace JWB::details