#pragma once

#include <memory>
#include <string>

#include "User.h"
#include "Location.h"

struct ChosenInlineResult {
	using Ptr = std::shared_ptr<ChosenInlineResult>;
	
	std::string result_id;
	User::Ptr from;
	[[maybe_unused]] Location::Ptr location;
	[[maybe_unused]] std::string inline_message_id;
	std::string query;
};