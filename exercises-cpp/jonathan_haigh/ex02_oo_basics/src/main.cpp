/**
 * Skeleton main routine
 */

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>

class Shape {
public:
	std::string name;
	double area;
	int n_sides;
	double perimeter;
	
	void print_values() {
		std::cout << name << " A:" << area << " P:" << perimeter << std::endl;
	}
};

class Square : public Shape {
public:
	Square(double side1) {
		name = "Square";
		area = pow(side1, 2);
		n_sides = 4;
		perimeter = side1 * 4;
	}
};

class Rectangle : public Shape {
public:
	Rectangle(double side1, double side2) {
		name = "Rectangle";
		area = side1 * side2;
		n_sides = 4;
		perimeter = side1 * 2 + side2 * 2;
	}
};

class Circle : public Shape {
public:
	Circle(double radius) {
		name = "Circle";
		area = M_PI * pow(radius, 2);
		n_sides = 1;
		perimeter = M_PI * 2 * radius;
	}
};

class Triangle : public Shape {
public:
	Triangle(double height, double base) {
		name = "Triangle";
		area = height * base / 2;
		n_sides = 3;
		perimeter = base + 2 * sqrt(pow(height, 2) + (pow(base, 2) / 4));
	}
};

class ShapeSorter {
public:
	std::vector<Shape> shape_list;

	ShapeSorter(std::vector<Shape> shapes) {
		shape_list = shapes;
	}

	void match_type(std::string name) {
		for (Shape el : shape_list) {
			if (el.name == name) {
				el.print_values();
			}
		}
	}

	void match_sides(int sides) {
		for (Shape el : shape_list) {
			if (el.n_sides == sides) {
				el.print_values();
			}
		}
	}

	void descending_area() {
		std::sort(shape_list.begin(), shape_list.end(),
			[](const Shape& x, const Shape& y) {
				return x.area > y.area;
			});
		for (Shape el : shape_list) {
			el.print_values();
		}
	}

	void descending_perimeter() {
		std::sort(shape_list.begin(), shape_list.end(),
			[](const Shape& x, const Shape& y) {
				return x.perimeter > y.perimeter;
			});
		for (Shape el : shape_list) {
			el.print_values();
		}
	}
};

int main(int, char **)
{
	std::vector<Shape> shapes = { Square(5), Rectangle(3,6), Circle(5.5), Triangle(9,3.5) };
	ShapeSorter shape_sorter(shapes);
	std::cout << "Descending area:" << std::endl;
	shape_sorter.descending_area();
	std::cout << std::endl << "Descending perimeter:" << std::endl;
	shape_sorter.descending_perimeter();
	std::cout << std::endl << "Looking for squares:" << std::endl;
	shape_sorter.match_type("Square");
	std::cout << std::endl << "Looking for one-sided shapes:" << std::endl;
	shape_sorter.match_sides(1);
}