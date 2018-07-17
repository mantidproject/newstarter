#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>


using std::cout; using std::endl;
using std::vector; using std::string;

// Class Shape
class Shape {
	std::string type = "Shape";
};

// Class Square
class Square : public Shape {

	// Type and number of sides
	std::string  = "Square";
	int sides = 4;

public:
	// length of side
	double length;
	
	Square(double x) {
		length = x;
	}

	// method to define area
	double area() {
		return length * length;
	}

	// method to define perimeter
	double perimeter() {
		return 4 * length;
	}


};

// Class Rectangle
class Rectangle : public Shape {
	// type and length of rectangle
	std::string = "Rectangle";
	int sides = 4;

public:
	// length of sides
	double length, breath;


	Rectangle(double x, double y) {
		length = x;
		breath = y;
	}

	// method to get area
	double area() {
		return length * breath;
	}

	// method to get perimeter
	double perimeter() {
		return 2 * (length + breath);
	}


};

// Class Circle
class Circle: public Shape {

	// type and length of rectangle
	std::string = "Circle";
	int sides = 0;

public:
	// radius of the circle
	double radius;

	// constructor
	Square(double r) {
		radius = r;
	}

	// method to define area
	double area() {
		return 3.14 * radius * radius;
	}

	// method to define perimeter
	double perimeter() {
		return 6.28 * radius;
	}


};


// Class Triangle
class Triangle: public Shape {

	// type and length of triangle
	std::string = "Triangle";
	int sides = 3;

public:
	// length of sides
	double height, base;

	Square(double x, double y) {
		base = x;
		height = y;
	}

	// method to get area
	double area() {
		return 0.5 * base * height;
	}

	// method to define perimeter
	double perimeter() {
		return base + 2 * std::sqrt(height ** 2 + (base / 2) ** 2);
	}


};


class ShapeSorter {


	sortByArea(const std::vector<Shape> vec) {
		std::sort(vec.begin(), vec.end(),
			[](Shape a, Shape b) {
			return a.area() > b.area();
		});
	}

};


int main() {
	
	// vec of shapes
	vector<Shape> someShapes = { Triangle(3, 5), Square(1.6), Rectangle(3, 5), Circle(1.6) };


	return 0;
}