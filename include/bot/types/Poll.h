#pragma once

#include <memory>
#include <vector>
#include <string>

#include "PollOption.h"
#include "MessageEntity.h"

struct Poll {
	using Ptr = std::shared_ptr<Poll>;
	
	std::string id;
	std::string question;
	std::vector<PollOption::Ptr> options;
	int total_voter_count;
	bool is_closed;
	bool is_anonymous;
	std::string type;
	bool allows_multiple_answers;
	int correct_option_id;
	std::string explanation;
	std::vector<MessageEntity::Ptr> explanation_entities;
	int open_period;
	int close_data;
};