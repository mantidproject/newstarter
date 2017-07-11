#include "Shape.h"
#include <ostream>
/** Prints the shape ToPrint to OutputStream.
 *
 *  Shapes are printed in the following format:
 *  <ShapeName>(<AttributeName1>: <AttributeValue1>[, <AttributeNameN>:
 * <AttributeValueN> ...]);
 *
 *  @param OutputStream The output stream to print to.
 *  @param ToPrint The shape to print.
 */
std::ostream &operator<<(std::ostream &OutputStream, Shape const &ToPrint) {
  OutputStream << ToPrint.getShapeType() << '(';
  ToPrint.printAttributes(OutputStream);
  OutputStream << ')';
  return OutputStream;
}
