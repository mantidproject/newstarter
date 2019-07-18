#ifndef MAIN_H_
#define MAIN_H_

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

bool isBadPunct(char &character);

int wordCounterInterface();

int main(int, char **);

void cleanWord(std::string &word);

void toLowerCase(std::string &word);

std::vector<std::pair<int, std::string>>
sortMap(const std::map<std::string, int> &map);

std::string::size_type
findMaxStringSize(const std::vector<std::pair<int, std::string>> &stringPairs);

std::map<std::string, int> countWords(std::ifstream &in,
                                      const int &minWordLength);

int writeToFile(std::vector<std::pair<int, std::string>> words);

#endif // MAIN_H_