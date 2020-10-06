#include <iostream>
#include <bot/http/async_http_client.h>
#include <bot/types/InputFile.h>
#include <bot/api.h>

int main() {
    Api api("api.telegram.org", "1287379915:AAF4hUK-jhUBHgOyyBK1dUjWFK7NPasqpu0");
	/*Message::Ptr Api::sendMessage(std::string_view chat_id,
							 std::string_view text,
							 std::string_view parse_mode,
							 bool disable_web_page_preview,
							 bool disable_notification,
							 int reply_to_message_id,
							 const GenericReply::Ptr& reply_markup) const */
	//api.sendMessage("528430785", "I send this message and after forward id itself");
	api.forwardMessage("528430785", "528430785", true, 10);
}