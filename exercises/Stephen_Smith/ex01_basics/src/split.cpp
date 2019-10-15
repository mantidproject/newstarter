// Splits a string into its asscoiated words, separated by hyphens and spaces. 

#include "../include/split.h"



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

std::vector<std::string> split(const std::string& line)
{

    // iterator over the string
    std::string::const_iterator wordStart = line.begin();

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