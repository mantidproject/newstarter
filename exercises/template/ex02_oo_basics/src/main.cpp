/**
 * Skeleton main routine
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

class Shape {
public:
  virtual int sides() const = 0;
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  virtual string type() const = 0;
};

ostream &operator<<(ostream &os, const Shape *shape) {
  // Print the important parts of a shape
  os << "A " << shape->type();
  os << " with " << shape->sides() << " sides";
  os << ", a permieter of " << shape->perimeter();
  os << ", and and area of " << shape->area();
  return os;
}

class Circle : public Shape {
private:
  double radius;

public:
  explicit Circle(double r) { radius = r; }
  int sides() const override { return 1; }
  double perimeter() const override { return 2 * M_PI * radius; }
  double area() const override { return M_PI * radius * radius; }
  string type() const override { return "circle"; }
};

class Square : public Shape {
private:
  double side;

public:
  explicit Square(double s) { side = s; }
  int sides() const override { return 4; }
  double perimeter() const override { return 4 * side; }
  double area() const override { return side * side; }
  string type() const override { return "square"; }
};

class Rectangle : public Shape {
private:
  double width;
  double height;

public:
  explicit Rectangle(double w, double h) {
    width = w;
    height = h;
  }
  int sides() const override { return 4; }
  double perimeter() const override { return 2 * (width + height); }
  double area() const override { return width * height; }
  string type() const override { return "rectangle"; }
};

class Triangle : public Shape {
private:
  double base;
  double height;

public:
  explicit Triangle(double b, double h) {
    base = b;
    height = h;
  }
  int sides() const override { return 3; }
  double perimeter() const override {
    return base + 2 * sqrt(height * height + base * base / 4);
  }
  double area() const override { return 0.5 * base * height; }
  string type() const override { return "triangle"; }
};

class ShapeSorter {
private:
  vector<shared_ptr<Shape>> contents;

public:
  explicit ShapeSorter(vector<shared_ptr<Shape>> &c) : contents(c){};
  void print() {
    // print all shapes
    for (auto &shape : contents) {
      cout << shape << endl;
    }
  }
  void sides(int side_count) {
    // print shapes with given number of sides
    for_each(contents.begin(), contents.end(),
             [side_count](shared_ptr<Shape> value) {
               if (value->sides() == side_count)
                 cout << value << endl;
             });
  }
  void typed(const string &type) {
    // print shapes of a given type
    for_each(contents.begin(), contents.end(), [type](shared_ptr<Shape> value) {
      if (value->type() == type)
        cout << value << endl;
    });
  }

  void area_sort() {
    // Sort contents by area and print
    sort(contents.begin(), contents.end(),
         [](shared_ptr<Shape> a, shared_ptr<Shape> b) {
           return a->area() > b->area();
         });
    print();
  }

  void perimeter_sort() {
    // Sort contents by perimeter and print
    sort(contents.begin(), contents.end(),
         [](shared_ptr<Shape> a, shared_ptr<Shape> b) {
           return a->perimeter() > b->perimeter();
         });
    print();
  }
};

int main(int, char **) {
  vector<shared_ptr<Shape>> shapes;
  shapes.push_back(shared_ptr<Shape>(new Circle(5)));
  shapes.push_back(shared_ptr<Shape>(new Square(5)));
  shapes.push_back(shared_ptr<Shape>(new Rectangle(1, 11)));
  shapes.push_back(shared_ptr<Shape>(new Triangle(5, 6)));

  ShapeSorter sorter(shapes);
  sorter.sides(4);
  cout << endl;
  sorter.typed("circle");
  cout << endl;
  sorter.area_sort();
  cout << endl;
  sorter.perimeter_sort();
  cout << endl;
}
