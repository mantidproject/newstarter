#include "Shapes.h"

int Shape::Sides() const {
	return _sides;
}
double Shape::Perimeter() const {
	return _perimeter;
}
double Shape::Area() const {
	return _area;
}
string Shape::Str() const {
	return this->Type() + ' ' + to_string(_sides) + " sides, " + to_string(_perimeter) + " perimeter, " + to_string(_area) + " area";
}
Shape::Shape() {
	_sides = 0;
	_perimeter = 0;
	_area = 0;
}
void Shape::setSides(int sides) {
	_sides = sides;
}
void Shape::setPerimeter(double perimeter) {
	_perimeter = perimeter;
}
void Shape::setArea(double area) {
	_area = area;
}

string Rectangle::RectangleStr = "Rectangle";
Rectangle::Rectangle(double sideLength, double otherSideLength) {
	setSides(4);
	setPerimeter(2 * sideLength + 2 * otherSideLength);
	setArea(sideLength * otherSideLength);
}
string Rectangle::Type() const {
	return RectangleStr;
}

string Square::SquareStr = "Square";
Square::Square(double sideLength) : Rectangle(sideLength, sideLength) {}
string Square::Type() const {
	return SquareStr;
}

string Circle::CircleStr = "Circle";
Circle::Circle(double radius) {
	setSides(1);
	setPerimeter(2 * M_PI * radius);
	setArea(M_PI * radius * radius);
}
string Circle::Type() const {
	return CircleStr;
}

string Triangle::TriangleStr = "Triangle";
Triangle::Triangle(double height, double base) {
	setSides(3);
	setPerimeter(base + 2 * sqrt(height * height + (base * base / 4.0)));
	setArea(0.5 * base * height);
}
string Triangle::Type() const {
	return TriangleStr;
}
