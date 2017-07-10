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
    Shape(const std::string& name, const int &s);

    ///Virtual destructor

    ///Prints the Shape's Type, followed by its measurements
    void printShape();

    ///Returns the Shape's Type
    std::string getType() const;

    ///Returns the number of sides of the shape
    int getSides() const;

    ///Returns the Shape's Area.
    virtual double getArea() const {return 0;}

    ///Returns the Shape's Perimeter
    virtual double getPerim() const {return 0;}

protected:
    ///Saves the Shape's dimensions
    void setDim(std::map<std::string, double>& dim);

    ///Sets the shape's type
    void setType(const std::string &name);

private:
    //e.g. type = "square"
    std::string type;

    //e.g. numSides = 4
    const int numSides;

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

    ///Returns Rectangle's Area
    double getArea() const;

    ///Returns Rectangle's Perimeter
    double getPerim() const;

private:
        double width, height;
};



//Square class
class Square: public Rectangle
{
public:
    //Constructor: sets side length
    Square(double w);
};



//Triangle class
class Triangle: public Shape
{
public:
    ///Constructor: sets base and hieght
    Triangle(double b, double h);

    ///Returns Triangle's Area
    double getArea() const;

    ///Returns Triangle's Perimeter
    double getPerim() const;
private:
    double base, height;
};



//Circle class
class Circle: public Shape
{
public:
    ///Constructor: sets radius length
    Circle(double r);

    ///Returns Circle's Area
    double getArea() const;

    ///Returns Circle's Perimeter
    double getPerim() const;
private:
    double radius;
};

#endif // SHAPES_H_
