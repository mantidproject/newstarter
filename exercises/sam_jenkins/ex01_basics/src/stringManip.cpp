#include <string>
#include <cctype>
#include <regex>
using std::string;
const int MINIMUM_WORD_LENGTH = 4;

bool space(const char& c)
{
	return (isspace(c) || c == '-');
}


void stripString(string& input)
{
	//remove these delimiters from the begining and ending of words
	const string delimiters = " .,?:;\'\"()!";

	while (input.length() > MINIMUM_WORD_LENGTH && delimiters.find(input.back()) != string::npos) {
		input.pop_back();
	}

	while (input.length() > MINIMUM_WORD_LENGTH && delimiters.find(input.front()) != string::npos) {
		input.erase(0, 1);

	}

}