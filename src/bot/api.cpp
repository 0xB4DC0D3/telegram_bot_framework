#include <bot/api.h>
#include <sstream>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>

Api::Api(std::string_view url, std::string_view bot_token) : async_http_client { url, bot_token } { }

Message::Ptr Api::sendMessage(std::string_view chat_id,
							 std::string_view text,
							 std::string_view parse_mode,
							 bool disable_web_page_preview,
							 bool disable_notification,
							 int reply_to_message_id,
							 const GenericReply::Ptr& reply_markup) const 
{
	std::vector<std::pair<std::string, std::string>> args;
	args.reserve(7);
	
	args.emplace_back("chat_id", std::string { chat_id });
	args.emplace_back("text", std::string { text });
	
	if (!parse_mode.empty()) {
		args.emplace_back("parse_mode", std::string { parse_mode });
	}
	
	args.emplace_back("disable_web_page_preview", disable_web_page_preview ? "true" : "false");
	args.emplace_back("disable_notification", disable_notification ? "true" : "false");
	args.emplace_back("reply_to_message_id", reply_to_message_id ? "true" : "false");
	
	if (std::dynamic_pointer_cast<InlineKeyboardMarkup>(reply_markup) != nullptr) {
		args.emplace_back("reply_markup", inlinekeyboardmarkup_to_string(std::dynamic_pointer_cast<InlineKeyboardMarkup>(reply_markup)));
	}
	/*
		here must be another inherited types of genericreply;
	*/
	
	return message_from_json(this->async_http_client.send_request("sendMessage", args));
}

Message::Ptr Api::forwardMessage(std::string_view chat_id,
							std::string_view from_chat_id,
							bool disable_notification,
							int message_id) const
{
	std::vector<std::pair<std::string, std::string>> args;
	args.reserve(4);
	
	args.emplace_back("chat_id", std::string { chat_id });
	args.emplace_back("from_chat_id", std::string { from_chat_id });
	args.emplace_back("disable_notification", disable_notification ? "true" : "false");
	args.emplace_back("message_id", std::to_string(message_id));
	
	return message_from_json(this->async_http_client.send_request("forwardMessage", args));
}

