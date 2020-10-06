#pragma once

#include <memory>
#include <string>

struct File {
	using Ptr = std::shared_ptr<File>;
	
	std::string file_id;
	std::string file_unique_id;
	[[maybe_unused]] int file_size;
	[[maybe_unused]] std::string file_path;
};