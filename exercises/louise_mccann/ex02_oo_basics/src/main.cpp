#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include <algorithm>

using namespace std;

//defines a general shape class
class Shape
{
public:
	Shape() {};
	virtual double perimeter() { return 0; };
	virtual double area() const { return 0; }
	virtual string type() { return 0; };
	virtual ~Shape() {};
};

const double pi = 3.14159265359;

//defines classes for for shapes
class Square : virtual public Shape {
	double side;
public:
	Square(double s) { side = s; }
	string type() { return "Square"; }
	double perimeter() { return (4 * side); }
	double area() const { return (side * side); }
};

class Rectangle : virtual public Shape {
	double side1;
	double side2;
public:
	Rectangle(double s1, double s2) { side1 = s1, side2 = s2; }
	string type() { return "Rectangle"; }
	double perimeter() { return (2 * (side1 + side2)); }
	double area() const { return (side1 * side2); }
};

class Circle : virtual public Shape {
	double radius;
public:
	Circle(double r) { radius = r; }
	string type() { return "Circle"; }
	double perimeter() { return (2 * pi * radius); }
	double area() const { return (pi * radius * radius); }
};

class Triangle : virtual public Shape {
	double base;
	double height;
public:
	Triangle(double b, double h) { base = b, height = h; }
	string type() { return "Triangle"; }
	double perimeter() { return (base + 2 * sqrt(pow(height, 2) + (pow(base, 2) / 4))); }
	double area() const { return(base * height / 2); }
};

//prints out shape data
void ShapeInfo(Shape* s) {
	cout << s->type() << ":" << endl;
	cout << "Area: " << s->area();
	cout << ", Perimeter: " << s->perimeter() << endl;
}
// functions to sort list of shapes
bool compArea(Shape* a1, Shape* a2) {
	return a1->area() > a2->area();
}
bool compPerim(Shape* p1, Shape* p2) {
	return p1->perimeter() > p2->perimeter();
}
bool compType(Shape* t1, Shape* t2) {
	return t1->type() < t2->type();
}

int main()
{

	Rectangle rec(10, 7);
	Triangle  tri(10, 5);
	Circle circ(3.0);
	Square squ(6.0);

	//puts shapes in a list
	list<Shape*> ShapeList;

	ShapeList.push_back(&rec);
	ShapeList.push_back(&tri);
	ShapeList.push_back(&circ);
	ShapeList.push_back(&squ);

	cout << "Please enter the number which corresponds to how you want" << endl;
	cout << "the shapes to be sorted." << endl;
	cout << "1. Name \n" << "2. Area \n" << "3. Perimeter \n";

	//sorts shapes in list accordingly
	int x;
	cin >> x;
	switch (x) {
	case 1:
		ShapeList.sort(compType);
		cout << " " << endl << "----------------Sorted By Name----------------" << endl;
		for_each(ShapeList.begin(), ShapeList.end(), ShapeInfo);
		break;
	case 2:
		ShapeList.sort(compArea);
		cout << " " << endl << "----------------Sorted By Area----------------" << endl;
		for_each(ShapeList.begin(), ShapeList.end(), ShapeInfo);
		break;
	case 3:
		ShapeList.sort(compPerim);
		cout << " " << endl << "----------------Sorted By Perimeter----------------" << endl;
		for_each(ShapeList.begin(), ShapeList.end(), ShapeInfo);
		break;
	default:
		cout << "Invalid input" << endl;
		return 1;
	}
	return 0;
}