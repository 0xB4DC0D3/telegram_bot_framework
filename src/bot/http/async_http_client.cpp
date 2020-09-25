#include <bot/http/async_http_client.h>

AsyncHttpClient::AsyncHttpClient(std::string_view url, std::string_view bot_token) : url { url }, bot_token { bot_token } {}

boost::property_tree::ptree AsyncHttpClient::send_request(std::string_view method, const std::vector<std::pair<std::string, std::string>>& args) const {
	boost::asio::ssl::context ctx { boost::asio::ssl::context::sslv23_client };
	ctx.set_default_verify_paths();
	
	boost::asio::io_context io_context;
	boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket { io_context, ctx };
	
	boost::asio::ip::tcp::resolver resolver { io_context };
	boost::asio::connect(socket.lowest_layer(), resolver.resolve("api.telegram.org", "https"));
	socket.lowest_layer().set_option(boost::asio::ip::tcp::no_delay(true));
	
	socket.set_verify_mode(boost::asio::ssl::verify_none);
	socket.set_verify_callback(boost::asio::ssl::rfc2818_verification("api.telegram.org"));

    socket.handshake(boost::asio::ssl::stream<boost::asio::ip::tcp::socket>::client);
	
	const auto request_method { args.empty() ? "GET" : "POST" };
	
	auto generate_arguments = [&args] {
		std::string generated_arguments {};
		for (const auto &[key, value] : args) {
			generated_arguments += key + "=" + value + "&";
		}
		
		generated_arguments.pop_back();
		
		return generated_arguments;
	};
	
	auto generated_arguments { generate_arguments() };
	
	std::stringstream ss;
	ss << request_method << " /bot" << this->bot_token << "/" << method << " HTTP/1.1\r\n";
	ss << "Host: " << this->url << "\r\n";
	ss << "Connection: close\r\n";
	
	if (request_method == "POST") {
		ss << "Content-Type: application/x-www-form-urlencoded\r\n";
		ss << "Content-Length: " << generated_arguments.length() << "\r\n\r\n";
		ss << generated_arguments;
	} else {
		ss << "\r\n";
	}
	
	std::cout << "Generated request: " << ss.str() << std::endl;
	
	boost::asio::async_write(socket, boost::asio::buffer(ss.str()), [] (const boost::system::error_code& error, std::size_t bytes_transferred) {
		if (error) {
			std::cout << "[async_write] " << error.message() << std::endl;
		}
	});
	
	char response[2048];
	
	boost::asio::async_read(socket, boost::asio::buffer(response), [] (const boost::system::error_code& error, std::size_t bytes_transferred) {
		if (error) {
			std::cout << "[async_read] " << error.message() << std::endl;
		}
	});
	
	io_context.run();
	
	std::string_view _response { response };
	const auto new_line_pos { _response.find("\r\n\r\n") + 4 };
	
	boost::property_tree::ptree json;
	std::istringstream input(static_cast<std::string>(_response.substr(new_line_pos, _response.find_last_of('}') + 1 - new_line_pos)));
	boost::property_tree::read_json(input, json);
	
	if (json.get<bool>("ok", false)) {
		return json.get_child("result");
	} else {
		throw std::exception { "Failed to send request" };
	}
}