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

void TreePrinterVisitor::visit(TreeClassDescription const* TreeClassDescription)
{
	cout << "Class visited!" << endl;
	cout << TreeClassDescription->getName() << " methods:" << endl;
	for (auto const x : TreeClassDescription->getMethods())
	{
		cout << x->getReturnType() << " " << x->getName() << " : ";
		for (auto const y : x->getParamTypes())
		{
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void TreePrinterVisitor::visit(TreeInterfaceDescription const* TreeInterfaceDescription)
{
	cout << "Interface visited!" << endl;
	cout << TreeInterfaceDescription->getName() << " methods:" << endl;
	for (auto const x : TreeInterfaceDescription->getMethods())
	{
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