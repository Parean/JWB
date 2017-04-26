#include "treeClassDescription.hpp"

#include <cassert>

using std::string;
using std::move;
using std::vector;

namespace JWB {	namespace details {

TreeClassDescription::TreeClassDescription(string className) :
	TreeInterfaceDescription(move(className)) // Assert on emptiness is inside TreeInterfaceDescription.
{}

void TreeClassDescription::addAttribute(AccessModifier modifier, string newAttribute)
{
	// newAttribute should never be empty. Otherwise it's a bag.
	assert(!newAttribute.empty());
	attributes.push_back(move(newAttribute));

	if (modifier == AccessModifier::PRIVATE)
		privateAttributes.push_back(move(&newAttribute));
}

vector<string> const& TreeClassDescription::getAttributes()
{
	return attributes;
}

void TreeClassDescription::takeVisitor(Visitor* visitor) const
{
	// visitor should be never nullptr. Otherwise it's a bag.
	assert(visitor);
	visitor->visit(this);
}

void TreeClassDescription::takeVisitorBack(Visitor* visitor) const
{
	// visitor should be never nullptr. Otherwise it's a bag.
	assert(visitor);
	visitor->visitBack(this);
}

}} // end of namespace JWB::details