#ifndef EX2_RECTANGLE
#define EX2_RECTANGLE
#include "Shape.h"
class Rectangle : public Shape {
  public:
    Rectangle(double Width, double Height);
    std::string getShapeName() const override;
    int getSideCount() const override;
    double getPerimeter() const override;
    double getArea() const override;
  private:
    void printAttributes(std::ostream& OutputStream) const override;
    double getHeight() const;
    double getWidth() const;
    double m_Width;
    double m_Height;
};
#endif // EX2_RECTANGLE
