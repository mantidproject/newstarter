//Base file for shapes to inherit from
#ifndef GUARD_Shapes_h
#define GUARD_Shapes_h
#include <string>
class Shapes {
public:
	Shapes();
	virtual double calcPerimiter()=0;
	virtual double calcArea()=0;
	virtual std::string print() = 0;
	std::string getType();
	
	int getSides();
protected:
	std::string type;
	int sides;
};
#endif