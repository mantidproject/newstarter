#ifndef SHAPES_H_
#define SHAPES_H_

#include <string>
#include <vector>
#include <memory>
#include <math.h>  

class BaseShape{
public:
    // Constructor
    BaseShape();
    virtual ~BaseShape() = default ;
    // Getters
    virtual int getNumSides() const = 0;
    virtual std::string getShapeName() const =0;
    // Return private members area and perimeter
    double getArea() const;
    double getPerimeter() const;
    // Print shape information
    virtual void printShapeDimensions() const = 0;
protected:
	void setArea(double area) {this->m_area = area;}
	void setPerimeter(double perimeter) {this->m_perimeter = perimeter;}
private:
	double m_area;
	double m_perimeter;

};
#endif