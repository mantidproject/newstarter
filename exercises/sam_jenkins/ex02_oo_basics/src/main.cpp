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
	shapes.emplace_back(make_unique<Square>(5));
	shapes.emplace_back(make_unique<Circle>(7));
	shapes.emplace_back(make_unique<Rectangle>(10, 5));
	shapes.emplace_back(make_unique<Triangle>(10, 5));
	shapes.emplace_back(make_unique<Square>(9));
	shapes.emplace_back(make_unique<Circle>(3));
	shapes.emplace_back(make_unique<Rectangle>(2, 4));
	shapes.emplace_back(make_unique<Triangle>(5, 6));
	shapes.emplace_back(make_unique<Square>(1));
	shapes.emplace_back(make_unique<Circle>(2));
	
	
		
	auto sorter = ShapeSorter();
	sorter.areaSort(shapes);
	sorter.perimiterSort(shapes);
	sorter.sidesPrint(SIDES_TO_PRINT,shapes);
	sorter.typePrint(SHAPE_TO_PRINT,shapes);
	
	
	return 0;
}