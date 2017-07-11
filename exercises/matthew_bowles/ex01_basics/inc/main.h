#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//loads word input from a file
map<string, int> loadFile(string path);

//splits a line of the input into words
void splitLine(string line, map<string, int> &words);

//adds a word to a given map
void addWord(map<string, int> &words, string word);

//compares two int values
bool compare(const pair<string, int>& x, const pair<string, int>& y);

//removes punctuation from a string
string removePunctuation(string word);

//converts a string to lowercase
string toLower(string word);

//sorts map of words into descending order by value
vector<pair<string, int>> sortWords(map<string, int> &words);

//outputs the words to a file
void outputCount(vector<pair<string, int>> &words);