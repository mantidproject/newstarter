#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

const static double PI = 2 * std::atan(1.0);

class ShapeBase
{
 public:
    virtual ~ShapeBase() {}
    virtual double area() const = 0;
    virtual ShapeBase* clone() const = 0;
    virtual double perimeter() const = 0;
    void print() const;
    unsigned sides() const { return pSides; }
    virtual std::string type() const = 0;
 protected:
    ShapeBase(unsigned sides) : pSides(sides) {}
 private:
    unsigned pSides;
};

void ShapeBase::print() const
{
    std::cout << type() << ": area = " << area() << " perimeter = " << perimeter() << std::endl;
}

class Circle : public ShapeBase
{
 public:
    Circle(double radius);
    double area() const;
    ShapeBase* clone() const;
    double perimeter() const;
    std::string type() const { return "Circle"; }
 private:
    double pRadius;
};

Circle::Circle(double radius) : ShapeBase(0), pRadius(radius)
{

}

double Circle::area() const
{
    return PI * pRadius * pRadius;
}

ShapeBase* Circle::clone() const
{
    return new Circle(pRadius);
}

double Circle::perimeter() const
{
    return 2 * PI * pRadius;
}

class Rectangle : public ShapeBase
{
 public:
    Rectangle(double width, double height);
    double area() const;
    ShapeBase* clone() const;
    double perimeter() const;
    std::string type() const { return "Rectangle"; }
 private:
    double pWidth;
    double pHeight;
};

Rectangle::Rectangle(double width, double height) : ShapeBase(4), pWidth(width), pHeight(height)
{

}

double Rectangle::area() const
{
    return pWidth * pHeight;
}

ShapeBase* Rectangle::clone() const
{
    return new Rectangle(pWidth, pHeight);
}

double Rectangle::perimeter() const
{
    return 2 * pWidth + 2 * pHeight;
}

class Square : public ShapeBase
{
 public:
    Square(double side) : ShapeBase(4), pSide(side) {}
    double area() const;
    ShapeBase* clone() const;
    double perimeter() const;
    std::string type() const { return "Square"; }
 private:
    double pSide;
};

double Square::area() const
{
    return pSide * pSide;
}

ShapeBase* Square::clone() const
{
    return new Square(pSide);
}

double Square::perimeter() const
{
    return 4 * pSide;
}

class Triangle : public ShapeBase
{
 public:
    Triangle(double height, double base);
    double area() const;
    ShapeBase* clone() const;
    double perimeter() const;
    std::string type() const { return "Triangle"; }
 private:
    double pBase;
    double pHeight;
};

Triangle::Triangle(double height, double base) : ShapeBase(3), pBase(base), pHeight(height)
{

}

double Triangle::area() const
{
    return 0.5 * pBase * pHeight;
}

ShapeBase* Triangle::clone() const
{
    return new Triangle(pHeight, pBase);
}

double Triangle::perimeter() const
{
    return pBase + 2 * std::sqrt(pHeight * pHeight + 0.25 * pBase * pBase);
}

class Shape
{
 public:
    explicit Shape(const ShapeBase* shape);
    Shape(const Shape& shape);
    ~Shape() { delete pShape; }
    double area() const { return pShape->area(); }
    Shape& operator=(const Shape& rhs);
    void print() const { pShape->print(); }
    double perimeter() const { return pShape->perimeter(); }
    unsigned sides() const { return pShape->sides(); }
    std::string type() const { return pShape->type(); }
 private:
    const ShapeBase *pShape;
};

Shape::Shape(const ShapeBase* shape) : pShape(shape)
{
    if(!shape) throw std::runtime_error("uninitialized shape");
}

Shape::Shape(const Shape& shape)
{
    pShape = shape.pShape->clone();
}

Shape& Shape::operator=(const Shape& rhs)
{
    if(this != &rhs) {
        pShape = rhs.pShape->clone();
    }
    return *this;
}

class ShapeSorter
{
 public:
    ShapeSorter(const std::vector<Shape>& shapes) : pShapes(shapes) {}
    void printBySides(unsigned sides) const;
    void printBySortedAreas() const;
    void printBySortedPerimeters() const;
    void printByType(const std::string type) const;
 private:
    std::vector<Shape> pShapes;
};

void ShapeSorter::printBySides(unsigned sides) const
{
    std::vector<Shape>::const_iterator iter = pShapes.begin();
    for( ; iter != pShapes.end(); ++iter) {
        if(iter->sides() == sides) iter->print();
    }
}

bool areaComp(const Shape& lhs, const Shape& rhs)
{
    return lhs.area() > rhs.area();
}

void ShapeSorter::printBySortedAreas() const
{
    std::vector<Shape> shapes(pShapes);
    std::sort(shapes.begin(), shapes.end(), areaComp);
    std::vector<Shape>::const_iterator iter = shapes.begin();
    for( ; iter != shapes.end(); ++iter) iter->print();
}

bool perimeterComp(const Shape& lhs, const Shape& rhs)
{
    return lhs.perimeter() > rhs.perimeter();
}

void ShapeSorter::printBySortedPerimeters() const
{
    std::vector<Shape> shapes(pShapes);
    std::sort(shapes.begin(), shapes.end(), perimeterComp);
    std::vector<Shape>::const_iterator iter = shapes.begin();
    for( ; iter != shapes.end(); ++iter) iter->print();
}

void ShapeSorter::printByType(const std::string type) const
{
    std::vector<Shape>::const_iterator iter = pShapes.begin();
    for( ; iter != pShapes.end(); ++iter) {
        if(iter->type() == type) iter->print();
    }
}

int main(int, char **)
{
    std::vector<Shape> shapes;
    shapes.push_back(Shape(new Triangle(4.6, 99)));
    shapes.push_back(Shape(new Circle(666)));
    shapes.push_back(Shape(new Triangle(3, 3)));
    shapes.push_back(Shape(new Rectangle(1, 1)));
    shapes.push_back(Shape(new Square(1)));
    shapes.push_back(Shape(new Rectangle(8, 1)));
    ShapeSorter sorter(shapes);
    std::cout << "*** Sorted by areas ***" << std::endl;
    sorter.printBySortedAreas();
    std::cout << "*** Sorted by perimeters ***" << std::endl;
    sorter.printBySortedPerimeters();
    std::cout << "*** Triangles ***" << std::endl;
    sorter.printByType("Triangle");
    std::cout << "*** Panzerwagens ***" << std::endl;
    sorter.printByType("Panzerwagen");
    std::cout<< "*** Sides: 4 ***" << std::endl;
    sorter.printBySides(4);
}
