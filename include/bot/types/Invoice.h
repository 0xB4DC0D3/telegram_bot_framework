#pragma once

#include <memory>
#include <string>

struct Invoice {
	using Ptr = std::shared_ptr<Invoice>;
	
	std::string title;
	std::string description;
	std::string start_parameter;
	std::string currency;
	int total_amount;
};