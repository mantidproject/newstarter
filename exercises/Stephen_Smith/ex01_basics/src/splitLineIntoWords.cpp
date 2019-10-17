#include "../include/splitLineIntoWords.h"

// boolean expression to test if character is a space of hyphen
bool spaceOrHyphen (char c)
{
    return (( c == '-') || (isspace(c)));
}
// boolean expression to ensure that character is neither a hyphen nor a space
bool notSpaceOrHyphen ( char c)
{
    return !(( c == '-') || (isspace(c)));
}
// Splits a line into words using spaces and hyphens as delimiters between the words 
std::vector<std::string> splitLineIntoWords(const std::string& line)
{
    // iterator over the string
    auto wordStart = line.begin();
    // output container
    std::vector<std::string> lineWords;
    while(wordStart != line.end())
    {
        // Find first character of word
        wordStart = std::find_if(wordStart,line.end(),notSpaceOrHyphen);
        // Find last character of word
        std::string::const_iterator wordEnd;
        wordEnd = std::find_if(wordStart,line.end(),spaceOrHyphen);
        // copy the word into output container
        if (wordStart != line.end())
        {
            lineWords.push_back(std::string(wordStart,wordEnd));
        }

        wordStart = wordEnd;
    }

    return lineWords;
}