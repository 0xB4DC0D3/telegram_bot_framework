#include <iostream>
#include <bot/http/async_http_client.h>

int main() {
    AsyncHttpClient http("api.telegram.org", "1287379915:AAF4hUK-jhUBHgOyyBK1dUjWFK7NPasqpu0");
	
	std::ostringstream oss;
	boost::property_tree::json_parser::write_json(oss, 
												  http.send_request("getUpdates", 
												  std::vector<std::pair<std::string, std::string>> {{ "offset", "0" }})
	);
	std::cout << oss.str() << std::endl;
}