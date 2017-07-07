#include "FileHelpers.h"
#include "MakeWordFrequencyMap.h"
#include "WordFrequencyTable.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

bool hasRequiredCommandLineArguments(int ArgumentCount) {
  auto constexpr MinimumCommandLineArguments = 1;
  return MinimumCommandLineArguments <= ArgumentCount;
}

void indicateSuccess() {
  std::cout << "Successfully wrote word frequencies to results.txt."
            << std::endl;
}

void noInputFiles() { std::cerr << "No input file specified." << std::endl; }

int main(int argc, char **argv) {
  if (hasRequiredCommandLineArguments(argc)) {
    try {
      auto const InputFileName = std::string(argv[1]);
      std::ifstream InputFileStream;
      openInputFile(InputFileName, InputFileStream);
      std::ofstream OutputFileStream;
      openOutputFile(OutputFile);
      auto const InputString = fileToString(InputFileStream);

      auto WordFrequencyMap =
          makeWordFrequencyMap(InputString.cbegin(), InputString.cend());
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
