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

	std::vector<std::string> cullShortWords(std::vector<std::string> textLine) {
		std::vector<std::string> newLine;
		for (int w = 0; w < textLine.size(); w++) {
			if (textLine[w].length() > 4) {
				newLine.push_back(textLine[w]);
			}
		}
		return newLine;
	}

	void incrementOccurances(std::vector<std::string> textLine) {
		// Look at each word in the line
		for (int i = 0; i < textLine.size(); i++) {
			// occurances should default to 0 for new keys 
			occurances[textLine[i]]++;
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

		outFile << "Words          Count     " << std::endl;

		// Write vector of pairs to the file
		for (const auto& pair : wordsAndCounts) {
			outFile << pair.first << "       " << pair.second << std::endl;
		}

		outFile.close();
		return 0;
	}



};

class Viewer {
public:
	std::string askForFilePath(std::string message) {
		std::string filePath;

		std::cout << message;
		std::cin >> filePath;

		return filePath;
	}


};

class Presenter {
public:
	Viewer viewer;
	WordCounter wordCounter;
	std::string inputFilePath;
	std::string outputFilePath;
	std::vector<std::string> lines;
	std::vector<std::string> line;
	std::vector<std::string> lowerLine;
	std::vector<std::pair<std::string, int> > wordsAndCounts;


	void runCounter() {
		// ask for input file
		inputFilePath = viewer.askForFilePath("Input File Path: ");

		// load txt file
		lines = wordCounter.loadTextFile(inputFilePath);

		// iterate over each line
		for (int i = 0; i < lines.size(); i++) {

			// process
			line = wordCounter.splitAtSpace(lines[i]);
			line = wordCounter.stripPunctuation(line);
			line = wordCounter.splitHyphens(line);

			// convert each word to lower case
			if (line.size() > 0) {
				for (int w = 0; w < line.size(); w++) {
					lowerLine.push_back(wordCounter.toLower(line[w]));
				}
				// Cull short words
				lowerLine = wordCounter.cullShortWords(lowerLine);

				// add line to counter map
				wordCounter.incrementOccurances(lowerLine);

				lowerLine.clear();
			}
		}

		// sort the counted words
		wordsAndCounts = wordCounter.convertMapToVector();
		wordsAndCounts = wordCounter.sortByCount(wordsAndCounts);

		// ask for output file
		outputFilePath = viewer.askForFilePath("Output File Path: ");
		wordCounter.writeToFile(outputFilePath, wordsAndCounts);
	}



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

	bool testCullShortWords(){
		std::vector<std::string> input = {"cull", "the", "words", "shorter", "than", "four", "letters"};
		std::vector<std::string> output;
		std::vector<std::string> expectedOutput = { "words", "shorter", "letters" };

		output = testedClass.cullShortWords(input);

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
								"CullShortWords",
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
		if (testCullShortWords()) {
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
	Viewer viewer;
	Presenter presenter(viewer, wordCounter);

	presenter.runCounter();

	// Uncomment these two to run the tests

	// Tester tester(wordCounter);
	// tester.runAllTests();


	return 0;
}