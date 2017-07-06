#include "FileHelpers.h"
#include <cassert>
#include <sstream>
#include <stdexcept>

std::ifstream openInputFile(std::string const &Filename) {
  auto InputFile = std::ifstream(Filename);
  if (InputFile.is_open()) {
    return std::move(InputFile);
  } else {
    throw std::runtime_error(
        "Input file does not exist or has incorect permisssions.");
  }
}

std::ofstream openOutputFile() {
  auto OutputFile = std::ofstream("results.txt", std::ofstream::out);
  if (OutputFile.is_open()) {
    return std::move(OutputFile);
  } else {
    throw std::runtime_error(
        "Failed to create an output file, check directory permissions.");
  }
}

std::string fileToString(std::ifstream const &File) {
  assert(File.is_open() &&
         "File must be open when it is passed to fileToString");
  auto FileStream = std::stringstream();
  FileStream << File.rdbuf();
  return FileStream.str();
}
