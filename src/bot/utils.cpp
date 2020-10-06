#include <bot/utils.h>

auto inlinekeyboardmarkup_to_string(const InlineKeyboardMarkup::Ptr& ikm) noexcept -> std::string {
	std::stringstream result;
	
	if (!ikm->inline_keyboard.empty()) {
		return result.str();
	}
	
	result << "[";
	for (const auto& x : ikm->inline_keyboard) {
		for (const auto& elem : x) {
			result << "[\"text\":\"" << elem->text << "\"";
				
			if (!elem->url.empty()) {
				result << ",\"url\":\"" << elem->url << "\"";
			}
						
			if (elem->login_url != nullptr) {
				result << ",\"login_url\":{";
				result << "\"url\":\"" << elem->login_url->url << "\"";
						
				if (!elem->login_url->forward_text.empty()) {
					result << ",\"forward_text\":\"" << elem->login_url->forward_text << "\"";
				} 
						
				if (!elem->login_url->bot_username.empty()) {
					result << ",\"bot_username\":\"" << elem->login_url->bot_username << "\"";
				}
						
				result << ",\"request_write_access\":\"" << elem->login_url->request_write_access << "\"]";
			}
				
			if (!elem->callback_data.empty()) {
				result << ",\"callback_data\":\"" << elem->callback_data << "\"";
			}
				
			if (!elem->switch_inline_query.empty()) {
				result << ",\"switch_inline_query\":\"" << elem->switch_inline_query << "\"";
			}
				
			if (!elem->switch_inline_query_current_chat.empty()) {
				result << ",\"switch_inline_query_current_chat\":\"" << elem->switch_inline_query_current_chat << "\"";
			}
				
			if (elem->callback_game != nullptr) {
				result << ",\"callback_game\":{}\"";
			}
				
			std::string pay { elem->pay ? "true" : "false" };
			result << ",\"pay\":\"" << pay << "\"]";
		}
	}
	result << "]";
	
	return result.str();
}

auto user_from_json(const boost::property_tree::ptree& pt) -> User::Ptr {
	if (pt.empty()) {
		return std::make_shared<User>();
	}
	
	return std::make_shared<User>(User {
		pt.get<int>("id"),
		pt.get<bool>("is_bot"),
		pt.get<std::string>("first_name"),
		pt.get<std::string>("last_name", ""),
		pt.get<std::string>("username", ""),
		pt.get<std::string>("language_code", ""),
		pt.get<bool>("can_join_groups", false),
		pt.get<bool>("can_read_all_group_messages", false),
		pt.get<bool>("supports_inline_queries", false)
	});
}

auto chat_from_json(const boost::property_tree::ptree& pt) -> Chat::Ptr {
	if (pt.empty()) {
		return std::make_shared<Chat>();
	}
	
	return std::make_shared<Chat>(Chat {
		pt.get<int>("id"),
		pt.get<std::string>("type"),
		pt.get<std::string>("title", ""),
		pt.get<std::string>("username", ""),
		pt.get<std::string>("first_name", ""),
		pt.get<std::string>("last_name", ""),
		chatphoto_from_json(pt.get_child("photo")),
		pt.get<std::string>("description"),
		pt.get<std::string>("invite_link"),
		message_from_json(pt.get_child("pinned_message")),
		chatpermissions_from_json(pt.get_child("permissions")),
		pt.get<int>("slow_mode_delay", 0),
		pt.get<std::string>("sticker_set_name", ""),
		pt.get<bool>("can_set_sticker_set", false)
	});
}

auto chatphoto_from_json(const boost::property_tree::ptree& pt) -> ChatPhoto::Ptr {
	if (pt.empty()) {
		return std::make_shared<ChatPhoto>();
	}
	
	return std::make_shared<ChatPhoto>(ChatPhoto {
		pt.get<std::string>("small_file_id"),
		pt.get<std::string>("small_file_unique_id"),
		pt.get<std::string>("big_file_id"),
		pt.get<std::string>("big_file_unique_id")
	});
}

auto chatpermissions_from_json(const boost::property_tree::ptree& pt) -> ChatPermissions::Ptr {
	if (pt.empty()) {
		return std::make_shared<ChatPermissions>();
	}
	
	return std::make_shared<ChatPermissions>(ChatPermissions {
		pt.get<bool>("can_send_messages", false),
		pt.get<bool>("can_send_media_messages", false),
		pt.get<bool>("can_send_polls", false),
		pt.get<bool>("can_send_other_messages", false),
		pt.get<bool>("can_add_web_page_previews", false),
		pt.get<bool>("can_change_info", false),
		pt.get<bool>("can_invite_users", false),
		pt.get<bool>("can_pin_messages", false)
	});
}

