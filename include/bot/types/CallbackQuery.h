#pragma once

#include <memory>
#include <string>

#include "User.h"
#include "Message.h"

struct CallbackQuery {
	using Ptr = std::shared_ptr<CallbackQuery>;
	
	std::string id;
	User::Ptr from;
	[[maybe_unused]] Message::Ptr message;
	[[maybe_unused]] std::string inline_message_id;
	std::string chat_instance;
	[[maybe_unused]] std::string data;
	[[maybe_unused]] std::string game_short_name;
};