#ifndef SHAPE_H
#define SHAPE_H

class shape {

public:
	virtual int getNumOfSides() const = 0; 
	virtual std::string getName() const = 0;

	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;

};

#endif