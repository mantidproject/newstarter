#pragma once

#include "ShapeImplementationCommon.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

class Shape
{
public:
	~Shape();
	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;
	virtual std::string GetType() const = 0;
	virtual int GetNumSides() const = 0;
	virtual std::string GetMessage() const = 0;
	virtual Shape* clone() const = 0;
	friend std::ostream &operator<<(std::ostream &os, const Shape &shape);
};
