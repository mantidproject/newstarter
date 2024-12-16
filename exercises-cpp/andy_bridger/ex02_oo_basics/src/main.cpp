#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>

class Shape {
public:
	std::string shapeName;
	int numSides;
	double area;
	double perimeter;

};


class Rectangle : public Shape {
public:
	double side1;
	double side2;
	double area;
	double perimeter;



	Rectangle(double side1, double side2) {
		this->side1 = side1;
		this->side2 = side2;
		std::string name = "Rectangle";
		int numSides = 4;
	}
	Rectangle() = default;
};


class Square : public Rectangle {
public:

	Square(double side1) {
		this->side1 = side1;
		this->side2 = side1;
		std::string name = "Square";
		int numSides = 4;
	}
};

class Circle : public Shape {
public:
	double radius;

	Circle(double radius) {
		this->radius = radius;
		std::string name = "Circle";
		int numSides = 1;
	}
};

class Triangle : public Shape {
public:
	double height; 
	double base;

	Triangle(double height, double base) {
		this->height = height;
		this->base = base;
		std::string name = "Triangle";
		int numSides = 3;
	}
};


class Tester {
public:
	Rectangle rectangle;
	Square square;
	Circle circle;
	Triangle triangle;

	bool ApproxEquals(double a, double b) {
		return abs(a - b) < 0.0005; // set some sensible precision tolerance
	}

	bool testRectanglePerimeter() {
		double sides1s[3] = { 1, 2.3, 3 };
		double sides2s[3] = { 1, 1, 2.5 };
		double perimeter[3] = { 4, 6.6, 11 };
		bool all_pass = true;

		for (int i = 0; i < 3; i++) {
			if (!ApproxEquals(Rectangle(sides1s[i], sides2s[i]).perimeter, perimeter[i])) {
				all_pass = false;
			}
		}
		return all_pass;
	}
};

int main(int, char **)
{
}