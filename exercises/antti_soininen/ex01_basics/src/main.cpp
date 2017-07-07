#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

bool is_punctuation(char c)
{
    const size_t nPunctuation = 9;
    const char punctuation[] = {
        '.', ',', '?', '\'', '\"', '!', '(', ')', ':'
    };
    for(size_t i = 0; i != nPunctuation; ++i)
        if(punctuation[i] == c) return true;
    return false;
}

typedef std::pair<const std::string*, unsigned> countPair;
bool count_comparison(const countPair& lhs, const countPair& rhs)
{
    return lhs.second > rhs.second;
}

int main(int argc, char **argv)
{
    std::ifstream in(argv[1]);
    std::map<std::string, unsigned> wordCount;
    std::string w;
    while(!in.eof()) {
        char c;
        in.get(c);
        c = std::tolower(c);
        if(!std::isspace(c) && !is_punctuation(c)) {
            w.push_back(c);
        }
        else {
            if(w.size() > 4) ++wordCount[w];
            w.clear();
        }
    }
    std::vector<countPair> resorted;
    std::map<std::string, unsigned>::iterator iter = wordCount.begin();
    for( ; iter != wordCount.end(); ++iter) {
        resorted.push_back(countPair(&iter->first, iter->second));
    }
    std::sort(resorted.begin(), resorted.end(), count_comparison);
    std::vector<countPair>::iterator iter2 = resorted.begin();
    for( ; iter2 != resorted.end(); ++iter2) {
        std::cout << *iter2->first << " " << iter2->second << std::endl;
    }
    return EXIT_SUCCESS;
}
