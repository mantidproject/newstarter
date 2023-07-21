#include <fstream>
#include <map>
#include <regex>
using namespace std;

string padding(string word, size_t targetLength);
void extractWordsFromLine(string lineText, regex splitter, map<string, int> &wordCounter);
multimap<int, string> sortWords(map<string, int>& wordCounter, size_t& lengthOfLongestWord);

int main(int argc, char** argv)
{
	string inputFilePath, outputFilePath;
	if (argc == 2)
	{
		inputFilePath = argv[1];
		outputFilePath = inputFilePath + ".Result.txt";
	}
	else if (argc == 3) 
	{
		inputFilePath = argv[1];
		outputFilePath = argv[2];
	}
	else
	{
		throw invalid_argument("If one argument is passed then it is assumed to be the path of the input file, "
			"if two arguments are passed then it should be the path of the input file followed by the output file. You passed in " + to_string(argc) + "arguments.");
	}

	string lineText;
	ifstream fileReader(inputFilePath);

	if (!fileReader.good())
		throw invalid_argument("The file " + inputFilePath + " doesn't exist or can't be opened.");

	map<string, int> wordCounter{};
	regex splitter("[ -.,?'\"!():]");

	for ( lineText; getline(fileReader, lineText); )
		extractWordsFromLine(lineText, splitter, wordCounter);

	fileReader.close();

	size_t lengthOfLongestWord = 0;
	multimap<int, string> sortedWordCounter = sortWords(wordCounter, lengthOfLongestWord);

	ofstream outputStream(outputFilePath);
	outputStream << "Word" + padding("Word", lengthOfLongestWord) + "    Usage\n\r";
	auto w = sortedWordCounter.rbegin();
	for (; w != sortedWordCounter.rend(); ++w)
		outputStream << w->second + padding(w->second, lengthOfLongestWord) + "    " + to_string(w->first) + "\n";

	outputStream.close();
}

string padding(string word, size_t targetLength) 
{
	string result;
	for (int i = 0; i < targetLength - word.length(); i++)
		result += " ";
	return result;
}

void extractWordsFromLine(string lineText, regex splitter, map<string, int> &wordCounter)
{
	sregex_token_iterator splitLine(lineText.begin(), lineText.end(), splitter, -1), end;
	for (; splitLine != end; ++splitLine)
	{
		string word = *splitLine;
		transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return tolower(c); });
		if (word.length() > 4)
		{
			if (wordCounter.count(word) == 0)
				wordCounter.insert({ word, 1 });
			else
				wordCounter[word]++;
		}
	}
}

multimap<int, string> sortWords(map<string, int> &wordCounter, size_t& lengthOfLongestWord)
{
	multimap<int, string> sortedWordCounter;
	for (const auto w : wordCounter)
	{
		sortedWordCounter.insert({ w.second, w.first });
		if (w.first.length() > lengthOfLongestWord)
			lengthOfLongestWord = w.first.length();
	}
	return sortedWordCounter;
}