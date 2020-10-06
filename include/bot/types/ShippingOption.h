#pragma once

#include <memory>
#include <vector>
#include <string>

#include "LabeledPrice.h"

struct ShippingOption {
	using Ptr = std::shared_ptr<ShippingOption>;
	
	std::string id;
	std::string title;
	std::vector<LabeledPrice::Ptr> prices;
};