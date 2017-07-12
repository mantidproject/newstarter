#ifndef WORDMANIP_H
#define WORDMANIP_H

#include <algorithm>
#include <string>
#include <map>

using namespace std;

//adds a word to a given map
void addWord(map<string, int>& words, string& word);

//compares two int values
bool compare(const pair<string, int>& x, const pair<string, int>& y);

//removes punctuation from a string
void removePunctuation(string& word);

//converts a string to lowercase
void toLower(string& word);

#endif
