/**
 * Skeleton main routine
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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

    // Saw the while section below on previous cpp book
    while (!(buffer >> word_out)) {

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
        buffer.str(line);
    }
    return *this;     // Don't really understand this yet, returns pointer to the object itself?
}
    
RemovePunctStream::operator bool () {
    return ist.good();    // It makes more sense to be buffer.good() but that doesn't work
}

int main()
{
    std::ifstream ist {"holmes.txt"};

    if (!ist) std::cout << "Could not open the file";

    // Stream wrapper that outputs same text but without punctuation
    RemovePunctStream rmpunct (ist, ".,?'!():");

    // Put all words into a list
    std::vector<std::string> word_list;
    while (rmpunct >> word) if (word.length()>4) word_list.push_back(word);

    // To be continued

}
