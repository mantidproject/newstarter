#include "main.h"

int main(int, char **)
{
	vector<Shape*> shapeVector;
	Square square1 = Square(10);
	Triangle triangle1 = Triangle(3, 4);
	Rectangle rectangle1 = Rectangle(6, 8);
	Circle circle1 = Circle(5);
	Square square2 = Square(15);
	Triangle triangle2 = Triangle(6, 8);
	Rectangle rectangle2 = Rectangle(3, 5);
	Circle circle2 = Circle(25);

	shapeVector.push_back(&square1);
	shapeVector.push_back(&triangle1);
	shapeVector.push_back(&rectangle1);
	shapeVector.push_back(&circle1);
	shapeVector.push_back(&square2);
	shapeVector.push_back(&triangle2);
	shapeVector.push_back(&rectangle2);
	shapeVector.push_back(&circle2);

	ShapeSorter ss;
	ss.matchType("Triangle", shapeVector);
}
