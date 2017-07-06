#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, int> ReadFile(string path);
void OutputCount(map<string, int>);
map<string,int> SplitLine(map<string, int>, string);
void AddWord(map<string, int> &Words, string Word);