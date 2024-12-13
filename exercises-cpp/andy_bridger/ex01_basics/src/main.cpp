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

	bool testLoadFile() {
		std::string filePath = "./test.txt";
		std::vector<std::string> output;
		std::vector<std::string> expectedOutput = {"Here", "is", "a", "test", "", "file!"};

		output = testedClass.loadTextFile(filePath);

		return output == expectedOutput;
	}

	bool testStripPunctuationFromLines() {
		std::vector<std::string> inputs = {"test.", "strings,", "\"for\"", "(striping?)"};
		std::vector<std::string> output;
		std::vector<std::string> expectedOutput = {"test", "strings", "for", "striping" };

		output = testedClass.stripPunctuation(inputs);

		return output == expectedOutput;
	}

	bool testSplitHyphensWithHyphens() {
		std::vector<std::string> input = {"this", "has", "a", "hyphen", "to-split"};
		std::vector<std::string> output;
		std::vector<std::string> expectedOutput = { "this", "has", "a", "hyphen", "to", "split" };

		output = testedClass.splitHyphens(input);

		return output == expectedOutput;
	}

	bool testSplitHyphensWithoutHyphens() {
		std::vector<std::string> input = { "this", "has", "no", "hyphen"};
		std::vector<std::string> output;
		std::vector<std::string> expectedOutput = { "this", "has", "no", "hyphen"};

		output = testedClass.splitHyphens(input);

		return output == expectedOutput;
	}

	bool testToLower() {
		std::string inputs[5] = {"Convert", "these", "to", "LOWER"};
		std::string output[5];
		std::string expectedOutput[5] = {"convert", "these", "to", "lower"};

		for (int i = 0; i < 5; i++) {
			output[i] = testedClass.toLower(inputs[i]);
		}

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

	std::vector<std::string> loadTextFile(std::string filePath) {
		std::vector<std::string> textLines;

		// do something

		//std::ifstream f(filePath)

		return textLines;
	}

	std::vector<std::string> stripPunctuation(std::vector<std::string> textLine) {

		// do something, probably inplace

		return textLine;
	}

	std::vector<std::string> splitHyphens(std::vector<std::string> textLine) {
		std::vector<std::string> newLine; 

		// do something, probably check for hyphen, if present make newLine, otherwise return old line

		return newLine;
	}

	std::string toLower(std::string inputString) {

		// inplace conversion to lowercase

		return inputString;
	}






};

int main(int, char **)
{
	std::cout << "Hello World!";
	return 0;
}