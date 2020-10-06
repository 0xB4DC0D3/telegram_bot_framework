#pragma once

#include <memory>
#include <string>

struct KeyboardButtonPollType {
	using Ptr = std::shared_ptr<KeyboardButtonPollType>;
	
	[[maybe_unused]] std::string type;
};