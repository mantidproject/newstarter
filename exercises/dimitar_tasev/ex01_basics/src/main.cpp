//---------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <streambuf>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>

// Order the dictionary in a descending order of word count
const static int PRINT_ORDER_DESC = 1;

// Order the dictionary in an ascending order of word count
const static int PRINT_ORDER_ASC = 2;


/** Checks if the word is contained within the dictionary map
 *	
 *	@param dictionary A map<string, int> that serves as a dictionary for the words
 *	@param word The word to look up into the dictionary
 *
 *	@return Returns true if the word is already in the dictionary
 *			Returns false if the word is not contained in the dictionary
 *
 */
bool wordIsContained(std::map<std::string, int>* dictionary, std::string word)
{
	return dictionary->count(word) ? true : false;
};

/** Checks if the word comforms to the conditions, the one's currently set are that
 *  the word is more than 4 characters long
 *	
 *	@param word The word that is to be checked versus the rules 
 *	
 *	@return True if the word conforms to the rules 
 *			False if the word fails to conform to the rules
 */
bool validWord(const std::string& word)
{
	return word.length() <= 4 ? false : true;
}

/**	Processes the string variable and builds a map serving as a word dictionary, 
 *	counting the occurences of each word
 *
 *	@param fileText The string containing all of the text from the file
 *	@param wordDictionary The map dictinoary that will STORE the information about the 
 *			words and occurence count after the fileText string has been processed
 *
 *	@return Returns a map containing std::pair<string, int> of all the valid words in the text
 *			and the count of their occurence in the text
 *
 *	@throw Throws -44 if the string is overflowing
 */
std::map<std::string, int>* processString(std::string& fileText)
{
	// throw -44 if the string is overflowing
	if (fileText.length() > fileText.max_size())
	{
		throw - 44; // String Overflow error
	}

	// Declare container for the dictionary as a map
	std::map<std::string, int>* wordDictionary = new std::map<std::string, int>();

	std::string word;

	std::stringstream textStream(fileText);

	// Read in a word, add it to the map, if it exists increase quantity
	for (int i = 0; textStream >> word; i++)
	{
		// if the word is not valid, it will not be added nor compared in the dictionary 
		if (!validWord(word))
		{
			continue;
		}

		// transform word to lower case if valid
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);


		// map.count() returns 0 if the word doesn't exist, or 1 if it does
		if (wordIsContained(wordDictionary, word))
		{
			// the word already exists, so increase count
			// second gives access to the integer element, which is 2nd in the pair<string,int>
			wordDictionary->find(word)->second++;
		}
		else
		{
			wordDictionary->insert(std::make_pair(word, 1));
		}
	}

	return wordDictionary;
}

/** Loads the file into a string using a streambuf 
 *  The string's max length is 4294967291, which according to reddit is about 4000 books,
 *	it is possible to overflow it, and then the program will crash
 *	
 *	@param file The file name that will be loaded into a string, it should provide relevant address
 *				to the executable file.
 *
 *	@return Returns an std::string pointer that holds all of the information from the text file
 */
std::string* loadString(std::ifstream* file)
{
	std::string* str = new std::string();

	file->seekg(0, std::ios::end);
	str->reserve(file->tellg());
	file->seekg(0, std::ios::beg);

	str->assign((std::istreambuf_iterator<char>(*file)),
	            std::istreambuf_iterator<char>());

	return str;
};

/** Moves the data from the map dictionary into the vector
 * 
 *	@param wordDictionary The map dictionary that contains all of the words and count pairs
 *	@param order The order in which the vector will be sorted 
 *					PRINT_ORDER_ASC for ascending order 
 *					PRINT_ORDER_DESC for descending order
 */
std::vector<std::pair<std::string, int>>* loadVectorFromMap(const std::map<std::string, int>& wordDictionary)
{
	std::vector<std::pair<std::string, int>> * mapVector = new std::vector<std::pair<std::string, int>>();
	// Traverse all of the map and move all the pairs into the vector
	for (auto itr = wordDictionary.begin(); itr != wordDictionary.end(); ++itr)
	{
		mapVector->push_back(*itr);
	}

	return mapVector;
}

