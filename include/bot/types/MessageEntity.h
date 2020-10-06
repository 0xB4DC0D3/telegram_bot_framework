#pragma once

#include <memory>
#include <string>

#include "User.h"

struct MessageEntity {
	using Ptr = std::shared_ptr<MessageEntity>;
	
	std::string type;
	int offset;
	int length;
	[[maybe_unused]] std::string url;
	[[maybe_unused]] User::Ptr user;
	[[maybe_unused]] std::string language;
};