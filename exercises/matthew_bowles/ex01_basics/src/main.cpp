#include "main.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ofstream Output;
		Output.open("Output.txt");
		Output << "Missing input file argument" << endl;
		Output.close();
		return 1;
	}
	map<string, int> Words = ReadFile(argv[1]);
	OutputCount(SortWords(Words));
	return 0;
}

map<string, int> ReadFile(string path)
{
	map<string, int> Words;
	ifstream FileIn;
	string Line;
	string Word;
	
	FileIn.open(path);
	if (FileIn.is_open())
	{
		while (getline(FileIn, Line))
		{
			SplitLine(Words, Line);
		}
	}
	else cout << "unable to open file";
	FileIn.close();
	return Words;
}

void SplitLine(map<string, int> &Words, string Line)
{
	string Word;
	size_t Space;

	Space = Line.find(" ");
	while (Space != string::npos)
	{
		Word = Line.substr(0, Space);
		Line = Line.substr(++Space);
		AddWord(Words, Word);
		Space = Line.find(" ");
	}
	AddWord(Words, Line);
}

void AddWord(map<string, int> &Words, string Word)
{
	map<string, int>::iterator Existing;
	Word = RemovePunc(Word);
	if (Word.length() > 4)
	{
		Word = ToLower(Word);

		Existing = Words.find(Word);
		if (Existing == Words.end())
		{
			Words.insert(std::pair<string, int>(Word, 1));
		}
		else
		{
			Words[Word]++;
		}
	}
}

string RemovePunc(string Word)
{
	while (Word.length() > 1 && !isalpha(Word[Word.length() - 1]))
		Word = Word.substr(0, Word.length() - 1);
	while (Word.length() > 1 && !isalpha(Word[0]))
		Word = Word.substr(1);
	return Word;
}

string ToLower(string Word)
{
	int i = 0;
	while (i < Word.length() && isupper(Word[i]))
	{
		Word[i] = tolower(Word[i]);
		i++;
	}
	return Word;
}

vector<pair<string, int>> SortWords(map<string, int> &Words)
{
	vector<std::pair<string, int>> WordsVector;
	map<string, int>::iterator iter;

	for (iter = Words.begin(); iter != Words.end(); ++iter)
	{
		WordsVector.push_back(*iter);
	}
	sort(WordsVector.begin(), WordsVector.end(), Compare);
	return WordsVector;

}

bool Compare(const pair<string, int>& x, const pair<string, int>& y)
{
	return x.second > y.second;
}

void OutputCount(vector<pair<string, int>> &Words)
{
	ofstream Output;
	vector<pair<string, int>>::iterator iter = Words.begin();
	string Word;

	Output.open("Output.txt");
	Output << "Word" << setw(16) << "Usage" << endl << endl;

	while (iter != Words.end())
	{
		Word = (iter->first).c_str();
		Output << Word << setw(20 - Word.length()) << iter->second << endl;
		++iter;
	}
	Output.close();
	return;
}
