#pragma once

#include <memory>

#include "User.h"

struct GameHighScore {
	using Ptr = std::shared_ptr<GameHighScore>;
	
	int position;
	User::Ptr user;
	int score;
};