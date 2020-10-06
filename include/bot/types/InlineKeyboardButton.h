#pragma once

#include <memory>
#include <string>

#include "LoginUrl.h"
#include "CallbackGame.h"

struct InlineKeyboardButton {
	using Ptr = std::shared_ptr<InlineKeyboardButton>;
	
	std::string text;
	[[maybe_unused]] std::string url;
	[[maybe_unused]] LoginUrl::Ptr login_url;
	[[maybe_unused]] std::string callback_data;
	[[maybe_unused]] std::string switch_inline_query;
	[[maybe_unused]] std::string switch_inline_query_current_chat;
	[[maybe_unused]] CallbackGame::Ptr callback_game;
	[[maybe_unused]] bool pay;
};