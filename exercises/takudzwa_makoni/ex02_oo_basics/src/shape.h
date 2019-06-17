#ifndef SHAPE_H
#define SHAPE_H




class shape {

public:
	virtual unsigned int numOfSides() const = 0; 
	virtual std::string name() const = 0;

	virtual double area() const = 0;
	virtual double perimeter() const = 0;

};

#endif