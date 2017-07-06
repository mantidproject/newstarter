#include "FileHelpers.h"
#include "MakeWordFrequencyMap.h"
#include "WordFrequencyTable.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

bool hasRequiredCommandLineArguments(int argc) {
  auto constexpr MinimumCommandLineArguments = 2;
  return argc < MinimumCommandLineArguments;
}

int main(int argc, char **argv) {
  if (hasRequiredCommandLineArguments(argc)) {
    try {
      auto const InputFileName = std::string(argv[1]);
      auto InputFileStream = openInputFile(InputFileName);
      auto OutputFileStream = openOutputFile();
      auto const InputString = fileToString(InputFileStream);

      auto WordFrequencyMap = makeWordFrequencyMap(InputString.cbegin(), InputString.cend());
      auto WordFrequencyTable = makeOrderedWordFrequencyTable(
          WordFrequencyMap.cbegin(), WordFrequencyMap.cend());

      std::cout << WordFrequencyTable << std::endl;

    } catch (std::runtime_error const &Error) {
      std::cout << Error.what() << std::endl;
    }
  }
}
