/**
 * Skeleton main routine
 */
#include <string>
#include <vector>
#include <iostream>
#include "Shapes.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"
using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

int main(int, char **)
{
	vector<Shapes*> shapes(10);
	shapes[0] = new Square(5);
	shapes[1] = new Circle(7);
	shapes[2] = new Rectangle(10, 5);
	shapes[3] = new Triangle(10, 5);
	shapes[4] = new Square(9);
	shapes[5] = new Circle(3);
	shapes[6] = new Rectangle(2, 4);
	shapes[7] = new Triangle(5, 6);
	shapes[8] = new Square(1);
	shapes[9] = new Circle(2);

	
		
	
	ShapeSorter::areaSort(shapes);
	ShapeSorter::perimiterSort(shapes);
	ShapeSorter::sidesPrint(4,shapes);
	ShapeSorter::typePrint("Triangle",shapes);
	for (int i = 0; i < 10; i++) {
		delete shapes[i];
	}
	
	return 0;
}