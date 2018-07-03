#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <list>

//Define namespace variables
using namespace std;

bool doesFileExist(const char*);
string getFileName();
void readUniqueWords(list<string> *, ifstream &);

/**
 * Skeleton main routine
 */

int main(int, char **)
{
    //Get the file name from the user via command line
    string fileName = getFileName();

    //Load the ascii file
    list<string> fileStrings;
    list<string[2]> uniqueWords;

    ifstream fs;
    fs.open(fileName.c_str());

    cout << "File Open" << endl;

    //Read the file words and get each unique word in
    readUniqueWords(&fileStrings, fs);

    fs.close();


    //Make sure that the unique words list is in the correct order

    //Print out the file containing the unique words and the number of uses in descending order
    //cout << "Word     Usage" << endl;
    //cout << endl;
    //cout << word1 << "\t\t" << word2 << endl;

}

//Get the file name and check whether or not the file exists etc.
string getFileName(){
    string fileName;
    do{
        fileName = "";
        cout << "Give the  file name" << endl;
        cin >> fileName;
        fileName = "../" + fileName;
    } while (!doesFileExist);
    return fileName;
}

//Return true if the file exists else false
bool doesFileExist(const char *fileName){
    std::ifstream infile(fileName);
    if(!infile.good()){
        cout << "File could not be found!" << endl;
    }
    return infile.good();
}

void readUniqueWords(list<string> *words, ifstream &fs){
    std::vector<std::string> wordss;
    //Reading all words
    char textBuffer[120];
    do{
        char* word;
        word=strtok(textBuffer, ".,?'\"!():- ");
        cout << word << endl;
        //Do this while the line is still a thing/have not reached end of the code
        while (word != NULL){
            words->push_back(word);
            word = strtok(NULL, ".,?'\"!():");

            //todo Remove before push
            cout << word << " " << words->size();
        }
    }while(!fs.eof());

    //Sort the words
    words->sort();
}
