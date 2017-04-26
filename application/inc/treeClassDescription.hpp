#pragma once

#include "treeInterfaceDescription.hpp"

#include <vector>
#include <string>

namespace JWB {	namespace details {
	
/// @class TreeClassDescription
/// @brief Description of a Java class. Contains its name, method and attributes names.
/// Should be contained in Node as a part of an inheritance tree.
class TreeClassDescription : public TreeInterfaceDescription
{
public:
	TreeClassDescription() = delete;
	TreeClassDescription(TreeClassDescription const&) = delete;
	TreeClassDescription(TreeClassDescription&&) = delete;
	TreeClassDescription& operator=(TreeClassDescription const&) = delete;
	TreeClassDescription& operator=(TreeClassDescription&&) = delete;
	TreeClassDescription(std::string className);

	void addAttribute(AccessModifier modifier, std::string newAttribute);
	std::vector<std::string> const& getAttributes();

	/// Take visitor and then transfer it "this" to visit() method. 
	/// Allows visitor get needed notes about current Java class.
	void takeVisitor(Visitor* visitor) const override;

	/// Take visitor and then transfer it "this" to visitBack() method. 
	/// Allows visitor get needed notes about current Java class.
	void takeVisitorBack(Visitor* visitor) const override;

private:
	std::vector<std::string> attributes;
	std::vector<std::string const*> privateAttributes;
};

}} // end of namespace JWB::details