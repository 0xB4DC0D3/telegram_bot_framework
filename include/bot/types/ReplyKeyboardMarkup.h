#pragma once

#include <memory>
#include <vector>

#include "GenericReply.h"
#include "KeyboardButton.h"

struct ReplyKeyboardMarkup : GenericReply {
	using Ptr = std::shared_ptr<ReplyKeyboardMarkup>;
	
	std::vector<std::vector<KeyboardButton::Ptr>> keyboard;
	[[maybe_unused]] bool resize_keyboard;
	[[maybe_unused]] bool one_time_keyboard;
	[[maybe_unused]] bool selective;
};