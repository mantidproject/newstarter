/**
 * Skeleton main routine
 */

#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"

int main(int, char **)
{
	ShapeSorter sorter;
	sorter.add(std::make_shared<Square>(5));
	sorter.add(std::make_shared<Rectangle>(3, 6));
	sorter.add(std::make_shared<Circle>(5.5));
	sorter.add(std::make_shared<Triangle>(9, 3.5));

	sorter.descendingArea();
	sorter.descendingPerimeter();
	sorter.matchName("square");
	sorter.matchSides(1);
}