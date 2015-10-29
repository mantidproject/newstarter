#include <iostream>
#include "circle.h"
#include "triangle.h"
#include "square.h"

/**
 * Shape: 
 */
int main(int argc, char ** argv)
{
	// test - remove later
	Circle circle(1.0);
	std::cout << circle.perimeter() << std::endl;
	std::cout << circle.area() << std::endl;

	Triangle triangle (1.0, 1.0);
	std::cout << triangle.perimeter() << std::endl;
	std::cout << triangle.area() << std::endl;

	Rectangle rect(1.0, 2.0);
	std::cout << rect.perimeter() << std::endl;
	std::cout << rect.area() << std::endl;

	Square square(1.0);
	std::cout << square.perimeter() << std::endl;
	std::cout << square.area() << std::endl;

	return 0;
}