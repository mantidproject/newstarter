/**
 * Skeleton main routine
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::pair<std::string, int> > pair_vec;

//checks if the character is among allowed punctuation characters
bool isNotSpecialCharacter(const char & c)
{
    static const std::string specialCharacters = ".,?'\"!():";
    return std::find(specialCharacters.begin(),specialCharacters.end(),c)
           == specialCharacters.end();
}

//builds a vector of pairs out of map
pair_vec MapToPairVector(const std::map<std::string,int> & map)
{
    pair_vec ret;

    for(std::map<std::string,int>::const_iterator it = map.begin();
        it != map.end(); ++it)
    {
        ret.push_back(std::make_pair(it->first,it->second));
    }

    return ret;
}

//compares pairs by the value
bool CompareCount(const std::pair<std::string, int> & p1, const std::pair<std::string, int> & p2)
{
    return p1.second < p2.second;
}

int main (int argc, char ** argv)
{
    std::ifstream infile;
    std::ofstream outfile;
    std::string word;
    std::map<std::string,int> wordCounts;
    std::string::size_type maxlength = 0;

    //check if the input file name is specified
    if (argc < 2)
    {
        std::cout << "Please specify a valid input file!\n";
        return 0;
    }

    infile.open(argv[1],std::ios::in);

    //read in word by word
    while (infile >> word) {

       //erase special characters from word
       std::string::iterator iter =
       std::stable_partition(word.begin(),word.end(),isNotSpecialCharacter);

       word.erase(iter,word.end());

       //check the word length
       if(word.size() <= 4)
           continue;

       //transform to lowercase
       std::transform(word.begin(), word.end(), word.begin(), ::tolower);

       //increment the count in the map
       ++wordCounts[word];

       //compute the maxlength for alignment
       if(word.size() > maxlength)
           maxlength = word.size();

    }

    infile.close();

    //sort the map by value
    pair_vec counts = MapToPairVector(wordCounts);

    sort(counts.begin(),counts.end(),CompareCount);

    outfile.open("output.txt",std::ios::out);

    outfile << "Word" << std::string(maxlength-4,' ') << "\t" << "Usage\n\n";

    //print out the results
    for(pair_vec::const_reverse_iterator it = counts.rbegin();
        it != counts.rend(); ++it)
    {
        outfile << it->first << std::string(maxlength-it->first.size(),' ')
                << "\t" << it->second << "\n";
    }

    outfile.close();

    return 0;
}
