#pragma once
#include <math.h>
#include <string>
#include <typeinfo>
using namespace std;

class Shape {
public:
	int Sides() const;
	double Perimeter() const;
	double Area() const;
	string Str() const;
	virtual string Type() const = 0;
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
	string Type() const override;
	static string RectangleStr;
};

class Square : public Rectangle {
public:
	Square(double sideLength);
	string Type() const override;
	static string SquareStr;
};

class Circle : public Shape {
public:
	Circle(double radius);
	string Type() const override;
	static string CircleStr;
};

class Triangle : public Shape {
public:
	Triangle(double height, double base);
	string Type() const override;
	static string TriangleStr;
};