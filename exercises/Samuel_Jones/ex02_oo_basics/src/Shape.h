#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape
{
private:
    std::string m_type;
public:
    Shape(std::string type);
    std::string getType() const;
    virtual ~Shape() = default;
    virtual double getPerimeter() const;
    virtual double getArea() const;
};

#endif /*SHAPE_H_*/