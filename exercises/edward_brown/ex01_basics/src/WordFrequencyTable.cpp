#include "WordFrequencyTable.h"
#include <iomanip>
#include <ostream>

std::ostream &operator<<(std::ostream &OutputStream,
                         WordFrequencyTable const &Table) {
  for (auto &&WordFrequency : Table) {
    OutputStream << WordFrequency << '\n';
  }
  return OutputStream;
}

std::ostream &operator<<(std::ostream &OutputStream,
                         WordFrequencyPair const &Row) {
  OutputStream << std::left << std::setfill(' ') << std::setw(17) << Row.first;
  OutputStream << std::right << std::setfill(' ') << std::setw(5) << Row.second;
  return OutputStream;
}
