#include <string>
#include "Shapes.h"
	Shapes::Shapes() :type("undefined"), sides(0) {};
	std::string Shapes::getType()const
	{
		return type;
	}
	int Shapes::getSides()const
	{
		return sides;
	}
	
	
