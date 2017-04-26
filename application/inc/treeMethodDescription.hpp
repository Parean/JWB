#pragma once

#include "accessModifier.hpp"
#include <vector>
#include <string>

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
	TreeMethodDescription(std::string methodName, AccessModifier const accessModifier, std::string returnType);
	TreeMethodDescription(AccessModifier const methodModifier, std::string methodName, std::string const &stringForHash);

	/// Adds parameter type to paramTypes. Is used to construct method.
	/// While params are added, TreeMethodDescription should be threated as invalid.
	void addParam(std::string paramType);

	bool operator==(TreeMethodDescription const& method) const;

	std::string const& getName() const;
	std::string const& getReturnType() const;

	/// Returns list of parameter types.
	std::vector<std::string const> const& getParamTypes() const;

	/// Returns access modifier of current method in interface/class container.
	AccessModifier getAccessModifier() const;

	/// Updates hash, used to distinguish methods by their signatures.
	void updateId();

	/// Returns set hash. 
	// Should not be used, if there was not invokation of updateHash() between this and addParam(string).
	size_t getId() const;

private:
	std::string const name;
	std::string const returnType;
	std::vector<std::string const> paramTypes;
	AccessModifier const accessModifier;

	size_t lazyHash;
	bool lazyHashUpdateNeed;
};

}} // end of namespace JWB::details