#pragma once

#include <memory>
#include <string>

struct InputMediaPhoto {
	using Ptr = std::shared_ptr<InputMediaPhoto>;
	
	std::string type;
	std::string media;
	[[maybe_unused]] std::string caption;
	[[maybe_unused]] std::string parse_mode;
};