auto messageentity_from_json(const boost::property_tree::ptree& pt) -> MessageEntity::Ptr {
	if (pt.empty()) {
		return std::make_shared<MessageEntity>();
	}
	
	return std::make_shared<MessageEntity>(MessageEntity {
		pt.get<std::string>("type"),
		pt.get<int>("offset"),
		pt.get<int>("length"),
		pt.get<std::string>("url", ""),
		user_from_json(pt.get_child("user")),
		pt.get<std::string>("language")
	});
}

auto photosize_from_json(const boost::property_tree::ptree& pt) -> PhotoSize::Ptr {
	if (pt.empty()) {
		return std::make_shared<PhotoSize>();
	}
	
	return std::make_shared<PhotoSize>(PhotoSize {
		pt.get<std::string>("file_id"),
		pt.get<std::string>("file_unique_id"),
		pt.get<int>("width"),
		pt.get<int>("height"),
		pt.get<int>("file_size", 0)
	});
}

auto animation_from_json(const boost::property_tree::ptree& pt) -> Animation::Ptr {
	if (pt.empty()) {
		return std::make_shared<Animation>();
	}
	
	return std::make_shared<Animation>(Animation {
		pt.get<std::string>("file_id"),
		pt.get<std::string>("file_unique_id"),
		pt.get<int>("width"),
		pt.get<int>("height"),
		pt.get<int>("duration"),
		photosize_from_json(pt.get_child("thumb")),
		pt.get<std::string>("file_name", ""),
		pt.get<std::string>("mime_type", ""),
		pt.get<int>("file_size", 0)
	});
}

auto audio_from_json(const boost::property_tree::ptree& pt) -> Audio::Ptr {
	if (pt.empty()) {
		return std::make_shared<Audio>();
	}
	
	return std::make_shared<Audio>(Audio {
		pt.get<std::string>("file_id"),
		pt.get<std::string>("file_unique_id"),
		pt.get<int>("duration"),
		pt.get<std::string>("performer"),
		pt.get<std::string>("title", ""),
		pt.get<std::string>("mime_type", ""),
		pt.get<int>("file_size", 0),
		photosize_from_json(pt.get_child("thumb"))
	});
}

auto document_from_json(const boost::property_tree::ptree& pt) -> Document::Ptr {
	if (pt.empty()) {
		return std::make_shared<Document>();
	}
	
	return std::make_shared<Document>(Document {
		pt.get<std::string>("file_id"),
		pt.get<std::string>("file_unique_id"),
		photosize_from_json(pt.get_child("thumb")),
		pt.get<std::string>("file_name"),
		pt.get<std::string>("mime_type"),
		pt.get<int>("file_size")
	});
}

auto maskposition_from_json(const boost::property_tree::ptree& pt) -> MaskPosition::Ptr {
	if (pt.empty()) {
		return std::make_shared<MaskPosition>();
	}
	
	return std::make_shared<MaskPosition>(MaskPosition {
		pt.get<std::string>("point"),
		pt.get<float>("x_shift"),
		pt.get<float>("y_shift"),
		pt.get<float>("scale")
	});
}

auto sticker_from_json(const boost::property_tree::ptree& pt) -> Sticker::Ptr {
	if (pt.empty()) {
		return std::make_shared<Sticker>();
	}
	
	return std::make_shared<Sticker>(Sticker {
		pt.get<std::string>("file_id"),
		pt.get<std::string>("file_unique_id"),
		pt.get<int>("width"),
		pt.get<int>("height"),
		pt.get<bool>("is_animated"),
		photosize_from_json(pt.get_child("thumb")),
		pt.get<std::string>("emoji"),
		pt.get<std::string>("set_name"),
		maskposition_from_json(pt.get_child("mask_position")),
		pt.get<int>("file_size")
	});
}

auto video_from_json(const boost::property_tree::ptree& pt) -> Video::Ptr {
	if (pt.empty()) {
		return std::make_shared<Video>();
	}
	
	return std::make_shared<Video>(Video {
		pt.get<std::string>("file_id"),
		pt.get<std::string>("file_unique_id"),
		pt.get<int>("width"),
		pt.get<int>("height"),
		pt.get<int>("duration"),
		photosize_from_json(pt.get_child("thumb")),
		pt.get<std::string>("mime_type"),
		pt.get<int>("file_size")
	});
}

