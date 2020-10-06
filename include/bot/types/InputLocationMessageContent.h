#pragma once

#include <memory>

struct InputLocationMessageContent {
	using Ptr = std::shared_ptr<InputLocationMessageContent>;
	
	float latitude;
	float longitude;
	[[maybe_unused]] int live_period;
};