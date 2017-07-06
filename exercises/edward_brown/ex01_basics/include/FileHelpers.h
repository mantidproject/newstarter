#include <fstream>
#include <string>
std::ifstream openInputFile(std::string const &Filename);
std::ofstream openOutputFile(); 
std::string fileToString(std::ifstream const &File);
