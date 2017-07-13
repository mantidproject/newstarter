#ifndef SHAPE_H
#define SHAPE_H

#include <string>


class Shape
{
public:
	Shape(std::string type, int sideCount);
	virtual ~Shape();

	std::string getType() const;
	int getSideCount() const;
	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print() const;

private:
	int m_sideCount;
	std::string m_type;

	

};
#endif
