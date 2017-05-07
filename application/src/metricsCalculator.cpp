#include <iostream>
#include <cassert>

#include "metricsCalculator.hpp"
#include "customListener.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::shared_ptr;
using namespace antlr4;

namespace JWB {	namespace details {

MetricsCalculator::	MetricsCalculator(AntlrComponentsKeeper &keeper)
{
	tokens = keeper.getTokens();
	auto trees = keeper.getTrees();

	assert(!tokens.empty());
	assert(!trees.empty());

	for (auto const& t : trees)
	{
		CustomListener listener(this);
		tree::ParseTreeWalker::DEFAULT.walk(&listener, t);
	}
}

void MetricsCalculator::bumpNumberSourceLinesOfCode()
{
	numberSourceLinesOfCode++;
}

void MetricsCalculator::bumpNumberSourceLinesOfCode(size_t number)
{
	numberSourceLinesOfCode += number;
}

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


size_t MetricsCalculator::getNumberOfCommentLines() const
{
	size_t numberOfCommentLines = 0;

	for (auto const& ts : tokens)
	{
		for(auto const& t : ts->getTokens())
		{
			// If token is comment, it is located in hidden channel and getChannel() return 1
			// If token doesn't located in hidden channel, getChannel() return 0 and we move on to the next iteration
			if (!t->getChannel())
				continue;

			if (t->getText().substr(0,2) == "//")
			{
				numberOfCommentLines++;
				continue;
			}

			// We count the number of lines in the comments, so in a multiline comment, we need to count the line feed characters
			for(auto const& c : t->getText())
			{
				if (c == '\n')
					numberOfCommentLines++;
			}

			// Last line hasn`t feed character
			numberOfCommentLines++;
		}
	}

	return numberOfCommentLines;
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
	size_t numOfMethods = 0;
	size_t numOfPrivateMethods = 0;

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
	size_t numOfAttributes = 0;
	size_t numOfPrivateAttributes = 0;

	for (auto const& c : classes)
	{
		numOfAttributes += c->getNumberOfAttributes();
		numOfPrivateAttributes += c->getNumberOfPrivateAttributes();
	}

	if (!numOfAttributes)
		return 0;

	return (double)numOfPrivateAttributes / numOfAttributes;
}

size_t MetricsCalculator::getSourceLinesOfCode() const
{
	return numberSourceLinesOfCode;
}

double MetricsCalculator::getCommentPercentage() const
{
	return (double)getNumberOfCommentLines() / getSourceLinesOfCode();
}

void MetricsCalculator::showCyclomaticComplexities() const
{
	cout << endl << "Cyclomatic complexities:" << endl;
	for (auto const& c : classes)
	{
		cout << endl << "> " << c->getName() << endl;
		auto const& methods = c->getMethods();

		for (auto m : methods)
		{
			cout << m->getName() << " — " << m->getIndependentPaths() << endl;
		}

		cout << "Average cyclomatic complexity — " << c->getAverageCyclomaticComplexity() << endl;
	}
}

size_t MetricsCalculator::getAverageCyclomaticComplexity() const
{
	int sumOfCyclomaticComplexities = 0;

	for (auto const& c : classes)
		sumOfCyclomaticComplexities += c->getAverageCyclomaticComplexity();

	if (classes.empty())
		return 0;

	return	(double)sumOfCyclomaticComplexities / classes.size() + 0.5;
}

}}