auto videonote_from_json(const boost::property_tree::ptree& pt) -> VideoNote::Ptr {
	if (pt.empty()) {
		return std::make_shared<VideoNote>();
	}
	
	return std::make_shared<VideoNote>(VideoNote {
		pt.get<std::string>("file_id"),
		pt.get<std::string>("file_unique_id"),
		pt.get<int>("length"),
		pt.get<int>("duration"),
		photosize_from_json(pt.get_child("thumb")),
		pt.get<int>("file_size")
	});
}

auto voice_from_json(const boost::property_tree::ptree& pt) -> Voice::Ptr {
	if (pt.empty()) {
		return std::make_shared<Voice>();
	}
	
	return std::make_shared<Voice>(Voice {
		pt.get<std::string>("file_id"),
		pt.get<std::string>("file_unique_id"),
		pt.get<int>("duration"),
		pt.get<std::string>("mime_type"),
		pt.get<int>("file_size")
	});
}

auto contact_from_json(const boost::property_tree::ptree& pt) -> Contact::Ptr {
	if (pt.empty()) {
		return std::make_shared<Contact>();
	}
	
	return std::make_shared<Contact>(Contact {
		pt.get<std::string>("phone_number"),
		pt.get<std::string>("first_name"),
		pt.get<std::string>("last_name", ""),
		pt.get<int>("user_id", 0),
		pt.get<std::string>("vcard", "")
	});
}

auto dice_from_json(const boost::property_tree::ptree& pt) -> Dice::Ptr {
	if (pt.empty()) {
		return std::make_shared<Dice>();
	}
	
	return std::make_shared<Dice>(Dice {
		pt.get<std::string>("emoji"),
		pt.get<int>("value")
	});
}

auto game_from_json(const boost::property_tree::ptree& pt) -> Game::Ptr {
	if (pt.empty()) {
		return std::make_shared<Game>();
	}
	
	return std::make_shared<Game>(Game {
		pt.get<std::string>("title"),
		pt.get<std::string>("description"),
		([&pt] () -> std::vector<PhotoSize::Ptr> {
			std::vector<PhotoSize::Ptr> photo;
			for (const auto& item : pt.get_child("photo")) {
				if (!item.second.empty()) {
					photo.emplace_back(photosize_from_json(item.second));
				}
			}
			return photo;
		})(),
		pt.get<std::string>("text"),
		([&pt] () -> std::vector<MessageEntity::Ptr> {
			std::vector<MessageEntity::Ptr> text_entities;
			for (const auto& item : pt.get_child("text_entities")) {
				if (!item.second.empty()) {
					text_entities.emplace_back(messageentity_from_json(item.second));
				}
			}
			return text_entities;
		})(),
		animation_from_json(pt.get_child("animation"))
	});
}

auto polloption_from_json(const boost::property_tree::ptree& pt) -> PollOption::Ptr {
	if (pt.empty()) {
		return std::make_shared<PollOption>();
	}
	
	return std::make_shared<PollOption>(PollOption {
		pt.get<std::string>("text"),
		pt.get<int>("voter_count")
	});
}

auto poll_from_json(const boost::property_tree::ptree& pt) -> Poll::Ptr {
	if (pt.empty()) {
		return std::make_shared<Poll>();
	}
	
	return std::make_shared<Poll>(Poll {
		pt.get<std::string>("id"),
		pt.get<std::string>("question"),
		([&pt] () -> std::vector<PollOption::Ptr> {
			std::vector<PollOption::Ptr> options;
			for (const auto& item : pt.get_child("options")) {
				if (!item.second.empty()) {
					options.emplace_back(polloption_from_json(item.second));
				}
			}
			return options;
		})(),
		pt.get<int>("total_voter_count"),
		pt.get<bool>("is_closed"),
		pt.get<bool>("is_anonymous"),
		pt.get<std::string>("type"),
		pt.get<bool>("allows_multiple_answers"),
		pt.get<int>("correct_option_id", 0),
		pt.get<std::string>("explanation", ""),
		([&pt] () -> std::vector<MessageEntity::Ptr> {
			std::vector<MessageEntity::Ptr> explanation_entities;
			for (const auto& item : pt.get_child("explanation_entities")) {
				if (!item.second.empty()) {
					explanation_entities.emplace_back(messageentity_from_json(item.second));
				}
			}
			return explanation_entities;
		})(),
		pt.get<int>("open_period"),
		pt.get<int>("close_data")
	});
}

auto location_from_json(const boost::property_tree::ptree& pt) -> Location::Ptr {
	if (pt.empty()) {
		return std::make_shared<Location>();
	}
	
	return std::make_shared<Location>(Location {
		pt.get<float>("longitude"),
		pt.get<float>("latitude")
	});
}

