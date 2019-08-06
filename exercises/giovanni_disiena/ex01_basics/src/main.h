#ifndef MAIN_H
#define MAIN_H

#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <string>

// declare map/lamba/pair/set types which will store values
// in non-increasing order unsing comparison logic
typedef std::map<std::string, int> MapType;
typedef std::pair<std::string, int> Pair;
typedef const std::function<bool(Pair, Pair)>& Comparator;

std::string str_tolower(std::string&);
void cleanWord(std::string&, std::vector<std::string>&);
void orderWords(const MapType&, std::vector<Pair>&, const Comparator&);
const std::string formatWhitespace(const std::string&, const std::size_t&);
bool readFile(const std::string&, MapType&, std::size_t&, const std::size_t = 4);
const void writeFile(const std::vector<Pair>&, const std::size_t&, bool&);

#endif // MAIN_H