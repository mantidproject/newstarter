#include "main.h"

using namespace std;

int main(int, char **)
{
	vector<Shape*> shapeVector;
	shapeVector.push_back(&Square(10));
	shapeVector.push_back(&Triangle(3, 4));
	shapeVector.push_back(&Rectangle(6, 8));
	shapeVector.push_back(&Circle(5));
	shapeVector.push_back(&Square(15));
	shapeVector.push_back(&Triangle(6, 8));
	shapeVector.push_back(&Rectangle(3, 5));
	shapeVector.push_back(&Circle(25));

	ShapeSorter ss;
	ss.matchType("Triangle", shapeVector);
}
