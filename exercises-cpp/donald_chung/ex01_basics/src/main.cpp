/**
 * Skeleton main routine
 */
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>

typedef std::map<std::string, int> word_counting_container; //typealias

void word_counting(std::istream& input, word_counting_container& word_counts)
{
	std::string current_word;
	while (input >> current_word)
	{
		current_word.erase(std::remove_if(current_word.begin(), current_word.end(), ispunct), current_word.end());//remove punctuation
		std::for_each(current_word.begin(), current_word.end(), [](char& c) {
			c = ::tolower(c);
			});
		if (current_word.length() > 4)
		{
			++word_counts[current_word];
		}
	}
}

bool compare(std::pair<std::string, int>& a, std::pair<std::string, int>& b)
{
	return a.second > b.second;
}

void sorting(word_counting_container& word_counts, std::vector<std::pair<std::string, int>>& arrange)
{

	for (auto& it : word_counts) {
		arrange.emplace_back(it);
	}
	std::sort(arrange.begin(), arrange.end(), compare);
}

void output_result(std::vector<std::pair<std::string, int>>& arrange)
{
	std::ofstream outf{ "result.txt" };
	if (!outf)
	{
		std::cerr << "result.txt" << " could not be opened for writing!\n";
		std::exit(1);
	}
	outf << "Word, Usage,\n";
	for (int i = 0; i < arrange.size(); i++)
	{
		outf << arrange[i].first << "," << arrange[i].second << ",\n";
	}
	std::cout << "result output to result.txt";
}

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		std::string arg1{ argv[1] };
		std::ifstream input_file{ arg1 };
		if (!input_file)
		{
			// Print an error and exit
			std::cerr << arg1 << " could not be opened for reading!\n";
			return 1;
		}
		std::cout << "counting file:" << arg1 << "\n";
		word_counting_container words_count_map;
		word_counting(input_file, words_count_map);
		std::vector<std::pair<std::string, int>> arrange;
		sorting(words_count_map, arrange);
		output_result(arrange);
	}

}
