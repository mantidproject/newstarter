/**
 * Skeleton main routine
 */
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iterator>
#include<vector>
#include<algorithm>
#include<map>

int main(int, char **)
{
	std::ifstream f("C:/Users/bya67386/work/newstarter/exercises-cpp/jonathan_haigh/ex01_basics/src/holmes.txt");
	std::string file_text, word;
	std::map<std::string, int> word_counts;

	// read file into string
	if (f) {
		std::ostringstream ss;
		ss << f.rdbuf();
		file_text = ss.str();
	}

	// replace hyphens and new-lines
	for (int i = 0; i < file_text.length(); i++) {
		if (file_text[i] == '-' || file_text[i] == '\n') {
			file_text[i] = ' ';
		}
	}
	// looping over each word to add to word list
	std::stringstream sstream(file_text);
	while (std::getline(sstream, word, ' ')) {
		if (word.length() > 4) {
			// remove other punctuation
			word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
			// to lower case (unsure if required)
			std::transform(word.begin(), word.end(), word.begin(), std::tolower);
			if (word_counts.find(word) != word_counts.end()) {
				// already in map
				word_counts[word] += 1;
			}
			else {
				// must be added
				word_counts[word] = 1;
			}
		}
	}

	// enter key-value pairs (reversed) into multi map to sort
	std::multimap<int, std::string, std::greater<int>> sorted_word_counts;
	for (auto& el : word_counts) {
		sorted_word_counts.insert({ el.second, el.first });
	}

	// printing
	const int column_width = 18;
	std::string a = "Word";
	int b;
	std::string remainder(column_width - a.length(), ' ');
	std::cout << a << remainder << "Uses" << std::endl;

	for (auto& el : sorted_word_counts) {
		a = el.second;
		b = el.first;
		std::string remainder(column_width - a.length(), ' ');
		std::cout << a << remainder << b << std::endl;
	}
}