#pragma once

#include <memory>
#include <string>

struct PhotoSize {
	using Ptr = std::shared_ptr<PhotoSize>;
	
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int file_size;
};