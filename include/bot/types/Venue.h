#pragma once

#include <memory>
#include <string>

#include "Location.h"

struct Venue {
	using Ptr = std::shared_ptr<Venue>;
	
	Location::Ptr location;
	std::string title;
	std::string address;
	[[maybe_unused]] std::string foursquare_id;
	[[maybe_unused]] std::string foursquare_type;
};