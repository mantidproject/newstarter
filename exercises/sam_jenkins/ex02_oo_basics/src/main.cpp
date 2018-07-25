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
#include <memory>
using namespace std;
const int SIDES_TO_PRINT = 4;
const string SHAPE_TO_PRINT = "Triangle";
int main(int, char **)
{
	vector<unique_ptr<Shapes>> shapes;
	shapes.reserve(10);

	shapes.push_back(unique_ptr<Square>(new Square(5)));
	shapes.push_back(unique_ptr<Circle>(new Circle(7)));
	shapes.push_back(unique_ptr<Rectangle>(new Rectangle(10, 5)));
	shapes.push_back(unique_ptr<Triangle>(new Triangle(10, 5)));
	shapes.push_back(unique_ptr<Square>(new Square(9)));
	shapes.push_back(unique_ptr<Circle>(new Circle(3)));
	shapes.push_back(unique_ptr<Rectangle>(new Rectangle(2, 4)));
	shapes.push_back(unique_ptr<Triangle>(new Triangle(5, 6)));
	shapes.push_back(unique_ptr<Square>(new Square( 1)));
	shapes.push_back(unique_ptr<Circle>(new Circle(2)));
	
	
		
	auto sorter = ShapeSorter();
	sorter.areaSort(shapes);
	sorter.perimiterSort(shapes);
	sorter.sidesPrint(SIDES_TO_PRINT,shapes);
	sorter.typePrint(SHAPE_TO_PRINT,shapes);
	
	
	return 0;
}