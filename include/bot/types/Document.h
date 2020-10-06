#pragma once

#include <memory>
#include <string>

#include "PhotoSize.h"

struct Document {
	using Ptr = std::shared_ptr<Document>;
	
	std::string file_id;
	std::string file_unique_id;
	[[maybe_unused]] PhotoSize::Ptr thumb;
	[[maybe_unused]] std::string file_name;
	[[maybe_unused]] std::string mime_type;
	[[maybe_unused]] int file_size;
};