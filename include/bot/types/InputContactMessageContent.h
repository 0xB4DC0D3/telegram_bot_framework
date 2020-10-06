#pragma once

#include <memory>
#include <string>

struct InputContactMessageContent {
	using Ptr = std::shared_ptr<InputContactMessageContent>;
	
	std::string phone_number;
	std::string first_name;
	[[maybe_unused]] std::string last_name;
	[[maybe_unused]] std::string vcard;
};