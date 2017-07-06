#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>

std::ifstream openInputFile(std::string const &filename) {
  auto InputFile = std::ifstream(filename);
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

std::string fileToString(std::ifstream& file) {
  auto FileStream = std::stringstream();
  FileStream << file.rdbuf();
  return FileStream.str();
}

int main(int argc, char **argv) {
  if (argc > 1) {
    try {
      auto const InputFileName = std::string(argv[0]);
      auto InputFileStream = openInputFile(InputFileName);
      auto OutputFileStream = openOutputFile();
    } catch (std::runtime_error const &ex) {
      std::cout << ex.what() << std::endl;
    }
  }
}
