#include <sstream>

#include <bot/types/types.h>
#include <boost/property_tree/ptree.hpp>

auto inlinekeyboardmarkup_to_string(const InlineKeyboardMarkup::Ptr& ikm) noexcept -> std::string;
auto user_from_json(const boost::property_tree::ptree& pt) -> User::Ptr;
auto chat_from_json(const boost::property_tree::ptree& pt) -> Chat::Ptr;
auto chatphoto_from_json(const boost::property_tree::ptree& pt) -> ChatPhoto::Ptr;
auto chatpermissions_from_json(const boost::property_tree::ptree& pt) -> ChatPermissions::Ptr;
auto messageentity_from_json(const boost::property_tree::ptree& pt) -> MessageEntity::Ptr;
auto photosize_from_json(const boost::property_tree::ptree& pt) -> PhotoSize::Ptr;
auto animation_from_json(const boost::property_tree::ptree& pt) -> Animation::Ptr;
auto audio_from_json(const boost::property_tree::ptree& pt) -> Audio::Ptr;
auto document_from_json(const boost::property_tree::ptree& pt) -> Document::Ptr;
auto maskposition_from_json(const boost::property_tree::ptree& pt) -> MaskPosition::Ptr;
auto sticker_from_json(const boost::property_tree::ptree& pt) -> Sticker::Ptr;
auto video_from_json(const boost::property_tree::ptree& pt) -> Video::Ptr;
auto videonote_from_json(const boost::property_tree::ptree& pt) -> VideoNote::Ptr;
auto voice_from_json(const boost::property_tree::ptree& pt) -> Voice::Ptr;
auto contact_from_json(const boost::property_tree::ptree& pt) -> Contact::Ptr;
auto dice_from_json(const boost::property_tree::ptree& pt) -> Dice::Ptr;
auto game_from_json(const boost::property_tree::ptree& pt) -> Game::Ptr;
auto polloption_from_json(const boost::property_tree::ptree& pt) -> PollOption::Ptr;
auto poll_from_json(const boost::property_tree::ptree& pt) -> Poll::Ptr;
auto location_from_json(const boost::property_tree::ptree& pt) -> Location::Ptr;
auto venue_from_json(const boost::property_tree::ptree& pt) -> Venue::Ptr;
auto invoice_from_json(const boost::property_tree::ptree& pt) -> Invoice::Ptr;
auto shippingaddress_from_json(const boost::property_tree::ptree& pt) -> ShippingAddress::Ptr;
auto orderinfo_from_json(const boost::property_tree::ptree& pt) -> OrderInfo::Ptr;
auto successfulpayment_from_json(const boost::property_tree::ptree& pt) -> SuccessfulPayment::Ptr;
auto loginurl_from_json(const boost::property_tree::ptree& pt) -> LoginUrl::Ptr;
auto callbackgame_from_json(const boost::property_tree::ptree& pt) -> CallbackGame::Ptr;
auto inlinekeyboardbutton_from_json(const boost::property_tree::ptree& pt) -> InlineKeyboardButton::Ptr;
auto inlinekeyboardmarkup_from_json(const boost::property_tree::ptree& pt) -> InlineKeyboardMarkup::Ptr;
auto message_from_json(const boost::property_tree::ptree& pt) -> Message::Ptr;