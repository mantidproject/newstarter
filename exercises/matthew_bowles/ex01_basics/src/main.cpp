#include "main.h"

using namespace std;

int main(int, char **)
{
	ReadFile("TextFile1.txt");
	return 0;
}

vector<string> ReadFile(string path)
{
	vector<string> Words;
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

	vector<string>::iterator iter = Words.begin();
	while (iter != Words.end())
	{
		printf("Next word is %s \n", iter->c_str());
		++iter;
	}
	getchar();
	FileIn.close();
	return Words;
}

vector<string> SplitLine(vector<string> Words, string Line)
{
	string Word;
	size_t Space;

	Space = Line.find(" ");
	while (Space != string::npos)
	{
		Word = Line.substr(0, Space);
		Line = Line.substr(++Space);
		if( Word.size() > 4)
			Words.push_back(Word);
		Space = Line.find(" ");
	}
	if (Word.size() > 4)
	Words.push_back(Line);
	return Words;
}

map<string, int> CreateWordCounter(vector<string>)
{
	map<string, int> WordCounter;
	return WordCounter;
}

void OutputCount(map<string, int>)
{
	return;
}
