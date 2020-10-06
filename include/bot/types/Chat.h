#pragma once

#include <memory>
#include <string>

#include "ChatPermissions.h"
#include "ChatPhoto.h"

struct Message;

struct Chat {
	using Ptr = std::shared_ptr<Chat>;
	
	int id;
	std::string type;
	[[maybe_unused]] std::string title;
	[[maybe_unused]] std::string username;
	[[maybe_unused]] std::string first_name;
	[[maybe_unused]] std::string last_name;
	[[maybe_unused]] ChatPhoto::Ptr photo;
	[[maybe_unused]] std::string description;
	[[maybe_unused]] std::string invite_link;
	[[maybe_unused]] /*Message::Ptr*/ std::shared_ptr<Message> pinned_message;
	[[maybe_unused]] ChatPermissions::Ptr permissions;
	[[maybe_unused]] int slow_mode_delay;
	[[maybe_unused]] std::string sticker_set_name;
	[[maybe_unused]] bool can_set_sticker_set;
};