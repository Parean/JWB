#include <cassert>
#include <algorithm>
#include <iostream>

#include "clusteringMethodDescription.hpp"

using std::string;
using std::move;
using std::hash;
using std::shared_ptr;
using std::unordered_map;
using std::unordered_set;
using std::vector;

namespace JWB {	namespace details {

ClusteringMethodDescription::ClusteringMethodDescription(AccessModifier methodModifier, string methodName, string const &stringForHash) :
	accessModifier(move(methodModifier)),
	name(move(methodName))
{
	assert(!name.empty());
	assert(!stringForHash.empty());

	hash<string> hasher;
	id = hasher(stringForHash);
}

void ClusteringMethodDescription::updateCalledMethods(std::unordered_map <std::string, std::shared_ptr <ClusteringMethodDescription> > const& classMethods)
{
	for (auto const& m : calledMethods)
	{
		if (classMethods.find(m.first) == classMethods.end())
			m.second->type = TypeOfCalledMethod::DIFFERENT_CLASS_METHOD;
		else
			m.second->type = TypeOfCalledMethod::CURRENT_CLASS_METHOD;
	}
}

void ClusteringMethodDescription::updateUsedAttributes(std::unordered_set<std::string> const& attributes)
{
	for (auto const& s : staticAttributes)
	{
		if (attributes.find(s) != attributes.end())
			addUsedAttribute(s);
		else
			usedAttributes.erase(s);
	}
}

string const& ClusteringMethodDescription::getName() const
{
	return name;
}

AccessModifier const& ClusteringMethodDescription::getAccessModifier() const
{
	return accessModifier;
}

void ClusteringMethodDescription::addUsedAttribute(string attribute)
{
	usedAttributes.insert(move(attribute));
}

void ClusteringMethodDescription::addStaticAttribute(string attribute)
{
	staticAttributes.insert(move(attribute));
}


unordered_set<string> const& ClusteringMethodDescription::getUsedAttributes() const
{
	return usedAttributes;
}

void ClusteringMethodDescription::addCalledMethod(string methodName, TypeOfCalledMethod typeOfCalledMethod)
{
	auto foundMethod = calledMethods.find(methodName);

	if (foundMethod != calledMethods.end())
		foundMethod->second->numberOfCalls++;
	else
		calledMethods.insert({move(methodName), std::shared_ptr<CalledMethod>(new CalledMethod(1, typeOfCalledMethod))});
}

unordered_map<string, shared_ptr<CalledMethod>> const& ClusteringMethodDescription::getCalledMethods() const
{
	return calledMethods;
}

void ClusteringMethodDescription::addParameter(string parameterName)
{
	parameters.push_back(move(parameterName));
}

void ClusteringMethodDescription::addUsedLocalVariable(string variable)
{
	auto foundVariable = usedLocalVariables.find(variable);

	if(foundVariable == usedLocalVariables.end())
		usedLocalVariables.insert({move(variable), 1});
	else
		foundVariable->second++;
}

unordered_map<string, int> const& ClusteringMethodDescription::getUsedLocalVariables() const
{
	return usedLocalVariables;
}

vector<string> const& ClusteringMethodDescription::getParameters() const
{
	return parameters;
}

size_t ClusteringMethodDescription::getNumberOfCall(string const& methodName) const
{
	auto foundMethod = calledMethods.find(methodName);

	if (foundMethod != calledMethods.end())
		return foundMethod->second->numberOfCalls;

	return 0;
}

size_t ClusteringMethodDescription::getId() const
{
	return id;
}

void ClusteringMethodDescription::bumpIndependentPaths()
{
	independentPaths++;
}

void ClusteringMethodDescription::bumpIndependentPaths(size_t number)
{
	independentPaths += number;
}

size_t ClusteringMethodDescription::getIndependentPaths() const
{
	return independentPaths;
}
}}
