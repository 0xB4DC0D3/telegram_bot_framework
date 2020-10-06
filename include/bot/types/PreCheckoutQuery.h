#pragma once

#include <memory>
#include <string>

struct PreCheckoutQuery {
	using Ptr = std::shared_ptr<PreCheckoutQuery>;
	
	std::string id;
	User::Ptr from;
	std::string currency;
	int total_amount;
	std::string invoice_payload;
	[[maybe_unused]] std::string shipping_option_id;
	[[maybe_unused]] OrderInfo::Ptr order_info;
};