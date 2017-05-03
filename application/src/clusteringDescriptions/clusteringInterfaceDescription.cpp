#include <cassert>
#include <iostream>
#include <unordered_set>

#include "accessModifier.hpp"
#include "clusteringInterfaceDescription.hpp"

using std::string;
using std::unordered_set;
using std::move;
using std::shared_ptr;
using std::vector;

namespace JWB {	namespace details {

ClusteringInterfaceDescription::ClusteringInterfaceDescription(string interfaceName) :
	name(move(interfaceName))
{
	assert(!name.empty());
}

void ClusteringInterfaceDescription::addMethod(shared_ptr<ClusteringMethodDescription> const &methodPtr)
{
	assert(methodPtr.get());
	methods.insert({methodPtr->getName(), methodPtr});
}

size_t ClusteringInterfaceDescription::getNumberOfMethods() const
{
	return methods.size();
}

size_t ClusteringInterfaceDescription::getNumberOfPrivateMethods() const
{
	size_t numOfMethods = 0;

	for (auto const& m : methods)
	{
		if (m.second->getAccessModifier() == AccessModifier::PRIVATE)
			numOfMethods++;
	}

	return numOfMethods;
}

string const& ClusteringInterfaceDescription::getName() const
{
	return name;
}

std::unordered_map <std::string, std::shared_ptr <ClusteringMethodDescription> > const& ClusteringInterfaceDescription::getMethods() const
{
	return methods;
}


}}
