/**
 * Skeleton main routine
 */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const std::string inputFilePath = argv[1];

    std::ifstream openFile(inputFilePath);

    // check the file for errors
    if(!openFile.good()) {
        std::cout << "Error: Unable to open the path of the input file." << inputFilePath << std::endl;
        return 1;
    }
}