#ifndef SHAPE_H
#define SHAPE_H
using namespace std;
#include <string>

class Shape
{
protected:
	string name;
	int sides;
	double area;
	double perimeter;
public:
	Shape(string name, int sides);
	//virtual ~Shape();
	virtual void setType(std::string s);
	virtual string getType()const; 
	virtual void setSides(int sides);
	virtual int getSides()const; 
	virtual double getArea()const;
	virtual double getPerimeter()const;
};

#endif