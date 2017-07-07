#ifndef EX2_SHAPE
#define EX2_SHAPE
#include <ostream>
#include <string>
class Shape {
  friend std::ostream& operator<<(std::ostream& OutputStream, Shape const& ToPrint);
  public:
    virtual std::string getShapeName() const = 0;
    virtual int getSideCount() const = 0;
    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
  private:
    virtual void printAttributes(std::ostream& OutputStream) const = 0;
};
#endif // EX2_SHAPE
