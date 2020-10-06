#pragma once

#include <memory>
#include <string>

struct ShippingAddress {
	using Ptr = std::shared_ptr<ShippingAddress>;
	
	std::string country_code;
	std::string state;
	std::string city;
	std::string street_line1;
	std::string street_line2;
	std::string post_code;
};