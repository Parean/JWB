#pragma once

#include <string>
#include <memory>
#include <vector>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>

#include "accessModifier.hpp"
#include "clusteringInterfaceDescription.hpp"

namespace JWB {	namespace details {

enum class CouplingType
{
	ATTRIBUTE,
	PARAMETER,
	VARIABLE,
	STATIC
};

/// @class ClusteringClassDescription
/// @brief Description of a Java class, contains it's name, attributes, used and using classes
class ClusteringClassDescription : public ClusteringInterfaceDescription
{
public:

	ClusteringClassDescription() = delete;
	ClusteringClassDescription(ClusteringClassDescription const&) = delete;
	ClusteringClassDescription(ClusteringClassDescription&&) = delete;
	ClusteringClassDescription& operator=(ClusteringClassDescription const&) = delete;
	ClusteringClassDescription& operator=(ClusteringClassDescription&&) = delete;

	ClusteringClassDescription(std::string className);

	// It combines two existing classes into one that is necessary for clustering
	ClusteringClassDescription(ClusteringClassDescription *class1, ClusteringClassDescription *class2);

	// It constructs class that consists from one method, that is also necessary for clustering
	ClusteringClassDescription(std::shared_ptr<ClusteringMethodDescription> method);

	void addAttribute(AccessModifier modifier, std::string newAttribute);
	void addUsedClass(std::string const &className, CouplingType type);
	void addUsingClass(std::string const &className, CouplingType type);

	// It is called by one of the previous two functions and implements the addition,
	// taking as third parameter either usedClasses or usingClasses
	void addCoupling(
		std::string const &className,
		CouplingType type,
		std::unordered_map<std::string, std::forward_list <CouplingType> > &classes
	);

	std::unordered_map<std::string, std::forward_list <CouplingType> > const& getUsedClasses() const;
	std::unordered_map<std::string, std::forward_list <CouplingType> > const& getUsingClasses() const;

	size_t getNumberOfAttributes() const;
	size_t getNumberOfPrivateAttributes() const;
	size_t getAverageCyclomaticComplexity() const;
	std::unordered_set<std::string> const& getAttributes() const;

	// It used to convert variable of enum CouplingType into std::string
	std::string static getStringCouplingType(CouplingType type);

private:

	std::unordered_set<std::string> attributes;
	std::vector<std::string const*> privateAttributes;

	// Contains classes, that use current class
	std::unordered_map<std::string, std::forward_list <CouplingType> > usingClasses;

	// Contains classes used by the current class
	std::unordered_map<std::string, std::forward_list <CouplingType> > usedClasses;
};

}}
