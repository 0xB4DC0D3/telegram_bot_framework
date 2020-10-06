#pragma once

#include <memory>
#include <string>

struct Dice {
	using Ptr = std::shared_ptr<Dice>;
	
	std::string emoji;
	int value;
};