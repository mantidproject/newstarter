#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>


/*
Shape class
*/
class Shape {

public:
	Shape() { area = 0.0; this->perimeter = 0.0; this->sides = 0; this->type = " "; };

	double get_area() { return area; };
	double get_perimeter() { return perimeter; };
	double get_sides() { return sides; };
	std::string get_type() { return type; };
	void print_shape(std::ostream &OutputStream) {  
		int pad = 10 - type.size();
		std::string pad_blank(pad, ' ');
		OutputStream << "Shape : " << type << pad_blank;
		OutputStream << " Area : " << area << " Perim. : " << perimeter << std::endl;
		};

protected:
	double area, perimeter;
	int sides;
	std::string type;
};

/*
Square class
*/
class Square: public Shape {

public:
	Square() {
		height = 0.0;
		sides = 4;
		area = 0.0;
		perimeter = 0.0;
		type = "Square";
	};
	Square(double height) {
		type = "Square";
		sides = 4;
		area = height * height;
		perimeter = 4 * height;
	};

private:
	double height;
};

/*
Rectangle class
*/
class Rectangle : public Shape {

public:
	Rectangle() {
		type = "Rectangle";
		height = 0.0;
		width = 0.0;
		sides = 4;
		area = 0.0;
		perimeter = 0.0;
	};
	Rectangle(double height, double width) {
		type = "Rectangle";
		sides = 4;
		area = height * width;
		perimeter = 2 * height + 2 * width;
	};

private:
	double height, width;

};

/*
Triangle Class
*/
class IsoscelesTriangle : public Shape {

public:
	IsoscelesTriangle() {
		type = "Triangle";
		height = 0.0;
		base = 0.0;
		sides = 3;
		area = 0.0;
		perimeter = 0.0;
	};
	IsoscelesTriangle(double base, double height) {
		type = "Triangle";
		sides = 3;
		area = 0.5 * base * height;
		perimeter = base + 2 * sqrt(pow(height, 2) + 0.25 * pow(base, 2));
	};

private:
	double base, height;
};

/*
Circlee Class
*/
class Circle : public Shape {

public:
	Circle() {
		type = "Circle";
		radius = 0.0;
		sides = 1;
		area = 0.0;
		perimeter = 0.0;
	};
	Circle(double radius) {
		type = "Circle";
		sides = 1;
		area = M_PI * pow(radius, 2);
		perimeter = M_PI * 2 * radius;
	};

private:
	double radius;
};

/*
Comparisons between shapes for area, perimeter
*/
bool compare_area(Shape* shape1, Shape* shape2) {
	return (*shape1).get_area() < (*shape2).get_area();
};
bool compare_perimeter(Shape* shape1, Shape* shape2) {
	return (*shape1).get_perimeter() < (*shape2).get_perimeter();
};

class ShapeSorter : public Shape {

public:
	ShapeSorter() { };
	ShapeSorter(std::vector<Shape*> vec) { shape_vector = vec; };
	void print_type(std::string type, std::ostream &Ostream);
	void print_sides(int sides, std::ostream &Ostream);
	void print_by_area(bool ascending, std::ostream &Ostream);
	void print_by_perimeter(bool ascending, std::ostream &Ostream);

private:
	std::vector<Shape*> shape_vector;

};

/*
Prints shapes in shape_vector with a given type.
*/
void ShapeSorter::print_type(std::string type, std::ostream &Ostream) {
	for (auto i = shape_vector.begin(); i != shape_vector.end(); i++) {
		if ((**i).get_type() == type) {
			(**i).print_shape(Ostream);
		};
	};
};

/*
Prints shapes in shape_vector with a given number of sides.
*/
void ShapeSorter::print_sides(int sides, std::ostream &Ostream) {
	for (auto i = shape_vector.begin(); i != shape_vector.end(); i++) {
		if ((**i).get_sides() == sides) {
			(**i).print_shape(Ostream);
		};
	};
};

/*
Sort the vector of Shapes by their area and print out the contents.

@param ascending : Wether to sort from lowest to highst
*/
void ShapeSorter::print_by_area(bool ascending, std::ostream &Ostream) {

	sort(shape_vector.begin(), shape_vector.end(),compare_area);

	if (ascending) {
		for (auto i = shape_vector.begin(); i != shape_vector.end(); i++) {
			(**i).print_shape(Ostream);
		};
	}
	else {
		for (auto i = shape_vector.rbegin(); i != shape_vector.rend(); i++) {
			(**i).print_shape(Ostream);
		};
	}
};

/*
Sort the vector of Shapes by their perimeter and print out the contents.

@param ascending : Wether to sort from lowest to highst.
*/
void ShapeSorter::print_by_perimeter(bool ascending, std::ostream &Ostream) {

	sort(shape_vector.begin(), shape_vector.end(), compare_perimeter);

	if (ascending) {
		for (auto i = shape_vector.begin(); i != shape_vector.end(); i++) {
			(**i).print_shape(Ostream);
		};
	}
	else {
		for (auto i = shape_vector.rbegin(); i != shape_vector.rend(); i++) {
			(**i).print_shape(Ostream);
		};

	}
};


int main(int, char **)
{

	Circle ci(5.0);
	Square sq(1.0);
	Rectangle re(1.0, 2.0);
	IsoscelesTriangle tri(5.7, 2.3);

	std::vector<Shape*> vec;
	vec.push_back(&ci);
	vec.push_back(&sq);
	vec.push_back(&re);
	vec.push_back(&tri);

	ShapeSorter sorter(vec);
	std::cout << "Print by type " << std::endl;
	sorter.print_type("Circle", std::cout);
	std::cout << "Print by sides " << std::endl;
	sorter.print_sides(3, std::cout);
	std::cout << "Print by area " << std::endl;
	sorter.print_by_area(true, std::cout);
	std::cout << "Print by perimeter " << std::endl;
	sorter.print_by_perimeter(true, std::cout);

	return 0;
}