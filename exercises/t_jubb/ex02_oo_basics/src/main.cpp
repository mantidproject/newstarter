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
	//virtual Shape() = 0;
	virtual double area() = 0;
	virtual double perimeter()  = 0;
	double get_sides() { return sides; };
	std::string get_type() { return type; };
	void print_shape(std::ostream &OutputStream) {  
		int pad = 10 - type.size();
		std::string pad_blank(pad, ' ');
		OutputStream << "Shape : " << type << pad_blank;
		OutputStream << " Area : " << this->area() << " Perim. : " << this->perimeter() << std::endl;
		};

protected:
	int sides;
	std::string type;
};

/*
Square class
*/
class Square: public Shape {

public:
	Square(double h) {
		height = h;
		type = "Square";
		sides = 4;
	};

	double area() { return height * height; };
	double perimeter() { return 4 * height; };

private:
	double height;
};

/*
Rectangle class
*/
class Rectangle : public Shape {

public:
	Rectangle(double h, double w) {
		height = h;
		width = w;
		type = "Rectangle";
		sides = 4;
	};
	double area() { return height * width; };
	double perimeter() { return  2 * height + 2 * width; };

private:
	double height, width;

};

/*
Triangle Class
*/
class IsoscelesTriangle : public Shape {

public:
	IsoscelesTriangle(double b, double h) {
		base = b;
		height = h;
		type = "Triangle";
		sides = 3;
	};
	double area() { return 0.5 * base * height; };
	double perimeter() { return  base + 2 * sqrt(pow(height, 2) + 0.25 * pow(base, 2)); };

private:
	double base, height;
};

/*
Circle Class
*/
class Circle : public Shape {

public:
	Circle(double r) {
		radius = r;
		type = "Circle";
		sides = 1;
	};
	double area() { return M_PI * pow(radius, 2); };
	double perimeter() { return  M_PI * 2 * radius; };

private:
	double radius;
};

/*
Comparisons between shapes for area, perimeter
*/
bool compare_area(Shape* shape1, Shape* shape2) {
	return (*shape1).area() < (*shape2).area();
};
bool compare_perimeter(Shape* shape1, Shape* shape2) {
	return (*shape1).perimeter() < (*shape2).perimeter();
};

class ShapeSorter {

public:
	ShapeSorter(std::vector<Shape*> vec) { shape_vector = vec; };
	void print_type(std::string type, std::ostream &Ostream);
	void print_sides(int sides, std::ostream &Ostream);
	void print_by_area(bool ascending, std::ostream &Ostream);
	void print_by_perimeter(bool ascending, std::ostream &Ostream);

private:
	std::vector<Shape*> shape_vector;
	void print_vector(std::ostream& Ostream) {
		for (const auto & iter : shape_vector) {
			(*iter).print_shape(Ostream);
		}
	}

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
		print_vector(Ostream);
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
		print_vector(Ostream);
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

	std::cout << ci.area() << std::endl;

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