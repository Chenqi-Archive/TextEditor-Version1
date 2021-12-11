#include <string>
#include <sstream>
#include <iostream>


using uint = unsigned;


std::string uint_to_hex_string(uint value) {
	std::stringstream stream;
	stream << std::hex << value;
	return stream.str();
}

std::string GetBlockPath(uint block_id) {
	std::string hex_str = uint_to_hex_string(block_id);
	std::string path;
	for (auto it = hex_str.begin(); it < hex_str.end() - 1; it++) {
		path.push_back(*it); path.push_back('/');
	}
	path.push_back(hex_str.back());
	path.append(".json");
	return path;
}


int main() {
	for (uint i = 0; i < 1000; ++i) {
		std::cout << GetBlockPath(i) << std::endl;
	}
}