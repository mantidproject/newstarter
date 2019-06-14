#ifndef SQUARE_H
#define SQUARE_H

class square : public shape {

private:

	const std::string name;
	const int numOfSides;

public:
	
	double sideLength;

	virtual int getNumOfSides() const override{ return numOfSides; }
	virtual std::string getName() const override { return name; }

	virtual double getArea() const override { return sideLength * sideLength; }
	virtual double getPerimeter() const override { return 4 * sideLength; }

	//contructor
	square::square() : name("square"), numOfSides(4) {
	
		sideLength = 1;
	
	};

};

#endif