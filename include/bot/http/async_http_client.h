#pragma once

#include <string_view>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class AsyncHttpClient {
public:
	AsyncHttpClient() = delete;
	AsyncHttpClient(const AsyncHttpClient&) = delete;
	AsyncHttpClient(AsyncHttpClient&&) = delete;
	AsyncHttpClient& operator=(const AsyncHttpClient&) = delete;
	AsyncHttpClient& operator=(AsyncHttpClient&&) = delete;
	
	AsyncHttpClient(std::string_view url, std::string_view bot_token);
	
	boost::property_tree::ptree send_request(std::string_view method, const std::vector<std::pair<std::string, std::string>>& args = std::vector<std::pair<std::string, std::string>>()) const;
	
private:
	std::string url;
	std::string bot_token;
};