auto venue_from_json(const boost::property_tree::ptree& pt) -> Venue::Ptr {
	if (pt.empty()) {
		return std::make_shared<Venue>();
	}
	
	return std::make_shared<Venue>(Venue {
		location_from_json(pt.get_child("location")),
		pt.get<std::string>("title"),
		pt.get<std::string>("address"),
		pt.get<std::string>("foursquare_id", ""),
		pt.get<std::string>("foursquare_type", "")
	});
}

auto invoice_from_json(const boost::property_tree::ptree& pt) -> Invoice::Ptr {
	if (pt.empty()) {
		return std::make_shared<Invoice>();
	}
	
	return std::make_shared<Invoice>(Invoice {
		pt.get<std::string>("title"),
		pt.get<std::string>("description"),
		pt.get<std::string>("start_parameter"),
		pt.get<std::string>("currency"),
		pt.get<int>("total_amount")
	});
}

auto shippingaddress_from_json(const boost::property_tree::ptree& pt) -> ShippingAddress::Ptr {
	if (pt.empty()) {
		return std::make_shared<ShippingAddress>();
	}
	
	return std::make_shared<ShippingAddress>(ShippingAddress {
		pt.get<std::string>("country_code"),
		pt.get<std::string>("state"),
		pt.get<std::string>("city"),
		pt.get<std::string>("street_line1"),
		pt.get<std::string>("street_line2"),
		pt.get<std::string>("post_code")
	});
}

auto orderinfo_from_json(const boost::property_tree::ptree& pt) -> OrderInfo::Ptr {
	if (pt.empty()) {
		return std::make_shared<OrderInfo>();
	}
	
	return std::make_shared<OrderInfo>(OrderInfo {
		pt.get<std::string>("name"),
		pt.get<std::string>("phone_number"),
		pt.get<std::string>("email"),
		shippingaddress_from_json(pt.get_child("shipping_address"))
	});
}

auto successfulpayment_from_json(const boost::property_tree::ptree& pt) -> SuccessfulPayment::Ptr {
	if (pt.empty()) {
		return std::make_shared<SuccessfulPayment>();
	}
	
	return std::make_shared<SuccessfulPayment>(SuccessfulPayment {
		pt.get<std::string>("currency"),
		pt.get<int>("total_amount"),
		pt.get<std::string>("invoice_payload"),
		pt.get<std::string>("shipping_option_id", ""),
		orderinfo_from_json(pt.get_child("order_info")),
		pt.get<std::string>("telegram_payment_charge_id"),
		pt.get<std::string>("provider_payment_charge_id")
	});
}

auto loginurl_from_json(const boost::property_tree::ptree& pt) -> LoginUrl::Ptr {
	if (pt.empty()) {
		return std::make_shared<LoginUrl>();
	}
	
	return std::make_shared<LoginUrl>(LoginUrl {
		pt.get<std::string>("url"),
		pt.get<std::string>("forward_text", ""),
		pt.get<std::string>("bot_username", ""),
		pt.get<bool>("request_write_access", "")
	});
}

auto callbackgame_from_json(const boost::property_tree::ptree& pt) -> CallbackGame::Ptr {
	if (pt.empty()) {
		return std::make_shared<CallbackGame>();
	}
	
	return std::make_shared<CallbackGame>(CallbackGame {});
}

auto inlinekeyboardbutton_from_json(const boost::property_tree::ptree& pt) -> InlineKeyboardButton::Ptr {
	if (pt.empty()) {
		return std::make_shared<InlineKeyboardButton>();
	}
	
	return std::make_shared<InlineKeyboardButton>(InlineKeyboardButton {
		pt.get<std::string>("text"),
		pt.get<std::string>("url"),
		loginurl_from_json(pt.get_child("login_url")),
		pt.get<std::string>("callback_data", ""),
		pt.get<std::string>("switch_inline_query", ""),
		pt.get<std::string>("switch_inline_query_current_chat", ""),
		callbackgame_from_json(pt.get_child("callback_game")),
		pt.get<bool>("pay")
	});
}

auto inlinekeyboardmarkup_from_json(const boost::property_tree::ptree& pt) -> InlineKeyboardMarkup::Ptr {
	if (pt.empty()) {
		return std::make_shared<InlineKeyboardMarkup>();
	}
	
	return std::make_shared<InlineKeyboardMarkup>(InlineKeyboardMarkup { 
		([&pt] () -> std::vector<std::vector<InlineKeyboardButton::Ptr>> {
			std::vector<std::vector<InlineKeyboardButton::Ptr>> inline_keyboard;
			for (const auto& item : pt.get_child("inline_keyboard")) {
				inline_keyboard.emplace_back();
				for (const auto& elem : item.second) {
					inline_keyboard.back().emplace_back(inlinekeyboardbutton_from_json(elem.second));
				}
			}
			return inline_keyboard;
		})()
	});
}

