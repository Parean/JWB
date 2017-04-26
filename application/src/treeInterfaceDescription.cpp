#include "treeInterfaceDescription.hpp"

#include <cassert>

using std::string;
using std::move;
using std::shared_ptr;
using std::vector;

namespace JWB {	namespace details {

TreeInterfaceDescription::TreeInterfaceDescription(string interfaceName) :
	interfaceName(move(interfaceName))
{
	// interfaceName should never be empty. Otherwise it's a bag.
	assert(!this->interfaceName.empty());	
}

void TreeInterfaceDescription::addMethod(TreeMethodDescription* newMethod)
{
	if (newMethod->getAccessModifier() == AccessModifier::PRIVATE)
		numberOfPrivateMethods++;

	methods.emplace_back(newMethod);
}

string const& TreeInterfaceDescription::getName() const
{
	return interfaceName;
}

vector<shared_ptr<TreeMethodDescription>> const& TreeInterfaceDescription::getMethods() const
{
	return methods;
}

void TreeInterfaceDescription::updateHashes()
{
	for (auto x : methods)
	{
		x->updateId();
	}
}

void TreeInterfaceDescription::takeVisitor(Visitor* visitor) const
{
	// visitor should be never nullptr. Otherwise it's a bag.
	assert(visitor);
	visitor->visit(this);
}

void TreeInterfaceDescription::takeVisitorBack(Visitor* visitor) const
{
	// visitor should be never nullptr. Otherwise it's a bag.
	assert(visitor);
	visitor->visitBack(this);
}

}} // end of namespace JWB::details