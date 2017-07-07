#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> ReadFile(string path);
void OutputCount(vector<pair<string, int>> &Words);
map<string,int> SplitLine(map<string, int>, string);
void AddWord(map<string, int> &Words, string Word);
bool Compare(const pair<string, int>& x, const pair<string, int>& y);
vector<pair<string, int>> SortWords(map<string, int> &Words);
string RemovePunc(string Word);
string ToLower(string Word);