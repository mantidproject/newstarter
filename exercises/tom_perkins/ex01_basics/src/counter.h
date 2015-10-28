#ifndef COUNTER_H_
#define COUNTER_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

/**
 * The Counter object keeps track of words that it has seen
 * and can report on how many times it has seen each.
 * Currently works for ASCII only (char not wchar_t).
 */
class Counter
{
public:
	void add(const std::string& word);
	void generateReport(std::ostream& stream);

private:
	std::map<std::string, int> m_dictionary; 

};



#endif