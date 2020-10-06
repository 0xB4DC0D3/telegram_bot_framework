#pragma once

#include <memory>
#include <vector>
#include <string>

#include "User.h"
#include "Game.h"
#include "Chat.h"
#include "Animation.h"
#include "Audio.h"
#include "Document.h"
#include "MessageEntity.h"
#include "PhotoSize.h"
#include "Sticker.h"
#include "Video.h"
#include "VideoNote.h"
#include "Voice.h"
#include "Contact.h"
#include "Dice.h"
#include "Poll.h"
#include "Venue.h"
#include "Location.h"
#include "Invoice.h"
#include "SuccessfulPayment.h"
#include "InlineKeyboardMarkup.h"

struct Message {
	using Ptr = std::shared_ptr<Message>;
	
	int message_id;
	[[maybe_unused]] User::Ptr from;
	int date;
	Chat::Ptr chat;
	[[maybe_unused]] User::Ptr forward_from;
	[[maybe_unused]] Chat::Ptr forward_from_chat;
	[[maybe_unused]] int forward_from_message_id;
	[[maybe_unused]] std::string forward_signature;
	[[maybe_unused]] std::string forward_sender_name;
	[[maybe_unused]] int forward_date;
	[[maybe_unused]] Message::Ptr reply_to_message;
	[[maybe_unused]] User::Ptr via_bot;
	[[maybe_unused]] int edit_date;
	[[maybe_unused]] std::string media_group_id;
	[[maybe_unused]] std::string author_signature;
	[[maybe_unused]] std::string text;
	[[maybe_unused]] std::vector<MessageEntity::Ptr> entities;
	[[maybe_unused]] Animation::Ptr animation;
	[[maybe_unused]] Audio::Ptr audio;
	[[maybe_unused]] Document::Ptr document;
	[[maybe_unused]] std::vector<PhotoSize::Ptr> photo;
	[[maybe_unused]] Sticker::Ptr sticker;
	[[maybe_unused]] Video::Ptr video;
	[[maybe_unused]] VideoNote::Ptr video_note;
	[[maybe_unused]] Voice::Ptr voice;
	[[maybe_unused]] std::string caption;
	[[maybe_unused]] std::vector<MessageEntity::Ptr> caption_entities;
	[[maybe_unused]] Contact::Ptr contact;
	[[maybe_unused]] Dice::Ptr dice;
	[[maybe_unused]] Game::Ptr game;
	[[maybe_unused]] Poll::Ptr poll;
	[[maybe_unused]] Venue::Ptr venue;
	[[maybe_unused]] Location::Ptr location;
	[[maybe_unused]] std::vector<User::Ptr> new_chat_members;
	[[maybe_unused]] User::Ptr left_chat_member;
	[[maybe_unused]] std::string new_chat_title;
	[[maybe_unused]] std::vector<PhotoSize::Ptr> new_chat_photo;
	[[maybe_unused]] bool delete_chat_photo;
	[[maybe_unused]] bool group_chat_created;
	[[maybe_unused]] bool supergroup_chat_created;
	[[maybe_unused]] bool channel_chat_created;
	[[maybe_unused]] long int migrate_to_chat_id;
	[[maybe_unused]] long int migrate_from_chat_id;
	[[maybe_unused]] Message::Ptr pinned_message;
	[[maybe_unused]] Invoice::Ptr invoice;
	[[maybe_unused]] SuccessfulPayment::Ptr successful_payment;
	[[maybe_unused]] std::string connected_website;
	// [[maybe_unused]] PassportData::Ptr passport_data;
	[[maybe_unused]] InlineKeyboardMarkup::Ptr reply_markup;
};

