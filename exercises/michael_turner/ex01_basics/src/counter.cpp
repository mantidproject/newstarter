#include "counter.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>

namespace{
    //Turns WordMap into WordRank [multimap]
    WordRank flipMap(WordMap& counters);

    //Returns true if character is whitespace or punctuations (except hyphens)
    bool isPunc(char c);

    //Returns true if character is hyphen
    bool isHyphen(char c);
}

/** Counts the number of occurences of unique words (over 4 letters)
 *
 *		@param line	The input text containing words to be counted
 *		@param counters		The container to hold the current totals.
 *
 */

void countWords(std::string& line, WordMap& counters){
    //Minimum word length
    static const std::string::size_type  MIN_LENGTH = 5;

    //Lower any capital letters, to ensure output is case insensitive
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);

    //Iterate through string to find words
    std::string::size_type i = 0;
    while (  i < line.size()){
        //Ignore leading blanks and punctuation (including hyphens)
        while (i < line.size() && (isPunc(line[i]) || isHyphen(line[i])) ){
            ++i;
        }

        //Find end of next word, allow hyphenations, but no double hyphens
        std::string::size_type j = i;

        //If current character is hyphen, following character cannot be
        while ( j < line.size() && (!isPunc(line[j]) && !(isHyphen(line[j]) && isHyphen(line[j+1]) ))){
            ++j;
}
        //If word longer than four letters is found, add to counter
        if ( j - i >= MIN_LENGTH)
            ++counters[line.substr(i, j - i)];

        //Set start iterator to current end position
        i = j;

    }
}

/** Ranks words by order of decreasing frequency, and
 * saves rank in a file.
 *
 * File placed in same dir
 *
 * @param counters     Map of words with associated key values
 * @param outFile       The output ofstream object to write the rank to
 *
 */

void rankWords(WordMap& counters, std::ofstream& outFile){
    //Column width
    static const int COL_WIDTH = 20;

    WordRank rank = flipMap(counters);

    //Output rank to file
    outFile << std::left << std::setw(COL_WIDTH)
                << "Word" << "Usage\n" << std::endl;
    for (auto it = rank.rbegin(); it != rank.rend(); ++it){
        outFile << std::left << std::setw(COL_WIDTH)
                    << it->second << it->first << std::endl;
    }
}

    namespace{
    /**  Turns WordMap into WordRank [multimap], which
     * automatically sorts words by descending frequency
     *
     * @param counters		Map of words and associated frequency
     *
     * @returns rank			MultiMap of frequencies and associated words
     *
     */

    WordRank flipMap(WordMap& counters){
        WordRank rank;

        for (auto it = counters.begin(); it != counters.end(); ++it)
            rank.insert(std::pair<int, std::string>(it -> second, it -> first));
          return rank;
    }

    /** Checks if character is whitespace or punctuation
     * Punctuation defined by PUNC
     *
     * @param c		The character to be checked
     *
     * @returns		True if punc or whitespace, false otherwise
     *
     */

    bool isPunc(char c){
        static const std::string PUNC = ".,?'\"!():;";
        return ((PUNC.find(c) != std::string::npos) || std::isspace(c));
    }

    /** Checks if character is a hyphen
     * Hyphen defined by HYPHEN
     *
     * @param c		The character to be checked
     *
     * @returns		True if hyphen, false otherwise
     *
     */

    bool isHyphen(char c){
        static const std::string HYPHEN = "-";
        return (HYPHEN.find(c) != std::string::npos);
    }
}
