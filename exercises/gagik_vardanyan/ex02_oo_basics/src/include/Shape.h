#ifndef CLASS_SHAPE
#define CLASS_SHAPE
#include "ShapeBase.h"

class Shape {
public:
    Shape() : cp(0) {}
    Shape(const Shape& s) : cp(0) {if(s.cp) cp = s.cp->clone();}
    Shape(ShapeBase * sh) {cp = sh;}
    ~Shape() {delete cp;}
    Shape& operator=(const Shape& s)
    {
        if(&s != this)
        {
            delete cp;
            if(s.cp)
                cp = s.cp->clone();
            else cp = 0;
        }
        return *this;
    }
    std::string GetType() const {return cp->GetType();}
    double GetNSides() const {return cp->GetNSides();}
    double ComputeArea() const {
        if(cp) return cp->ComputeArea();
        else throw std::runtime_error("Uninitialized Shape");
    }
    double ComputePerimeter() const {
        if(cp) return cp->ComputePerimeter();
        else throw std::runtime_error("Uninitialized Shape");
    }
    static bool CompareArea(const Shape& sh1, const Shape& sh2) {
        return sh1.ComputeArea() > sh2.ComputeArea();
    }
    static bool ComparePerimeter(const Shape& sh1, const Shape& sh2) {
        return sh1.ComputePerimeter() > sh2.ComputePerimeter();
    }
private:
    ShapeBase * cp;
};

#endif
