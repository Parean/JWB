#pragma once

#include <vector>
#include <string>
#include <memory>

#include "methodDescription.hpp"

namespace JWB {	namespace details {

/// @class InterfaceDescription
/// @brief Description of a Java interface, contains it's name and methods
///        Should be contained in Node as a part of an inheritance tree
class InterfaceDescription
{
	public:
		InterfaceDescription() = delete;
		InterfaceDescription(InterfaceDescription const&) = delete;
		InterfaceDescription(InterfaceDescription&&) = delete;
		InterfaceDescription& operator=(InterfaceDescription const&) = delete;
		InterfaceDescription& operator=(InterfaceDescription&&) = delete;
		virtual ~InterfaceDescription() = default;

		InterfaceDescription(std::string interfaceName);
		void addMethod(MethodDescription const *newMethod);

		size_t getNumberOfMethods() const;
		size_t getNumberOfPrivateMethods() const;
		std::string const& getName() const;

	protected:
		std::string const name;
		std::vector <std::shared_ptr <const JWB::details::MethodDescription> > methods;
};

}}
