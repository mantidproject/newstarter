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

std::string read_file(const std::string &fp) {
	std::ifstream f(fp);
	std::string file_text;

	if (f) {
		std::ostringstream ss;
		ss << f.rdbuf();
		file_text = ss.str();
	}

	return file_text;
}

void replace_hyphens_newlines(std::string &input_txt) {
	for (int i = 0; i < input_txt.length(); i++) {
		if (input_txt[i] == '-' || input_txt[i] == '\n') {
			input_txt[i] = ' ';
		}
	}
}

void remove_punctuation(std::string &input_txt) {
	input_txt.erase(std::remove_if(input_txt.begin(), input_txt.end(), ispunct), input_txt.end());
}

void word_to_lower_case(std::string &word) {
	std::transform(word.begin(), word.end(), word.begin(), std::tolower);
}

void add_to_map(const std::string &word, std::map<std::string, int> &word_counts) {
	if (word_counts.find(word) != word_counts.end()) {
		word_counts[word] += 1;
	} else {
		word_counts[word] = 1;
	}
}

std::map<std::string, int> build_word_counts(const std::string &input_txt) {
	std::map<std::string, int> word_counts;
	std::string word;
	std::stringstream sstream(input_txt);

	while (std::getline(sstream, word, ' ')) {
		remove_punctuation(word);
		if (word.length() > 4) {
			word_to_lower_case(word);
			add_to_map(word, word_counts);
		}
	}

	return word_counts;
}

std::multimap<int, std::string, std::greater<int>>  create_sorted_word_count(const std::map<std::string, int> &word_counts) {
	std::multimap<int, std::string, std::greater<int>> sorted_word_counts;
	for (const auto& el : word_counts) {
		sorted_word_counts.insert({ el.second, el.first });
	}

	return sorted_word_counts;
}


size_t find_max_word_length(const std::map<std::string, int> &word_counts) {
	size_t max_l = 0;
	size_t l = 0;
	for (const auto& pair : word_counts) {
		l = pair.first.length();
		if (l > max_l) {
			max_l = l;
		}
	}
	return max_l;
}


void print_word_counts(const std::map<std::string, int> &word_counts) {
	std::multimap<int, std::string, std::greater<int>> sorted_word_counts; 
	sorted_word_counts = create_sorted_word_count(word_counts);

	const size_t column_width = find_max_word_length(word_counts) + 1;
	std::string a = "Word";
	int b;
	std::string remainder(column_width - a.length(), ' ');

	std::cout << a << remainder << "Uses" << std::endl;

	for (const auto& el : sorted_word_counts) {
		a = el.second;
		b = el.first;
		std::string remainder(column_width - a.length(), ' ');
		std::cout << a << remainder << b << std::endl;
	}
}

int main(int, char **)
{
	std::string file_text, word;
	std::map<std::string, int> word_counts;
	const std::string file_path = "C:/Users/bya67386/work/newstarter/exercises-cpp/jonathan_haigh/ex01_basics/src/holmes.txt";

	file_text = read_file(file_path);
	replace_hyphens_newlines(file_text);
	word_counts = build_word_counts(file_text);

	print_word_counts(word_counts);
}