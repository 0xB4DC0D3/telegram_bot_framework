#pragma once

#include <memory>
#include <vector>
#include <string>

#include "User.h"

struct PollAnswer {
	using Ptr = std::shared_ptr<PollAnswer>;
	
	std::string poll_id;
	User::Ptr user;
	std::vector<int> option_ids;
};