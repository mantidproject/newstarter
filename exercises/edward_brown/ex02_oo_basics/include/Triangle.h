#ifndef EX2_RECTANGLE
#define EX2_RECTANGLE
#include "Shape.h"
class Triangle : public Shape {
  public:
    Triangle(double Base, double Height);
    std::string getShapeName() const override;
    int getSideCount() const override;
    double getPerimeter() const override;
    double getArea() const override;
  private:
    void printAttributes(std::ostream& OutputStream) const override;
    double getHeight() const;
    double getBase() const;
    double m_Base;
    double m_Height;
};
#endif // EX2_RECTANGLE
