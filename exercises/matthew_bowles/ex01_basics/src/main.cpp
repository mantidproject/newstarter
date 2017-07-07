#include "main.h"

using namespace std;

int main(int, char **)
{
	ReadFile("Holmes.txt");
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
			Words = SplitLine(Words, Line);
		}
	}
	else cout << "unable to open file";
	SortWords(Words);
	OutputCount(SortWords(Words));
	FileIn.close();
	return Words;
}

map<string, int> SplitLine(map<string, int> Words, string Line)
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
	return Words;
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
	return x.second < y.second;
}

void OutputCount(vector<pair<string, int>> &Words)
{
	vector<pair<string, int>>::iterator iter = Words.begin();
	while (iter != Words.end())
	{
		printf("%s: %d \n", (iter->first).c_str(), iter->second);
		++iter;
	}
	getchar();
	return;
}
