#ifndef GUARD_Triangle_h
#define GUARD_Triangle_h
#include "Shapes.h"
class Triangle : public Shapes {
public:
	Triangle();
	Triangle(double base, double height);
	double calcPerimiter() const;
	double calcArea() const;
private:
	double height;
	double base;
};
#endif