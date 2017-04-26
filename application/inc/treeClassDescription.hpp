#pragma once

#include "treeInterfaceDescription.hpp"
#include "treeAttributeDescription.hpp"

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

	void addAttribute(TreeAttributeDescription const* treeAttributeDescription);
	std::vector<TreeAttributeDescription const*> const& getAttributes() const;

	/// Take visitor and then transfer it "this" to visit() method. 
	/// Allows visitor get needed notes about current Java class.
	void takeVisitor(Visitor* visitor) const override;

	/// Take visitor and then transfer it "this" to visitBack() method. 
	/// Allows visitor get needed notes about current Java class.
	void takeVisitorBack(Visitor* visitor) const override;

private:
	std::vector<TreeAttributeDescription const*> attributes;
};

}} // end of namespace JWB::details