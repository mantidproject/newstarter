#include "Shape.h"

std::ostream& operator<<(std::ostream& OutputStream, Shape const& ToPrint) {
  OutputStream << ToPrint.getShapeName() << '(';
  ToPrint.printAttributes(OutputStream);
  OutputStream << ')';
  return OutputStream;
}
