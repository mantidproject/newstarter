#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using std::cout;
using std::endl;


std::vector<int> find_spaces(std::string input_string){
  /*
    Finds all the spaces in a string.

    @param input_string, a string of characters.
    @return spaces, a vector of ints, the indices of the spaces.
  */
  std::vector<int> spaces;
  int index = 0;
  spaces.push_back(0);
  for ( std::string::iterator i = input_string.begin(); i != input_string.end(); i++ ) {
    index++;
    if (isspace(*i) != 0){
      spaces.push_back(index);
      std::cout << "Found a space!" << std::endl;
    }
    std::cout << (*i) << std::endl;
  }
  return spaces;
}



std::vector<std::string> get_words(std::string input_string) {
  /*
    Splits input_string up into its components words by detecting
    any spaces in the string.

    @param input_string a string with spaces.
    @return a vector of strings (the words).
  */
  std::vector<std::string> words;
  std::vector<int> space_locations;
  space_locations = find_spaces(input_string);

  for (int i = 0; i < space_locations.size(); i++) {
    int word_length = (space_locations[i+1]-space_locations[i]);
    if (word_length > 1) {
      std::string word = input_string.substr(space_locations[i], word_length);
      words.push_back(word);
    };
  };
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
    cout << line << " : " << file_line << endl;

  }


  myFile.close();
}

std::vector<std::string> words;
words = get_words("hello world    ");
// std::vector<int> spaces;
// spaces = find_spaces("hello ");

int counter = 0;
for ( auto i = words.begin(); i != words.end(); i++ ) {
    counter++;
    std::cout << counter << " : " << *i << std::endl;
}


std::map<std::string, int> counts;
counts = word_counts(counts , words);

}
