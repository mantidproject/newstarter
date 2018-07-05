#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

#include "Shape.h"
#include "ShapeSorter.h"



void ShapeSorter::print_vector(std::ostream& Ostream) {
	for (const auto & iter : shape_vector) {
		(*iter).print_shape(Ostream);
	}
}

/*
Comparisons between shapes for area, perimeter
*/
bool compare_area(Shape* shape1, Shape* shape2) {
	return (*shape1).area() < (*shape2).area();
};
bool compare_perimeter(Shape* shape1, Shape* shape2) {
	return (*shape1).perimeter() < (*shape2).perimeter();
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
	Sort shape_vector by their area and print out the contents.
*/
void ShapeSorter::print_by_area(bool ascending, std::ostream &Ostream) {

	sort(shape_vector.begin(), shape_vector.end(), compare_area);

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