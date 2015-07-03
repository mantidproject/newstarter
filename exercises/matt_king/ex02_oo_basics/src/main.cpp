/**
* Skeleton main routine
*/
#include <iostream>

template <class S> class ShapeSorter{
public:
	std::string printShapesThatMatchType(string type) const{};
	std::string printShapesThatMatchSides(int sides) const{};
	std::string printAreasDesc() const{};
	std::string printPerimeterDesc() const{};
private:
	bool compare(S thisShape, S anotherShape){};
};

class Shape{
	Shape();
	Shape(std::string type);
};

class Square: public Shape{
	Square();
	Square(std::string type, int side);
};

class Rectangle: public Shape{
	Rectangle();
	Rectangle(std::string type, int sideOne, int sideTwo);
};

class Circle: public Shape{
	Circle();
	Circle(std::string type, int radius);
};

class Triangle: public Shape{
	Triangle();
	Triangle(std::string type, int base, int height);
};

int main(int, char **)
{
	std::cout << "Hello";
}