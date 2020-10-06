#pragma once

#include <memory>
#include <vector>

#include "PhotoSize.h"

struct UserProfilePhotos {
	using Ptr = std::shared_ptr<UserProfilePhotos>;
	
	int total_count;
	std::vector<std::vector<PhotoSize::Ptr>> photos;
};