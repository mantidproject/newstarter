
#include "main.h"
#include "shapeEnum.h"
#include "ShapeController.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



int main(int, char **)
{
	vector<ShapeController> shapeCollection;
	char c = ' ';

	//Generate new shapes randomly until user tells us to stop
	do {
		
		ShapesEnum selectedShape = static_cast<ShapesEnum>(rand() % SHAPE_ENUM_LEN);
		double height = rand() % 100;
		double width = rand() % 100;

		
		ShapeController newShape(selectedShape, width, height);
		cout << "Shape: " << newShape.getShapeName() << endl;
		cout << "W:" << width << " H:" << height;
		shapeCollection.push_back(newShape);

		cout << "'q' to stop generation, enter to generate more shapes:" << "\n" << endl;
		cin.get(c);
	} while (c != 'q');


	int selection = getPrintType();
	//Have to add 1 as ENUM is 0 based index whilst selection starts at 1
	switch (selection) {
	//Select based on print ENUM between type, sides, area....etc.
	case TYPE+1:
		printShapeOutput(sortOutputByType, shapeCollection);
		break;
	case SIDES+1:
		printShapeOutput(sortOutputBySides, shapeCollection);
		break;
	case DESC_AREA+1:
		printShapeOutput(sortOutputByDescArea, shapeCollection);
		break;
	case DESC_PERIM+1:
		printShapeOutput(sortOutputByDescPerim, shapeCollection);
	default:
		break;
	}

	return 0;
}

//Gets the type of print the user wants and returns an int corresponding to the print ENUM
int getPrintType() {

	int c = ' ';
	do {
		//Have to add 1 as ENUM is 0 indexed
		cout << "Printing options:" << endl;
		cout << TYPE + 1 << " Matching Type" << endl;
		cout << SIDES + 1 << " Matching Number of Sides" << endl;
		cout << DESC_AREA + 1 << " In Order of Desc. Areas" << endl;
		cout << DESC_PERIM + 1 << " In Order of Desc. Perimeters" << endl;
		cout << "Please select 1-4 or 0 to exit:";
		cin >> c;


		//Test range against options
	} while (c < 0 || c > PRINT_ENUM_LEN);

	return c;
}

//Takes a pointer to a sort function and prints the resulting vector
void printShapeOutput(outputSortFuncPtr sortMethod,	vector<ShapeController> const &inputVector) {
	//Using function pointer we can keep it generic and just plug in what we need
	vector<ShapeController> toPrint = sortMethod(inputVector, cin);

	//Print out our sorted vector to the user
	for (ShapeController &output : toPrint) {
		cout << "Shape: " << output.getShapeName() << endl;
		cout << "Sides: " << output.getNoOfSides() << endl;
		cout << "Area: " << output.getShapeArea() << endl;
		cout << "Perimeter: " << output.getShapePerimeter() << endl;
		cout << "\n"; //create some space for next output
	}

}

//Asks user for shape type and filter so only that type is present
vector<ShapeController> sortOutputByType(const vector<ShapeController> &inputVector,
	istream &inputSource) {
	vector<ShapeController> foundShapes;

	cout << "Please type the shape you would like to find:" << endl;

	string filterInput;
	inputSource >> filterInput;

	for (ShapeController i : inputVector) {
		if (i.getShapeName() == filterInput) {
			foundShapes.push_back(i);
		}
	}

	return foundShapes;
}

//Asks user for the number of sides and filters so only shapes with that no is present
vector<ShapeController> sortOutputBySides(const vector<ShapeController> &inputVector,
	istream &inputSource) {
	vector<ShapeController> foundShapes;

	cout << "Please enter the number of sides you would like to filter by:" << endl;

	int noOfSides;
	inputSource >> noOfSides;

	for (ShapeController i : inputVector) {
		if (i.getNoOfSides() == noOfSides) {
			foundShapes.push_back(i);
		}
	}

	return foundShapes;
}

//Sorts inputted shapes by their area
vector<ShapeController> sortOutputByDescArea(const vector<ShapeController> &inputVector,
	istream &inputSource) {
	vector<ShapeController> orderedShapes = inputVector;
	sort(orderedShapes.begin(), orderedShapes.end(), compareShapeArea);
	return orderedShapes;
}

//Sorts inputted shapes by their perimeter
vector<ShapeController> sortOutputByDescPerim(const vector<ShapeController> &inputVector,
	istream &inputSource) {
	vector<ShapeController> orderedShapes = inputVector;
	sort(orderedShapes.begin(), orderedShapes.end(), compareShapePerim);
	return orderedShapes;
}

bool compareShapeArea(const ShapeController &i, const ShapeController &j) {
	return i.getShapeArea() > j.getShapeArea();
}

bool compareShapePerim(const ShapeController &i, const ShapeController &j) {
	return i.getShapePerimeter() > j.getShapePerimeter();
}