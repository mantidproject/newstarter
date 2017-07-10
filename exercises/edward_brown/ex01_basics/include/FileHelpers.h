#ifndef EX1_FILE_HELPERS
#define EX1_FILE_HELPERS
#include <fstream>
#include <string>

std::string readInputFile(std::string const &Filename);
void openOutputFile(std::ofstream &OutputFileStream);
std::string fileToString(std::ifstream const &File);
#endif // EX1_FILE_HELPERS
