#pragma once

#include <memory>
#include <string>

struct BotCommand {
	using Ptr = std::shared_ptr<BotCommand>;
	
	std::string command;
	std::string description;
};