#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape
{
private:
    std::string m_type;
public:
    Shape(std::string type);
    std::string getType();
};

#endif /*SHAPE_H_*/