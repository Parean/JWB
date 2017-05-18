#pragma once

#include <vector>
#include <string>
#include <cassert>

#include "accessModifier.hpp"

namespace JWB {	namespace details {
/// @class TreeMethodDescription
/// @brief Description of a Java method. Contains its name, access modifier, list of parameters and return type.
class TreeMethodDescription
{
public:
	TreeMethodDescription() = delete;
	TreeMethodDescription(TreeMethodDescription const&) = delete;
	TreeMethodDescription(TreeMethodDescription&&) = delete;
	TreeMethodDescription& operator=(TreeMethodDescription const&) = delete;
	TreeMethodDescription& operator=(TreeMethodDescription&&) = delete;

	template <bool isGenericCompileTime = false>
	TreeMethodDescription(std::string methodName, AccessModifier const accessModifier, std::string returnType) :
	name(move(methodName)),
	returnType(move(returnType)),
	accessModifier(accessModifier),
	isGeneric(isGenericCompileTime),
	lazyHash(0),
	lazyHashUpdateNeed(true)
{
	assert(!this->name.empty());
	assert(!this->returnType.empty());
}

	template <bool isGenericCompileTime = false>
	TreeMethodDescription(AccessModifier const methodModifier, std::string methodName, std::string const &stringForHash) :
	name(move(methodName)),
	returnType("void"),
	accessModifier(methodModifier),
	isGeneric(isGenericCompileTime),
	lazyHash(std::hash<std::string>()(stringForHash)),
	lazyHashUpdateNeed(false)
{
	assert(!name.empty());
	assert(!stringForHash.empty());
}

	/// Adds parameter type to paramTypes. Is used to construct method.
	/// While params are added, TreeMethodDescription should be threated as invalid.
	void addParam(std::string paramType);

	bool operator==(TreeMethodDescription const& method) const;

	std::string const& getName() const;
	std::string const& getReturnType() const;

	/// Returns list of parameter types.
	std::vector<std::string> const& getParamTypes() const;

	/// Returns access modifier of current method in interface/class container.
	AccessModifier getAccessModifier() const;

	bool getIsGeneric() const;

	/// Updates hash, used to distinguish methods by their signatures.
	void updateId();

	/// Returns set hash.
	// Should not be used, if there was not invokation of updateHash() between this and addParam(string).
	size_t getId() const;

private:
	std::string const name;
	std::string const returnType;
	std::vector<std::string> paramTypes;
	AccessModifier const accessModifier;

	bool isGeneric = false;

	size_t lazyHash;
	bool lazyHashUpdateNeed;
};

namespace methodComparison
{
	bool compare(TreeMethodDescription const& firstMethod, TreeMethodDescription const& secondMethod);
	bool isWider(TreeMethodDescription const& firstMethod, TreeMethodDescription const& secondMethod);
}// end of namespace JWD::details::methodComparison

}} // end of namespace JWB::details
