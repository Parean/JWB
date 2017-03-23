#include <iostream>
#include <cassert>

#include "classDescription.hpp"

using std::string;
using std::move;
using std::cout;
using std::endl;

namespace JWB {	namespace details {

ClassDescription::ClassDescription(string className) :
	// Assert on emptiness is inside InterfaceDescription
	InterfaceDescription(move(className))
{}

void ClassDescription::addAttribute(AccessModifier modifier, string newAttribute)
{
	assert(!newAttribute.empty());
	attributes.push_back(move(newAttribute));

	if (modifier == AccessModifier::PRIVATE)
		privateAttributes.push_back(move(&newAttribute));
}

size_t ClassDescription::getNumberOfAttributes() const
{
	return attributes.size();
}

size_t ClassDescription::getNumberOfPrivateAttributes() const
{
	return privateAttributes.size();
}

size_t ClassDescription::getAverageCyclomaticComplexity() const
{
	int sumOfIndependentPaths = 0;

	for (auto const& m : methods)
		sumOfIndependentPaths += m->getIndependentPaths();

	if (methods.empty())
		return 0;

	return	(double)sumOfIndependentPaths / methods.size() + 0.5;
}

}}
