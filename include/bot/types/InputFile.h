#pragma once

#include <memory>
#include <string>
#include <fstream>
#include <sstream>

#include <boost/dll/runtime_symbol_info.hpp>

struct InputFile {
	using Ptr = std::shared_ptr<InputFile>;
	
	std::string file_name;
	std::string data;

	static Ptr from_file(std::string_view file) {
		std::ifstream read_file { boost::dll::program_location().parent_path().string() + '\\' + std::string { file }, std::ios::binary };
		
		std::stringstream buffer;
		buffer << read_file.rdbuf();
		
		return std::make_shared<InputFile>(InputFile { std::string(file), buffer.str() });
	}
};