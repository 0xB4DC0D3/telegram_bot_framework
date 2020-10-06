#pragma once

#include <memory>
#include <string>

#include "OrderInfo.h"

struct SuccessfulPayment {
	using Ptr = std::shared_ptr<SuccessfulPayment>;
	
	std::string currency;
	int total_amount;
	std::string invoice_payload;
	[[maybe_unused]] std::string shipping_option_id;
	[[maybe_unused]] OrderInfo::Ptr order_info;
	std::string telegram_payment_charge_id;
	std::string provider_payment_charge_id;
};