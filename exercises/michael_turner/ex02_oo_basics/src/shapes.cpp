#include "shapes.h"

#include <cmath>

//Base Class
Shape::Shape(const std::string& name, const int& s): type(name), sides(s) {}
std::string Shape::getType() const{
    return type;
}
int Shape::getSides() const{
	return sides;
}

//Rectangle Class
Rectangle::Rectangle(double w, double h): Shape(constants::RECTANGLE_NAME, constants::RECTANGLE_SIDES), width(w), height(h){}
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
Triangle::Triangle(double b, double h): Shape(constants::TRIANGLE_NAME, constants::TRIANGLE_SIDES), base(b), height(h){}
double Triangle::getArea() const{
	return (base * height) / 2;
}
double Triangle::getPerim() const{
	return (base + 2 * std::sqrt( std::pow(height, 2) + pow(base, 2)/4 ));
}

//Circle Class
Circle::Circle(double r): Shape(constants::CIRCLE_NAME, constants::CIRCLE_SIDES), radius(r){}
double Circle::getArea() const{
	return (constants::PI * pow(radius, 2));
}
double Circle::getPerim() const{
	return (2*constants::PI*radius);
}

