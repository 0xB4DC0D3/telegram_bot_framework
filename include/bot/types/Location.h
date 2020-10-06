#pragma once

#include <memory>

struct Location {
	using Ptr = std::shared_ptr<Location>;
	
	float longitude;
	float latitude;
};