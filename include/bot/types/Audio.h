#pragma once

#include <memory>
#include <string>

#include "PhotoSize.h"

struct Audio {
	using Ptr = std::shared_ptr<Audio>;
	
	std::string file_id;
	std::string file_unique_id;
	int duration;
	[[maybe_unused]] std::string performer;
	[[maybe_unused]] std::string title;
	[[maybe_unused]] std::string mime_type;
	[[maybe_unused]] int file_size;
	[[maybe_unused]] PhotoSize::Ptr thumb;
};