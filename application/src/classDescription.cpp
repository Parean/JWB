#include "classDescription.hpp"

#include <cassert>

using std::string;
using std::move;

namespace JWB {	namespace details {

ClassDescription::ClassDescription(string className) :
	InterfaceDescription(move(className)) // Assert on emptiness is inside InterfaceDescription
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

}}
