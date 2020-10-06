#pragma once

#include <memory>
#include <string>

struct ChatPhoto {
	using Ptr = std::shared_ptr<ChatPhoto>;
	
	std::string small_file_id;
	std::string small_file_unique_id;
	std::string big_file_id;
	std::string big_file_unique_id;
};