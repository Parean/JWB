#include "treeClassDescription.hpp"

#include <cassert>

using std::string;
using std::move;
using std::vector;

namespace JWB {	namespace details {

TreeClassDescription::TreeClassDescription(string className) :
	TreeInterfaceDescription(move(className)) // Assert on emptiness is inside TreeInterfaceDescription.
{}

void TreeClassDescription::addAttribute(TreeAttributeDescription const* treeAttributeDescription)
{
	// treeAttributeDescription should never be nullptr. Otherwise it's a bag.
	assert(treeAttributeDescription);
	attributes.emplace_back(treeAttributeDescription);
}

vector<TreeAttributeDescription const*> const& TreeClassDescription::getAttributes() const
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