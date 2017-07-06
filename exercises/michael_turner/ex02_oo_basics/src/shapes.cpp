#include "shapes.h"

#include <cmath>

//Base Class
Shape::Shape(const std::string& n, const int& s): name(n), sides(s) {}
std::string Shape::getType(){
	return name;
}
int Shape::getSides(){
	return sides;
}

//Rectangle Class
Rect::Rect(double& w, double& h): Shape(constants::RECT_NAME, constants::RECT_SIDES), width(w), height(h){}
double Rect::getArea(){
	return width * height;
}
double Rect::getPerim(){
	return 2*(width+height);
}

//Square Class
Square::Square(double& w): Rect(w, w){
	name = constants::SQUARE_NAME;
}

//Triangle Class
Triangle::Triangle(double& b, double& h): Shape(constants::TRIANGLE_NAME, constants::TRIANGLE_SIDES), base(b), height(h){}
double Triangle::getArea(){
	return (base * height) / 2;
}
double Triangle::getPerim(){
	return (base + 2 * std::sqrt( std::pow(height, 2) + pow(base, 2)/4 ));
}

//Circle Class
Circle::Circle(double &r): Shape(constants::CIRCLE_NAME, constants::CIRCLE_SIDES), radius(r){}
double Circle::getArea(){
	return (constants::PI * pow(radius, 2));
}
double Circle::getPerim(){
	return (2*constants::PI*radius);
}

