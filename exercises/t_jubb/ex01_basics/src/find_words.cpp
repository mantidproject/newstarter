#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;


std::vector<std::string> get_words(const std::string input_string, const int min_len) {
  /*
    Splits input_string up into its components words by finding a character, and then
    iterating through characters until a non-alphabetic character is found.

    @param input_string a string with spaces.
    @param min_len, minimum lenth of word to store.
    @return a vector of strings (the words).
  */
  std::vector<std::string> words;
  
  int index      = -1;
  int word_start = 0;
  int word_end   = 0;
  int word_len   = 0;

  for ( std::string::const_iterator i = input_string.begin(); i <= input_string.end(); i++ ) {
    index++;
    // If we find the start of a word.
    if (isalpha(*i) != 0){
      word_start = index;
      // Iterate through the string until the character is not part of a word.
      while ((isalpha(*i) != 0)) {
        index++;
        i++;
        // Catch the end of the string for last word
        if ((i == input_string.end())) {
          break;
        }
      }
      word_end = index;
      word_len = word_end - word_start;
      if ( word_len > min_len){
        words.push_back(input_string.substr(word_start,(word_end-word_start)));
      }
    }
  }

  return words;
};

int add_word_counts(std::map<std::string, int>& current_counts , const std::vector<std::string>& word_vec  ) {
  /*
    Adds a vector of words into a map of word:occurance pairs.

    @param current_counts, a map of word:occurance pairs.
    @param word_vec a vector of words.
    @return current_counts after the words in word_vec have been added.
  */
  for ( std::vector<std::string>::const_iterator i = word_vec.begin(); i != word_vec.end(); i++ ) {
      ++current_counts[(*i)];
  };
  // return current_counts;
  return 0;
};

int ordered_by_value(std::vector< std::pair<  int , std::string > >& vec ,std::map<std::string, int >& count_map) {
  // Create a vector to store the pairs.
  std::pair<int,std::string> elem;
  for ( std::map<std::string, int >::iterator i = count_map.begin() ; i != count_map.end(); i++ ) {
      // Reverse the pair to allow the default vector sort to compare the first entry.
      elem.first = (*i).second;
      elem.second = (*i).first;
      vec.push_back(elem);
  };
  std::sort(vec.begin(),vec.end());
  return 0;
}

int main()
{
const bool verbose = false;

// Map to store the words and counts and key/value pairs
std::map<std::string, int> counts;

// Prompt user for a filepath and check if file exists
std::string file_path;
cout << "Please enter a valid filepath : " ;
bool valid_file = false;
while (!valid_file){
  std::cin >> file_path;
  std::ifstream infile(file_path);
  if (!infile.good() ){
    cout << "File does not exist, please enter a valid file : ";
  }
  else {
    valid_file = true;
  }
}

// Import test file
file_path = "words.txt";
std::fstream myFile;
myFile.open(file_path,std::ios_base::in);

if (myFile.is_open()) {

  cout << "File " << file_path << " opened successfully!" << std::endl;
  std::string file_line;
  int line = 0;

  while (myFile.good()) {
    line++;
    std::getline(myFile,file_line);
    if (verbose == true) {
      cout << "\tFile Line " << line << " : " << file_line << endl;
    }

    // count the words
    std::vector<std::string> words;
    words = get_words(file_line, 4);
    if (verbose == true) {
      int counter = 0;
      for ( auto i = words.begin(); i != words.end(); i++ ) {
          counter++;
          std::cout << counter << " : " << *i << std::endl;
      }
    }
    add_word_counts(counts , words);
  }
  myFile.close();
}

// Display the words and counts
unsigned int counter = 0;
for ( std::map<std::string, int>::iterator i = counts.begin(); i != counts.end(); i++ ) {
    counter++;

    // Pad the gap between word and count.
    int pad = 15 - (*i).first.size();
    std::string pad_blank = " " ;
    for (int i=1; i<pad; i++) {
      pad_blank = pad_blank + " ";
    }

    // Pad the index of the words
    int num_pad = 3; 

    cout << std::setfill('0') << std::setw(num_pad) << counter << " : ";
    cout << (*i).first << pad_blank << (*i).second << endl;
}

// Order the pairs by value using default vector sort
std::vector< std::pair<  int , std::string > > ordered;
ordered_by_value(ordered, counts);

// Display the ordered words and counts.
counter = 0;
for ( std::vector< std::pair<  int , std::string > >::iterator i = ordered.begin(); i != ordered.end(); i++ ) {
    counter++;

    // Pad the gap between word and count.
    int pad = 15 - (*i).second.size();
    std::string pad_blank = " " ;
    for (int i=1; i<pad; i++) {
      pad_blank = pad_blank + " ";
    }

    // Pad the index of the words
    int num_pad = 3; 

    cout << std::setfill('0') << std::setw(num_pad) << counter << " : ";
    cout << (*i).second << pad_blank << (*i).first << endl;
}

}
