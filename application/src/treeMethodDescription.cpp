#include <cassert>

#include "treeMethodDescription.hpp"

using std::vector;
using std::string;
using std::move;
using std::hash;

namespace JWB {	namespace details {

TreeMethodDescription::TreeMethodDescription(string methodName, AccessModifier const accessModifier, string returnType) :
	name(move(methodName)),
	returnType(move(returnType)),
	accessModifier(accessModifier),
	lazyHash(0),
	lazyHashUpdateNeed(true)
{
	assert(!this->name.empty());
	assert(!this->returnType.empty());
}

bool TreeMethodDescription::operator==(TreeMethodDescription const& method) const
{
	return getId() == method.getId();
}

void TreeMethodDescription::addParam(string paramType)
{
	paramTypes.push_back(move(paramType));
	lazyHashUpdateNeed = true;
}

TreeMethodDescription::TreeMethodDescription(AccessModifier const methodModifier, string methodName, string const &stringForHash) :
	name(move(methodName)),
	returnType("void"),
	accessModifier(methodModifier),
	lazyHash(0),
	lazyHashUpdateNeed(false)
{
	assert(!name.empty());
	assert(!stringForHash.empty());

	hash<string> hasher;
	lazyHash = hasher(stringForHash);
}

string const& TreeMethodDescription::getName() const
{
	return name;
}

string const& TreeMethodDescription::getReturnType() const
{
	return returnType;
}

vector<string const> const& TreeMethodDescription::getParamTypes() const
{
	return paramTypes;
}

AccessModifier TreeMethodDescription::getAccessModifier() const
{
	return accessModifier;
}

void TreeMethodDescription::updateId()
{
	// If hash needs to be updated, update.
	// Hash is valued as hash from sum of strings from class name, param names, return type.
	if (lazyHashUpdateNeed)
	{
		string hashHelper = (char)accessModifier + returnType + name;
		for (auto const& x : paramTypes)
			hashHelper += ',' + x;
		lazyHash = hash<string>()(hashHelper);
		lazyHashUpdateNeed = false;
	}
}

size_t TreeMethodDescription::getId() const
{
	// Assert to verify that there was an invokation of updateHash() between this one and addParam(string).
	assert(!lazyHashUpdateNeed);
	return lazyHash;
}

}} // end of namespace JWB::details