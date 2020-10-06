#pragma once

#include <memory>
#include <string>

struct InputMediaAnimation {
	using Ptr = std::shared_ptr<InputMediaAnimation>;
	
	std::string type;
	std::string media;
	[[maybe_unused]] std::string thumb;
	[[maybe_unused]] std::string caption;
	[[maybe_unused]] std::string parse_mode;
	[[maybe_unused]] int width;
	[[maybe_unused]] int height;
	[[maybe_unused]] int duration;
};