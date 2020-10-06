#pragma once

#include <memory>
#include <string>

struct InputMediaDocument {
	std::string type;
	std::string media;
	[[maybe_unused]] std::string thumb;
	[[maybe_unused]] std::string caption;
	[[maybe_unused]] std::string parse_mode;
};