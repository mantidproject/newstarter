#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

bool checkWord(string &wrd);
bool isPunctuation(char c);

/** Flips an std pair around so that the key becomes the value and the value becomes the key

	@param p This is the pair which will be swapped around.
*/
template<typename A, typename B>
std::pair<B,A> flipPair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

/** Creates a flipped multimap which swaps the keys with values for conventional maps

	Multimaps are used because the allow duplicate keys.

	@param src Source map whose keys and values will be swapped
*/
template<typename A, typename B>
std::multimap<B,A> flipMap(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flipPair<A,B>);
    return dst;
}

int main(int argc, char **argv)
{
	//Program will be terminated if no file specified
	if(argc == 0)
	{
		cout << "No arguments specified. Ending program." << endl;
		return -1;
	}

	//store filename in string
	string fname(argv[1]);


	cout << "Processing " << fname << ":\n" << endl;

	
	ifstream infile(fname);
	ofstream outfile("HolmesWordUsage.txt");
	map<string, int> wordFreq;
	string word;

	//Read each string from file and process before adding to frequence map
	while(!infile.eof())
	{
		infile >> word;
		
		if(checkWord(word))
			wordFreq[word]++;
	}

	multimap<int, string> sortedList = flipMap(wordFreq);

	outfile<< "Word" << "\tUsage\n" << endl;// write header to output file

	//Write entries in reverse order since keys are sorted in ascending order 1 to n.
	for(map<int, string>::const_reverse_iterator iter = sortedList.rbegin(); iter != sortedList.rend(); iter++)
		outfile<<iter->first<<"\t"<<iter->second<<endl;

	system("notepad.exe HolmesWordUsage.txt");

	cout<<"Complete!"<<endl;

	return 0;
}

/** Checks that the string is at lease 4 chars long, does not start with a digit, removes punctiation and forces lower case.

	@param str String to be examined and if necessary modified.
*/
bool checkWord(string &str)
{
	bool isWord = false;

	if(str.size() > 4 && !isdigit(str[0]))
	{
		isWord = true;
		str.erase(std::remove_if(str.begin(), str.end(), isPunctuation), str.end());
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	}

	return isWord;
}

/** Predicate function which tests whether or not character is a punctuation character

@param c character tested against the list ".,?'"!():"
*/
bool isPunctuation(char c)
{
	bool isPunc = false;

	static const char chars[] = ".,?\'\"!():";

	for(int i=0; i<strlen(chars); i++)
	{
		if(c == chars[i])
		{
			isPunc = true;
			break;
		}
	}

	return isPunc;
}