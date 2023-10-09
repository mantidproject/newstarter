/**
 * Skeleton main routine
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <filesystem>

class RemovePunctStream{
    public:
    RemovePunctStream(std::ifstream& ist, const std::string& punct) : ist {ist}, punct {punct} {};
    RemovePunctStream& operator>>(std::string&);
    operator bool();

    private:
    std::ifstream& ist;
    std::istringstream buffer;
    std::string punct;
    std::string GetLineNoPunct();
};

RemovePunctStream& RemovePunctStream::operator>> (std::string& word_out) {

    while (!(buffer >> word_out)) {     // Output here 

        if (!ist.good()) break;        // No more characters left to extract 

        buffer.clear();

        std::string line = GetLineNoPunct();

        buffer.str(line);     // Write line 
    }
    return *this;     // The char * deferences the pointer, so a reference to the object itself is returned 
}

std::string RemovePunctStream::GetLineNoPunct () {

    std::string line;
    std::getline(ist, line);

    for (char& ch : line) {
        for (const char& ch_punct : punct) {
            if (ch == ch_punct) { ch = ' '; }
        }
    }
    return line;
}
    
RemovePunctStream::operator bool () {
    return ist.good();    // It makes more sense to be buffer.good() but that doesn't work
}

int main()
try
{
    std::cout << "Current path is " << std::filesystem::current_path() << '\n';
    std::ifstream ist {"../holmes.txt"};     // Still have not figured out how to change working dir of cmake
    if (!ist) { throw "Could not open the input text file."; }

    // Stream wrapper that outputs same text but without punctuation
    RemovePunctStream rmpunct (ist, ".,?'\"!():");     // Not sure how to deal with char " ' "

    std::vector<std::string> word_list;
    std::string word;
    std::unordered_map<std::string, int> counts;

    while (rmpunct >> word) {
        if (word.length()>4){    // Only long words 
            for (auto &c : word) {c = tolower(c);}    // Case insensitive
            word_list.push_back(word);
            if (!(counts[word]+=1)) {counts[word] = 1;}    // Count
        }
    }
    // Pass map into vector to use sort() method next
    std::vector<std::pair<std::string, int>> mapcopy(counts.begin(), counts.end());

    // Sort by number of ocurrences
    std::sort(mapcopy.begin(), mapcopy.end(), [](auto& left, auto& right){return left.second > right.second;});

    // Write results to a file 
    std::ofstream out {"./word_counts_out.txt"};
    if (!out) { throw "Could not write to the file specified."; }

    for (auto &pair : mapcopy) out << pair.first << " : " << pair.second << "\n";
}
catch (char const* s)
{
    std::cout << s << '\n';
}
