#pragma once

#include <memory>
#include <string>

struct LabeledPrice {
	using Ptr = std::shared_ptr<LabeledPrice>;
	
	std::string label;
	int amount;
};