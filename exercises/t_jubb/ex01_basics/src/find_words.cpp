#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using std::cout;
using std::endl;


std::vector<std::string> get_words(std::string input_string) {
  /*
    Splits input_string up into its components words by detecting
    any spaces in the string.

    @param input_string a string with spaces.
    @return a vector of strings (the words).
  */
  std::vector<std::string> words;
  
  int index      = -1;
  int word_start = 0;
  int word_end   = 0;

  for ( std::string::iterator i = input_string.begin(); i <= input_string.end(); i++ ) {
    index++;

    if (isalpha(*i) != 0){
      word_start = index;
      while ((isalpha(*i) != 0)) {
        index++;
        i++;
        if ((i == input_string.end())) {
          break;
        }
      }
      word_end = index;
      words.push_back(input_string.substr(word_start,(word_end-word_start)));
    }
  }

  return words;
};

std::map<std::string, int> word_counts(std::map<std::string, int> current_counts , std::vector<std::string> word_vec  ) {
  /*
    Adds a vector of words into a map of word:occurance pairs.

    @param current_counts, a map of word:occurance pairs.
    @param word_vec a vector of words.
    @return current_counts after the words in word_vec have been added.
  */
  for ( std::vector<std::string>::iterator i = word_vec.begin(); i != word_vec.end(); i++ ) {
      ++current_counts[(*i)];
  };
  return current_counts;
};




int main()
{

std::map<std::string, int> counts;

// Import test file
std::string file_path = "words.txt";

std::fstream myFile;
myFile.open(file_path,std::ios_base::in);

if (myFile.is_open()) {

  cout << "File " << file_path << " opened successfully!" << std::endl;
  std::string file_line;
  int line = 0;

  while (myFile.good()) {
    line++;
    std::getline(myFile,file_line);
    cout << "\tFile Line " << line << " : " << file_line << endl;

    // count the words
    std::vector<std::string> words;
    words = get_words(file_line);
    int counter = 0;
    for ( auto i = words.begin(); i != words.end(); i++ ) {
        counter++;
        std::cout << counter << " : " << *i << std::endl;
    }
    counts = word_counts(counts , words);

  }
  myFile.close();
}

// Display the words and counts
int counter = 0;
for ( std::map<std::string, int>::iterator i = counts.begin(); i != counts.end(); i++ ) {
    counter++;
    std::cout << counter << " : " << (*i).first << "   " << (*i).second << std::endl;
}

// // Test code
// std::vector<std::string> words;
// words = get_words("hello world    ");
// int counter = 0;
// for ( auto i = words.begin(); i != words.end(); i++ ) {
//     counter++;
//     std::cout << counter << " : " << *i << std::endl;
// }
// counts = word_counts(counts , words);

}
