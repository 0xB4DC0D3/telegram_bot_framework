#pragma once

#include <memory>
#include <string>

#include "PhotoSize.h"

struct VideoNote {
	using Ptr = std::shared_ptr<VideoNote>;
	
	std::string file_id;
	std::string file_unique_id;
	int length;
	int duration;
	[[maybe_unused]] PhotoSize::Ptr thumb;
	[[maybe_unused]] int file_size;
};