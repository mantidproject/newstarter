#ifndef SHAPES_H_
#define SHAPES_H_

#include <string>
#include <map>

//Column width - for printing data in columns
static const int COL_WIDTH = 15;

//Base class
class Shape
{
public:
    ///Constructor: sets the type and number of sides
    Shape();

    ///Virtual destructor
    virtual ~Shape() = default;

    ///Prints the Shape's Type, followed by its measurements
    void printShape();

    ///Returns the Shape's Type
    virtual std::string getType() const = 0;

    ///Returns the number of sides of the shape
    virtual int getSides() const = 0;

    ///Returns the Shape's Area.
    virtual double getArea() const = 0;

    ///Returns the Shape's Perimeter
    virtual double getPerim() const = 0;

protected:
    ///Holds the Shape's dimensions
    /// e.g Triangle: (base, 5), (height, 3)
    std::map<std::string, double> dimensions;
};



//Rectangle class
class Rectangle: public Shape
{
public:
    ///Constructor: sets width & height
    Rectangle(double w, double h);

    ///Returns Rectangle's Type
    std::string getType() const override;

    ///Returns number of sides of Rectangle
    int getSides() const override;

    ///Returns Rectangle's Area
    double getArea() const override;

    ///Returns Rectangle's Perimeter
    double getPerim() const override;

private:
        double width, height;
};



//Square class
class Square: public Rectangle
{
public:
    //Constructor: sets side length
    Square(double w);

    std::string getType() const override;
};



//Triangle class
class Triangle: public Shape
{
public:
    ///Constructor: sets base and height
    Triangle(double b, double h);

    ///Returns Triangle's Type
    std::string getType() const override;

    ///Returns number of sides of Triangle
    int getSides() const override;

    ///Returns Triangle's Area
    double getArea() const override;

    ///Returns Triangle's Perimeter
    double getPerim() const override;
private:
    double base, height;
};



//Circle class
class Circle: public Shape
{
public:
    ///Constructor: sets radius length
    Circle(double r);

    ///Returns Circle's Type
    std::string getType() const override;

    ///Returns number of sides of Circle
    int getSides() const override;

    ///Returns Circle's Area
    double getArea() const override;

    ///Returns Circle's Perimeter
    double getPerim() const override;
private:
    double radius;
    static constexpr double PI = 3.14159;
};

#endif // SHAPES_H_
