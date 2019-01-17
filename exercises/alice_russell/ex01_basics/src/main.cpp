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
std::vector<std::pair<std::string, int> > count_words(std::vector<std::string> s)
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

int main(int argc, char **argv)
{ 

	if (argc > 2)
	{
		std::cerr << "too many files" << std::endl;
	}
	else
	{
		std::ifstream infile(argv[1]);
		std::ofstream outfile("results");
		if (infile)
		{
			std::string s;
			std::vector<std::string> find;
			while (std::getline(infile, s))
			{
				std::vector<std::string> line = find_words(s);
				for (std::vector<std::string>::const_iterator it = line.begin(); it != line.end(); ++it)
				{
					find.push_back(*it);
				}
			}
			std::vector<std::pair<std::string, int> > words = count_words(find);

			//formatting output
			//find longest word
			int max_length = 0;
			for (std::vector<std::pair<std::string, int> >::const_iterator i = words.begin(); i != words.end(); ++i)
			{
				max_length = (i->first.length() > max_length) ? i->first.length() : max_length;
			}


			outfile << std::left << std::setw(max_length) << "Word" << "\t"  << "Usage" << std::endl << std::endl;
			for (std::vector<std::pair<std::string, int> >::const_iterator i = words.begin(); i != words.end(); ++i)
			{
				outfile << std::left << std::setw(max_length) << i->first << "\t"  << i->second << std::endl;
			}
		}
		else
		{
			std::cerr << "cannot open file " << argv[1] << std::endl;
		}
	}
	return 0;
}  
