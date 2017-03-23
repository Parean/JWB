#pragma once

#include <string>

#include "accessModifier.hpp"

namespace JWB {	namespace details {

/// @class MethodDescription
/// @brief Description of a Java method, contains it's name and access modifier
class MethodDescription
{
	public:
		MethodDescription() = delete;
		MethodDescription(MethodDescription const&) = delete;
		MethodDescription(MethodDescription&&) = delete;
		MethodDescription& operator=(MethodDescription const&) = delete;
		MethodDescription& operator=(MethodDescription&&) = delete;

		// The constructor takes std::string as a third parameter to hash it and make hash the identifier of the method
		MethodDescription(AccessModifier methodModifier, std::string methodName, std::string const &stringForHash);

		std::string const& getName() const;
		size_t getId() const;
		AccessModifier const& getAccessModifier() const;

	private:
		AccessModifier accessModifier;
		std::string const name;
		size_t id;
};

}}
