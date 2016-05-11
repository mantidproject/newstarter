#ifndef CLASS_SHAPEBASE
#define CLASS_SHAPEBASE
#include <string>

class ShapeBase {
    friend class Shape;
protected:
    std::string type;
    int nSides;
    virtual ShapeBase* clone() const {return new ShapeBase(*this);}
public:
    ShapeBase() : type(""), nSides(0) {}
    double GetNSides() const {return nSides;}
    std::string GetType() const {return type;}
    virtual double ComputeArea() const {return 0;}
    virtual double ComputePerimeter() const {return 0;}
    virtual ~ShapeBase() {}

};

#endif
