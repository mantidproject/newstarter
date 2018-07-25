#include <string>
#include "Shapes.h"
	Shapes::Shapes(const std::string type, int sides) :type(type), sides(sides) {};
	std::string Shapes::getType()const
	{
		return type;
	}

	
	
