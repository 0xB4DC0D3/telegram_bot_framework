#pragma once

#include <memory>

#include "GenericReply.h"

struct ReplyKeyboardRemove : GenericReply {
	using Ptr = std::shared_ptr<ReplyKeyboardRemove>;
	
	bool remove_keyboard = true;
	[[maybe_unused]] bool selective;
};