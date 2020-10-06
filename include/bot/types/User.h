#pragma once

#include <memory>
#include <string>

struct User {
	using Ptr = std::shared_ptr<User>;
	
	int id;
	bool is_bot;
	std::string first_name;
	[[maybe_unused]] std::string last_name;
	[[maybe_unused]] std::string username;
	[[maybe_unused]] std::string language_code;
	[[maybe_unused]] bool can_join_groups;
	[[maybe_unused]] bool can_read_all_group_messages;
	[[maybe_unused]] bool supports_inline_queries;
};