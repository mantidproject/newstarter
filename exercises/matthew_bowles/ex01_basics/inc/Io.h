#ifndef IO_H
#define IO_H

#include <string>
#include <map>
#include <vector>

using namespace std;

//loads word input from a file 
map<string, int> loadFile(const string& path);

//splits a line of the input into words
void splitLine(string &line, map<string, int>& words);

//sorts map of words into descending order by value
vector<pair<string, int>> sortWords(const map<string, int>& words);

//outputs the words to a file
void outputCount(const vector<pair<string, int>>& words);

#endif
