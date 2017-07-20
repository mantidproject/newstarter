#include "shapes.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>

//Base Class
/**
 * @brief Shape::Shape  Constructor for the Shape class - sets type and number of sides
 * @param name      The type of the shape (i.e. subclass)
 * @param s         Number of Sides of the shape
 */
Shape::Shape(){}

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

//Rectangle Class
/**
 * @brief Rectangle::Rectangle      Constructor for the rectangle class.  Sets width and height
 *                                                    Sets dimensions variables
 * @param w     Width of Rectangle
 * @param h     Height of Rectangle
 */
Rectangle::Rectangle(double w, double h): Shape(), width(w), height(h){
    dimensions.insert(std::pair<std::string, double>("width", width));
    dimensions.insert(std::pair<std::string, double>("height", height));
}

/**
 * @brief Rectangle::getType    Returns 'rectangle'
 * @return      std::string
 */
std::string Rectangle::getType() const{
    return "rectangle";
}

/**
 * @brief Rectangle::getSides   Returns 4
 * @return      int
 */
int Rectangle::getSides() const{
    return 4;
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
Square::Square(double w): Rectangle(w, w){}

    /**
 * @brief Square::getType       Returns 'square'
 * @return      std::string
 */
std::string Square::getType() const{
    return "square";
}



//Triangle Class
/**
 * @brief Triangle::Triangle        Constructor for the triangle class.  Sets base length and height.
 *                                                  Sets 'dimensions' variable.
 *                                                  Triangle is assumed to be isoceles.
 * @param b     Base lenght
 * @param h     Height
 */
Triangle::Triangle(double b, double h): Shape(), base(b), height(h){
    dimensions.insert(std::pair<std::string, double>("base", base ));
    dimensions.insert(std::pair<std::string, double>("height", height));
}

/**
 * @brief Triangle::getType     Returns 'triangle'
 * @return      std::string
 */
std::string Triangle::getType() const{
    return "triangle";
}

/**
 * @brief Triangle::getSides    Returns 3
 * @return      int
 */
int Triangle::getSides() const{
    return 3;
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
Circle::Circle(double r): Shape(), radius(r){
    dimensions.insert(std::pair<std::string, double>("radius", radius));
}


/**
 * @brief Circle::getType       Returns 'cirlce'
 * @return      std::string
 */
std::string Circle::getType() const{
    return "circle";
}


/**
 * @brief Circle::getSides      Returns 1
 * @return      int
 */
int Circle::getSides() const{
    return 1;
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
