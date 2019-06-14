#ifndef CIRCLE_H
#define CIRCLE_H

class circle : public shape { // circle class

private:

	
	const std::string name;
	const int numOfSides;
	const double pi = 3.14159;

public:

	double radius;

	virtual int getNumOfSides() const override { return numOfSides; }
	virtual std::string getName() const override { return name; }

	virtual double getArea() const override { return pi * radius * radius; }
	virtual double getPerimeter() const override { return pi * 2 * radius; }

	//constructor
	circle::circle() : name("circle"), numOfSides(1) {

		radius = 1;
	};

};

#endif