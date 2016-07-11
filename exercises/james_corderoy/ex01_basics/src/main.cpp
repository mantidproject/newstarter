#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

#define WORDDELIMS " \n\t\r"
#define PUNCTUATION ".,?'\"!():"
#define LETTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define OUTFILENAME "results.txt"


std::string readContents(std::string fileName)
{
	std::ifstream inFile(fileName.c_str());
	if (!inFile)
		throw "Could not open input " + fileName;
	
	std::stringstream buffer; buffer << inFile.rdbuf(); 
	return buffer.str();
}


bool isIn(char ch, std::string str)
{
	return str.find(std::string(1, ch)) != std::string::npos;
}

std::map<std::string, int> countWords(std::string fileContents)
{
	fileContents += WORDDELIMS[0]; // make sure the last word gets counted if there is one
	std::map<std::string, int> wordCounter;
	std::map<std::string, int>::iterator it;
	std::string currentWord = "";
	
	for (int i = 0; i < fileContents.length(); i++)
	{
		char currentChar = fileContents[i];
		if (isIn(currentChar, WORDDELIMS))
		{ // split the current word off and add it to the tally
	
			if (currentWord.length() <= 4)
			{ // too short, discard the word
				currentWord = "";
				continue;				
			}
	
			int oldCount = 0;
			
			try 
			{ // word already exists in map
				oldCount = wordCounter.at(currentWord);
				wordCounter.erase(currentWord);
			}
			catch (std::out_of_range err)
			{ // word doesn't exist yet
			}
			
			int newCount = oldCount + 1;
			wordCounter.insert( std::pair<std::string, int> (currentWord, newCount) );
			currentWord = "";
		}
		
		else if (isIn(currentChar, PUNCTUATION))
		{ // ignore punctuation			
		}
		
		else if (isIn(currentChar, LETTERS))
		{ // a letter, so just uncapitalise it and add it to the current word
			currentWord += tolower(currentChar);
		}
		
		else
		{ // something else, just ignore it
		}
	}
	
	return wordCounter;
}


void printWordMap(std::map<std::string, int> wordCounts)
{
	std::ofstream outFile(OUTFILENAME);
	if (!outFile)
	{
		std::cout << "Could not open output " OUTFILENAME;
		return;
	}
	
	outFile << "Word\t\tUsage\n";
	
	std::vector< std::pair<int, std::string> > words;
	for (std::map<std::string, int>::iterator it = wordCounts.begin(); it != wordCounts.end(); ++it) 
	{
    	words.push_back(std::pair<int, std::string> (it->second, it->first));
    }
	std::sort(words.rbegin(), words.rend()); // sorts in descending order
	for (std::vector< std::pair<int, std::string> >::iterator it = words.begin(); it != words.end(); ++it) 
	{
    	outFile << it->second << "\t\t" << it->first << "\n";
    }
}



int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		std::cout << "Too few arguments";
		return 0;
	}
	
	
	std::string fileName = argv[1];
	std::string fileContents;
	try
	{
		fileContents = readContents(fileName);
	}
	catch (std::string errStr)
	{
		std::cout << errStr;
		return 0;
	}

	
	std::map<std::string, int> wordCounts = countWords(fileContents);

	printWordMap(wordCounts);
	
	return 0;
}