/*
Command-line tool for counting unique words in a text file
Usage: ./WordCounter infile [outfile]
 */


#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>


using namespace std;


/** Convert character to lower
 *
 * @param c The character to convert
 * @return The converted character
 */
char charToLower(const char c){
  if (65 <= c && c <= 90)
    return c + 32;
  return c;
}


/** Convert a string to lower case
 *
 * @param s The string to convert
 * @return The converted string
 */
string lower(const string s){
  string t;
  transform(s.begin(), s.end(), back_inserter(t), chartolower);
  return t;
}


/** Is a character whitespace or a dash?
 *
 * @param c The character to test
 * @return True if the character is whitespace or hyphen, false otherise
 */
bool space(const char c){
  return isspace(c) || c == '-';
}


/** Is not the character not whitespace or a dash?
 *
 * @param c The character to test
 * @return True if the character is not whitespace or hyphen, false otherwise
 */
bool notSpace(const char c){
  return !space(c);
}


/** Split a string on whitespace and hyphens
 *
 * @param s The string to split
 * @return A vector of the words in the string
 */
std::vector<string> split(const string s){
  typedef string::const_iterator Iter;
  vector<string> words;
  Iter i = s.begin();

  while (i != s.end()){ // While i is not at the end of s
    // Put i at the start of the next word, and j at the end of it
    i = find_if(i, s.end(), notSpace);
    iter j = find_if(i, s.end(), space);
    
    if (i != s.end()) // Success, so add the word to the vector
      words.push_back(string(i, j));
    i = j;
  }
  return words;
}


/** Is a character not a lowercase character?
 *
 * @param c The character to test
 * @return True if the character is any other than a-z, false otherwise
 */
bool notLowerChar(const char c){
  return c < 97 || c > 122;
}


/** Remove punctuation from a string
 *
 * @param s The string to remove from
 * @return The modified string
 */
string noPunct(string s){
  string::const_iterator iter(remove_if(s.begin(), s.end(), notLowerChar));
  s.erase(iter, s.end());
  return s;
}


/** Get the maximum length of word in a word counter
 * @param counter The word counter
 * @return The length of the longest word
 */
int maxLen(const map<string, int> counter){
  int m = 0;
  for (map<string, int>::const_iterator it = counter.begin();
       it != counter.end(); ++it){
    m = max(m, int(it->first.length()));
  }
  return m;
}


/** Compare two pairs, according to their second element
 * @param p1 The first pair
 * @param p2 The second pair
 * @return True if p1's second element is greater than p2's, false otherwise
 */
bool comparePair(const pair<string, int> p1, const pair<string, int> p2){
  return p1.second > p2.second;
}


/** Copy a map into a vector, sorted in descening order by the map's values
 * @param counter The map to copy
 * @return A sorted vector of pairs
 */
vector<pair<string,int>> sortedMap(map<string, int> counter){
  vector<pair<string,int>> sorted;
  for_each(counter.begin(), counter.end(),
	   [&] (pair<string, int> p){
	     sorted.push_back(p);
	   });
  sort(sorted.begin(), sorted.end(), comparePair);
  return sorted;
}


int main(int argv, char **argc){
  if (argv <= 1){ // User didn't supply enough arguments
    cout << "Please enter a filename\n";
    cout << "Usage: ./WordCounter infile [outfile]\n";
    return 1;
  }
  
  ifstream infile(argc[1]);

  if (!infile.good()){ // User entered a bad file
    cout << "File does not exist\n";
    cout << "Usage: ./WordCounter infile [outfile]\n";
    return 1;
  }
  
  string s;
  map<string, int> counter;
  
  // While there are lines left to read, read s into a new line
  while (getline(infile, s)){ 
    vector<string> words = split(lower(s));
    // Strip punctutation from the next line
    transform(words.begin(), words.end(), words.begin(), noPunct);
    // Add all words over 4 letter long to the counter
    for_each(words.begin(), words.end(),
	     [&](string t){
	       if (t.length() > 4) ++counter[t];
	     });
  }
  
  vector<pair<string, int>> sortedCounter = sortedMap(counter);
  int maxWordLength = maxLen(counter);

  string outname = "output.txt";
  if (argv == 3) // If the user has given a name for outfile, then use it
    outname = argc[2];
  
  ofstream outfile(outname);
  outfile << "Word" << string(maxWordLength - 3, ' ') <<  "Usage\n\n";

  // Print each word to outfile, with buffer making sure everything is nicely aligned
  for_each(sortedCounter.begin(), sortedCounter.end(),
	   [&] (pair<string, int> p){
	     string buffer = string(maxWordLength - p.first.length() + 1, ' ');
	     outfile << p.first << buffer << p.second << endl;
	   });

  cout << "Output file written to " << outname << "\n";
  return 0; 
}



