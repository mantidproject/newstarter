#include "shapes.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>

//Base Class
Shape::Shape(const std::string& name, const int& s): type(name), numSides(s) {}

void Shape::setDim(std::map<std::string, double>& dim){
    dimensions = dim;
}

void Shape::printShape(){
    std::cout <<std::left<< std::setw(constants::COL_WIDTH) << getType();
    for (std::map<std::string, double>::iterator iter = dimensions.begin(); iter != dimensions.end(); ++iter){
        std::cout << std::right <<std::setw(constants::COL_WIDTH)<< iter->first << ": " << std::left << std::setw(constants::COL_WIDTH) << iter->second;
    }
    std::cout << std::endl;
}

std::string Shape::getType() const{
    return type;
}
int Shape::getSides() const{
    return numSides;
}

//Rectangle Class
Rectangle::Rectangle(double w, double h): Shape(constants::RECTANGLE_NAME, constants::RECTANGLE_SIDES), width(w), height(h){
    std::map<std::string, double> dim;
    dim.insert(std::pair<std::string, double>("side1", width));
    dim.insert(std::pair<std::string, double>("side2", height));
    setDim(dim);
}

double Rectangle::getArea() const{
	return width * height;
}
double Rectangle::getPerim() const{
	return 2*(width+height);
}

//Square Class
Square::Square(double w): Rectangle(w, w){
    type = constants::SQUARE_NAME;
}

//Triangle Class
Triangle::Triangle(double b, double h): Shape(constants::TRIANGLE_NAME, constants::TRIANGLE_SIDES), base(b), height(h){
    std::map<std::string, double> dim;
    dim.insert(std::pair<std::string, double>("base", base ));
    dim.insert(std::pair<std::string, double>("height", height));
    setDim(dim);
}

double Triangle::getArea() const{
	return (base * height) / 2;
}
double Triangle::getPerim() const{
	return (base + 2 * std::sqrt( std::pow(height, 2) + pow(base, 2)/4 ));
}

//Circle Class
Circle::Circle(double r): Shape(constants::CIRCLE_NAME, constants::CIRCLE_SIDES), radius(r){
    std::map<std::string, double> dim;
    dim.insert(std::pair<std::string, double>("radius", radius));
    setDim(dim);
}
double Circle::getArea() const{
	return (constants::PI * pow(radius, 2));
}
double Circle::getPerim() const{
	return (2*constants::PI*radius);
}

