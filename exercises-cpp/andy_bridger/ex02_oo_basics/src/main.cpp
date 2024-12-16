#include <iostream>
#include <vector>
#include <cmath>

class Shape {
public:
	double PI = 3.14159265358979323846;
	std::string shapeKind;
	std::string shapeName;
	int numSides = 1;
	double area = 0.0;
	double perimeter = 0.0;

};


class Rectangle : public Shape {
public:
	double side1 = 0.0;
	double side2 = 0.0;

	Rectangle(double side1, double side2, std::string name) {
		this->side1 = side1;
		this->side2 = side2;
		this->shapeName = name;
		std::string shapeKind = "Rectangle";
		int numSides = 4;
		calcPerimeter();
		calcArea();
	}
	Rectangle() {
		double side1 = 0.0;
		double side2 = 0.0;
	}

	void calcPerimeter() {
		perimeter = (2 * side1) + (2 * side2);
	}
	void calcArea() {
		area = side1* side2;
	}

};


class Square : public Rectangle {
public:

	Square(double side1, std::string name) {
		this->side1 = side1;
		this->side2 = side1;
		this->shapeName = name;
		std::string shapeKind = "Square";
		int numSides = 4;
		calcPerimeter();
		calcArea();
	}
};

class Circle : public Shape {
public:
	double radius;

	Circle(double radius, std::string name) {
		this->radius = radius;
		this->shapeName = name;
		std::string shapeKind = "Circle";
		int numSides = 1;
		calcPerimeter();
		calcArea();
	}

	void calcPerimeter() {
		perimeter = 2 * PI * radius;
	}
	void calcArea() {
		area = PI*pow(radius, 2);
	}
};

class Triangle : public Shape {
public:
	double height; 
	double base;

	Triangle(double height, double base, std::string name) {
		this->height = height;
		this->base = base;
		this->shapeName = name;
		std::string shapeKind = "Triangle";
		int numSides = 3;
		calcPerimeter();
		calcArea();
	}
	void calcArea() {
		area = 0.5 * base * height;
	}
	void calcPerimeter() {
		perimeter = base + 2*sqrt((pow(height,2) + (pow(base, 2)/4)));
	}
};

class ShapeSorter {
public:
	std::vector<Shape*> shapes;

	ShapeSorter(std::vector<Shape*> shapes) {
		this->shapes = shapes;
	}

	void printShape(std::string shape) {
		for (int i = 0; i < shapes.size(); i++) {
			std::cout << shapes[i]->shapeName;
			if (shapes[i]->shapeKind == shape) {
				std::cout << shapes[i]->shapeKind;
			}
		
		}
	
	}


};

class Tester {
public:
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
				std::cout << Triangle(height[i], base[i]).perimeter << " " << perimeters[i] << "\n";
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

	void runAllTests() {
		int pass = 0;
		int fail = 0;
		int n = 0;
		std::string tests[10] = { "RectanglePerimeter", "RectangleArea",
									"SquarePerimeter", "SquareArea",
									"CirclePerimeter", "CircleArea",
									"TrianglePerimeter", "TriangleArea" };

		if (testRectanglePerimeter()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testRectangleArea()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testSquarePerimeter()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testSquareArea()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testCirclePerimeter()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testCircleArea()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testTrianglePerimeter()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;
		if (testTriangleArea()) {
			pass++;
			std::cout << "Test: " << tests[n] << " passed \n";
		}
		else {
			fail++;
			std::cout << "Test: " << tests[n] << " failed \n";
		}
		n++;

		std::cout << "Tests passed: " << pass << ". Tests failed: " << fail << "\n";
	}
};

int main(int, char **)
{
	//Tester tester;

	//tester.runAllTests();

	Square sq1(1, "squaro");
	Rectangle rect(2.2, 3.4, "recky");
	Circle circ(1.3, "mr circ");
	Triangle tri(2.9, 2.3, "points");

	// vector of pointers to account for the different classes
	std::vector<Shape*> shapes = {&sq1, &rect, &circ, &tri};

	ShapeSorter sorter(shapes);

	sorter.printShape("Square");



}