#include <bot/types/types.h>
#include <string>
#include <vector>

struct types::types::User {
	int id;
	bool is_bot;
	std::string first_name;
	[[maybe_unused]] std::string last_name;
	[[maybe_unused]] std::string username;
	[[maybe_unused]] std::string language_code;
	[[maybe_unused]] bool can_join_groups;
	[[maybe_unused]] bool can_read_all_group_messages;
	[[maybe_unused]] supports_inline_queries;
};

struct types::Chat {
	int id;
	std::string type;
	[[maybe_unused]] title;
	[[maybe_unused]] username;
	[[maybe_unused]] first_name;
	[[maybe_unused]] last_name;
	[[maybe_unused]] types::ChatPhoto photo;
	[[maybe_unused]] std::string description;
	[[maybe_unused]] std::string invite_link;
	[[maybe_unused]] types::Message pinned_message;
	[[maybe_unused]] types::ChatPermissions permissions;
	[[maybe_unused]] int slow_mode_delay;
	[[maybe_unused]] std::string sticker_set_name;
	[[maybe_unused]] bool can_set_sticker_set;
};

struct types::Message {
	int message_id;
	[[maybe_unused]] types::User from;
	int date;
	types::Chat chat;
	[[maybe_unused]] types::User forward_from;
	[[maybe_unused]] types::Chat forward_from_chat;
	[[maybe_unused]] int forward_from_message_id;
	[[maybe_unused]] std::string forward_signature;
	[[maybe_unused]] std::string forward_sender_name;
	[[maybe_unused]] int forward_date;
	[[maybe_unused]] types::Message reply_to_message;
	[[maybe_unused]] types::User via_bot;
	[[maybe_unused]] int edit_time;
	[[maybe_unused]] std::string media_group_id;
	[[maybe_unused]] std::string author_signature;
	[[maybe_unused]] std::string text;
	[[maybe_unused]] std::vector<types::MessageEntity> entities;
	[[maybe_unused]] types::Animation animation;
	[[maybe_unused]] types::Audio audio;
	[[maybe_unused]] types::Document document;
	[[maybe_unused]] std::vector<types::photo> photo;
	[[maybe_unused]] types::Sticker sticker;
	[[maybe_unused]] types::Video video;
	[[maybe_unused]] types::VideoNote video_note;
	[[maybe_unused]] types::Voice voice;
	[[maybe_unused]] std::string caption;
	[[maybe_unused]] std::vector<types::MessageEntity> caption_entities;
	[[maybe_unused]] types::Contact contact;
	[[maybe_unused]] types::Dice dice;
	[[maybe_unused]] types::Game game;
	[[maybe_unused]] types::Poll poll;
	[[maybe_unused]] types::Venue venue;
	[[maybe_unused]] types::Location location;
	[[maybe_unused]] std::vector<types::User> new_chat_members;
	[[maybe_unused]] types::User left_chat_member;
	[[maybe_unused]] std::string new_chat_title;
	[[maybe_unused]] std::vector<types::PhotoSize> new_chat_photo;
	[[maybe_unused]] bool delete_chat_photo;
	[[maybe_unused]] bool group_chat_deleted;
	[[maybe_unused]] bool supergroup_chat_deleted;
	[[maybe_unused]] bool channel_chat_created;
	[[maybe_unused]] int migrate_to_chat_id;
	[[maybe_unused]] int migrate_from_chat_id;
	[[maybe_unused]] types::Message pinned_message;
	[[maybe_unused]] types::Invoice invoice;
	[[maybe_unused]] types::SuccessfulPayment successful_payment;
	[[maybe_unused]] std::string connected_website;
	[[maybe_unused]] types::PassportData passport_data;
	[[maybe_unused]] types::InlineKeyboardMarkup reply_markup;
};

struct types::MessageEntity {
	std::string type;
	int offset;
	int length;
	[[maybe_unused]] std::string url;
	[[maybe_unused]] types::User user;
	[[maybe_unused]] std::string language;
};

struct types::PhotoSize {
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	[[maybe_unused]] int file_size;
};

struct types::Animation {
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int duration;
	[[maybe_unused]] types::PhotoSize thumb;
	[[maybe_unused]] std::string file_name;
	[[maybe_unused]] std::string mime_type;
	[[maybe_unused]] int file_size;
};

struct types::Audio {
	std::string file_id;
	std::string file_unique_id;
	int duration;
	[[maybe_unused]] std::string performer;
	[[maybe_unused]] std::string title;
	[[maybe_unused]] std::string mime_type;
	[[maybe_unused]] int file_size;
	[[maybe_unused]] types::PhotoSize thumb;
};

struct types::Document {
	std::string file_id;
	std::string file_unique_id;
	[[maybe_unused]] types::PhotoSize thumb;
	[[maybe_unused]] std::string file_name;
	[[maybe_unused]] std::string mime_type;
	[[maybe_unused]] int file_size;
};

struct types::Video {
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int duration;
	[[maybe_unused]] types::PhotoSize thumb;
	[[maybe_unused]] std::string mime_type;
	[[maybe_unused]] int file_size;
};

struct types::VideoNote {
	std::string file_id;
	std::string file_unique_id;
	int length;
	int duration;
	[[maybe_unused]] types::PhotoSize thumb;
	[[maybe_unused]] int file_size;
};

struct types::Voice {
	std::string file_id;
	std::string file_unique_id;
	int duration;
	[[maybe_unused]] std::string mime_type;
	[[maybe_unused]] int file_size;
};

struct types::Contact {
	std::string phone_number;
	std::string first_name;
	[[maybe_unused]] std::string last_name;
	[[maybe_unused]] int user_id;
	[[maybe_unused]] std::string vcard;
};

struct types::Dice;
struct types::PollOption;
struct types::PollAnswer;
struct types::Poll;
struct types::Location;
struct types::Venue;
struct types::UserProfilePhotos;
struct types::File;
struct types::ReplyKeyboardMarkup;
struct types::KeyboardButton;
struct types::KeyboardButtonPollType;
struct types::ReplyKeyboardRemove;
struct types::InlineKeyboardMarkup;
struct types::InlineKeyboardButton;
struct types::LoginUrl;
struct types::CallbackQuery;
struct types::ForceReply;
struct types::ChatPhoto;
struct types::ChatMember;
struct types::ChatPermissions;
struct types::BotCommand;
struct types::ResponseParameters;
struct types::InputMedia;
struct types::InputMediaPhoto;
struct types::InputMediaVideo;
struct types::InputMediaAnimation;
struct types::InputMediaAudio;
struct types::InputMediaDocument;
struct types::InputFile;
struct types::LabeledPrice;
struct types::Invoice;
struct types::ShippingAddress;
struct types::OrderInfo;
struct types::ShippingOption;
struct types::SuccessfulPayment;
struct types::ShippingQuery;
struct types::PreCheckoutquery;
struct types::PassportData;
struct types::PassportFile;
struct types::EncryptedPassportElement;
struct types::EncryptedCredentials;
struct types::PassportElementError;
struct types::PassportElementErrorDataField;
struct types::PassportElementErrorFrontSide;
struct types::PassportElementErrorReverseSide;
struct types::PassportElementErrorSelfie;
struct types::PassportElementErrorFile;
struct types::PassportElementErrorFiles;
struct types::PassportElementErrorTranslationFile;
struct types::PassportElementErrorTranslationFiles;
struct types::PassportElementErrorUnspecified;