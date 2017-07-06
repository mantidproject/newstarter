#include "FileHelpers.h"
#include "MakeWordFrequencyMap.h"
#include "WordFrequencyTable.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

bool hasRequiredCommandLineArguments(int argc) {
  auto constexpr MINIMUM_COMMAND_LINE_ARGUMENTS = 1;
  return MINIMUM_COMMAND_LINE_ARGUMENTS;
}

int main(int argc, char **argv) {
  if (hasRequiredCommandLineArguments(argc)) {
    try {
      auto const InputFileName = std::string(argv[0]);
      auto InputFileStream = openInputFile(InputFileName);
      auto OutputFileStream = openOutputFile();
      auto const InputString = fileToString(InputFileStream);

      auto WordFrequencyMap = makeWordFrequencyMap(InputString.cbegin(), InputString.cend());
      auto WordFrequencyTable = makeOrderedWordFrequencyTable(
          WordFrequencyMap.cbegin(), WordFrequencyMap.cend());
      std::cout << InputString << std::endl;

    } catch (std::runtime_error const &ex) {
      std::cout << ex.what() << std::endl;
    }
  }
}
