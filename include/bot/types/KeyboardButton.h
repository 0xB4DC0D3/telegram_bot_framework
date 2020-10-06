#pragma once

#include <memory>
#include <string>

#include "KeyboardButtonPollType.h"

struct KeyboardButton {
	using Ptr = std::shared_ptr<KeyboardButton>;
	
	std::string text;
	[[maybe_unused]] bool request_contact;
	[[maybe_unused]] bool request_location;
	[[maybe_unused]] KeyboardButtonPollType::Ptr request_poll;
};