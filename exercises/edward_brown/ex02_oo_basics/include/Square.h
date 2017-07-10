#ifndef EX2_SQUARE
#define EX2_SQUARE
#include "Shape.h"
class Square : public Shape {
  public:
    Square(double SideLength);
    ShapeType getShapeType() const override;
    int getSideCount() const override;
    double getPerimeter() const override;
    double getArea() const override;
  private:
    void printAttributes(std::ostream& OutputStream) const override;
    double getSideLength() const;
    double m_SideLength;
};
#endif // EX2_SQUARE
