//
//  WordSearch.cpp
//  Tutorials
//
//  Created by Keith Butler on 15/02/2018.
//  Copyright © 2018 Keith Butler. All rights reserved.
//
#include <cctype>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>

using std::vector; using std::string; using std::map;
using std::ifstream; using std::cout; using std::cin;
using std::ofstream; using std::pair;

// true if argument is an allowed character
bool allowed_character(char c)
{
    // This is the set of characters beyond alphanumeric that we want to consider
    static const string character_set = ".,?'\"!():";
    return (isalnum(c) || find(character_set.begin(),
                               character_set.end(), c) != character_set.end());
}
//true if argument is not an allowed character
bool not_allowed_character(char c)
{
    // This is the set of characters beyond alphanumeric that we want to consider
    static const string character_set = ".,?'\"!():";
    return !(isalnum(c) || find(character_set.begin(),
                                character_set.end(), c) != character_set.end());
}
//split a line (string) into words (vector); based on Acc. C++ pp 103
//the input min lenght can change the minimum length of word that we want to consider
vector<string> split(const string& str, int min_length = 4)
{
    typedef string::const_iterator it;
    vector<string> ret;
    
    it i = str.begin();
    while (i != str.end()){
        //finds the segments bounded by non-allowed characters
        i = find_if(i, str.end(), allowed_character);
        it j = find_if(i, str.end(), not_allowed_character);
        // copy the characters i through to j
        if (i != str.end() && j - i > min_length) // only count > n letter words
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}

// A function to count words in a line adapted from Acc. C++ pp 124 - 127
map<string, int> find_words(const string& line, map<string, int>& counters)
{
    //split the line into words
    vector<string> words = split(line);
    // iterate over words and add new words to counters
    for (vector<string>::const_iterator it = words.begin();
         it != words.end(); it++)
        ++counters[*it];
    return counters;
}
// Template function for switching pairs; adapted from https://stackoverflow.com/questions/8321316/flip-map-key-value-pair
template<typename A, typename B>
pair<B, A> flip_pair(const pair<A, B> &p)
{
    return pair<B, A>(p.second, p.first);
}

// Template function for switching map keys -> values and vice versa
template<typename A, typename B>
vector<pair<B, A> > flip_vec(const vector<pair<A, B> >& src)
{
    vector<pair<B, A> > ret;
    transform(src.begin(), src.end(), inserter(ret, ret.begin()),
              flip_pair<A, B>);
    return ret;
}

// calculates the number of digits in an integer; adapted from https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
int num_digits(int number)
{
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

// Find the maximum width of a pair
int width_pair(const vector<pair<int, string> >& v)
{
    int max_len = 0;
    for(vector<pair<int, string> >::const_iterator it = v.begin();
        it != v.end(); ++it) {
        int len = num_digits(it->first) + (it->second).size();
        max_len = std::max(max_len, len);
    }
    return max_len;
}

// Getting down to business, reading in the file and going through line by line
int main () {
    // Get the name of the input file from the user
    cout << "Please enter the name of the file you want to analyse. " << "\n";
    string filename;
    cin >> filename;
    ifstream myfile (filename);
    map<string, int> counters;
    // Test that the file has opened properly
    if (!myfile.is_open())
        perror("Error while opening file");
    // Read in the file
    string line;
    while ( getline (myfile,line) )
    {
        find_words(line, counters);
    }
    myfile.close();
    
    // Do the sorting
    // Change the map to a vector to allow sorting
    // Use a vector of pairs to preserve pairing
    vector<std::pair<string, int> > counters_v(counters.begin(), counters.end());
    // Reverse the order of the pairs to allow sorting on the numbers
    vector<std::pair<int, string> > reversed = flip_vec(counters_v);
    sort(reversed.begin(), reversed.end());
    reverse(reversed.begin(), reversed.end());
    // write the ouptut
    // we need to findd the longest pair of word + number
    int width = width_pair(reversed);
    cout << "Widest pair ... " << width << '\n';
    ofstream outfile("analysis.out");
    outfile << "Word" << string(width - 9,' ') << "Usage" << '\n';
    outfile << '\n';
    for(vector<pair<int, string> >::const_iterator it = reversed.begin();
        it != reversed.end(); ++it) {
        int pair_width = num_digits(it->first) + (it->second).size();
        
        outfile << it->second << string(width - pair_width,' ')
        << it->first << '\n';
    }
    return 0;
}
