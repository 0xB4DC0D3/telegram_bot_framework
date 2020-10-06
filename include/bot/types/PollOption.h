#pragma once

#include <memory>
#include <string>

struct PollOption {
	using Ptr = std::shared_ptr<PollOption>;
	
	std::string text;
	int voter_count;
};