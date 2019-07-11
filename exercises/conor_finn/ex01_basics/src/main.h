#ifndef MAIN_H_
#define MAIN_H_

#include <map>
#include <iostream>
#include <fstream>


bool isBadPunct(char c);

std::map<std::string, int> countWords(std::ifstream& in);

int wordCounterInterface();

int main(int, char **);

#endif MAIN_H_