#pragma once

#include <memory>
#include <vector>

#include "GenericReply.h"
#include "InlineKeyboardButton.h"

struct InlineKeyboardMarkup : GenericReply {
	using Ptr = std::shared_ptr<InlineKeyboardMarkup>;
	
	InlineKeyboardMarkup() = default;
	InlineKeyboardMarkup(const std::vector<std::vector<InlineKeyboardButton::Ptr>>& x) : inline_keyboard { x } { }
	
	std::vector<std::vector<InlineKeyboardButton::Ptr>> inline_keyboard;
};