/* 
* File:   main.cpp
* Author: Elliot Oram
*/

/*Includes*/
#include <vector>
#include "Shape.h"
#include "Square.h"


std::vector<Shape*> addShape(std::vector<Shape*> shapes, Shape* s){
	shapes.push_back(s);
}

Square* createSqaure(int height){
	return new Square("Square", 4, height, height);
}

void printAllShapes(std::vector<Shape> shapes){
	for(int i = 0 ; i < shapes.size(); i++){

	}
}


int main(int, char **)
{
	std::vector<Shape*> shapes;
	Square* s;
	s = createSqaure(2);
	addShape(shapes, s);

	
}