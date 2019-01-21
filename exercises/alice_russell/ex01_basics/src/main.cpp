/**
 * Skeleton main routine
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <iterator>
#include <iomanip>

using WordFrequency = std::pair<std::string, int>;

 //returns true if the character is punctuation
bool find_punctuation(char c)
{
	static const std::string punc = ".,?'\"!():";
	return (std::find(punc.begin(), punc.end(), c) != punc.end());
}

std::vector<std::string> find_words(const std::string& s)
{
	std::vector<std::string> ret;
	typedef std::string::size_type string_size;
	string_size i = 0;

	
	while (i != s.size())
	{
		//finds first character which is not a space or hyphen
		while (i != s.size() && (isspace(s[i]) || s[i] == '-'))
		{
			++i;
		}
		//finding the end of the word
		string_size j = i;
		while (j != s.size() && !isspace(s[j]) && s[j] != '-')
		{
			++j;
		}

		std::string word = s.substr(i, j - i);
		//removing any punctuation within the word
		word.erase(std::remove_if(word.begin(), word.end(), find_punctuation), word.end());

		

		//checks if the word is longer than 4 characters 
		if (word.length() > 4)
		{
			//make word lower case
			std::transform(word.begin(), word.end(), word.begin(), tolower);

			ret.push_back(word);
		}
		i = j;
	}
	return ret;
}

bool compare(std::pair<std::string, int> a, std::pair<std::string, int> b)
{
	return a.second > b.second;
}

//counts and sorts the words
std::vector<std::pair<std::string, int> > count_words(const std::vector<std::string>& s)
{

	std::map<std::string, int> count;
	for (std::vector<std::string>::size_type i = 0; i != s.size(); ++i)
	{
		++count[s[i]];
	}

	std::vector<std::pair<std::string, int> > ordered;
	std::copy(count.begin(), count.end(), back_inserter(ordered));

	std::sort(ordered.begin(), ordered.end(), compare);

	return ordered;
}

void count_words(std::istream& in, std::ostream& out)
{
	std::string s;
	std::vector<std::string> find;
	while (std::getline(in, s))
	{
		auto line = find_words(s);
		find.insert(find.end(), line.cbegin(), line.cend());
	}
	std::vector<WordFrequency> words = count_words(find);

	//formatting output
	//find longest word
	unsigned int max_length = 0;
	for (const auto &wordAndCount : words)
	{
		max_length = (wordAndCount.first.length() > max_length) ? wordAndCount.first.length() : max_length;
	}

	out << std::left << std::setw(max_length) << "Word" << "\t" << "Usage" << std::endl << std::endl;
	for (const auto &wordAndCount : words)
	{
		out << std::left << std::setw(max_length) << wordAndCount.first << "\t" << wordAndCount.second << std::endl;
	}
}

void count_words_in_file(const std::string & in_filename, const std::string & out_filename)
{
	std::ifstream infile(in_filename);
	std::ofstream outfile(out_filename);
	if (infile.is_open())
	{
		count_words(infile, outfile);
	}
	else
	{
		throw std::invalid_argument("Unable to open input file: " + in_filename);
	}
}

int main(int argc, char **argv)
{ 

	if (argc > 2)
	{
		std::cerr << "too many files" << std::endl;
	}
	else
	{
		count_words_in_file(argv[1], "results");
	}
	return 0;
}  