/** Sorts the vector depending on specified order in parameter
 *	
 *	@param mapVector The vector that will be sorted
 *	@param order The order in which the vector will be sorted
 *					PRINT_ORDER_ASC for ascending order
 *					PRINT_ORDER_DESC for descending order
 */
void sortVector(std::vector<std::pair<std::string, int>>* mapVector, int order)
{
	// Change sorting depending on the order
	if (order == PRINT_ORDER_ASC)
	{
		// Sort the vector by each pair's second member
		std::sort(mapVector->begin(), mapVector->end(),
			[=](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
		{
			return a.second < b.second;
		}
		);
	}
	else
	{
		// Sort the vector by each pair's second member
		std::sort(mapVector->begin(), mapVector->end(),
			[=](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
		{
			return a.second > b.second;
		});

	}
}

/** Prints the map dictionary to the console screen in a order specified by the second parameter.
 *	
 *	PRINT_ORDER_ASC for ascending order 
 *	PRINT_ORDER_DESC for descending order
 *
 *	It moves the whole map into a vector so that it can be sorted without 
 *	flipping the map and each pair and then re-ordering by key.
 *
 *	@param wordDictionary The map variable containing the word dictionary
 *	@param order The order in which the dictionary will the ordered, can be
 *					PRINT_ORDER_ASC for ascending or PRINT_ORDER_DESC for descending
 *
 */
void printMap(const std::map<std::string, int>& wordDictionary, int order)
{
	// Create vector holder
	std::vector<std::pair<std::string, int>> * mapVector = loadVectorFromMap(wordDictionary);

	sortVector(mapVector, order);

	std::cout << std::setw(10) << "Word" << ':' << "Count" << std::endl;
	int wordCount = 0;
	std::string buffer;

	for (auto it = mapVector->begin(); it != mapVector->end(); ++it)
	{
		buffer += it->first + "  " + std::to_string(it->second) + '\n';
		wordCount++;
	}
	std::cout << buffer << "\nTotal valid word count: " << wordCount << std::endl;

	//Clean up
	delete mapVector;
}

/** Prints the map dictionary to the console screen in a (default) ascending order.
*	To specify the order provide a second parameter for the function.
*	
*	@param wordDictionary The map variable containing the word dictionary
*							PRINT_ORDER_ASC for ascending or PRINT_ORDER_DESC for descending
*/
void printMap(const std::map<std::string, int>& map)
{
	printMap(map, PRINT_ORDER_ASC);
}

/** Traverses the string parameter and removes all invalid characters specified 
 *
 *	@param fileText The string parameter that holds all of the text
 *	@param invalidCharacters[] The char array parameter that holds all of the invalid characters that will be removed,
								can be specified as a string of characters, and each one of them will be removed

 */
void removeInvalidCharacters(std::string* fileText, const std::string& invalidCharacters)
{
	for (unsigned int i = 0; i < invalidCharacters.length(); i++)
	{
		fileText->erase(std::remove(fileText->begin(), fileText->end(), invalidCharacters[i]), fileText->end());
	}
}

int main(int argc, char** argv)
{

	// The invalid characters that will be removed from the file
	const std::string invalidChars = ".,?\'\"!():-";

	// If the argument list is less than 2 then the file name is missing return and show error
	if (argc < 2)
	{
		std::cerr << "ERROR: Missing file name! Please specify file name as a parameter" << std::endl;
		return -1;
	}

	std::ifstream file;

	file.open(argv[1]);

	// If we failed to load the file return and show error
	if (!file.is_open())
	{
		std::cerr << "ERROR: Cannot find or open file!" << std::endl;
		return -1;
	}

	// Load the text from the file into a string
	std::string* fileText = loadString(&file);

	// Remove all invalid characters from text
	removeInvalidCharacters(fileText, invalidChars);

	std::map<std::string, int>* wordDictionary = nullptr;

	// Process the string after removing all of the invalid characters
	try
	{
		wordDictionary = processString(*fileText);
	}
	catch (int e) // will probably never catch anything because the program will crash
	{
		if (e == -44)
		{
			std::cout << "The string has overflown and the program cannot continue to work properly!";
			return -44;
		}
	}

	// Print the words onto the screen
	printMap(*wordDictionary);
	
	if(wordDictionary)
		delete(wordDictionary);
	delete(fileText);

	return 0;
}
