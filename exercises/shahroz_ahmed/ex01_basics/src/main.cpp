/**
 * Skeleton main routine
 */
#include<iomanip>
#include<algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

//print and save in another file
void printMap(map <string, unsigned int> map){
    std::map<std::string, unsigned int, std:: less<unsigned int> >:: iterator i;//less<int> should print in decending order?
    ofstream outfile;
    outfile.open ("outfile.txt");
    outfile << "Word      Usage \n" << endl;
    for (i = map.begin(); i != map.end(); i++ ){
        outfile << (*i).first  << "    " << (*i).second << endl;
    }
    outfile.close();
}


string upperToLower(string& input){
	
    unsigned i = 0;
    while( i < input.length()){
        input[i] = tolower( input[i]);
        
        if (ispunct(input[i])){
            input[i] = ' ';
        }
        ++i;
    }
    return input;
}



int main()
{
    std::map<std::string, unsigned int > mapData;
    
    std::cout << "Enter the file name: ";
    std:: string file;
	std:: cin >> file;


    ifstream myfile;

	myfile.open(file);
    if ( myfile.is_open() ){
      while(myfile.good())
      {
        string output;
        myfile >> output;
        
        string word;
        word = upperToLower(output);
        

        if(word.length() > 5){
            if(mapData.find(word) == mapData.end()){
                mapData[word] = 1;
            }
            else{
                mapData[word]++;
            }
        }
      }
    }
     else
         {
             cout << "Couldn't open the file. " << endl;
             return EXIT_FAILURE; }

    
    printMap(mapData);
    //return EXIT_SUCCESS;

    system("PAUSE");
    
    return 0;
    
}
