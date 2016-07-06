
#include "shapeEnum.h"
#include "ShapeController.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int, char **)
{
	vector<ShapeController> shapeCollection;

	char c = ' ';
	do {
		

		shapes selectedShape = static_cast<shapes>(rand() % SHAPE_ENUM_LEN);
		double height = rand() % 100;
		double width = rand() % 100;
		double radius = rand() % 100;

		cout << "H:" << height << " W:" << width << " R:" << radius << endl;
		ShapeController newShape(selectedShape, width, height, radius);

		cout << "Name: " << newShape.getShapeName() << endl;
		cout << "Sides: " << newShape.getNoOfSides() << endl;
		cout << "Area: " << newShape.getShapeArea() << endl;
		cout << "Perimeter: " << newShape.getShapePerimeter() << endl;


		cout << "Enter q to exit or any key followed by enter to continue" << "\n" << endl;
		cin.get(c);
	} while (c != 'q');
}