#ifndef EX2_SHAPE
#define EX2_SHAPE
#include "ShapeType.h"
#include <string>
class Shape {
  friend std::ostream &operator<<(std::ostream &OutputStream,
                                  Shape const &ToPrint);

public:
  virtual ShapeType getShapeType() const = 0;
  virtual int getSideCount() const = 0;
  virtual double getPerimeter() const = 0;
  virtual double getArea() const = 0;
  virtual ~Shape() = default;

private:
  /** Prints the names and values of the attributes of this shape.
   * Properties are printed in the following format.
   * <AttributeName1>: <AttributeValue1>[, <AttributeNameN>: <AttributeValueN>
   * ...]
   */
  virtual void printAttributes(std::ostream &OutputStream) const = 0;
};
#endif // EX2_SHAPE
