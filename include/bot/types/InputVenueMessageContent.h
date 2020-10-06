#pragma once

#include <memory>
#include <string>

struct InputVenueMessageContent {
	using Ptr = std::shared_ptr<InputVenueMessageContent>;
	
	float latitude;
	float longitude;
	std::string title;
	std::string address;
	[[maybe_unused]] std::string foursquare_id;
	[[maybe_unused]] std::string foursquare_type;
};