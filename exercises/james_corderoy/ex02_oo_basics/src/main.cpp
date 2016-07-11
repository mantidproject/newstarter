#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

#define PI 3.14159265359f


class shape
{
	public:
	
	virtual std::string type() const = 0;
	virtual int nSides() const = 0;
	virtual float perimeter() const = 0;
	virtual float area() const = 0;
	
	friend std::ostream& operator<<(std::ostream& os, const shape& sh);
};

std::ostream& operator<<(std::ostream& os, const shape& sh)
{
	os << "Type: " << sh.type() << ", sides: " << sh.nSides() << ", perimeter: " << sh.perimeter() << ", area: " << sh.area();
	return os;
}


class square: public shape
{
	public:
	
	float side;
	
	square(float iside) { side = iside; }
	
	std::string type() const { return "Square"; }
	int nSides() const { return 4; }
	float perimeter() const { return 4.0f * side; }
	float area() const { return side * side; }
	
};

class rectangle: public shape
{
	public:
	
	float side1, side2;
	
	rectangle(float iside1, float iside2) { side1 = iside1; side2 = iside2; }
	
	std::string type() const { return "Rectangle"; }
	int nSides() const { return 4; }
	float perimeter() const { return 2.0f * side1 + 2.0f * side2; }
	float area() const { return side1 * side2; }
	
};

class circle: public shape
{
	public:
	
	float radius;
	
	circle(float iradius) { radius = iradius; }
	
	std::string type() const { return "Circle"; }
	int nSides() const { return 1; }
	float perimeter() const { return 2.0f * PI * radius; }
	float area() const { return PI * radius * radius ; }
	
};

class triangle: public shape
{
	public:
	
	float base, height;
	
	triangle(float iheight, float ibase) { height = iheight; base = ibase; }
	
	std::string type() const { return "Triangle"; }
	int nSides() const { return 3; }
	float perimeter() const { return base + 2.0f * sqrt(height*height + base*base / 4.0f); }
	float area() const { return 0.5f * base * height; }
	
};


bool areaGT (const shape* i, const shape* j) {return i->area() > j->area(); }
bool perimGT (const shape* i, const shape* j) {return i->perimeter() > j->perimeter(); }

class ShapeSorter
{
	public:
	
	void printOfType(const std::vector<shape*> &shapeVector, const std::string type)
	{
		for (std::vector<shape*>::const_iterator it = shapeVector.begin(); it != shapeVector.end(); ++it)
			if ((*it)->type() == type)
				std::cout << **it << std::endl;		
	}
	
	void printOfNSides(const std::vector<shape*> &shapeVector, const int nSides)
	{
		for (std::vector<shape*>::const_iterator it = shapeVector.begin(); it != shapeVector.end(); ++it)
			if ((*it)->nSides() == nSides)
				std::cout << **it << std::endl;		
	}
	
	void printSortedByArea(const std::vector<shape*> &shapeVector)
	{
		std::vector<shape*> sorted = shapeVector;
		std::sort(sorted.begin(), sorted.end(), areaGT);
		for (std::vector<shape*>::const_iterator it = sorted.begin(); it != sorted.end(); ++it)
			std::cout << **it << std::endl;		
	}
	
	void printSortedByPerimeter(const std::vector<shape*> &shapeVector)
	{
		std::vector<shape*> sorted = shapeVector;
		std::sort(sorted.begin(), sorted.end(), perimGT);
		for (std::vector<shape*>::const_iterator it = sorted.begin(); it != sorted.end(); ++it)
			std::cout << **it << std::endl;		
	}
};




int main(int argc, char ** argv)
{
	std::vector<shape*> shv;
	shv.push_back(new square(10.0f));
	shv.push_back(new circle(2.0f));
	shv.push_back(new rectangle(5.0f, 3.0f));
	shv.push_back(new triangle(5.0f, 15.0f));
	
	ShapeSorter sorter;
	sorter.printOfNSides(shv, 4);
	
	for (std::vector<shape*>::const_iterator it = shv.begin(); it != shv.end(); ++it)
		delete *it;
	
	return 0;
}