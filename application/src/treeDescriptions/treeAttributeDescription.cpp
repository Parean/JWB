#include "treeAttributeDescription.hpp"

using std::string;
using std::move;

namespace JWB {namespace details {

TreeAttributeDescription::TreeAttributeDescription(string type, string attributeName, AccessModifier const attributeModifier) :
	type(move(type)),
	name(move(attributeName)),
	attributeModifier(attributeModifier)
	{}

string const& TreeAttributeDescription::getType() const
{
	return type;
}

string const& TreeAttributeDescription::getName() const
{
	return name;
}

AccessModifier TreeAttributeDescription::getAccessModifier() const
{
	return attributeModifier;
}

}}