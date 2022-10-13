#pragma once
#include <string>

class Shape {
public:
	Shape(const int sides, const std::string& name);
	virtual ~Shape() {};

	const std::string& getName() const;
	int getSides() const;
	double getArea() const;
	double getPerimeter() const;

	void print() const;

private:
	int m_sides;
	std::string m_name;

protected:
	virtual void calcArea() = 0;
	virtual void calcPerimeter() = 0;
	double m_area;
	double m_perimeter;
};

