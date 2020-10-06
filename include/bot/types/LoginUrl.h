#pragma once

#include <memory>
#include <string>

struct LoginUrl {
	using Ptr = std::shared_ptr<LoginUrl>;
	
	std::string url;
	[[maybe_unused]] std::string forward_text;
	[[maybe_unused]] std::string bot_username;
	[[maybe_unused]] bool request_write_access;
};