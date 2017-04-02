#include <iostream>
#include <cassert>

#include "metricsCalculator.hpp"

using std::cout;
using std::endl;
using std::shared_ptr;

namespace JWB {	namespace details {

void MetricsCalculator::addClass(shared_ptr <const ClassDescription> const &classPtr)
{
	assert(classPtr.get());
	classes.push_back(classPtr);
}

void MetricsCalculator::addInterface(shared_ptr <const InterfaceDescription> const &interfacePtr)
{
	assert(interfacePtr.get());
	interfaces.push_back(interfacePtr);
}

void MetricsCalculator::showNumberOfMethods() const
{
	for (auto const& c : classes)
	{
		cout << c->getName()  << " has " << c->getNumberOfMethods() << " methods, "
			 << c->getNumberOfPrivateMethods() << " of which is private." << endl;
	}
	for (auto const& i : interfaces)
	{
		cout << i->getName()  << " has " << i->getNumberOfMethods() << " methods, "
		 	 << i->getNumberOfPrivateMethods() << " of which is private." << endl;
	}
}

void MetricsCalculator::showNumberOfFields() const
{
	for (auto const& c : classes)
	{
		cout << c->getName()  << " has " << c->getNumberOfAttributes() << " attributes, "
		 	 << c->getNumberOfPrivateAttributes() << " of which is private." << endl;
	}
}

double MetricsCalculator::getMethodHidingFactor() const
{
	int numOfMethods = 0;
	int numOfPrivateMethods = 0;

	for (auto const& c : classes)
	{
		numOfMethods += c->getNumberOfMethods();
		numOfPrivateMethods += c->getNumberOfPrivateMethods();
	}

	for (auto const& i : interfaces)
	{
		numOfMethods += i->getNumberOfMethods();
		numOfPrivateMethods += i->getNumberOfPrivateMethods();
	}

	if (!numOfMethods)
		return 0;

	return (double)numOfPrivateMethods / numOfMethods;
}

double MetricsCalculator::getAttributeHidingFactor() const
{
	int numOfAttributes = 0;
	int numOfPrivateAttributes = 0;

	for (auto const& c : classes)
	{
		numOfAttributes += c->getNumberOfAttributes();
		numOfPrivateAttributes += c->getNumberOfPrivateAttributes();
	}

	if (!numOfAttributes)
		return 0;

	return (double)numOfPrivateAttributes / numOfAttributes;
}

}}
