#include <cassert>
#include <iostream>

#include "accessModifier.hpp"
#include "interfaceDescription.hpp"

using std::string;
using std::move;

namespace JWB {	namespace details {

InterfaceDescription::InterfaceDescription(string interfaceName) :
	name(move(interfaceName))
{
	assert(!name.empty());
}

void InterfaceDescription::addMethod(MethodDescription const *newMethod)
{
	assert(newMethod);
	methods.emplace_back(newMethod);
}

size_t InterfaceDescription::getNumberOfMethods() const
{
	return methods.size();
}

size_t InterfaceDescription::getNumberOfPrivateMethods() const
{
	size_t numOfMethods = 0;

	for (auto const& m : methods)
	{
		if (m->getAccessModifier() == AccessModifier::PRIVATE)
			numOfMethods++;
	}

	return numOfMethods;
}

string const& InterfaceDescription::getName() const
{
	return name;
}

}}
