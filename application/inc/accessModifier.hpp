#pragma once

namespace JWB {	namespace details {

/// @class AccessModifier
/// @brief Describes access modifier to a interface/class, method, field, etc.
enum class AccessModifier : size_t
{
	DEFAULT,
	PUBLIC,
	PROTECTED,
	PRIVATE
};

}} // end of namespace JWB::details