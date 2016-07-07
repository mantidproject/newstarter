
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
		
		shapes selectedShape = static_cast<shapes>(rand() % SHAPE_ENUM_LEN);
		double height = rand() % 100;
		double width = rand() % 100;

		
		ShapeController newShape(selectedShape, width, height);
		cout << "Shape: " << newShape.getShapeName() << endl;
		cout << "W:" << width << " H:" << height;
		shapeCollection.push_back(newShape);

		cout << "Enter 'q' to stop generating new shapes" << "\n" << endl;
		cin.get(c);
	} while (c != 'q');


	int selection = getPrintType();
	//Have to add 1 as ENUM is 0 based index whilst selection starts at 1
	switch (selection) {
	case TYPE+1:
		printShapeOutput(sortOutputByType, shapeCollection);
		break;
	case SIDES+1:
		printShapeOutput(sortOutputBySides, shapeCollection);
		break;
	default:
		break;
	}

}




void printShapeOutput(outputSortFuncPtr sortMethod,	vector<ShapeController> const &inputVector) {
	//Using function pointer we can keep it generic and just plug in what we need

	vector<ShapeController> toPrint = sortMethod(inputVector, cin);

	for (ShapeController &output : toPrint) {
		cout << "Shape: " << output.getShapeName() << endl;
		cout << "Sides: " << output.getNoOfSides() << endl;
		cout << "Area: " << output.getShapeArea() << endl;
		cout << "Perimeter: " << output.getShapePerimeter() << endl;
		cout << "\n"; //create some space for next output
	}

}

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


int getPrintType() {
	
	int c = ' ';
	do {
		//Have to add 1 as ENUM is 0 indexed
		cout << "Printing options:" << endl;
		cout << TYPE + 1 << " Matching Type" << endl;
		cout << SIDES + 1 << " Matching Number of Sides" << endl;
		cout << DESC_VOL + 1 << " In Order of Desc. Volumes" << endl;
		cout << DESC_PERIM + 1 << " In Order of Desc. Perimeters" << endl;
		cout << "Please select 1-4 or 0 to exit:";
		cin >> c;


		//Test range against options
	} while (c < 0 || c > PRINT_ENUM_LEN);

	return c;
}