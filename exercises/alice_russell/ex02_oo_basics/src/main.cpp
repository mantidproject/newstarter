/**
 * Skeleton main routine
 */

#include <iostream>
#include <vector>
#include <fstream>


#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "ShapeSorter.h"

int main(int, char **)
{
	Circle c1(1.2), c2(2), c3(10.1);
	Square s1(7), s2(0.5);
	Rectangle r1(1.9,9.4), r2(5,7), r3(6.8,1.2), r4(11,6.8);
	Triangle t1(5.5, 6);

	std::cout;
	std::vector<Shape*> shape_vector{&c1,&c2,&c3,&s1,&s2,&r1,&r2,&r3,&r4,&t1};

	ShapeSorter shape;
	
	std::string type = "Circle";
	int side = 4;

	std::cout << "Shapes of type circle:" << std::endl;
	shape.print_type(std::cout, shape_vector, type);
	std::cout << "Shapes with 4 sides:" << std::endl;
	shape.print_sides(std::cout, shape_vector, side);
	std::cout << "Shapes in order of area descending" << std::endl;
	shape.print_area_descending(std::cout, shape_vector);
	std::cout << "Shapes in order of perimeter descending" << std::endl;
	shape.print_perimeter_descending(std::cout, shape_vector);
}