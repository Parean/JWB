#pragma once

#include <unordered_map>
#include <string>
#include <memory>

#include "clusteringMethodDescription.hpp"

namespace JWB {	namespace details {

/// @class ClusteringInterfaceDescription
/// @brief Description of a Java interface, contains it's name and methods
class ClusteringInterfaceDescription
{
public:

	ClusteringInterfaceDescription() = delete;
	ClusteringInterfaceDescription(ClusteringInterfaceDescription const&) = delete;
	ClusteringInterfaceDescription(ClusteringInterfaceDescription&&) = delete;
	ClusteringInterfaceDescription& operator=(ClusteringInterfaceDescription const&) = delete;
	ClusteringInterfaceDescription& operator=(ClusteringInterfaceDescription&&) = delete;
	virtual ~ClusteringInterfaceDescription() = default;

	ClusteringInterfaceDescription(std::string interfaceName);
	void addMethod(std::shared_ptr<ClusteringMethodDescription> const &methodPtr);

	size_t getNumberOfMethods() const;
	size_t getNumberOfPrivateMethods() const;
	std::string const& getName() const;
	std::unordered_map <std::string, std::shared_ptr <ClusteringMethodDescription> > const& getMethods() const;

protected:

	std::string const name;
	std::unordered_map <std::string, std::shared_ptr <ClusteringMethodDescription> > methods;
};

}}
