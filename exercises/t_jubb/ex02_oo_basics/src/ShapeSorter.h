#ifndef HEADER_SHAPESORTER
#define HEADER_SHAPESORTER

#include <string>
#include <vector>

#include "Shape.h"

/*
	ShapeSorter class allows vectors of Shape objects to be sorted and 
	printed in various ways
*/
class ShapeSorter {

public:
	ShapeSorter(std::vector<Shape*> vec) { shape_vector = vec; };
	/*
		Prints shapes in shape_vector with a given type.

		@param : type, a supported shape type, e.g. "Square"
		@param : output stream.
	*/
	void print_type(std::string type, std::ostream &Ostream);
	/*
		Prints shapes in shape_vector with a given number of sides.

		@param : sides, the number of sides in the desired shape.
		@param : output stream.
	*/
	void print_sides(int sides, std::ostream &Ostream);
	/*
		Sort shape_vector by their area and print out the contents.

		@param ascending : Wether to sort from lowest to highst.
		@param : output stream.
	*/
	void print_by_area(bool ascending, std::ostream &Ostream);
	/*
		Sort the vector of Shapes by their perimeter and print out the contents.

		@param ascending : Wether to sort from lowest to highst.
		@param Ostream : output stream.
	*/
	void print_by_perimeter(bool ascending, std::ostream &Ostream);

private:
	std::vector<Shape*> shape_vector;
	void print_vector(std::ostream& Ostream);

};

#endif