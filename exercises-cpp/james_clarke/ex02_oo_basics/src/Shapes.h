#pragma once
#include <math.h>

class Shape {
public:
	int Sides();
	double Perimeter();
	double Area();
protected:
	Shape();
	void setSides(int sides);
	void setPerimeter(double perimeter);
	void setArea(double area);
private:
	int _sides;
	double _perimeter;
	double _area;
};

class Rectangle : public Shape {
public:
	Rectangle(double sideLength, double otherSideLength);
};

class Square : public Rectangle {
public:
	Square(double sideLength);
};

class Circle : public Shape {
public:
	Circle(double radius);
};

class Triangle : public Shape {
public:
	Triangle(double height, double base);
};