auto message_from_json(const boost::property_tree::ptree& pt) -> Message::Ptr {
	if (pt.empty()) { 
		return std::make_shared<Message>(); 
	}
	
	return std::make_shared<Message>(Message {
		pt.get<int>("message_id"),
		user_from_json(pt.get_child("from")),
		pt.get<int>("date"),
		chat_from_json(pt.get_child("chat")),
		user_from_json(pt.get_child("forward_from")),
		chat_from_json(pt.get_child("forward_from_chat")),
		pt.get<int>("forward_from_message_id", 0),
		pt.get<std::string>("forward_signature", ""),
		pt.get<std::string>("forward_sender_name", ""),
		pt.get<int>("forward_date", 0),
		message_from_json(pt.get_child("reply_to_message")),
		user_from_json(pt.get_child("via_bot")),
		pt.get<int>("edit_date", 0),
		pt.get<std::string>("media_group_id", ""),
		pt.get<std::string>("author_signature", ""),
		pt.get<std::string>("text", ""),
		([&pt] () -> std::vector<MessageEntity::Ptr> {
			std::vector<MessageEntity::Ptr> entities;
			for (const auto& item : pt.get_child("entities")) {
				if (!item.second.empty()) {
					entities.emplace_back(messageentity_from_json(item.second));
				}
			}
			return entities;
		})(),
		animation_from_json(pt.get_child("animation")),
		audio_from_json(pt.get_child("audio")),
		document_from_json(pt.get_child("document")),
		([&pt] () -> std::vector<PhotoSize::Ptr> {
			std::vector<PhotoSize::Ptr> photo;
			for (const auto& item : pt.get_child("photo")) {
				if (!item.second.empty()) {
					photo.emplace_back(photosize_from_json(item.second));
				}
			}
			return photo;
		})(),
		sticker_from_json(pt.get_child("sticker")),
		video_from_json(pt.get_child("video")),
		videonote_from_json(pt.get_child("video_note")),
		voice_from_json(pt.get_child("voice")),
		pt.get<std::string>("caption", ""),
		([&pt] () -> std::vector<MessageEntity::Ptr> {
			std::vector<MessageEntity::Ptr> caption_entities;
			for (const auto& item : pt.get_child("caption_entities")) {
				if (!item.second.empty()) {
					caption_entities.emplace_back(messageentity_from_json(item.second));
				}
			}
			return caption_entities;
		})(),
		contact_from_json(pt.get_child("contact")),
		dice_from_json(pt.get_child("dice")),
		game_from_json(pt.get_child("game")),
		poll_from_json(pt.get_child("poll")),
		venue_from_json(pt.get_child("venue")),
		location_from_json(pt.get_child("location")),
		([&pt] () -> std::vector<User::Ptr> {
			std::vector<User::Ptr> new_chat_members;
			for (const auto& item : pt.get_child("new_chat_members")) {
				if (!item.second.empty()) {
					new_chat_members.emplace_back(user_from_json(item.second));
				}
			}
			return new_chat_members;
		})(),
		user_from_json(pt.get_child("left_chat_member")),
		pt.get<std::string>("new_chat_title"),
		([&pt] () -> std::vector<PhotoSize::Ptr> {
			std::vector<PhotoSize::Ptr> new_chat_photo;
			for (const auto& item : pt.get_child("new_chat_photo")) {
				if (!item.second.empty()) {
					new_chat_photo.emplace_back(photosize_from_json(item.second));
				}
			}
			return new_chat_photo;
		})(),
		pt.get<bool>("delete_chat_photo", false),
		pt.get<bool>("group_chat_created", false),
		pt.get<bool>("supergroup_chat_created", false),
		pt.get<bool>("channel_chat_created", false),
		pt.get<long int>("migrate_to_chat_id", 0),
		pt.get<long int>("migrate_from_chat_id", 0),
		message_from_json(pt.get_child("pinned_message")),
		invoice_from_json(pt.get_child("invoice")),
		successfulpayment_from_json(pt.get_child("successful_payment")),
		pt.get<std::string>("connected_website"),
		// here later must be passport_data
		inlinekeyboardmarkup_from_json(pt.get_child("reply_markup"))
	});
}