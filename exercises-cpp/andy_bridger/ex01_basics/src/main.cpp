/**
 * Skeleton main routine
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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

	bool testIncrementing() {
		std::map<std::string, int> testInitOccurances = { {"test", 1}, {"this", 3}, {"map", 5}};
		std::map<std::string, int> testFinalOccurances = { {"test", 2}, {"this", 4}, {"map", 5}, {"adding", 1}};
		std::vector<std::string> inputLine = { "test", "adding", "this" };
		testedClass.occurances = testInitOccurances;

		testedClass.incrementOccurances(inputLine);

		return testedClass.occurances == testFinalOccurances;
		
	}

	bool testMapToVectorConverter() {
		std::map<std::string, int> testOccurances = { {"test", 1}, {"this", 3}, {"map", 5} };
		std::vector<std::pair<std::string, int> > expectedVector = { {"test", 1}, {"this", 3}, {"map", 5} };
		std::vector<std::pair<std::string, int> > outputVector;
		testedClass.occurances = testOccurances;

		outputVector = testedClass.convertMapToVector();

		return outputVector == expectedVector;

	
	
	}

	bool testVectorSorter() {
		std::vector<std::pair<std::string, int> > inputVector = { {"test", 3}, {"this", 1}, {"map", 5} };
		std::vector<std::pair<std::string, int> > outputVector;
		std::vector<std::pair<std::string, int> > expectedVector = { {"map", 5}, {"test", 3}, {"this", 1} };

		outputVector = testedClass.sortByCount(inputVector);

		return outputVector == expectedVector;



	}


	Tester(WordCounter wordCounter) {
		testedClass = wordCounter;
	}
};

class WordCounter {
public:

	std::map<std::string, int> occurances;

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

	void incrementOccurances(std::vector<std::string> textLine) {
		// Look at each word in the line
		for (int i = 0; i < textLine.size(); i++) {
			// Check if the word has already been counted in the map
			if (auto search = occurances.find(textLine[i]); search != occurances.end()) {
				// If it has, increment
				occurances[textLine[i]]++;
			}
			else {
				// If it hasn't add a key value pair with a count of 1
				occurances[textLine[i]] = 1;
			}
		}

	}

	std::vector<std::pair<std::string, int> > convertMapToVector() {
		std::vector<std::pair<std::string, int> > wordsAndCounts;

		std::copy(occurances.begin(), occurances.end(), back_inserter(wordsAndCounts));

		return wordsAndCounts;

	}

	std::vector<std::pair<std::string, int> > sortByCount(std::vector<std::pair<std::string, int> > wordsAndCounts) {
		
		std::sort(wordsAndCounts.begin(), wordsAndCounts.end(), [](auto& left, auto& right) {
			return left.second > right.second;
			});

		return wordsAndCounts;

	}










};

int main(int, char **)
{
	std::cout << "Hello World!";
	return 0;
}