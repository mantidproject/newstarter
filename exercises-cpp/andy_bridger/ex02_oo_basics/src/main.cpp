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
		double perimeters[3] = { 4, 6.6, 11 };
		bool all_pass = true;

		for (int i = 0; i < 3; i++) {
			if (!ApproxEquals(Rectangle(sides1s[i], sides2s[i]).perimeter, perimeters[i])) {
				all_pass = false;
			}
		}
		return all_pass;
	}

	bool testRectangleArea() {
		double sides1s[3] = { 1, 2.3, 3 };
		double sides2s[3] = { 1, 1, 2.5 };
		double areas[3] = { 1, 2.3, 7.5 };
		bool all_pass = true;

		for (int i = 0; i < 3; i++) {
			if (!ApproxEquals(Rectangle(sides1s[i], sides2s[i]).area, areas[i])) {
				all_pass = false;
			}
		}
		return all_pass;
	}

	bool testSquarePerimeter() {
		double sides1s[3] = { 1, 2.3, 3 };
		double perimeters[3] = { 4, 9.2, 12};
		bool all_pass = true;

		for (int i = 0; i < 3; i++) {
			if (!ApproxEquals(Square(sides1s[i]).perimeter, perimeters[i])) {
				all_pass = false;
			}
		}
		return all_pass;
	}

	bool testSquareArea() {
		double sides1s[3] = { 1, 2.3, 3 };
		double areas[3] = { 1, 5.29, 9 };
		bool all_pass = true;

		for (int i = 0; i < 3; i++) {
			if (!ApproxEquals(Square(sides1s[i]).area, areas[i])) {
				all_pass = false;
			}
		}
		return all_pass;
	}


	bool testCirclePerimeter() {
		double radii[3] = { 1, 2.3, 3 };
		double perimeters[3] = { 6.28319, 14.451326, 18.849556 };
		bool all_pass = true;

		for (int i = 0; i < 3; i++) {
			if (!ApproxEquals(Circle(radii[i]).perimeter, perimeters[i])) {
				all_pass = false;
			}
		}
		return all_pass;
	}

	bool testCircleArea() {
		double radii[3] = { 1, 2.3, 3 };
		double areas[3] = { 3.141593, 16.61903, 28.274334 };
		bool all_pass = true;

		for (int i = 0; i < 3; i++) {
			if (!ApproxEquals(Circle(radii[i]).area, areas[i])) {
				all_pass = false;
			}
		}
		return all_pass;
	}

	bool testTrianglePerimeter() {
		double height[3] = { 1, 2.3, 3 };
		double base[3] =   { 1, 1, 2.5 };
		double perimeters[3] = { 3.236, 5.707, 9 };
		bool all_pass = true;

		for (int i = 0; i < 3; i++) {
			if (!ApproxEquals(Triangle(height[i], base[i]).perimeter, perimeters[i])) {
				all_pass = false;
			}
		}
		return all_pass;
	}

	bool testTriangleArea() {
		double height[3] = { 1, 2.3, 3 };
		double base[3] =   { 1, 1, 2.5 };
		double areas[3] =  { 0.5, 1.15, 3.75 };
		bool all_pass = true;

		for (int i = 0; i < 3; i++) {
			if (!ApproxEquals(Triangle(height[i], base[i]).area, areas[i])) {
				all_pass = false;
			}
		}
		return all_pass;
	}

};

int main(int, char **)
{
}