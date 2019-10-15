#ifndef SHAPES_H_
#define SHAPES_H_

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <math.h>  

namespace{

    const double PI  =3.141592653589793238463;

}


class BaseShape{

public:
    
    // Constructor
    BaseShape();
    virtual ~BaseShape() = 0 ;

    // Getters
    virtual int getNumSides() const = 0;
    virtual std::string getShapeName() const =0;
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

// Circle class
class Circle : public BaseShape
{
public:

    static const std::string SHAPENAME;
    static const int NUMSIDES;


    // Constructors
    Circle();
    Circle(const double radius);


    // Getters
    int getNumSides() const override;
    std::string getShapeName() const override;


    // Print shape information
    void printShapeDimensions() const override;


private:

    // Radius
    double m_radius;
    // Area
    double m_area;

    // Perimeter
    double m_perimeter;

    // Private method to calculate area
    double calculateArea()
    {
        return PI*m_radius*m_radius;
    }
    // Private method to calculate perimeter
    double calculatePerimeter()
    {
        return 2*PI*m_radius;

    }
};


// Rectangle
class Rectangle : public BaseShape
{
public:

    static const std::string SHAPENAME;
    static const int NUMSIDES;


    // Constructors
    Rectangle();
    Rectangle(const double width, const double depth);


    // Getters
    int getNumSides() const override;
    std::string getShapeName() const override;


    // Print shape information
    void printShapeDimensions() const override;

private:

    // Width
    double m_width;
    // Depth
    double m_depth;
 
    // Private method to calculate area
    double calculateArea() 
    {
        return m_width*m_depth;
    }
    // Private method to calculate perimeter
    double calculatePerimeter() 
    {
        return  m_width*2 + m_depth*2;

    }
};


// Square
class Square : public BaseShape
{
public:

    static const std::string SHAPENAME;
    static const int NUMSIDES;


    // Constructors
    Square();
    Square(const double sideLength);


    // Getters
    int getNumSides() const override;
    std::string getShapeName() const override;

    // Print shape information
    void printShapeDimensions() const override;


private:

    double m_sideLength;

    // Private method to calculate area
    double calculateArea() 
    {
        return m_sideLength*m_sideLength;
    }
    // Private method to calculate perimeter
    double calculatePerimeter() 
    {
        return 4*m_sideLength;

    }

};

// Triangle
class Triangle : public BaseShape
{
public:

    static const std::string SHAPENAME;
    static const int NUMSIDES;


    // Constructors
    Triangle();
    Triangle(const double base, const double height);


    // Getters
    int getNumSides() const override;
    std::string getShapeName() const override;

    // Print shape information
    void printShapeDimensions() const override;

private:
    double m_base;
    double m_height;


    // Private method to calculate area
    double calculateArea() 
    {
        return (1.00/2.00) * (m_base*m_height);
    }
    // Private method to calculate perimeter
    double calculatePerimeter() 
    {
        return m_base + 2*sqrt(m_height*m_height + 0.25*m_base*m_base);

    }


};



#endif