#pragma once

#include <memory>
#include <vector>
#include <string>

#include "PhotoSize.h"
#include "MessageEntity.h"
#include "Animation.h"

struct Game {
	using Ptr = std::shared_ptr<Game>;
	
	std::string title;
	std::string description;
	std::vector<PhotoSize::Ptr> photo;
	[[maybe_unused]] std::string text;
	[[maybe_unused]] std::vector<MessageEntity::Ptr> text_entities;
	[[maybe_unused]] Animation::Ptr animation;
};