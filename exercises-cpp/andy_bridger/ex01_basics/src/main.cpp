/**
 * Skeleton main routine
 */

#include <iostream>
#include <vector>

class Tester {
public:
	WordCounter testedClass;

	bool testSplitAtSpace(){
		std::string testString = "here is a test! string with, various? \"incorrect\" applications of: (punctuation)";
		std::vector<std::string> output;
		std::vector<std::string> expectedOutput = {"here", "is", "a", "test!", "string", "with,", "various?", "\"incorrect\"", "applications", "of:", "(punctuation)"};

		output = testedClass.splitAtSpace(testString);

		return output == expectedOutput;


	}

	Tester(WordCounter wordCounter) {
		testedClass = wordCounter;
	}
};

class WordCounter {
public:
	std::vector<std::string> splitAtSpace(std::string inputString) {
		std::vector<std::string> splitWords;
		//do something

		return splitWords;

	}




};

int main(int, char **)
{
	std::cout << "Hello World!";
	return 0;
}