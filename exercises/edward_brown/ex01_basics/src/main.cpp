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

      auto const str = std::string{"Hello world, this is some text."};
      auto WordFrequencyMap = makeWordFrequencyMap(str.cbegin(), str.cend());
      auto WordFrequencyTable = makeOrderedWordFrequencyTable(
          WordFrequencyMap.cbegin(), WordFrequencyMap.cend());
      std::cout << WordFrequencyTable << std::endl;

    } catch (std::runtime_error const &ex) {
      std::cout << ex.what() << std::endl;
    }
  }
}
