#pragma once
#include <string>
#include <iostream>


class Shape
{
public:
	Shape();
	Shape(std::string type, int sideCount);
	~Shape();

	std::string getType() const;
	int getSideCount() const;
	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print() const;

private:
	int sideCount;
	std::string type;

	

};

