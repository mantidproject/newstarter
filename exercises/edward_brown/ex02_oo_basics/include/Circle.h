#ifndef EX2_CIRCLE
#define EX2_CIRCLE
#include "Shape.h"
class Circle : public Shape {
  public:
    Circle(double Radius);
    std::string getShapeName() const override;
    int getSideCount() const override;
    double getPerimeter() const override;
    double getArea() const override;
    static constexpr double PI = 3.14159265359;
    ~Circle(){}
  private:
    void printAttributes(std::ostream& OutputStream) const override;
    double getDiameter() const;
    double getRadius() const;
    double m_Radius;
};
#endif // EX2_CIRCLE
