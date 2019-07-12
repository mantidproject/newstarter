#ifndef MAIN_H_
#define MAIN_H_

#include <map>
#include <iostream>
#include <fstream>
#include <vector>

std::map<std::string, int> countWords(std::ifstream& in);

bool isBadPunct(char c);

int wordCounterInterface();

int main(int, char **);

void cleanWord(std::string& s);

void toLowerCase(std::string& s);

std::vector<std::pair<int, std::string>> sortMap(std::map<std::string, int>);

std::string::size_type findMaxSize(const std::vector<std::pair<int, std::string>> v);

#endif