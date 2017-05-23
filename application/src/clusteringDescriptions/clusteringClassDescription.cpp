#include <iostream>
#include <cassert>
#include <algorithm>

#include "clusteringClassDescription.hpp"

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::move;
using std::cout;
using std::endl;
using std::find;
using std::forward_list;
using std::shared_ptr;

namespace JWB {	namespace details {

ClusteringClassDescription::ClusteringClassDescription(string className) :
	// Assert on emptiness is inside ClusteringInterfaceDescription
	ClusteringInterfaceDescription(move(className))
{}


ClusteringClassDescription::ClusteringClassDescription(ClusteringClassDescription *class1, ClusteringClassDescription *class2):
	ClusteringInterfaceDescription(class1->getName() + class2->getName())
{
	attributes = class1->getAttributes();
	auto class2Attributes = class2->getAttributes();
	attributes.insert(class2Attributes.begin(), class2Attributes.end());

	usedClasses = class1->getUsedClasses();
	auto class2UsedClasses = class2->getUsedClasses();
	usedClasses.insert(class2UsedClasses.begin(), class2UsedClasses.end());
	usedClasses.erase(class1->getName());
	usedClasses.erase(class2->getName());

	usingClasses = class1->getUsingClasses();
	auto class2UsingClasses = class2->getUsingClasses();
	usingClasses.insert(class2UsingClasses.begin(), class2UsingClasses.end());
	usingClasses.erase(class1->getName());
	usingClasses.erase(class2->getName());

	methods = class1->getMethods();
	auto class2Methods = class2->getMethods();
	methods.insert(class2Methods.begin(), class2Methods.end());
}

ClusteringClassDescription::ClusteringClassDescription(shared_ptr<ClusteringMethodDescription> method):
	ClusteringInterfaceDescription(method->getName())
{
	attributes = method->getUsedAttributes();
	methods.insert({method->getName(), method});
}

void ClusteringClassDescription::addAttribute(AccessModifier modifier, string newAttribute)
{
	assert(!newAttribute.empty());
	attributes.insert(move(newAttribute));

	if (modifier == AccessModifier::PRIVATE)
		privateAttributes.push_back(&newAttribute);
}

unordered_set<string> const& ClusteringClassDescription::getAttributes() const
{
	return attributes;
}

void ClusteringClassDescription::addUsedClass(string const &className, CouplingType type)
{
	addCoupling(className, type, usedClasses);
}

void ClusteringClassDescription::addUsingClass(string const &className, CouplingType type)
{
	addCoupling(className, type, usingClasses);
}

void ClusteringClassDescription::addCoupling(
	string const &className,
	CouplingType type,
	unordered_map<string, forward_list <CouplingType> > &classes
)
{
	auto foundClass = classes.find(className);
	if (foundClass != classes.end())
	{
		if (find(foundClass->second.begin(), foundClass->second.end(), type) != foundClass->second.end())
			return;
		else
			foundClass->second.push_front(type);
	}

	// usedClasses.emplace(className, new forward_list<CouplingType>(1, type));
	classes.insert({className, forward_list<CouplingType>(1, type)});
}

unordered_map<string, forward_list <CouplingType> > const& ClusteringClassDescription::getUsedClasses() const
{
	return usedClasses;
}

unordered_map<string, forward_list <CouplingType> > const& ClusteringClassDescription::getUsingClasses() const
{
	return usingClasses;
}

size_t ClusteringClassDescription::getNumberOfAttributes() const
{
	return attributes.size();
}

size_t ClusteringClassDescription::getNumberOfPrivateAttributes() const
{
	return privateAttributes.size();
}

size_t ClusteringClassDescription::getAverageCyclomaticComplexity() const
{
	int sumOfIndependentPaths = 0;

	for (auto const& m : methods)
		sumOfIndependentPaths += m.second->getIndependentPaths();

	if (methods.empty())
		return 0;

	return	(double)sumOfIndependentPaths / methods.size() + 0.5;
}

string ClusteringClassDescription::getStringCouplingType(CouplingType type)
{
	switch (type)
	{
		case CouplingType::PARAMETER : return "parameter";
		case CouplingType::ATTRIBUTE : return "attribute";
		case CouplingType::VARIABLE : return "variable";
		case CouplingType::STATIC : return "static";
	}
}

}}
