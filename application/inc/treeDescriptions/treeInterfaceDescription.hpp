#pragma once

#include <vector>
#include <string>
#include <memory>

#include "visitor.hpp"
#include "treeMethodDescription.hpp"

namespace JWB {	namespace details {
	
/// @class TreeInterfaceDescription
/// @brief Description of a Java interface. Contains its name and methods.
/// Should be contained in Node as a part of an inheritance tree.
class TreeInterfaceDescription
{
public:
	TreeInterfaceDescription() = delete;
	TreeInterfaceDescription(TreeInterfaceDescription const&) = delete;
	TreeInterfaceDescription(TreeInterfaceDescription&&) = delete;
	TreeInterfaceDescription& operator=(TreeInterfaceDescription const&) = delete;
	TreeInterfaceDescription& operator=(TreeInterfaceDescription&&) = delete;
	virtual ~TreeInterfaceDescription() = default;

	/// Takes string as a parameter and sets it as its name.
	TreeInterfaceDescription(std::string interfaceName);

	/// Adds a new method name to the vector.
	void addMethod(TreeMethodDescription* newMethod);

	std::string const& getName() const;
	std::vector<std::shared_ptr<TreeMethodDescription>> const& getMethods() const;

	/// Update hashes of contained methods.
	void updateHashes();

	/// Take visitor and then transfer it "this" to visit() method. 
	/// Allows visitor get needed notes about current Java interface.
	virtual void takeVisitor(Visitor* visitor) const;

	/// Take visitor and then transfer it "this" to visitBack() method. 
	/// Allows visitor get needed notes about current Java class.
	virtual void takeVisitorBack(Visitor* visitor) const;

protected:
	const std::string interfaceName;
	std::vector<std::shared_ptr<TreeMethodDescription>> methods;
	size_t numberOfPrivateMethods = 0;
};

}} // end of namespace JWB::details