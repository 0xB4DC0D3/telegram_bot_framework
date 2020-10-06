#pragma once

#include <memory>
#include <string>

struct Contact {
	using Ptr = std::shared_ptr<Contact>;
	
	std::string phone_number;
	std::string first_name;
	[[maybe_unused]] std::string last_name;
	[[maybe_unused]] int user_id;
	[[maybe_unused]] std::string vcard;
};