#include <cassert>
#include <iostream>

#include "accessModifier.hpp"
#include "interfaceDescription.hpp"

using std::string;
using std::move;
using std::shared_ptr;
using std::vector;

namespace JWB {	namespace details {

InterfaceDescription::InterfaceDescription(string interfaceName) :
	name(move(interfaceName))
{
	assert(!name.empty());
}

void InterfaceDescription::addMethod(shared_ptr<const MethodDescription> const &methodPtr)
{
	assert(methodPtr.get());
	methods.push_back(methodPtr);
}


void InterfaceDescription::addMethod(MethodDescription const *methodPtr)
{
	assert(methodPtr);
	methods.emplace_back(methodPtr);
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

vector <shared_ptr <const MethodDescription> > const& InterfaceDescription::getMethods() const
{
	return methods;
}

}}
