#ifndef EX1_FILE_HELPERS
#define EX1_FILE_HELPERS
#include <fstream>
#include <string>

void openInputFile(std::string const &Filename, std::ifstream& InputFileStream);
void openOutputFile(std::ofstream &OutputFileStream);
std::string fileToString(std::ifstream const &File);
#endif // EX1_FILE_HELPERS
