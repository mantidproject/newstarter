/*
Command-line tool for counting unique words in a text file Usage:
./WordCounter infile [outfile]
 */

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

const unordered_set<char> PUNCT({'.', ',', '?', '\'', '\\', '"', '!', '(', ')', ':'});

/** Convert a string to lower case
 *
 * @param s The string to convert
 * @return The converted string
 */
string lower(const string& s) {
  string t;
  transform(s.begin(), s.end(), back_inserter(t), ::tolower);
  return t;
}

/** Is a character whitespace or a dash?
 *
 * @param c The character to test
 * @return True if the character is whitespace or hyphen, false otherise
 */
bool space(const char c) { return isspace(c) || c == '-'; }

/** Is not the character not whitespace or a dash?
 *
 * @param c The character to test
 * @return True if the character is not whitespace or hyphen, false otherwise
 */
bool notSpace(const char c) { return !space(c); }

/** Split a string on whitespace and hyphens
 *
 * @param s The string to split
 * @return A vector of the words in the string
 */
std::vector<string> split(const string& s) {
  vector<string> words;
  auto i = s.begin();

  while (i != s.end()) { // While i is not at the end of s
    // Put i at the start of the next word, and j at the end of it
    i = find_if(i, s.end(), notSpace);
    string::const_iterator j = find_if(i, s.end(), space);

    if (i != s.end()) // Success, so add the word to the vector
      words.push_back(string(i, j));
    i = j;
  }
  return words;
}

/** Is a character a disallowed punctuation character?
 *
 * @param c The character to test
 * @return True if the character is any other of .,?'"!():, false otherwise
 */
bool isPunct(const char c){
  return PUNCT.find(c) != PUNCT.end();
}

/** Remove punctuation from a string
 *
 * @param s The string to remove from
 * @return The modified string
 */
string noPunct(string s) {
  string::iterator iter(remove_if(s.begin(), s.end(), isPunct));
  s.erase(iter, s.end());
  return s;
}

/** Get the maximum length of word in a word counter
 * @param counter The word counter
 * @return The length of the longest word
 */
int maxLen(const map<string, int> &counter) {
  int m = 0;
  for (const auto &element : counter){
    m = max(m, int(element.first.length()));
  }
  return m;
}

/** Compare two pairs, according to their second element
 * @param p1 The first pair
 * @param p2 The second pair
 * @return True if p1's second element is greater than p2's, false otherwise
 */
bool comparePair(const pair<string, int> &p1, const pair<string, int> &p2) {
  return p1.second > p2.second;
}

/** Copy a map into a vector, sorted in descening order by the map's values
 * @param counter The map to copy
 * @return A sorted vector of pairs
 */
vector<pair<string, int>> sortedMap(map<string, int> &counter) {
  vector<pair<string, int>> sorted;
  copy(counter.cbegin(), counter.cend(), back_inserter(sorted));
  sort(sorted.begin(), sorted.end(), comparePair);
  return sorted;
}

void displayError(const string &msg){
  cout << msg << "\nUsage: ./WordCounter infile [outfile]\n";
}


int main(int argv, char **argc) {
  if (argv <= 1) { // User didn't supply enough arguments
    displayError("Please enter a filename");
    return 1;
  }

  ifstream infile(argc[1]);

  if (!infile.good()) { // User entered a bad file
    displayError("File does not exist");
    return 1;
  }

  string s;
  map<string, int> counter;

  // While there are lines left to read, read s into a new line
  while (getline(infile, s)) {
    vector<string> words = split(lower(s));
    // Strip punctutation from the next line
    transform(words.begin(), words.end(), words.begin(), noPunct);
    // Add all words over 4 letters long to the counter
    for_each(words.begin(), words.end(), [&counter](string t) {
      if (t.length() > 4)
        ++counter[t];
    });
  }

  vector<pair<string, int>> sortedCounter = sortedMap(counter);
  int maxWordLength = maxLen(counter) + 1;
 
  string outname = "output.txt";
  if (argv == 3) // If the user has given a name for outfile, then use it
    outname = argc[2];

  ofstream outfile(outname);
  outfile << "Word" << setw(maxWordLength) << "Usage\n\n";

  // Print each word to outfile, with buffer making sure everything is nicely
  // aligned
  for_each(sortedCounter.begin(), sortedCounter.end(),
           [&](const pair<string, int> &p) {
	     outfile << setfill(' ') << setw(maxWordLength) << left
		     << p.first << p.second << "\n";
           });

  cout << "Output file written to " << outname << "\n";
  return 0;
}
