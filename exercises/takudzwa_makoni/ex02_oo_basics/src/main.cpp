
//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>

const double pi = (double)3.14159; // constant Pi casted to double
using namespace std;



//------------------------- shape class -----------------------------------

class shape {

public:
	virtual void getNumOfSides()	{ cout << "override" << endl; }
	virtual void getName()			{ cout << "override" << endl; }

	virtual void getArea()			{ cout << "override" << endl; }
	virtual void getPerimeter()		{ cout << "override" << endl; }
};


//--------------------------------------------------------------------------

//------------------------- shape subclasses -------------------------------

class square : public shape {

private:

	double sideLength;
	string name;
	int numOfSides;

public:

	virtual void getNumOfSides() { cout << numOfSides << endl; }
	virtual void getName() { cout << name << endl; }

	virtual void getArea() { cout << sideLength * sideLength << endl; }
	virtual void getPerimeter() { cout << 4 * sideLength << endl; }

	//contructor
	square::square() {
		sideLength = 1;
		name = "square";
		numOfSides = 4;
	};
};

class rectangle : public shape {

private:

	double sideWidth, sideHeight;
	string name;
	int numOfSides;

public:

	virtual void getNumOfSides() { cout << numOfSides << endl; }
	virtual void getName() { cout << name << endl; }

	virtual void getArea()		{ cout << sideHeight * sideWidth << endl; }
	virtual void getPerimeter()	{ cout << (2 * sideWidth) + (2 * sideHeight) << endl; }

	rectangle::rectangle() {
		sideWidth = 1;
		sideHeight = 2;
		name = "rectangle";
		numOfSides = 4;
	};
};

class isoTriangle : public shape { // isosceles triangle class

private:

	double base, height;
	string name;
	int numOfSides;


public:

	virtual void getNumOfSides()	{ cout << numOfSides << endl; }
	virtual void getName()			{ cout << name << endl; }

	virtual void getArea()		{ cout << 0.5 * base* height << endl; }
	virtual void getPerimeter() { cout << 2 * (sqrt(height * height) + ((base * base) / 4)) << endl; }

	//constructor
	isoTriangle::isoTriangle() {
		base	= 1;
		height	= 2;
		name = "isosceles-triangle";
		numOfSides = 3;
	};
};


class circle : public shape { // circle class

private:

	double radius;
	string name;
	int numOfSides;

public:

	virtual void getNumOfSides() { cout << numOfSides << endl; }
	virtual void getName() { cout << name << endl; }

	virtual void getArea() { cout << pi * radius * radius << endl; }
	virtual void getPerimeter() { cout << pi * 2 * radius << endl; }

	//constructor
	circle::circle() {
		radius = 1;
		name = "circle";
		numOfSides = 1;
	};

};

//--------------------------------------------------------------

//------------------- function definitions ---------------------


void printMatchForType(vector<shape>& shapes) {};		// print match for type. Wont mutate vector so will pass by reference.
void printMatchForSide(vector<shape>& shapes) {};		// print match for number of side
void printOrderForVol(vector<shape>& shapes) {};		// print order for volume (descending)
void printorderForPerim(vector<shape>& shapes) {};		// print order for perimeter (descending)


//------------------------- main -------------------------------

int main() {


	square x;
	circle y;
	rectangle z;
	isoTriangle p;

	vector<shape*> shapeVector({ &x, &y, &z, &p });
	
	for (vector<shape>::size_type i = 0; i != shapeVector.size(); i++) //using indices for random access optimisation. size_type for correct memory allocation.
	{
		shapeVector[i]->getName();
	}
	
	cin.get();
	return 0;
}

//{ return 2 * (sqrt(height * height) + ((base * base) / 4)); }