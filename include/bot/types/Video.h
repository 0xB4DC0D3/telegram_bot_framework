#pragma once

#include <memory>
#include <string>

#include "PhotoSize.h"

struct Video {
	using Ptr = std::shared_ptr<Video>;
	
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int duration;
	[[maybe_unused]] PhotoSize::Ptr thumb;
	[[maybe_unused]] std::string mime_type;
	[[maybe_unused]] int file_size;
};