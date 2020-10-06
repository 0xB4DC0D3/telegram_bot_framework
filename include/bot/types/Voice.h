#pragma once

#include <memory>
#include <string>

struct Voice {
	using Ptr = std::shared_ptr<Voice>;
	
	std::string file_id;
	std::string file_unique_id;
	int duration;
	[[maybe_unused]] std::string mime_type;
	[[maybe_unused]] int file_size;
};