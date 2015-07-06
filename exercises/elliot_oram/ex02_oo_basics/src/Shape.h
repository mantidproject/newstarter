#ifndef SHAPE_H
#define	SHAPE_H
/********************************INCLUDES***********************************/
#include <string>

/*******************************CLASS HEADER********************************/
class Shape{
public:
	Shape();		//Default constructor
	~Shape();
	
	std::string getType();	
	int getSides();
	double getArea();
	double getPerimeter();
	double getHeight();
	double getWidth();
	void setType(const std::string &t);
	void setSides(const int &s);
	void setArea(const double &a);
	void setPerimeter(const double &p);
	void setWidth(const double &w);
	void setHeight(const double &h);
	virtual void print();

private:
	std::string type;
	int sides;
	double area, perimeter, height, width;
};

/**********************************END OF FILE*******************************/

#endif SHAPE_H 