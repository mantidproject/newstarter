#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"

using namespace std;
using namespace Shapes;

namespace
{
	/** Obtains a random number between 0 and 3 which corresponds to ShapesTypes.
	*/
	ShapeType getRandomShape()
	{
		return (ShapeType)((int)floor( 4 * (double)rand() / RAND_MAX ));
	}

	/** Obtains a random number between 0 and 120 which corresponds to a side.
	*/
	double getRandomSide()
	{
		return ( 120 * (double) rand() / RAND_MAX );
	}
}

int main(int, char **)
{
	vector<shared_ptr<Shape>> shapeList;
	int numShapes;

	cout << "Welcome, please enter your desired number of shapes." << endl;
	cin >> numShapes;


	srand(numShapes);//Seed random number generator with user selection

	//Select 20 random-ish shapes. Ideally random number generated should be seeded
	for(int i=0; i<numShapes; i++)
	{
		switch(getRandomShape())
		{
		case ShapeType::RECTANGLE:
			shapeList.push_back(std::make_shared<Rectangle>(getRandomSide(), getRandomSide()));
			break;
		case ShapeType::SQUARE:
			shapeList.push_back(std::make_shared<Square>(getRandomSide()));
			break;
		case ShapeType::CIRCLE:
			shapeList.push_back(std::make_shared<Circle>(getRandomSide()));
			break;
		case ShapeType::TRIANGLE:
			shapeList.push_back(std::make_shared<Triangle>(getRandomSide(), getRandomSide()));
			break;
		default:
			continue;
		}
	}

	bool exit = false;
	int option;
	int type;
	int sides;
	ShapeSorter sorter;

	//Application loop
	while(!exit)
	{
		cout << "\n\nSelect an option: " << endl;

		cout << "\n0 - Print shapes by type\
			  \n1 - Print shapes by number of sides\
			  \n2 - Print shapes in order of perimeter\
			  \n3 - Print shapes in order of area\
			  \n4 - exit\n" << endl;

		cin >> option;

		switch(option)
		{
		case 0:
			cout << "\nSelect Shape:\n\n0 - Square\n1 - Rectangle\n2 - Circle\n3 - Iso Triangle" <<endl;
			cin >> type;

			sorter.printByType((ShapeType)type, shapeList);
			break;
		case 1:
			cout << "\nEnter number of sides." <<endl;
			cin >> sides;

			sorter.printBySides(sides, shapeList);
			break;
		case 2:
			sorter.printOrderPerimeter(shapeList);
			break;
		case 3:
			sorter.printOrderArea(shapeList);
			break;
		case 4:
			exit = true;
			break;
		default:
			continue;
		}
	}

	cout << "Goodbye." <<endl;
}