#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

class WordCounter {
public:

	std::map<std::string, int> occurances;

	std::vector<std::string> loadTextFile(std::string filePath) {
		std::vector<std::string> textLines;
		std::ifstream file(filePath);
		std::string line;

		// check that file opens
		if (!file.is_open()) {
			std::cerr << "Error opening file." << std::endl;
		}

		// iterate over lines and add to vector
		while (std::getline(file, line)) {
			textLines.push_back(line);
		}

		//shut file
		file.close();


		return textLines;
	}

	std::vector<std::string> splitAtSpace(std::string inputString) {
		std::vector<std::string> splitWords;
		std::string tmp;
		std::stringstream ss(inputString);

		// treat the string as a string stream with space as delimiter
		while (std::getline(ss, tmp, ' ')) {

			// add each string section between spaces to the vector
			splitWords.push_back(tmp);
		}

		return splitWords;

	}


	std::vector<std::string> stripPunctuation(std::vector<std::string> textLine) {
		std::string text;
		// iterate over the strings in the line
		for (int i = 0; i < textLine.size(); i++) {

			//set the temp text to be equal to each string
			text = textLine[i];

			//inplace alter this temp variable to remove punctuation
			text.erase(std::remove_if(text.begin(), text.end(), ispunct), text.end());
			
			// update the value in the vector
			textLine[i] = text;
		}
		// do something, probably inplace

		return textLine;
	}

	std::vector<std::string> splitHyphens(std::vector<std::string> textLine) {
		std::vector<std::string> newLine;
		std::vector<std::string> tmpVec;
		std::string tmp;
		
		// iterate over the strings in the line
		for (int i = 0; i < textLine.size(); i++) {

			// convert each string to a string stream
			std::stringstream ss(textLine[i]);

			// treat the - as delimeters to split string
			while (std::getline(ss, tmp, '-')) {

				// add to a temp vector
				tmpVec.push_back(tmp);
			}

			// iterate over the temp vector
			for (int j = 0; j < tmpVec.size(); j++) {

				// add each string to the final line vector
				newLine.push_back(tmpVec[j]);
			}

			// clear the tempory vector between iterations
			tmpVec.clear();
		}
		return newLine;
	}

	std::string toLower(std::string inputString) {
		// Iterates over range and applies the to lower transformation
		std::transform(inputString.cbegin(), inputString.cend(), inputString.begin(), std::tolower);
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

	std::vector<std::pair<std::string, int> > sortByCount(std::vector<std::pair<std::string, int> > &wordsAndCounts) {
		std::sort(wordsAndCounts.begin(), wordsAndCounts.end(), [](std::pair<std::string, int> left, std::pair<std::string, int> right) {
			return left.second > right.second;
			});

		return wordsAndCounts;

	}

	int writeToFile(std::string filePath, std::vector<std::pair<std::string, int> > wordsAndCounts) {

		std::ofstream outFile(filePath);

		if (!outFile.is_open()) {
			std::cerr << "Error opening file for writing!" << std::endl;
			return 1;
		}

		outFile << "Words      Count     " << std::endl;

		// Write vector of pairs to the file
		for (const auto& pair : wordsAndCounts) {
			outFile << pair.first << " " << pair.second << std::endl;
		}

		outFile.close();
		return 0;
	}



};

class Viewer {
public:
	std::string getFilePath() {
		std::string filePath;

		std::cout << "Input File Path: ";
		std::cin >> filePath;

		return filePath
	}

};

class Presenter {
public:
	Viewer viewer;
	WordCounter wordCounter;



	Presenter(Viewer& viewer, WordCounter& wordCounter) {
		this->viewer = viewer;
		this->wordCounter = wordCounter;
	}
};

class Tester {
public:
	WordCounter testedClass;


	bool testLoadFile() {
		std::string filePath = "C:/Users/kcd17618/Documents/Induction/newstarter/tests/test.txt";
		std::vector<std::string> output;
		std::vector<std::string> expectedOutput = {"Here", "is", "a", "test", "", "file!"};

		output = testedClass.loadTextFile(filePath);


		return output == expectedOutput;
	}

	bool testSplitAtSpace() {
		std::string testString = "here is a test! string with, various? \"incorrect\" applications of: (punctuation)";
		std::vector<std::string> output;
		std::vector<std::string> expectedOutput = { "here", "is", "a", "test!", "string", "with,", "various?", "\"incorrect\"", "applications", "of:", "(punctuation)" };

		output = testedClass.splitAtSpace(testString);

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
		std::string inputs[4] = {"Convert", "these", "to", "LOWER"};
		std::string output[4];
		std::string expectedOutput[4] = {"convert", "these", "to", "lower"};
		bool pass = true;

		for (int i = 0; i < 4; i++) {
			output[i] = testedClass.toLower(inputs[i]);
			if (expectedOutput[i] != output[i]) {
				pass = false;
			}
		}

		return pass;
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
		std::vector<std::pair<std::string, int> > outputVector;
		testedClass.occurances = testOccurances;

		outputVector = testedClass.convertMapToVector();

		// if we get through to this point the map must have been successfully converted.
		return true;

	
	
	}

	bool testVectorSorter() {
		std::vector<std::pair<std::string, int> > inputVector = { {"test", 3}, {"this", 1}, {"map", 5} };
		std::vector<std::pair<std::string, int> > outputVector;
		std::vector<std::pair<std::string, int> > expectedVector = { {"map", 5}, {"test", 3}, {"this", 1} };

		outputVector = testedClass.sortByCount(inputVector);

		return outputVector == expectedVector;



	}

	void runAllTests() {
		int pass = 0;
		int fail = 0;
		int n = 0;
		std::string tests[10] = {"LoadFile", 
								"SplitAtSpace",
								"StripPunctuation", 
								"SplitHyphensWith",
								"SplitHyphensWithout",
								"ToLower",
								"Increment", 
								"MapToVector", 
								"VectorSorter"};
		
		if (testLoadFile()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testSplitAtSpace()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testStripPunctuationFromLines()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testSplitHyphensWithHyphens()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testSplitHyphensWithoutHyphens()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testToLower()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testIncrementing()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testMapToVectorConverter()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testVectorSorter()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		
		std::cout << "Tests passed: " << pass << ". Tests failed: " << fail << "\n";


	
	}


	Tester(WordCounter wordCounter) {
		testedClass = wordCounter;
	}
};

int main(int, char **)
{
	WordCounter wordCounter;

	Tester tester(wordCounter);


	tester.runAllTests();




	return 0;
}