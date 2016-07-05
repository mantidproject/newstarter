#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "ShapeSorter.h"
#include "Circle.h"

int main(int argc, char** argv)
{
	// test shapes
	Triangle t = Triangle(15, 13);
	Rectangle t1 = Rectangle(15, 13);
	Rectangle t2 = Rectangle(25, 13);
	Rectangle t3 = Rectangle(35, 13);
	Circle t4 = Circle(15);

	ShapeSorter shapeSorter = ShapeSorter();

	shapeSorter.addShape(t);
	shapeSorter.addShape(t1);
	shapeSorter.addShape(t2);
	shapeSorter.addShape(t3);
	shapeSorter.addShape(t4);

	shapeSorter.getShapesFromType("rectangle");
	shapeSorter.getShapesFromSides(3);
	shapeSorter.getShapesPerimeterDesc();
	shapeSorter.getShapesVolumeDesc();
}
