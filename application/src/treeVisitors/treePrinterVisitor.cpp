#include "treePrinterVisitor.hpp"
#include <iostream>

using std::unordered_set;
using std::cout;
using std::endl;

namespace JWB {	namespace details {

TreePrinterVisitor::TreePrinterVisitor(unordered_set<Node const*>& filter, ReturnVisitorStatus<TreePrinterVisitor>& result) :
	Visitor(filter),
	result(result)
	{}

void TreePrinterVisitor::visit(TreeClassDescription const* treeClassDescription)
{
	cout << "Class visited!" << endl;
	cout << treeClassDescription->getName() << " methods:" << endl;
	for (auto const x : treeClassDescription->getMethods())
	{
		if (x->getIsGeneric())
			cout << "Generic ";
		cout << x->getReturnType() << " " << x->getName() << " : ";
		for (auto const y : x->getParamTypes())
		{
			cout << y << " ";
		}
		cout << endl;
	}
	for (auto const x : treeClassDescription->getAttributes())
	{
		cout << x->getType() << " " << x->getName() << endl;
	}
	cout << endl;
}

void TreePrinterVisitor::visit(TreeInterfaceDescription const* treeInterfaceDescription)
{
	cout << "Interface visited!" << endl;
	cout << treeInterfaceDescription->getName() << " methods:" << endl;
	for (auto const x : treeInterfaceDescription->getMethods())
	{
		if (x->getIsGeneric())
			cout << "Generic ";
		cout << x->getReturnType() << " " << x->getName() << " : ";
		for (auto const y : x->getParamTypes())
		{
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void TreePrinterVisitor::visitBack(TreeClassDescription const*) {}

void TreePrinterVisitor::visitBack(TreeInterfaceDescription const*) {}

}} // end of namespace JWB::details