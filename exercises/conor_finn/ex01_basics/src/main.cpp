#include "main.h"
#include <algorithm>
#include <functional>

using std::cin;         using std::cout;
using std::string;      using std::endl;
using std::ifstream;    using std::ofstream;
using std::map;         using std::vector;
using std::pair;

/**
 * @brief Creates a results file containing the number of
 * counts of words of >4 characters in a user defined file.
 * 
 * @return int 0 on success, >0 otherwise.
 */
int wordCounterInterface() {
    //Number of characters a word must have to be counted.
    const int characters = 5;
    // Ask for a file path. 
    cout << "Please enter the file path:";
    string path;
    cin >> path;
    ifstream filein;
    filein.open(path.c_str());
    //Create a file in the calling directory. 
    ofstream fileout;

    map<string, int> counts; //Map to hold the counts of each word.

    // Check if the file exists. 
    if(filein.is_open()) {
        map<string, int> counts = countWords(filein, characters);
        vector<pair<int, string> > sorted{sortMap(counts)};
        cout << "Please enter the output path (paths that do not reach existing files will create new ones):";
        cin >> path;
        fileout.open(path.c_str());
        // Write headings to the file. 
        string::size_type maxLength = findMaxSize(sorted);
        fileout << "Word" + string(maxLength - 4, ' ') + "\tCounts" << endl;
        //Write the list of words to the file. 
        for(auto it = sorted.begin(); it != sorted.end(); ++it){
            fileout << it->second + string(maxLength - (it->second.size()), ' ') + 
                "\t" << it->first << endl;
        }
        filein.close();
        fileout.close();
        return 0;
    } else {
        cout << "Invalid path or blank file." << endl;
        return 1;
    }
}

/**
 * @brief Finds the maximum length string in vector of pairs.
 * 
 * @param v The vector to check.
 * @return string::size_type The max size. 
 */
string::size_type findMaxSize(const vector<pair<int, string>> v) {
    string::size_type max = 0;
    for(pair<int, string> p : v) {
        if(p.second.size() > max) {
            max = p.second.size();
        }
    }
    return max;
}

/**
 * @brief Count the number of words with a number characters. 
 * Excludes punctuation and ignores case. 
 * 
 * @param in Input file stream of words. 
 * @return map<string, int> Map of words and counts.
 */
map<string, int> countWords(ifstream& in, int chars) {
    map<string, int> words;
    string s;
    while(in >> s) {
        cleanWord(s);
        if(s.size() >= chars) {
            ++words[s];
        }
    }
    return words;
}

/**
 * @brief Sorting for pairs based on the first value.
 * 
 * @param a First pair to compare. 
 * @param b Second pair to compare. 
 * @return true First element of a > the first element of b
 * @return false First elemet of a <= first element of b
 */
bool sortInRev(const pair<int, string> &a, const pair<int, string> &b) {
    return (a.first > b.first);
}

/**
 * @brief Sorts a map into a vector based on the number of counts. 
 * 
 * @param wordMap The map to sort.
 * @return vector<pair<int, string> > A sorted vector of pairs.  
 */
vector<pair<int, string> > sortMap(map<string, int> wordMap) {
    vector<pair<int, string> > pairs;
    pair<int, string> p;
    for (auto i = wordMap.begin(); i != wordMap.end(); ++i){
        p.first = i->second;
        p.second = i->first;
        pairs.push_back(p);
    }
    std::sort(pairs.begin(), pairs.end(), sortInRev);
    return pairs;
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
    s.erase(std::remove_if(s.begin(), s.end(), isBadPunct), s.end());
    toLowerCase(s);
}

/**
 * @brief Main method to start the program. 
 * Simply calls the wordCounter method. 
 * 
 * @return int 0 on success, any other number otherwise. 
 */
int main(int argc, char ** argv) {
    return wordCounterInterface();
}