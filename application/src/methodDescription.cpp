#include <cassert>

#include "methodDescription.hpp"

using std::string;
using std::move;
using std::hash;

namespace JWB {	namespace details {

MethodDescription::MethodDescription(AccessModifier methodModifier, string methodName, string const &stringForHash) :
	accessModifier(move(methodModifier)),
	name(move(methodName))
{
	assert(!name.empty());
	assert(!stringForHash.empty());

	hash<string> hasher;
	id = hasher(stringForHash);
}

string const& MethodDescription::getName() const
{
	return name;
}

AccessModifier const& MethodDescription::getAccessModifier() const
{
	return accessModifier;
}

size_t MethodDescription::getId() const
{
	return id;
}

}}
