#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>

#include "accessModifier.hpp"

namespace JWB {	namespace details {

enum class TypeOfCalledMethod
{
	CURRENT_CLASS_METHOD,
	DIFFERENT_CLASS_METHOD
};

// It represent pair of values which consists of the type of the called method and the number of its calls
struct CalledMethod
{
	CalledMethod(size_t numOfCalls, TypeOfCalledMethod typeOfCalledMethod):
		numberOfCalls(numOfCalls),
		type(typeOfCalledMethod) {}
	size_t numberOfCalls;
	TypeOfCalledMethod type;
};

/// @class ClusteringMethodDescription
/// @brief Description of a Java method, contains it's id, name, access modifier, parameters, used attributes and used local variables
class ClusteringMethodDescription
{
public:

	ClusteringMethodDescription() = delete;
	ClusteringMethodDescription(ClusteringMethodDescription const&) = delete;
	ClusteringMethodDescription(ClusteringMethodDescription&&) = delete;
	ClusteringMethodDescription& operator=(ClusteringMethodDescription const&) = delete;
	ClusteringMethodDescription& operator=(ClusteringMethodDescription&&) = delete;

	// The constructor takes std::string as a third parameter to hash it and make hash the identifier of the method
	ClusteringMethodDescription(AccessModifier methodModifier, std::string methodName, std::string const &stringForHash);

	void addCalledMethod(std::string methodName, TypeOfCalledMethod typeOfCalledMethod);
	void addParameter(std::string parameterName);
	void addUsedLocalVariable(std::string localVariable);
	void addUsedAttribute(std::string attribute);

	// If in method there is a
	void addStaticAttribute(std::string attribute);

	std::string const& getName() const;
	AccessModifier const& getAccessModifier() const;
	size_t getId() const;
	size_t getIndependentPaths() const;
	size_t getNumberOfCall(std::string const& methodName) const;
	std::vector<std::string> const& getParameters() const;
	std::unordered_set<std::string> const& getUsedAttributes() const;
	std::unordered_map<std::string, std::shared_ptr<CalledMethod>> const& getCalledMethods() const;
	std::unordered_map<std::string, int> const& getUsedLocalVariables() const;

	// These methods needed to update data of ClusteringMethodDescription during the clustering
	void updateCalledMethods(std::unordered_map <std::string, std::shared_ptr <ClusteringMethodDescription> > const& classMethods);
	void updateUsedAttributes(std::unordered_set<std::string> const& attributes);

	void bumpIndependentPaths();
	void bumpIndependentPaths(size_t number);

private:

	AccessModifier const accessModifier;
	std::vector<std::string> parameters;
	std::unordered_set<std::string> usedAttributes;
	std::unordered_map<std::string, int> usedLocalVariables;

	// If there is a static attribute of another class, that used in this method, it is stored here
	std::unordered_set<std::string> staticAttributes;

	std::string const name;
	size_t id;

	// It is a quantitative measure of the number of linearly independent paths through a method's source code
	size_t independentPaths = 1;

	// It contains methods that called from this method
	std::unordered_map<std::string, std::shared_ptr<CalledMethod>> calledMethods;
};

}}
