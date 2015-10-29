#include <iostream>
#include "circle.h"

/**
 * Shape: 
 */
int main(int argc, char ** argv)
{
	Circle circle(1.0);
	std::cout << circle.perimeter() << std::endl;
	std::cout << circle.area() << std::endl;

	return 0;
}