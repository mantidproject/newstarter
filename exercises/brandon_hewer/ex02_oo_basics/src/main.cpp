#include "Circle.h"
#include "Rectangle.h"
#include "ShapeSorter.h"
#include "Square.h"
#include "Triangle.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int, char**) {

	// Setting up valid example shapes.
	Circle circle(10);
	Circle circle2(8.3);
	Square square(10);
	Square square2(3.2);
	Rectangle rectangle(8, 12);
	Rectangle rectangle2(9.01, 17.3);
	Triangle triangle(5, 10);
	Triangle triangle2(20, 20.1);

	// Testing sorting and filtering of shapes.
	vector<const Shape*> shapes = { &circle, &circle2, &square, &square2, &rectangle, 
		&rectangle2, &triangle, &triangle2 };
	ShapeSorter sorter(shapes);
	cout << "Printing out squares:\n" << sorter.filterByType(ShapeType::Square) << "\n" 
		<< endl;
	cout << "Printing out circles:\n" << sorter.filterByType(ShapeType::Circle) << "\n" 
		<< endl;
	cout << "Printing out triangles:\n" << sorter.filterByType(ShapeType::Triangle) << 
		"\n" << endl;
	cout << "Printing out rectangles:\n" << sorter.filterByType(ShapeType::Rectangle) << 
		"\n" << endl;
	cout << "Printing out shapes with 4 sides:\n" << sorter.filterBySideNumber(4) 
		<< "\n" << endl;
	cout << "Printing out shapes with 3 sides:\n" << sorter.filterBySideNumber(3) 
		<< "\n" << endl;
	cout << "Printing out shapes with 2 sides:\n" << sorter.filterBySideNumber(2) 
		<< "\n" << endl;
	cout << "Printing out shapes with 1 side:\n" << sorter.filterBySideNumber(1) 
		<< "\n" << endl;
	cout << "Printing out shapes in order of area decreasing:\n" << 
		sorter.sortByArea(ShapeSorter::DESCENDING) << "\n" << endl;
	cout << "Printing out shapes in order of perimeter descending:\n" <<
		sorter.sortByPerimeter(ShapeSorter::DESCENDING) << "\n" << endl;
}