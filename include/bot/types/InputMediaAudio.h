#pragma once

#include <memory>
#include <string>

struct InputMediaAudio {
	using Ptr = std::shared_ptr<InputMediaAudio>;
	
	std::string type;
	std::string media;
	[[maybe_unused]] std::string thumb;
	[[maybe_unused]] std::string caption;
	[[maybe_unused]] std::string parse_mode;
	[[maybe_unused]] int duration;
	[[maybe_unused]] std::string performer;
	[[maybe_unused]] std::string title;
};