/**
 * PROGRAM DESCRIPTION:
 * 
 * A commnad line program to read in a text file and give the occurrences of the words. 
 *
**/

// Imports
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

// Namespace being used
using namespace std;


/**
 *  Split function to take a line of input and return words in line.
 *  From Accelerated C++ Textbook, page 88.
**/
vector<string> split(const string& s) {
    // Create return object
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    // Process characters
    while(i != s.size()) {
        // Ignore the leading blanks
        while(i != s.size() && isspace(s[i])) {
            ++i;
        }

        // Find end of next word
        string_size j = i;
        while(j != s.size() && !isspace(s[j])) {
            ++j;
        }
        
        // Found some non-whitespace characters
        if(i != j) {
            ret.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return ret;
}


/**
 * Main function.
**/
int main(int, char **) {

    // Get file name from user and store
    cout << "Please enter the name of the file: " << endl;
    string file_name;
    cin >> file_name;

    // Load the file
    ifstream input_file(file_name);

    // To store line of text and words and their counts
    string line;
    map<string, int> word_and_count;

    // Loop through each line
    while(getline(input_file, line)) {
        // Get the list of words in each line
        vector<string> words = split(line);
        
        // Process each word
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); it++) {
            // Dereference the iterator to get back the word
            string word = *it;

            // Loop through the word
            for(int i = 0; i < word.size(); i++) {
                // Deal with hyphens?
                // Deal with allowed punctuation?
                
                // Remove all punctuation and white space
                // Convert upper case letters to lowercase letters
                if(ispunct(word[i]) || isspace(word[i])) {
                    word.erase(i--, 1);
                } else if(isupper(word[i])) {
                    word[i] = tolower(word[i]);
                }
            }

            // Only count words that are longer than 4 letters
            if(word.length() > 4) {
                ++word_and_count[word];
            }
        }
    }

    // Print out the word and it's count
    for(map <string, int>::const_iterator it = word_and_count.begin(); it != word_and_count.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }

    return 0;
}


