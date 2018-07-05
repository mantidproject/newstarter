#ifndef HEADER_SHAPE
#define HEADER_SHAPE

/*
Shape class
*/
class Shape {

public:
	//virtual Shape() = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
	int get_sides();
	std::string get_type();
	void print_shape(std::ostream &OutputStream);

protected:
	int sides;
	std::string type;
};

#endif