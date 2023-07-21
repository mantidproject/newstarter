#include "Shapes.h"

int Shape::Sides() {
	return _sides;
}
double Shape::Perimeter() {
	return _perimeter;
}
double Shape::Area() {
	return _area;
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

Rectangle::Rectangle(double sideLength, double otherSideLength) {
	setSides(4);
	setPerimeter(2 * sideLength + 2 * otherSideLength);
	setArea(sideLength * otherSideLength);
}

Square::Square(double sideLength) : Rectangle(sideLength, sideLength) {}


Circle::Circle(double radius) {
	setSides(1);
	setPerimeter(2 * M_PI * radius);
	setArea(M_PI * radius * radius);
}

Triangle::Triangle(double height, double base) {
	setSides(3);
	setPerimeter(base + 2 * sqrt(height * height + (base * base / 4.0)));
	setArea(0.5 * base * height);
}
