#pragma once

#include <memory>
#include <string>

#include "ShippingAddress.h"

struct OrderInfo {
	using Ptr = std::shared_ptr<OrderInfo>;
	
	[[maybe_unused]] std::string name;
	[[maybe_unused]] std::string phone_number;
	[[maybe_unused]] std::string email;
	[[maybe_unused]] ShippingAddress::Ptr shipping_address;
};