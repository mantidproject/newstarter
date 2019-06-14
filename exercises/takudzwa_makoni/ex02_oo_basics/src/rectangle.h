#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle : public shape {

private:

	
	const std::string name;
	const int numOfSides;

public:

	double sideWidth, sideHeight;

	virtual int getNumOfSides() const override{ return numOfSides; }
	virtual std::string getName() const override{ return name; }

	virtual double getArea() const override { return sideHeight * sideWidth; }
	virtual double getPerimeter()	const override { return (2 * sideWidth) + (2 * sideHeight); }

	rectangle::rectangle() : name("rectangle"), numOfSides(4) {

		sideWidth = 1;
		sideHeight = 2;
	};
};

#endif