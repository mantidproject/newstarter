#include "FileHelpers.h"
#include <cassert>
#include <sstream>
#include <stdexcept>

/** Opens the file with the specified path on the InputFileStream object.
 *  @param Filename The name or path of the input file.
 *  @param InputFile The target ifstream.
 *  @throws std::runtime_eror When the file cannot be opened.
 */
std::string readInputFile(std::string const &Filename) {
  std::ifstream InputFileStream(Filename);
  if (InputFileStream.good()) {
    return fileToString(InputFileStream);
  } else {
    throw std::runtime_error(
        "Input file does not exist or has incorrect permisssions.");
  }
}

/** Opens the results.txt output file on the target ofstream
 *  overriting it if one exists already,
 *  @param OutputFileStream The target ofstream.
 *  @throws std::runtime_error When the file cannot be created.
 */
void openOutputFile(std::ofstream &OutputFileStream) {
  OutputFileStream.open("results.txt", std::ofstream::out);
  if (!OutputFileStream.good()) {
    throw std::runtime_error(
        "Failed to create an output file, check directory permissions.");
  }
}

/** Converts the content of the stream to a string.
 *  @pre The stream is open and in an error free state.
 */
std::string fileToString(std::ifstream const &FileStream) {
  assert(FileStream.good() &&
         "File must be open/good when it is passed to fileToString");
  std::stringstream FileContentsStream;
  FileContentsStream << FileStream.rdbuf();
  return FileContentsStream.str();
}
