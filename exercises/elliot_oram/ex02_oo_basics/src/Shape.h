#include <string>


class Shape{
public:
	Shape(std::string t, int s);
	~Shape();
	
	std::string getType();
	int getSides();
	double getArea();
	double getPerimiter();

private:
	std::string type;
	int sides;
	double area, perimeter, height, width;
};