#include "analyzeSimultanInhAndPolyVisitor.hpp"
#include "node.hpp"

#include <vector>
#include <cassert>
#include <functional>
#include <cassert>
#include <bitset>
#include <iostream>

using std::unordered_set;
using std::vector;
using std::pair;
using std::function;
using std::hash;
using std::unordered_map;
using std::bitset;
using std::cout;
using std::endl;

// It is here not to use vector<bool>.
using boolForVector = char;

namespace JWB {	namespace details {

AnalyzeSimultanInhAndPolyVisitor::AnalyzeSimultanInhAndPolyVisitor(unordered_set<Node const*>& filter, ReturnVisitorStatus<AnalyzeSimultanInhAndPolyVisitor>& result) :
	Visitor(filter),
	inheritedMethodsRealSize(0),
	numberOfEveryMethodThatWasFoundOnTheWay(0),
	result(result)
{}

size_t AnalyzeSimultanInhAndPolyVisitor::hash_for_TreeMethodDescription::operator()(TreeMethodDescription const* p) const
{
	assert(p);
	return p->getId();
}

bool AnalyzeSimultanInhAndPolyVisitor::equal_to_for_TreeMethodDescription::operator()(TreeMethodDescription const* lhs, TreeMethodDescription const* rhs) const
{
	return *lhs == *rhs;
}

void printAccessModifier(AccessModifier accessModifier)
{
	switch(accessModifier)
	{
		case AccessModifier::DEFAULT:
		{
			cout << "default";
			break;
		}
		case AccessModifier::PUBLIC:
		{
			cout << "public";
			break;
		}
		case AccessModifier::PROTECTED:
		{
			cout << "protected";
			break;
		}
		case AccessModifier::PRIVATE:
		{
			cout << "private";
			break;
		}
		default:
		{
			// Can never reach this code.
			assert(false);
		}
	}
}

template <bool isProto = true>
void printSuggestClass(TreeClassDescription const* treeClassDescription, vector<boolForVector> const& methodIsAnOverride)
{
	assert(treeClassDescription);
	assert(treeClassDescription->getMethods().size() == methodIsAnOverride.size());
	cout << "class ";
	cout << " " << treeClassDescription->getName();
	if (isProto)
		cout << "Proto";
	else
		cout << " extends " << treeClassDescription->getName() << "Proto";
	cout << " {" << endl;
	for (size_t i = 0; i < treeClassDescription->getMethods().size(); ++i)
	{
		if (methodIsAnOverride[i] != 2)
			if (methodIsAnOverride[i] ^ isProto)
			{
				cout << "    ";
				printAccessModifier(treeClassDescription->getMethods()[i]->getAccessModifier());
				cout << " " << treeClassDescription->getMethods()[i]->getName() << "(";
				for (size_t j = 0; j < treeClassDescription->getMethods()[i]->getParamTypes().size(); ++j)
				{
					cout << (j == 0 ? "" : ",") << treeClassDescription->getMethods()[i]->getParamTypes()[j];
				}
				cout << ");" << endl;
			}
	}
	cout << "}" << endl;
}

void AnalyzeSimultanInhAndPolyVisitor::visit(TreeClassDescription const* treeClassDescription)
{
	// Seems that Node garantes notemptyness of TreeClassDescription, but still.
	assert(treeClassDescription);

	// Maximum number of possibly inherited methods. It is decremented when override found.
	int64_t possibleInheritanceNumber = inheritedMethodsRealSize;
	stackOfAddedGenericMethods.emplace_back();

	// Were there simultanious inheritance and polymorphism?
	// 0 bit indicates extension, 1 bit indicates polymorphism.
	bitset<2> wereThereSimInhAndPoly = {};

	// Marks method as an override.
	vector<boolForVector> methodIsAnOverride;
	methodIsAnOverride.reserve(treeClassDescription->getMethods().size());

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
					wereThereSimInhAndPoly[0] = 1;
					methodIsAnOverride.push_back(0);
				}
				else
				{
					// Method is overridden.
					possibleInheritanceNumber--;
					wereThereSimInhAndPoly[1] = 1;
					methodIsAnOverride.push_back(1);
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
				wereThereSimInhAndPoly[1] = 1;
				methodIsAnOverride.push_back(1);
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
				wereThereSimInhAndPoly[1] = 1;
				methodIsAnOverride.push_back(1);
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
					wereThereSimInhAndPoly[0] = 1;
					methodIsAnOverride.push_back(0);
				}
				else
				{
					possibleInheritanceNumber--;
					wereThereSimInhAndPoly[1] = 1;
					methodIsAnOverride.push_back(1);
				}
			}
			else
				// Constructor
				methodIsAnOverride.push_back(2);
		}
	}
	if (wereThereSimInhAndPoly.all())
	{
		cout << treeClassDescription->getName() << " is found not to satisfy criteria, it overrides and extends simultaneously." << endl;
		cout << "The following upgrade is suggested:" << endl;
		printSuggestClass(treeClassDescription, methodIsAnOverride);
		printSuggestClass<false>(treeClassDescription, methodIsAnOverride);
	}
}

void AnalyzeSimultanInhAndPolyVisitor::visit(TreeInterfaceDescription const* TreeInterfaceDescription)
{
	// This class should be ran only on classes, its cannot get into interfaces. Otherwise it's a bug.
	assert(true);
}

void AnalyzeSimultanInhAndPolyVisitor::visitBack(TreeClassDescription const* treeClassDescription) 
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

void AnalyzeSimultanInhAndPolyVisitor::visitBack(TreeInterfaceDescription const*) 
{
	// This class should be ran only on classes, its cannot get into interfaces. Otherwise it's a bug.
	assert(true);
}

}} // end of namespace JWB::details