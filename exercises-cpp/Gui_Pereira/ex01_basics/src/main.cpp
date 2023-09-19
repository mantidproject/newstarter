/**
 * Skeleton main routine
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class RemovePunctStream{
    public:
    RemovePunctStream(std::ifstream& ist, std::string punct) : ist {ist}, punct {punct} {};
    RemovePunctStream& operator>>(std::string&);
    operator bool();

    private:
    std::ifstream& ist;
    std::istringstream buffer;
    std::string punct;
};

RemovePunctStream& RemovePunctStream::operator>> (std::string& word_out) {

    while (!(buffer >> word_out)) {     // Output here 

        // if (buffer.bad()) break;     // Probably needs something like this, but I am too tired to think about which cases 
        if (!ist.good()) break;        // !good() covers bad(), fail() and eof()

        buffer.clear();

        // Apply punctuaction extraction filter
        std::string line;
        std::getline(ist, line);

        for (char& ch : line) {
            for (const char& ch_punct : punct) {
                if (ch == ch_punct) ch = ' ';
            }
        }
        buffer.str(line);     // Write line to buffer
    }
    return *this;     // Don't really understand this yet, returns pointer to the object itself?
}
    
RemovePunctStream::operator bool () {
    return ist.good();    // It makes more sense to be buffer.good() but that doesn't work
}

std::map<std::string, int> CountOcurrencesInVector(std::vector<std::string> all_words) {

    std::map<std::string, int> counts;

    for (std::string word : all_words) {

        if (!(counts[word]+=1)) counts[word] = 1;
    }
    return counts;
}

int main()
try
{
    // Uncomment this block to ask the user for the text file
    // std::cout << "Please enter the path of the input file:\n";
    // std::string path_to_file;
    // std::cin >> path_to_file;
    // std::ifstream ist {path_to_file};

    // Uncomment for built-in path
    std::ifstream ist {"holmes.txt"};

    if (!ist) throw "Could not open the input text file.";

    // Stream wrapper that outputs same text but without punctuation
    RemovePunctStream rmpunct (ist, ".,?'\"!():");     // Not sure how to deal with char " ' "

    // Put all words into a list
    std::vector<std::string> word_list;
    std::string word;

    while (rmpunct >> word) {
        if (word.length()>4){    // Apply filter for longer words 
            for (char& c : word) c = tolower(c);     // Case insensitive
            word_list.push_back(word);
        }
    }
    // Count ocurrences of a word  
    std::map <std::string, int> counts = CountOcurrencesInVector(word_list);

    // Pass map into vector to use sort() method next
    std::vector<std::pair<std::string, int>> mapcopy(counts.begin(), counts.end());

    // Sort by number of ocurrences
    std::sort(mapcopy.begin(), mapcopy.end(), [](auto& left, auto& right){return left.second > right.second;});

    // Write results to a file 
    std::ofstream out {"./word_counts_out.txt"};
    if (!out) throw "Could not write to the file specified.";

    for (auto pair : mapcopy) out << pair.first << " : " << pair.second << "\n";
}
catch (char const* s)
{
    std::cout << s << '\n';
}
