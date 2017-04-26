#pragma once

#include <string>

#include "accessModifier.hpp"

namespace JWB {	namespace details {

class TreeAttributeDescription
{
public:
	TreeAttributeDescription() = delete;
	TreeAttributeDescription(TreeAttributeDescription const&) = delete;
	TreeAttributeDescription(TreeAttributeDescription&&) = delete;
	TreeAttributeDescription& operator=(TreeAttributeDescription const&) = delete;
	TreeAttributeDescription& operator=(TreeAttributeDescription&&) = delete;

	TreeAttributeDescription(std::string type, std::string attributeName, AccessModifier const attributeModifier);

	std::string const& getType() const;
	std::string const& getName() const;
	AccessModifier getAccessModifier() const;

private:
	std::string const type;
	std::string const name;
	AccessModifier const attributeModifier;
};

}} //end of namespace JWB::details