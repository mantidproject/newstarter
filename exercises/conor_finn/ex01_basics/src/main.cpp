/**
 * Skeleton main routine
 */
#include "main.h"
#include <algorithm>

using std::cin;         using std::cout;
using std::string;      using std::endl;
using std::ifstream;    using std::ofstream;
using std::map;

/**
 * @brief Creates a results file containing the number of
 * counts of words of >4 characters in a user defined file.
 * 
 * @return int 0 on success, >0 otherwise.
 */
int wordCounterInterface() {
    // Ask for a file path. 
    cout << "Please enter the file path:";
    string path;
    cin >> path;
    ifstream filein(path);
    //Create a file in the calling directory. 
    ofstream fileout("results.txt");

    map<string, int> counts; //Map to hold the counts of each word.

    // Check if the file exists. 
    if(!filein.fail()) {
            counts = countWords(filein);
    } else {
        cout << "Invalid path or blank file." << endl;
    }
}

/**
 * @brief Determine if a character is an invalid punctuation character.
 * 
 * @param c The character to check.
 * @return true If invalid.
 * @return false if valid or alphanumeric.
 */
bool isBadPunct(char c) {
    static const string badPunct = ".,?'\"!():";
    return !(isalnum(c) || 
        find(badPunct.begin(), badPunct.end(), c) == badPunct.end());
}

/**
 * @brief Convert a string to be all lower case. 
 * 
 * @param s The string to convert. 
 */
void toLowerCase(string& s) {
    for(string::size_type i = 0; i < s.size(); ++i) {
        s[i] = tolower(s[i]);
    }
}

/**
 * @brief Cleans a word by excluduing invalid punctuation,
 * and changing its case. 
 * 
 * @param s The string to clean. 
 */
void cleanWord(string& s) {
    s.erase(std::remove_if(s.begin(), s.end(), isBadPunct));
    toLowerCase(s);
}

/**
 * @brief Counts the number of occurances of >4 character words 
 * in a file stream. 
 * 
 * @param in The input stream.
 * @return map<string, int> A map of the word and number of occurances. 
 */
map<string, int> countWords(ifstream& in) {
    map<string, int> ret;
    string s;
    // Read strings, using whitespace as a separator. 
    while(in >> s) {
        cleanWord(s);
        // Check that clean string is >4 characters. 
        if(s.size > 4) {
            ++ret[s];
        }
    }
}

/**
 * @brief Main method to start the program. 
 * Simply calls the wordCounter method. 
 * 
 * @return int 0 on success, any other number otherwise. 
 */
int main(int, char **) {
    return wordCounterInterface();
}