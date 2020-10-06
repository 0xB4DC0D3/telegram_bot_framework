#pragma once

#include <memory>
#include <string>

#include "User.h"

struct ChatMember {
	using Ptr = std::shared_ptr<ChatMember>;
	
	User::Ptr user;
	std::string status;
	[[maybe_unused]] std::string custom_title;
	[[maybe_unused]] int until_date;
	[[maybe_unused]] bool can_be_edited;
	[[maybe_unused]] bool can_post_messages;
	[[maybe_unused]] bool can_edit_messages;
	[[maybe_unused]] bool can_delete_messages;
	[[maybe_unused]] bool can_restrict_members;
	[[maybe_unused]] bool can_promote_members;
	[[maybe_unused]] bool can_change_info;
	[[maybe_unused]] bool can_invite_users;
	[[maybe_unused]] bool can_pin_messages;
	[[maybe_unused]] bool is_member;
	[[maybe_unused]] bool can_send_messages;
	[[maybe_unused]] bool can_send_media_messages;
	[[maybe_unused]] bool can_send_polls;
	[[maybe_unused]] bool can_send_other_messages;
	[[maybe_unused]] bool can_add_web_page_preview;
};