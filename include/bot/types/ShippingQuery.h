#pragma once

#include <memory>
#include <string>

#include "User.h"
#include "ShippingAddress.h"

struct ShippingQuery {
	using Ptr = std::shared_ptr<ShippingQuery>;
	
	std::string id;
	User::Ptr from;
	std::string invoice_payload;
	ShippingAddress::Ptr shipping_address;
};