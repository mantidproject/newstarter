#include "FileHelpers.h"
#include <cassert>
#include <sstream>
#include <stdexcept>

std::ifstream openInputFile(std::string const &Filename) {
  auto InputFile = std::ifstream(Filename);
  if (InputFile.good()) {
    return std::move(InputFile);
  } else {
    throw std::runtime_error(
        "Input file does not exist or has incorrect permisssions.");
  }
}

std::ofstream openOutputFile() {
  auto OutputFile = std::ofstream("results.txt", std::ofstream::out);
  if (OutputFile.good()) {
    return std::move(OutputFile);
  } else {
    throw std::runtime_error(
        "Failed to create an output file, check directory permissions.");
  }
}

std::string fileToString(std::ifstream const &File) {
  assert(File.good() &&
         "File must be open/good when it is passed to fileToString");
  auto FileStream = std::stringstream();
  FileStream << File.rdbuf();
  return FileStream.str();
}
