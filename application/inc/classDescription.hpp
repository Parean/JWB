#pragma once

#include <string>
#include <vector>

#include "accessModifier.hpp"
#include "interfaceDescription.hpp"

namespace JWB {	namespace details {

/// @class ClassDescription
/// @brief Description of a Java class, contains it's name and attributes
///        Should be contained in Node as a part of an inheritance tree
class ClassDescription : public InterfaceDescription
{
	public:
		ClassDescription() = delete;
		ClassDescription(ClassDescription const&) = delete;
		ClassDescription(ClassDescription&&) = delete;
		ClassDescription& operator=(ClassDescription const&) = delete;
		ClassDescription& operator=(ClassDescription&&) = delete;

		ClassDescription(std::string className);
		void addAttribute(AccessModifier modifier, std::string newAttribute);

		size_t getNumberOfAttributes() const;
		size_t getNumberOfPrivateAttributes() const;
		size_t getAverageCyclomaticComplexity() const;

		/// Take visitor and then transfer it "this". 
		/// Allows visitor get needed notes about current Java class.
		void takeVisitor(Visitor* visitor) const override;

	private:
		std::vector<std::string> attributes;
		std::vector<std::string const*> privateAttributes;
};

}}
