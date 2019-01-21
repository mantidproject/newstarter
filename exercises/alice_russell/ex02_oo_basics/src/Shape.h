#pragma once

#include <string>

class Shape {
public:
	virtual double find_perimeter() const = 0;
	virtual double find_area() const = 0;
	virtual std::string get_type() const = 0;
	virtual unsigned int get_sides() const = 0;
	void print_details(std::ostream & out);
};
