#pragma once

#include <memory>

struct ChatPermissions {
	using Ptr = std::shared_ptr<ChatPermissions>;
	
	[[maybe_unused]] bool can_send_messages;
	[[maybe_unused]] bool can_send_media_messages;
	[[maybe_unused]] bool can_send_polls;
	[[maybe_unused]] bool can_send_other_messages;
	[[maybe_unused]] bool can_add_web_page_previews;
	[[maybe_unused]] bool can_change_info;
	[[maybe_unused]] bool can_invite_users;
	[[maybe_unused]] bool can_pin_messages;
};