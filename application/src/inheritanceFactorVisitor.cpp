#include "inheritanceFactorVisitor.hpp"
#include "node.hpp"

#include <vector>
#include <cassert>
#include <functional>
#include <cassert>

#include <iostream>
using std::cout;
using std::endl;

using std::unordered_set;
using std::vector;
using std::pair;
using std::function;
using std::hash;
using std::unordered_map;

namespace JWB {	namespace details {

InheritanceFactorVisitor::InheritanceFactorVisitor(unordered_set<Node const*>& filter, ReturnVisitorStatus<InheritanceFactorVisitor>& result) :
	Visitor(filter),
	result(result)
{}

/// @class TreeOfClassesInheritanceVisitor
/// @brief Visitor throw line of class, binded by inheritance. 
class InheritanceFactorVisitor::TreeOfClassesInheritanceVisitor : public Visitor
{
public:
	TreeOfClassesInheritanceVisitor() = delete;
	TreeOfClassesInheritanceVisitor(TreeOfClassesInheritanceVisitor const&) = delete;
	TreeOfClassesInheritanceVisitor(TreeOfClassesInheritanceVisitor&&) = delete;
	TreeOfClassesInheritanceVisitor& operator=(TreeOfClassesInheritanceVisitor const&) = delete;
	TreeOfClassesInheritanceVisitor& operator=(TreeOfClassesInheritanceVisitor&&) = delete;

	/// Takes filter that will contain visited nodes. Is the same with InheritanceFactorVisitor object.
	TreeOfClassesInheritanceVisitor(unordered_set<Node const*>& filter, size_t& totalMethodNumber, size_t& inheritedMethodNumber) :
		Visitor(filter),
		totalMethodNumber(totalMethodNumber),
		inheritedMethodNumber(inheritedMethodNumber)
	{}

	void visit(TreeClassDescription const* TreeClassDescription)
	{
		// Seems that Node garantes notemptyness of TreeClassDescription, but still.
		assert(TreeClassDescription);

		/// Maximum number of possibly inherited methods. It is decremented when override found.
		size_t possibleInheritanceNumber = inheritedMethodsRealSize;

		for (auto const x : TreeClassDescription->getMethods())
		{
			totalMethodNumber++;

			// If method is in inheritedMethods, then it is overriden and not inherited. 
			// If it is not private, it can be inherited.
			auto iter = inheritedMethods.find(x.get());
			if (iter != inheritedMethods.cend())
			{
				iter->second++;
				inheritedMethodsRealSize++;
				possibleInheritanceNumber--;
			}
			inheritedMethods.insert({x.get(), 1});
			inheritedMethodsRealSize++;
		}

		inheritedMethodNumber += possibleInheritanceNumber;
	}

	void visit(TreeInterfaceDescription const* TreeInterfaceDescription)
	{
		// This class should be ran only on classes, its cannot get into interfaces. Otherwise it's a bug.
		assert(true);
	}

	void visitBack(TreeClassDescription const* TreeClassDescription) 
	{
		for (auto const x : TreeClassDescription->getMethods())
		{
			auto iter = inheritedMethods.find(x.get());
			if (iter != inheritedMethods.cend())
			{
				iter->second--;
				inheritedMethodsRealSize--;
				if (!iter->second)
				{
					inheritedMethods.erase(iter);
				}
			}
		}
	}

	void visitBack(TreeInterfaceDescription const*) 
	{
		// This class should be ran only on classes, its cannot get into interfaces. Otherwise it's a bug.
		assert(true);
	}

private:
	struct TreeMethodDescriptionHash
	{
		size_t operator()(TreeMethodDescription const* p) const
		{
			assert(p);
			return p->getId();
		}
	};

	unordered_map<TreeMethodDescription const*, size_t, TreeMethodDescriptionHash> inheritedMethods;
	size_t inheritedMethodsRealSize;
	size_t& totalMethodNumber;
	size_t& inheritedMethodNumber;
};

void InheritanceFactorVisitor::visit(TreeClassDescription const* TreeClassDescription)
{
	assert(node);
	TreeOfClassesInheritanceVisitor helperVisitor(Visitor::filter, result.totalMethodNumber, result.inheritedMethodNumber);
	takeVisitorDown(&helperVisitor, node);
}

void InheritanceFactorVisitor::visit(TreeInterfaceDescription const* TreeInterfaceDescription)
{}

void InheritanceFactorVisitor::visitBack(TreeClassDescription const*) {}

void InheritanceFactorVisitor::visitBack(TreeInterfaceDescription const*) {}

}} // end of namespace JWB::details