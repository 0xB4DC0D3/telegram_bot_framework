#pragma once

#include <memory>
#include <string>

struct InputTextMessageContent {
	using Ptr = std::shared_ptr<InputTextMessageContent>;
	
	std::string message_text;
	[[maybe_unused]] std::string parse_mode;
	[[maybe_unused]] bool disable_web_page_preview;
};