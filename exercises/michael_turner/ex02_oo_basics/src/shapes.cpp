#include "shapes.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>

//Constants - defines type names and number of sides
namespace {
    const std::string CIRCLE_NAME = "circle";
    const int CIRCLE_SIDES = 1;

    const std::string TRIANGLE_NAME = "triangle";
    const int TRIANGLE_SIDES = 3;

    const std::string RECTANGLE_NAME = "rectangle";
    const int RECTANGLE_SIDES = 4;

    const std::string SQUARE_NAME = "square";

    const double PI = 3.14159;
}

//Base Class
/**
 * @brief Shape::Shape  Constructor for the Shape class - sets type and number of sides
 * @param name      The type of the shape (i.e. subclass)
 * @param s         Number of Sides of the shape
 */
Shape::Shape(const std::string& name, const int& s): type(name), numSides(s) {}

/**
 * @brief Shape::setDim   Stores the measurements of the shape in 'dim': e.g. Circle: (radius, 5)
 * @param dim       Container for shape measurements
 */
void Shape::setDim(std::map<std::string, double>& dim){
    dimensions = dim;
}

/**
 * @brief Shape::setType  Allows the subclass to change its type
 * @param name          Subclass type
 */
void Shape::setType(const std::string& name){
    type = name;
}

/**
 * @brief Shape::printShape  Displays the Shape's type & measurements on a single line.
 */
void Shape::printShape(){
    std::cout <<std::left<< std::setw(COL_WIDTH) << getType();
    for (std::map<std::string, double>::iterator iter = dimensions.begin(); iter != dimensions.end(); ++iter){
        std::cout << std::right <<std::setw(COL_WIDTH)<< iter->first << ": " << std::left << std::setw(COL_WIDTH) << iter->second;
    }
    std::cout << std::endl;
}

/**
 * @brief Shape::getType        Gets the shape's type
 * @return      std::string
 */
std::string Shape::getType() const{
    return type;
}

/**
 * @brief Shape::getSides       Gets the number of sides of the shape
 * @return      int
 */
int Shape::getSides() const{
    return numSides;
}

//Rectangle Class
/**
 * @brief Rectangle::Rectangle      Constructor for the rectangle class.  Sets width and height
 *                                                    Sets dimensions variables
 * @param w     Width of Rectangle
 * @param h     Height of Rectangle
 */
Rectangle::Rectangle(double w, double h): Shape(RECTANGLE_NAME, RECTANGLE_SIDES), width(w), height(h){
    std::map<std::string, double> dim;
    dim.insert(std::pair<std::string, double>("width", width));
    dim.insert(std::pair<std::string, double>("height", height));

    //Saves measurements in 'dimensions'
    setDim(dim);
}

/**
 * @brief Rectangle::getArea        Returns the area of the rectangle
 * @return      double
 */
double Rectangle::getArea() const{
	return width * height;
}

/**
 * @brief Rectangle::getPerim       Returns the perimeter of the rectangle
 * @return      double
 */
double Rectangle::getPerim() const{
	return 2*(width+height);
}



//Square Class
/**
 * @brief Square::Square            Constructor for the square class.
 *                                                  Creates a special instance of the Rectangle class,
 * and sets width equal to height.  Renames the type to 'square'
 *
 * @param w         Side length
 */
Square::Square(double w): Rectangle(w, w){
    setType(SQUARE_NAME);
}



//Triangle Class
/**
 * @brief Triangle::Triangle        Constructor for the triangle class.  Sets base length and height.
 *                                                  Sets 'dimensions' variable.
 *                                                  Triangle is assumed to be isoceles.
 * @param b     Base lenght
 * @param h     Height
 */
Triangle::Triangle(double b, double h): Shape(TRIANGLE_NAME, TRIANGLE_SIDES), base(b), height(h){
    std::map<std::string, double> dim;
    dim.insert(std::pair<std::string, double>("base", base ));
    dim.insert(std::pair<std::string, double>("height", height));
    setDim(dim);
}

/**
 * @brief Triangle::getArea         Returns the area of the triangle
 * @return      double
 */
double Triangle::getArea() const{
	return (base * height) / 2;
}

/**
 * @brief Triangle::getPerim        Returns the perimeter of the triangle
 *                                                  Triangle assumed to be isoceles.
 * @return      double
 */
double Triangle::getPerim() const{
	return (base + 2 * std::sqrt( std::pow(height, 2) + pow(base, 2)/4 ));
}



//Circle Class
/**
 * @brief Circle::Circle        Constructor for the Circle class. Sets radius length
 *                                          Sets the 'dimensions' variable
 * @param r
 */
Circle::Circle(double r): Shape(CIRCLE_NAME, CIRCLE_SIDES), radius(r){
    std::map<std::string, double> dim;
    dim.insert(std::pair<std::string, double>("radius", radius));
    setDim(dim);
}

/**
 * @brief Circle::getArea      Returns the area of the circle
 * @return      double
 */
double Circle::getArea() const{
    return (PI * pow(radius, 2));
}

/**
 * @brief Circle::getPerim      Returns the perimeter of the circle
 * @return      double
 */
double Circle::getPerim() const{
    return (2*PI*radius);
}
