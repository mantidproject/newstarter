#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>


class Rectangle {
public:
	double side1;
	double side2;

	Rectangle(double side1, double side2) {
		this->side1 = side1;
		this->side2 = side2;
	}
	Rectangle() = default;
};


class Square : public Rectangle {
public:
	Square(double side1) {
		this->side1 = side1;
		this->side2 = side1;
	}
};

class Circle {
public:
	double radius;

	Circle(double radius) {
		this->radius = radius;
	}
};

class Triangle {
public:
	double height; 
	double base;

	Triangle(double height, double base) {
		this->height = height;
		this->base = base;
	}
};


int main(int, char **)
{
}