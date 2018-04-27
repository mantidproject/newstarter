#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "IsoscelesTriangle.h"
#include "Shape.h"
#include "ShapeSorter.h"




int main(int, char **)
{

	Circle ci(5.0);
	Square sq(1.0);
	Rectangle re(1.2, 2.0);
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