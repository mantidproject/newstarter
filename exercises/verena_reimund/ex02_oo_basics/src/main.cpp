/**
* New type: Shapes (circle, ..) with functionality defined in class ShapeSorter
*/
#include <math.h>    //pow
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for_each
//#include <memory>  //smart pointers


// base class
class print{
public:// overloaded print functions
   void out (std::string type, double val);
   void out (std::string type, std::string val);
   void out (std::string type, double val1, double val2);
};

// abstract base class
class Shapes: public print{
   std::string n;
   double shape_area;
   double shape_perimeter;
   std::string n_sides;
public:
   Shapes(){}
   virtual std::string type() const {return n;}
   virtual std::string Square() const {return n_sides;}
   virtual double perimeter () const {return shape_perimeter;}
   virtual double area () const {return shape_area;}
   virtual ~Shapes(){}
};

// type definitions

typedef std::vector<Shapes*> collection; // std::unique_ptr
typedef std::vector<Shapes*>::size_type its;

// compare functions, const required
bool compare_strings (const std::string &s1, const std::string &s2){
   return s1.compare(s2)==0;
}

bool compare_volume (const Shapes *s1, const Shapes *s2){
   return s1->area()>s2->area();
}

bool compare_perimeter (const Shapes *s1, const Shapes *s2){
   return s1->perimeter()>s2->perimeter();
}

// class definitions

class rectangle: public Shapes{
   double side1;
   double side2;
public:
   rectangle(double x, double y) : side1(x), side2(y) {} // constructor
   rectangle(double z) : side1(z), side2(z) {} // constructor squares
   std::string type() const {return "Rectangle";}
   std::string Square() const {return "4";}
   double perimeter() const {return (2*(side1+side2));}
   double area() const {return (side1*side2);}
};

class circle: public Shapes{
   double radius;
public:
   explicit circle(double r) : radius(r) {} // constructor, default constructor disabled
   std::string type() const {return "Circle";}
   std::string Square() const {return "inf";}
   double perimeter() const {return(2*M_PI*radius);}
   double area() const {return (M_PI*pow(radius,2));}
};

class triangle: public Shapes{
   double height;
   double base;
public:
   triangle(double h, double b) : height(h), base(b) {}
   std::string type() const {return "Triangle";}
   std::string Square() const {return "3";}
   double perimeter() const {return(base+2*sqrt(pow(height,2.0)+pow(base,2.0)/4));}
   double area() const {return (height*base/2);}
};

class ShapeSorter: public Shapes{
   collection shapes;
public:
   explicit ShapeSorter(collection s) : shapes(s) {}
   void type(std::string select_type);
   void sides(std::string select_number_of_sides);
   void volume_dec();
   void perimeter_dec();
};

// member functions

void print::out(std::string type, double val) {
   std::cout << type << "\t" << val << std::endl;
}

void print::out(std::string type, double val1, double val2) {
   std::cout << type << "\t" << val1 << "\t" << val2 << std::endl;
}

void print::out(std::string type, std::string val) {
   std::cout << type << "\t" << val << std::endl;
}

// would like to print values of derived class members like side1, side2, .. using dynamic_cast

void ShapeSorter::type(std::string select_type){
  std::cout << "Shapes of type : " << select_type << std::endl;
  for(its i = 0; i!=shapes.size(); ++i){
    if (compare_strings(select_type,shapes[i]->type())){
      shapes[i]->out(shapes[i]->type(),shapes[i]->area());
    }
  }
  std::cout << '\n' << std::endl;
}

void ShapeSorter::sides(std::string number_of_sides){
  std::cout << "Shapes with number of sides : " << number_of_sides << std::endl;
  for(its i = 0; i!=shapes.size(); ++i){
    if (compare_strings(number_of_sides,shapes[i]->Square())){
      shapes[i]->out(shapes[i]->type(),shapes[i]->Square());
    }
  }
}

void ShapeSorter::volume_dec(){
  std::cout << "Volume of shapes in decreasing order : " << std::endl;
  sort(shapes.begin(),shapes.end(),compare_volume);
  for(its i = 0; i!=shapes.size(); ++i){
    shapes[i]->out(shapes[i]->type(),shapes[i]->area());
  }
  std::cout << '\n' << std::endl;
}

void ShapeSorter::perimeter_dec(){
  std::cout << "Perimeter of shapes in decreasing order : " << std::endl;
  sort(shapes.begin(),shapes.end(),compare_perimeter);
  for(its i = 0; i!=shapes.size(); ++i){
    shapes[i]->out(shapes[i]->type(),shapes[i]->perimeter());
  }
  std::cout << '\n' << std::endl;
}

// template function in order to delete classes
template <typename T>
void delete_shapes(T* const ptr){delete ptr;}

int main(int argc, char** argv){
  try{

   collection cshapes;

   cshapes.push_back(new rectangle(4.5,2.0));// std::make_unique
   cshapes.push_back(new rectangle(1.5,2.0));
   cshapes.push_back(new circle(3.0));
   cshapes.push_back(new rectangle(4.0));
   cshapes.push_back(new triangle(2.0,2.0));

   ShapeSorter shape_sorter(cshapes);
   shape_sorter.type("Rectangle");
   shape_sorter.sides("4");
   shape_sorter.volume_dec();
   shape_sorter.perimeter_dec();

   std::for_each(cshapes.begin(), cshapes.end(), delete_shapes<Shapes>); // required deletes
   return 0;
    
  }
  catch (std::exception const& ex) {//catch standard exception
    std::cout << "Exception: " << ex.what() <<std::endl;
    return -1;
  }

}
