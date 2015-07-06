/**
* Skeleton main routine
* 
* Read in a file, filename is given by argv from command line
* Store each line in Map so that we can:
*   -> search by key and:      
*    -> IF KEY EXISTS:          increment the value (frequency of that string in file).
*
*    -> IF KEY DOESN'T EXIST:   add the key with value 0.
* 
* After this has been done we can then print the map with key and value to return
* each word and the frequency at which it appears in the textfile.
*/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
#include <iterator>
#include <map>

using namespace std;

map<string, int> loadFileAndCountWords(string inputFileName)
{

	/*********************L O A D I N G  W O R D S  F R O M  I N P U T ****************/
	ifstream inputFile;
	inputFile.open(inputFileName, ios::in);
	if (!inputFile)
	{
		cerr << "Can't open the input file " <<inputFileName << endl;
		exit(1);
	}
	/**********************************************************************************/

	/*ONCE WORDS ARE LOADED WE NEED TO ANALYSE THEM TO SEE WHICH ONES ARE VALID FOR OUR PURPOSES*/
	string line;
	string currentWord;
	int validWordCounter = 0;
	map<string, int> validWordsAndFrequencies;
	//get each line but use a space ' ' as a delimiter to get
	// each word on its own. 

	/* MAY NEED TO USE NESTED GETLINES TO FETCH A LINE AND THEN PARSE IT FOR SPACES*/

	while (getline(inputFile, line)) 
	{
		/*** FORMATTING THE LINE BEFORE READING WORD BY WORD ***/
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == '-') //replacing all hyphens with whitespace to treat them as 2 separate words
			{
				line[i] = ' ';
			}
			// removing some punctuation from the line before it is passed into the string stream.
			if (line[i] == '\"' || line[i] == '\'' || line[i] == '.' || line[i] == ',')
			{
				line.erase(i,1);
			}
			if (isupper(line[i])) // convert all uppercase letters to lowercase (case-insensitivty)
			{
				line[i] = tolower(line[i]); 
			}
		}
		/******************************************************/

		istringstream currentLine(line); // set up the string stream to read in word by word with white space delimiter.

		while (currentLine >> currentWord)
		{
			std::string::size_type wordLengthMinusPunctuation = currentWord.size(); // will be equal before we remove punct.
			if (wordLengthMinusPunctuation > 4)
			{
				for (int i = 0; i < wordLengthMinusPunctuation; i++)
				{
					if (ispunct(currentWord[i]))
					{
						//disregard punctuation so that it doesn't add
						// to the length of the word.
						currentWord.erase(i,1);
						wordLengthMinusPunctuation = currentWord.size();
					}

				}// end for
				// we now have a word that is lowercase and doesn't regard punctuation.
				if (currentWord.size() > 4) // check again that the length is greater than 4 now ALL punct has been removed
				{
					++validWordsAndFrequencies[currentWord];  //add word to the map, increase freq each time that word is
					// seen in the file.
				}
			}// end > 4 if
		}//end word while
	}//end line while
	inputFile.close();
	return validWordsAndFrequencies; // return the map.
}

int writeWordsAndFrequenciesToFile(string outputFilePath, map<string,int> wordsAndFrequencies)
{
	ofstream outputFile;

	/*when the words have been counted the results will be placed into
	* a file called WordCounter.txt. 
	*/
	outputFile.open(outputFilePath, ios::out);
	if (!outputFile)
	{
		cerr << "Can't open the input file " << outputFilePath << endl;
		exit(1);
	}

	//writing the map to WordCounter.txt

	for (map<string,int>::const_iterator it = wordsAndFrequencies.begin();
		it != wordsAndFrequencies.end(); ++it){
			outputFile << it->first << ": " << it->second << endl;
	}
	outputFile.close();
	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		/*if and argument is given to main, set that argument as the
		* name of the file we wish to use as input.
		*/
		printf("%s\n", "No argument provided, exiting.");
		return 0;
	} // end argc if

	string inputFileName(argv[1]); //convert char* to a string
	map<string, int> wordsAndFrequencies = loadFileAndCountWords(inputFileName);
	string outputFilePath(argv[2]);
	writeWordsAndFrequenciesToFile(outputFilePath, wordsAndFrequencies);
	return 0;
} //end main