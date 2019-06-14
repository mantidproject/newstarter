#ifndef ISOTRIANGLE_H
#define ISOTRIANGLE_H

class isoTriangle : public shape { // isosceles triangle class

private:

	
	const std::string name;
	const int numOfSides;


public:

	double base, height;

	virtual int getNumOfSides() const override{ return numOfSides; }
	virtual std::string getName() const override{ return name; }

	virtual double getArea()	const override { return 0.5 * base* height; }
	virtual double getPerimeter() const override{ return 2 * (sqrt(height * height) + ((base * base) / 4)); }

	//constructor
	isoTriangle::isoTriangle() : name("isosceles-triangle"), numOfSides(3) {

		//empty

	};
};

#endif