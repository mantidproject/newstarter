#ifndef SHAPE_H
#define SHAPE_H

#include <string>


class Shape abstract
{
public:
	Shape(std::string type, int sideCount);
	virtual ~Shape() = default;

	std::string getType() const;
	int getSideCount() const;
	virtual double calcArea() const = 0;
	virtual double calcPerimeter() const = 0;
	virtual void print() const = 0;

protected:
	int m_sideCount;
	std::string m_type;

	
};
#endif
