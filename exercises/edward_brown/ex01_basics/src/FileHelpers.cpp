#include "FileHelpers.h"
#include <stdexcept>
#include <sstream>

std::ifstream openInputFile(std::string const &Filename) {
  auto InputFile = std::ifstream(Filename);
  if (InputFile.is_open()) {
    return InputFile;
  } else {
    throw std::runtime_error(
        "Input file does not exist or has incorect permisssions.");
  }
}

std::ofstream openOutputFile() {
  auto OutputFile = std::ofstream("results.txt", std::ofstream::out);
  if (OutputFile.is_open()) {
    return OutputFile;
  } else {
    throw std::runtime_error(
        "Failed to create an output file, check directory permissions.");
  }
}

std::string fileToString(std::ifstream const &File) {
  auto FileStream = std::stringstream();
  FileStream << File.rdbuf();
  return FileStream.str();
}
