#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>

//Define namespace variables
using namespace std;

bool doesFileExist(string &);
string getFileName();
void readWords(vector<string> *, ifstream &);
void findOccurencesofWords(vector<string>, vector< vector<string> > *);
bool notDelim(char);
bool sortingWords(const vector<string>&, const vector<string>&);

/**
 * Skeleton main routine
 */

int main(int, char **)
{
    //Get the file name from the user via command line
    string fileName = getFileName();

    //Load the ascii file
    vector<string> fileStrings;
    vector< vector<string> > uniqueWords;

    ifstream fs;
    fs.open(fileName.c_str());
    //Read the file words and get each unique word in
    readWords(&fileStrings, fs);

    fs.close();


    //Make sure that the unique words vector is in the correct order
    findOccurencesofWords(fileStrings, &uniqueWords);

    //Print out the file containing the unique words and the number of uses in descending order
    cout << "Word\t\tUsage" << endl;
    cout << endl;
    
    //Sort the lists based on the number of times it is present
    sort(uniqueWords.begin(), uniqueWords.end(), sortingWords);


    for(auto i = 0u; i<uniqueWords.size(); i++){
        vector<string> currentWord = uniqueWords.front();
        uniqueWords.at(i);
        cout << currentWord.front() << "\t\t" << currentWord.back() << endl;
    }
}

//Get the file name a)nd check whether or not the file exists etc.
string getFileName(){
    string fileName;
    do{
        fileName = "";
        cout << "Give the  file name" << endl;
        cin >> fileName;
    } while (!doesFileExist(fileName));
    return fileName;
}

//Return true if the file exists else false
bool doesFileExist(string &fileName){
    std::ifstream infile(fileName.c_str());
    if(!infile.good()){
        cout << "File could not be found!" << endl;
    }
    return infile.good();
}

void readWords(vector<string> *words, ifstream &fs){
    //Create the stream buffer for content into a string.
    string contents((istreambuf_iterator<char>(fs)), istreambuf_iterator<char>());

    //Create the word utilising the buffer iterators
    string tempWord;
    for(auto i = 0u; i<contents.length(); i++){
        if(notDelim(contents[i])){
            tempWord+=contents[i];
        } else if(tempWord != "" && tempWord.length() >= 4){
            //Make sure word is all upper case
            transform(tempWord.begin(), tempWord.end(), tempWord.begin(), ::toupper);

            words->push_back(tempWord);
            tempWord = "";
        } else{
            tempWord = "";
        }
    }
}

//If the charecter is one of the delimeters return false
bool notDelim(char c){
    switch(c){
        case '.': return false;
        case ' ': return false;
        case ',': return false;
        case '?': return false;
        case '\'': return false;
        case '\\': return false;
        case '"': return false;
        case '!': return false;
        case '(': return false;
        case ')': return false;
        case ':': return false;
        case '\n': return false;
        case '\r': return false;
        case '-': return false;
        default:
            return true;
            break;
    }
}

void findOccurencesofWords(vector<string> words, vector< vector<string> > *uniqueWords){
    string currentWord = "";
    string lastWord = "";
    bool inSet = false;
    bool alreadyThere = false;
    int currentTally = 0;
    //Make sure that the vector is sorted
    sort(words.begin(), words.end());

    for(auto i = 0u; i<words.size(); i++){
        currentWord = words.at(i);
        //If new word is same as last word then then check if new set
        if(currentWord == lastWord){
            if(inSet){
                //Is in a set already and thus we are adding to the tally
                currentTally++;
            }else{
                //Isn't already in a set and so we are creating a new set for the vector of lists of strings
                inSet = true;
                currentTally++;
            }
        } else {
            //Check whether or not the set has ended
            if(inSet && !alreadyThere){
                //Add new set to the vector of lists and reset values
                vector<string> newSet;
                newSet.push_back(lastWord);
                newSet.push_back(to_string(currentTally));
                currentTally = 0;
                uniqueWords->push_back(newSet);
                alreadyThere = true;
            }else{
                //It's just a new wordset so is it really a problem???
                alreadyThere = false;
                currentTally++;
            }
        }
        lastWord = currentWord;
    }
}

bool sortingWords (const vector<string> &a, const vector<string> &b){
    return a[1] > b[1];
}