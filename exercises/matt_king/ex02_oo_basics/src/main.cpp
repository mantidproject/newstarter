/**
* Skeleton main routine
*/
#include <iostream>

template <class S>class ShapeSorter{
public:
	ShapeSorter();
	std::string printShapesThatMatchType(std::string type) const{};
	std::string printShapesThatMatchSides(int sides) const{};
	std::string printAreasDesc() const{};
	std::string printPerimeterDesc() const{};
private:
	bool compare(S thisShape, S anotherShape){};
};

class Shape{
public:
	Shape();
	Shape(std::string type){shapeType = type;};
private:
	std::string shapeType;
	double area;
	double perimeter;
};

class Square: public Shape{
public:
	Square();
	Square(std::string type, int side);
private:
	int side;
};

class Rectangle: public Shape{
public:
	Rectangle();
	Rectangle(std::string type, int sideOne, int sideTwo);
private:
	int sideOne;
	int sideTwo;
};

class Circle: public Shape{
public:
	Circle();
	Circle(std::string type, int radius);
private:
	int radius;
};


class Triangle: public Shape{
public:
	Triangle();
	Triangle(std::string type, int base, int height);
private:
	int base;
	int height;
};

int main(int, char **)
{
	Shape s("Circle");
	std::cout << "Hello";
}