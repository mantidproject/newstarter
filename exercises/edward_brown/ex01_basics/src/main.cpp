#include "FileHelpers.h"
#include "MakeWordFrequencyMap.h"
#include "WordFrequencyTable.h"
#include <cassert>
#include <iostream>

/** Ensures the existance of at least one command line argument to be used as
 * the input
 *  file name.
 *  @param ArgumentCount The value of the argc parameter passed to main.
 *  @return True if the minimum number of arguments or greater are present.
 */
bool hasRequiredCommandLineArguments(int ArgumentCount) {
  auto constexpr MINIMUM_COMMAND_LINE_ARGUMENTS = 2;
  return MINIMUM_COMMAND_LINE_ARGUMENTS <= ArgumentCount;
}

/// Indicates to the user that the output has been created and written
/// successfully.
void indicateSuccess() {
  std::cout << "Successfully wrote word frequencies to results.txt."
            << std::endl;
}

/// Indicates to the user that no input files were provided.
void noInputFiles() { std::cerr << "No input file specified." << std::endl; }

int main(int argc, char **argv) {
  if (hasRequiredCommandLineArguments(argc)) {
    try {
      auto const InputFileName = std::string(argv[1]);
      std::ifstream InputFileStream;
      openInputFile(InputFileName, InputFileStream);
      std::ofstream OutputFileStream;
      openOutputFile(OutputFileStream);

      using FileIterator = std::istreambuf_iterator<char>;
      auto Begin = FileIterator(InputFileStream), End = FileIterator();
      auto WordFrequencyMap = makeWordFrequencyMap(Begin, End);
      auto WordFrequencyTable = makeOrderedWordFrequencyTable(
          WordFrequencyMap.cbegin(), WordFrequencyMap.cend());
      OutputFileStream << WordFrequencyTable << std::endl;
      indicateSuccess();
    } catch (std::runtime_error &Error) {
      std::cerr << Error.what() << std::endl;
    }
  } else {
    noInputFiles();
  }
}
