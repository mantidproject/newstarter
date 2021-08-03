#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <bits/stdc++.h>

//Adds words to dictionary
void pushWord(std::unordered_map<std::string, unsigned>& dict, std::string word)
{
    word.erase (std::remove_if (word.begin (), word.end (), ispunct), word.end ());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word.length()>4)
        {
            ++dict[word];
        }
}
int main()
{
    std::string fileName;
    std::string inLine;

    std::cout << "type fileName: ";
    std::cin >> fileName;
    
    std::ifstream inFile("../"+fileName);
    std::unordered_map<std::string, unsigned> dict;
    
    std::string word;
    while (inFile >> word)
    {
        //splits hypenated
        std::size_t found = word.find('-');
        if (found!=std::string::npos)
        {
            pushWord(dict, word.substr(0,found));
            pushWord(dict, word.substr(found+1,word.length()-found));
        }
        else
        {
            pushWord(dict, word);
        }
        
    }
    inFile.close();

    std::multimap<int, std::string> MM;
    for (auto& it : dict) {
        MM.insert({ it.second, it.first });
    }
    //AscendingCout
    /*
    for (auto const &pair: MM) {
        //std::cout << "{" << pair.second << ": " << pair.first << "}\n";
    }
    */

    //DescendingCout
    /*
    std::multimap<int, std::string>::reverse_iterator rit;
    for (rit=MM.rbegin(); rit!=MM.rend(); ++rit) {
        std::cout << "{" << rit -> second << ": " << rit -> first << "}\n";
    }
    */
    
    //DescendingFout
    std::ofstream outFile("../outText.txt");
    std::multimap<int, std::string>::reverse_iterator rit;
    for (rit=MM.rbegin(); rit!=MM.rend(); ++rit) {
        outFile << "{" << rit -> second << ": " << rit -> first << "}\n";
    }
    outFile.close();
}