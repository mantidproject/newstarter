#include <cmath>
#include <string>

#include "Shape.h"


/*
Shape class
*/

int Shape::get_sides() { return sides; };

std::string Shape::get_type() { return type; };

void Shape::print_shape(std::ostream &OutputStream) {
		int pad = 10 - type.size();
		std::string pad_blank(pad, ' ');
		OutputStream << "Shape : " << type << pad_blank;
		OutputStream << " Area : " << this->area() << " Perim. : " << this->perimeter() << std::endl;
	};
