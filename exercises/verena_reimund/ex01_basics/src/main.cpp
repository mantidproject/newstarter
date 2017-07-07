/**
 * read a text file and count unique words under some conditions:
 *
 * - minimum word length is 5 letters
 * - remove  hyphen from all words
 * - case and punctuation insensitive
 * - limit punctuation in a word to .,?'"!():
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cstddef>     // std::size_t

const int MWL=5; // min word length

//using namespace std;

// check whether the word contains predefined punctuation
bool punctuation (char c){
    static const std::string punctuation = ".,?'\"!():";
    return (find(punctuation.begin(),punctuation.end(),c)==punctuation.end());
}

// write string and check length
std::string write_str (const std::string& s,std::size_t b, std::size_t e){
    std::string newstr;
    int countp = 0; // count occurence of punctuation
    for (size_t t=b; t<e; ++t){
        if(punctuation(s[t]))
            newstr.push_back(std::tolower(s[t]));// single character required to be case insensitive
    }
    return newstr;
}

// update map
std::map<std::string,int> &update_map (std::map<std::string,int> &themap,std::string s){
    if(s.length()>=MWL){
        ++themap[s];
    }
    s.clear();
    return themap;
}

int main(int argn, char ** argv)
{

    std::string file(argv[1]); // input file as std::string
    // load ascii file for reading
    std::ifstream ifile(file.c_str(),std::ios::in);

    std::string s;         // single word
    std::string splitted;  // will contain substring
    std::size_t sb,se;     // indicators for the begin and end of the substring in single word
    std::map<std::string,int> counter; // map countains key=words, value=occurence
    std::map<std::string,int>::iterator i,k;

    if (ifile.is_open()){
        while(ifile.is_open() && ifile.good()){
            ifile >> s; //read single word
            sb = 0;
            se = s.find_first_of("-");
            while (se!=std::string::npos){// case hyphen, split word in substrings
                splitted = write_str(s,sb,se); // substring 'splitted' inside word 's'
                counter = update_map(counter,splitted);
                sb = se + 1;                     // update start position in new substring
                se = s.find_first_of("-",se +1); // update end position in new substring
            }
            // case hyphen, last substring or replace s
            s = write_str(s,sb,s.length());
            counter = update_map(counter,s);
        }
        ifile.close();
    }
    else{
        std::cout << "Failed to open input file for writing" << std::endl;
    }

    // Write results file in descending order of word usage
    // search for max occurence, print out, delete from map; repeat
    std::ofstream ofile("UniqueWordOccurence",std::ios::out);
    int max_val;
    if (ofile.is_open()){
        while(!counter.empty()){
           k=counter.begin();
           max_val = 0;
           for (i = counter.begin();i!=counter.end();i++){
               if(max_val<i->second){
                   max_val=i->second;
                   k=i;
               }
           }
           // write to file in decending order of occurence
           ofile << k->first << "\t" << k->second << "\n";
           counter.erase(k);
        }
    }
    else{
        std::cout << "Failed to open output file for writing" << std::endl;
    }
    ofile.close();

    return 0;
}
