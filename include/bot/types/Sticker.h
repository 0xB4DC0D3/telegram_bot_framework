#pragma once

#include <memory>
#include <string>

#include "PhotoSize.h"
#include "MaskPosition.h"

struct Sticker {
	using Ptr = std::shared_ptr<Sticker>;
	
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	bool is_animated;
	[[maybe_unused]] PhotoSize::Ptr thumb;
	[[maybe_unused]] std::string emoji;
	[[maybe_unused]] std::string set_name;
	[[maybe_unused]] MaskPosition::Ptr mask_position;
	[[maybe_unused]] int file_size;
};