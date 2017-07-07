#include "FileHelpers.h"
#include <cassert>
#include <sstream>
#include <stdexcept>

void openInputFile(std::string const &Filename, std::ifstream& InputFileStream) {
  InputFileStream.open(Filename);
  if (!InputFileStream.good()) {
    throw std::runtime_error(
        "Input file does not exist or has incorrect permisssions.");
  }
}

void openOutputFile(std::ofstream& OutputFileStream) {
  OutputFileStream.open("results.txt", std::ofstream::out);
  if (!OutputFileStream.good()) {
    throw std::runtime_error(
        "Failed to create an output file, check directory permissions.");
  }
}

std::string fileToString(std::ifstream const &FileStream) {
  assert(FileStream.good() &&
         "File must be open/good when it is passed to fileToString");
  std::stringstream FileContentsStream;
  FileContentsStream << FileStream.rdbuf();
  return FileContentsStream.str();
}
