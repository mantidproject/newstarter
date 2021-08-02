#include <iostream>
#include <fstream>
#include <string>

int main(std::string fileName)
{
    std::string inLine;
    std::ifstream inFile(fileName);

    while (getline(inFile,inLine))
    {
        std::cout << inLine;
    }
    inFile.close();
}