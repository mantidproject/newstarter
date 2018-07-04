#include <string>
#include <cctype>
#include <regex>
using std::string;


bool space(const char& c)
{
	return (isspace(c) || c == '-');
}

bool not_space(const char& c)
{
	return !(isspace(c) || c == '-');
}

void strip_string(string& input)
{
	string delimiters = " .,?:;\'\"()!";
	while (input.length() > 4 && delimiters.find(input.back()) != string::npos) {
		input.pop_back();
	}
	while (input.length() > 4 && delimiters.find(input.front()) != string::npos) {
		input.erase(0, 1);

	}

}