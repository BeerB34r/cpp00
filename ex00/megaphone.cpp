#include <iostream>

std::string megaphone(std::string s) {
	std::string temp;

	if (s.empty()) { return "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; }
	for (char c : s) { temp.push_back((char)std::toupper(c)); }
	return temp;
}

int main(int argc, char *argv[]) {
	std::string message;

	for (int i = 1; i < argc; i++) { message.append(argv[i]); }
	message.pop_back();
	std::cout << megaphone(message) << std::endl;
}
