#pragma once

#include <memory>

struct ResponseParametes {
	using Ptr = std::shared_ptr<ResponseParametes>;
	
	[[maybe_unused]] int migrate_to_chat_id;
	[[maybe_unused]] int retry_after;
};