/*Message::Ptr sendPhoto(std::string_view chat_id,
						   std::string_view photo,
						   std::string_view caption = "",
						   std::string_view parse_mode = "",
						   bool disable_notification = false,
						   int reply_to_message_id = 0,
						   const GenericReply::Ptr& reply_markup = nullptr) const;
Message::Ptr sendAudio(std::string_view chat_id,
						   std::string_view audio,
						   std::string_view caption = "",
						   std::string_view parse_mode = "",
						   int duration = 0,
						   std::string_view performer = "",
						   std::string_view title = "",
						   std::string_view thumb = "",
						   bool disable_notification = false,
						   int reply_to_message_id = 0,
						   const GenericReply::Ptr& reply_markup = nullptr) const; 
Message::Ptr sendDocument(std::string_view chat_id,
							  std::string_view document,
							  std::string_view thumb = "",
							  std::string_view caption = "",
							  std::string_view parse_mode = "",
							  bool disable_notification = false,
							  int reply_to_message_id = 0,
							  const GenericReply::Ptr& reply_markup = nullptr) const;
Message::Ptr sendVideo(std::string_view chat_id,
						   std::string_view video,
						   int duration = 0,
						   int width = 0,
						   int height = 0,
						   std::string_view thumb = "",
						   std::string_view caption = "",
						   std::string_view parse_mode = "",
						   bool supports_streaming = false,
						   bool disable_notification = false,
						   int reply_to_message_id = 0,
						   const GenericReply::Ptr& reply_markup = nullptr) const;
Message::Ptr sendAnimation(std::string_view chat_id,
						   std::string_view animation,
						   int duration = 0,
						   int width = 0,
						   int height = 0,
						   std::string_view thumb = "",
						   std::string_view caption = "",
						   std::string_view parse_mode = "",
						   bool disable_notification = false,
						   int reply_to_message_id = 0,
						   const GenericReply::Ptr& reply_markup = nullptr) const;
Message::Ptr sendVoice(std::string_view chat_id,
						   std::string_view voice,
						   std::string_view caption = ""
						   std::string_view parse_mode = "",
						   int duration = 0,
						   bool disable_notification = false,
						   int reply_to_message_id = 0,
						   const GenericReply::Ptr& reply_markup = nullptr) const;
Message::Ptr sendVideoNote(std::string_view chat_id,
							   std::string_view video_note,
							   int duration = 0,
							   int length = 0,
							   std::string_view thumb,
							   bool disable_notification = false,
							   int reply_to_message_id = 0,
							   const GenericReply::Ptr& reply_markup = nullptr) const;
std::vector<Message::Ptr> sendMediaGroup(std::string_view chat_id,
											 const std::vector<GenericMedia::Ptr>& media,
											 bool disable_notification = false,
											 int reply_to_message_id = 0) const;
Message::Ptr sendLocation(std::string_view chat_id,
							  float latitue,
							  float longitude,
							  int live_period = 0,
							  bool disable_notification = false,
							  int reply_to_message_id = 0,
							  const GenericReply::Ptr& reply_markup = nullptr) const;
Message::Ptr sendVenue(std::string_view chat_id,
						   float latitude,
						   float longitude,
						   std::string_view title,
						   std::string_view address,
						   std::string_view foursquare_id = "",
						   std::string_view foursquare_type = "",
						   bool disable_notification = false,
						   int reply_to_message_id = 0,
						   const GenericReply::Ptr& reply_markup = nullptr) const;
Message::Ptr sendContact(std::string_view chat_id,
							 std::string_view phone_number,
							 std::string_view first_name,
							 std::string_view last_name = "",
							 std::string_view vcard = "",
							 bool disable_notification = false,
							 int reply_to_message_id = 0,
							 const GenericReply::Ptr& reply_markup = nullptr) const;
Message::Ptr sendPoll(std::string_view chat_id,
						  std::string_view question,
						  std::vector<std::string>& options,
						  bool is_anonymous = false,
						  std::string_view type = "regular",
						  bool allows_multiple_answers = true,
						  int correct_option_id = 0,
						  std::string_view explanation = "",
						  std::string_view explanation_parse_mode = "MarkdownV2",
						  int open_period = 5,
						  int close_date = 5,
						  bool is_closed = false,
						  bool disable_notification = false,
						  int reply_to_message_id = 0,
						  const GenericReply::Ptr& reply_markup = nullptr) const;
Message::Ptr sendDice(std::string_view chat_id,
						  std::string_view emoji = "🎲",
						  bool disable_notification = false,
						  int reply_to_message_id = 0,
						  const GenericReply::Ptr& reply_markup = nullptr) const;
bool sendChatAction(std::string_view chat_id, std::string_view action) const;
UserProfilePhotos::Ptr getUserProfilePhotos(int user_id, int offset = 0, int limit = 100) const;
bool kickChatMember(std::string_view chat_id, int user_id, int until_date = 0) const;
bool unbanChatMember(std::string_view chat_id, int user_id) const;
bool restrictChatMember(std::string_view chat_id, int user_id, const ChatPermissions::Ptr& permissions, int until_date = 0) const;
bool promoteChatMember(std::string_view chat_id,
						   int user_id,
						   bool can_change_info = false,
						   bool can_post_messages = false,
						   bool can_edit_messages = false,
						   bool can_delete_messages = false,
						   bool can_invite_users = false,
						   bool can_restrict_members = false,
						   bool can_pin_messages = false,
						   bool can_promote_members = false) const;
bool setChatAdministratorCustomTitle(std::string_view chat_id, int user_id, std::string_view custom_title) const;
bool setChatPermissions(std::string_view chat_id, const ChatPermissions::Ptr& permissions) const;
std::string exportChatInviteLink(std::string_view chat_id) const;
bool setChatPhoto(std::string_view chat_id, const InputFile::Ptr& photo) const;
bool deleteChatPhoto(std::string_view chat_id) const;
bool setChatTitle(std::string_view chat_id, std::string_view title) const;
bool setChatDescription(std::string_view chat_id, std::string_view description) const;
bool pinChatMessage(std::string_view chat_id, int message_id, bool disable_notification = false) const;
bool unpinChatMessage(std::string_view chat_id) const;
bool leaveChat(std::string_view chat_id) const;
Chat::Ptr getChat(std::string_view chat_id) const;
std::vector<ChatMember::Ptr> getChatAdministrators(std::string_view chat_id) const;
int getChatMembersCount(std::string_view chat_id) const;
ChatMember::Ptr getChatMember(std::string_view chat_id, int user_id) const;
bool setChatStickerSet(std::string_view chat_id, std::string_view sticker_set_name) const;
bool deleteChatStickerSet(std::string_view chat_id) const;
bool answerCallbackQuery(std::string_view callback_query_id,
							 std::string_view text = "",
							 bool show_alert = false,
							 std::string_view url = "",
							 int cache_time = 0) const;
bool setMyCommands(const std::vector<BotCommand::Ptr>& commands) const;
std::vector<BotCommand::Ptr> getMyCommands() const;
bool editMessageText(std::string_view text,
						 std::string_view chat_id,
						 int message_id,
						 std::string_view inline_message_id = "",
						 std::string_view parse_mode = "",
						 bool disable_web_page_preview = false,
						 const InlineKeyboardMarkup::Ptr& reply_markup = nullptr) const;
bool editMessageCaption(std::string_view chat_id,
							int message_id,
							std::string_view inline_message_id = "",
							std::string_view caption = "",
							std::string_view parse_mode = "",
							const InlineKeyboardMarkup::Ptr& reply_markup = nullptr) const;
bool editMessageMedia(std::string_view chat_id,
						  int message_id,
						  std::string_view inline_message_id = "",
						  const GenericMedia::Ptr& media,
						  const InlineKeyboardMarkup::Ptr& reply_markup) const;
bool editMessageReplyMarkup(std::string_view chat_id,
								int message_id,
								std::string_view inline_message_id = "",
								const InlineKeyboardMarkup::Ptr& reply_markup) const;
Poll::Ptr stopPoll(std::string_view chat_id,
					   int message_id,
					   const InlineKeyboardMarkup::Ptr& reply_markup) const;
bool deleteMessage(std::string_view chat_id, int message_id) const;
Message::Ptr sendSticker(std::string_view chat_id,
							 const InputFile::Ptr& sticker,
							 bool disable_notification = false,
							 bool reply_to_message_id = 0,
							 const GenericReply::Ptr& reply_markup) const;
StickerSet::Ptr getStickerSet(std::string_view name) const;
File::Ptr uploadStickerFile(int user_id, const InputFile::Ptr& png_sticker) const;
bool createNewStickerSet(int user_id,
							 std::string_view name,
							 std::string_view title,
							 std::string_view emojis,
							 const InputFile::Ptr& png_sticker = nullptr,
							 const InputFile::Ptr& tgs_sticker = nullptr,
							 bool contains_masks = false,
							 const MaskPosition::Ptr& mask_position = nullptr) const;
bool addStickerToSet(int user_id,
						 std::string_view name,
						 std::string_view emojis,
						 const InputFile::Ptr& png_sticker,
						 const InputFile::Ptr& tgs_sticker,
						 const MaskPosition::Ptr& mask_position) const;
						 
bool setStickerPositionInSet(std::string_view sticker, int position) const;
bool deleteStickerFromSet(std::string_view sticker) const;
bool setStickerSetThumb(std::string_view name, int user_id, const InputFile::Ptr& thumb) const;*/