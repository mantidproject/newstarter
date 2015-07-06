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


    ifstream fileStream(file);
    if ( fileStream.is_open() ){
      while(fileStream.good())
      {
        string output;
        fileStream >> output;
        
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

/*
---------------------------------------------------------
previous codes
---------------------------------------------------------

int main()
{
	bool stop = false;
	int choice, index;
	string name, name2;
	int appearance;

	citiesdb db;
	db.load("database.txt");		//load cities from disk

	while(!stop){

		displayMenu();
		cin >> choice;		//read user choice

		switch(choice){


	std:: cout << "Please enter the file name: ";
	std:: string FileName;
	std:: cin >> FileName;

	std::string line;
	ifstream infile;
	infile.open (FileName);

	if(infile.fail()){
		//c errorrs
		cerr << "Error openning File......." << endl;
		std:: cin >> FileName; //delete later
		exit(1);
	}
	
	if(infile.is_open())
	{
		while( getline(FileName, line))
		{
			std::cout << line << '\n';
		}
		infile.close();
	}}
	}
}

	/*
	
	
	
	infile >> x >> y;

	getline(cin, x);
	cout << "Line 1: " << x << endl;
	cout << "Line 2: " << y << endl;

	std:: cin >> FileName; //delete later
	infile.close();
	-- * /
	return 0;
}

/*
int main () {

	std:: cout << "Please enter the file name: ";
	std:: string FileName;
	std:: cin >> FileName;

	string line;
	fstream infile;
	infile.open (FileName);

	if(infile.fail()){
		//c errorrs
		cerr << "Error openning File" << endl;
		std:: cin >> FileName; //delete later
		exit(1);
	}

	if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

	std:: cin >> FileName; //delete later
	infile.close();
	
	return 0;
}


	/*ofstream inFile;
	inFile.open("newFile.txt");
	
	if(inFile.fail()){
		cerr << "Error openning File" << endl;
		std:: cin >> FileName;
	//c errorrs 
		exit(1);
	}

	int x, y;
	
	inFile >> x >> y;

	cout << "Num 1: " << x << endl;
	cout << "Num 2: " << y << endl;


	return 0; 
}

/*
//void function
void openFile(string inFile)
{
	ifstream inFile;
	inFile.open(inFile);

	if (inFile.fail()){
		cerr << "Error openning File" << endl;
	//c errorrs 
		exit(1);
}
	
	/*
	string line;
	ifstream myfile ("textFile.txt");
	if(myfile.is_open())
	{
		while (getline (myfile,line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	std::string name;
	std:: cin >> name;
	return 0;
}

/*int addition (int a, int b)
//{
  //int r;
  r=a+b;
  return r;
}

----------------------------------------
 working output file:

	
int main () {

	std:: cout << "Please enter the file name: ";
	std:: string FileName;
	std:: cin >> FileName;

	ofstream infile;
	infile.open (FileName);
	infile << "Writing this to a file from shahroz. \n";
	infile.close();
	
	return 0;
}

void Keyword(ifstream & stream, string token) {
    string line;
    while (getline(stream, line)) {
        if (line.find(token) != string::npos) {
            cout << line << endl;
        }
    }
    cout << token << " not found" << endl;
}

*/