#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<string> ReadFile(string path);
map<string, int> CreateWordCounter(vector<string>);
void OutputCount(map<string, int>);
vector<string> SplitLine(vector<string>, string);