#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

/**
* A class to represent shapes
*/
class Shape {
public:
	virtual double perimeter() const = 0; 
	virtual double area() const = 0; 
	virtual std::string type() const = 0; 
	virtual unsigned int sides() const = 0;
	void print_details(std::ostream & out) const;
};

#endif //SHAPE_H_