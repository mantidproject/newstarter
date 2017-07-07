//===-- llvm/main.h - Main definition -------*- C++ -*-=======================//
//
//                           The Word Counter
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration for the methods contained in the
/// main.cpp file.
///
//===----------------------------------------------------------------------===//
#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/// Minimum length of a word.
const int MIN_WORD_LENGTH = 5;

/// Flips the keys and values of the map \p mp.
template<typename A, typename B>
std::multimap<B, A> flip_map(const std::unordered_map<A, B>& mp);

/// Totals the number of each unique word in the vector \p words,
/// which passes the condition \p cond.
std::unordered_map<std::string, int> countUniqueWords(const std::vector<std::string>& words, 
	const bool cond(std::string));

/// Retrieves all words from the input stream \p in, where words
/// are defined as the vector created when the input is split by
/// the delimiters specified in \p delimiters.
std::vector<std::string> getWords(std::istream& in, const std::unordered_set<char>& delimiters);

/// Splits a string \p str, at the delimiters specified in \p delimiters and
/// stores the result in the specified vector \p words.
std::vector<std::string> split(const std::string str, const std::unordered_set<char>& delimiters,
	std::vector<std::string> words);

/// Overloading the << operator to allow for inserting multimaps with int keys 
/// and string values into output streams.
std::ostream &operator<<(std::ostream &os, const std::multimap<int, std::string>& mp);

#endif /* WORD_COUNTER_H */