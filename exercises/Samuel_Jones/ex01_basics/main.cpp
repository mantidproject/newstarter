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
void findOccurencesofWords(vector<string>, vector< pair<string,int> > *);
bool notDelim(char);
bool sortingWords(const pair<string,int>&, const pair<string,int>&);

/**
 * Skeleton main routine
 */

int main(int, char **)
{
    //Get the file name from the user via command line
    string fileName = getFileName();

    //Load the ascii file
    vector<string> fileStrings;
    vector< pair<string, int> > uniqueWords;

    ifstream fs;
    fs.open(fileName.c_str());
    //Read the file words and get each unique word in
    readWords(&fileStrings, fs);

    fs.close();

    //Make sure that the unique words vector is in the correct order
    findOccurencesofWords(fileStrings, &uniqueWords);
    
    //Sort the lists based on the number of times it is present
    sort(uniqueWords.begin(), uniqueWords.end(), sortingWords);

    //print out to file named results, could request filename using getFileName() but not required.
    ofstream results;
    results.open("results.txt");
    results << "Word\t\tUsage" << endl;
    results << endl;
    for(auto i = 0u; i<uniqueWords.size(); i++){
        pair<string,int> currentWord = uniqueWords.at(i);
        results << currentWord.first << "\t\t" << currentWord.second << endl;
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
            //Make sure word is all lower case
            transform(tempWord.begin(), tempWord.end(), tempWord.begin(), ::tolower);

            words->push_back(tempWord);
            tempWord = "";
        } else{
            tempWord = "";
        }
    }
    //Catch the final word and add it to the list as it will be forgotten.
    words->push_back(tempWord);
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

void findOccurencesofWords(vector<string> words, vector< pair<string, int> > *uniqueWords){
    string currentWord = "";
    string lastWord;
    bool inSet = false;
    int currentTally = 1;
    //Make sure that the vector is sorted
    sort(words.begin(), words.end());

    for(auto i = 0u; i<words.size(); i++){
        lastWord = currentWord;
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
            //There is an issue whether it will accept null charecters and I am filtering them out, at submission
            //This reduces the load on checking all of the passed words.
            if(lastWord == ""){
                continue;
            }
            //Check whether or not the set has ended
            pair<string, int> newSet;
            newSet.first = lastWord;
            newSet.second = currentTally;
            currentTally = 1;
            uniqueWords->push_back(newSet);
        }
    }
    //Catch the last one and put it into a pair.
    pair<string, int> newSet;
    newSet.first = lastWord;
    newSet.second = currentTally;
    uniqueWords->push_back(newSet);
}

bool sortingWords (const pair<string,int> &a, const pair<string,int> &b){
    return a.second > b.second;
}