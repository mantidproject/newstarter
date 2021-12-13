#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <ctime>

class shape{
public:
	int sideNo() const{
		return _sideNo;
	}

	std::string shapeType() const{
		return _shapeType;
	}

	virtual float perimiter() const = 0;
	
	virtual float area() const = 0;

	virtual void print() const = 0;

protected:
	std::string _shapeType;
	int _sideNo;

	shape() {};
};

class square : public shape {
public:
	square(const float& side1Len)
		:_side1Len{side1Len} {
		_shapeType = "square";
		_sideNo = 4;
	}

	float perimiter() const override {
		return pow(_side1Len, 2);
	}

	float area() const override {
		return _side1Len * 4;
	}

	void print() const override {
		std::cout << _shapeType << " - side: " << _side1Len << " - area: " << area() << "- perimiter: " << perimiter() << std::endl;
	}

private:
		float _side1Len;
};

class triangle : public shape {
public:
	triangle(const float& height, const float& base)
		:_height{ height }, _base{ base } {
		_shapeType = "triangle";
		_sideNo = 3;
	}

	float perimiter() const override {
		return _base + 2/sqrt(pow(_height,2) + (pow(_base,2)/4));
	}

	float area() const override {
		return _base * _height;
	}

	void print() const override {
		std::cout << _shapeType << " - height: " << _height << " base: " << _base << " - area: " << area() << "- perimiter: " << perimiter() << std::endl;
	}

private:
	float _height;
	float _base;
};

class rectangle : public shape {
public:
	rectangle(const float& side1Len, const float& side2Len) 
		:_side1Len{ side1Len }, _side2Len{ side2Len } {
		_shapeType = "rectangle";
		_sideNo = 4;
	}

	float perimiter() const override {
		return (_side1Len * 2) + (_side2Len * 2);
	}

	float area() const override {
		return _side1Len * _side2Len;
	}

	void print() const override {
		std::cout << _shapeType << " - side 1: " << _side1Len << " side 2: " << _side2Len << " - area: " << area() << "- perimiter: " << perimiter() << std::endl;
	}

private:
	float _side1Len;
	float _side2Len;
};

class circle : public shape {
public:
	circle(const float& radius) 
		:_radius{radius} {
		_shapeType = "circle";
		_sideNo = 1;
	}

	float perimiter() const override {
		return M_PI * 2 * _radius;
	}

	float area() const override {
		return M_PI * pow(_radius,2);
	}

	void print() const override {
		std::cout << _shapeType << " - radius: " << _radius << " - area: " << area() << "- perimiter: " << perimiter() << std::endl;
	}

private:
	float _radius;
};

class shapeSorter {
public:
	shapeSorter(std::vector<shape*>& shapes)
		:_shapes{ shapes }{}

	void printShapes(std::string shapeType) {
		std::vector<shape*>::iterator it;

		for (it = _shapes.begin(); it != _shapes.end(); ++it) {
			if ((*it)->shapeType() == shapeType) {
				(*it)->print();
			}
		}
	}

	void printShapes(int sideNo) {
		std::vector<shape*>::iterator it;

		for(it = _shapes.begin(); it != _shapes.end(); ++it) {
			if ((*it)->sideNo() == sideNo) {
				(*it)->print();
			}
		}
	}

	void printAreaDecending() {
		std::sort(_shapes.begin(), _shapes.end(), dec_area_sort());
		printShapes();
	}

	void printPerimiterDecending() {
		std::sort(_shapes.begin(), _shapes.end(), dec_perimiter_sort());
		printShapes();
	}

private:
	std::vector<shape*>& _shapes;

	void printShapes() {
		std::vector<shape*>::iterator it;

		for (it = _shapes.begin(); it != _shapes.end(); ++it) {
			(*it)->print();
		}
	}

	struct dec_area_sort
	{
		bool operator() (shape* shape1, shape* shape2)
		{
			return (shape1->area() > shape2->area());
		}
	};

	struct dec_perimiter_sort
	{
		bool operator() (shape* shape1, shape* shape2)
		{
			return (shape1->perimiter() > shape2->perimiter());
		}
	};
};

class shapeGenerator{
public: 
	shapeGenerator() {
		srand((unsigned)time(0));
	}

	void generateShapes(const int& shapeNo, const float& maxLength) {
		for (int i = 0; i < shapeNo; i++) {
			int x = rand() % 4;

			switch (x) {
				case 0: //square
					_shapes.push_back(new square(randomFloat(1.0, maxLength)));
				case 1: //rectangle
					_shapes.push_back(new rectangle(randomFloat(1.0, maxLength), randomFloat(1.0, maxLength)));
				case 2: //triangle
					_shapes.push_back(new triangle(randomFloat(1.0, maxLength), randomFloat(1.0, maxLength)));
				case 3: //circle
					_shapes.push_back(new circle(randomFloat(1.0, maxLength)));
			}
		}
	}

	std::vector<shape*> returnShapes() {
		return _shapes;
	}

private:
	std::vector<shape*> _shapes;

	float randomFloat(float a, float b) {
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = b - a;
		float r = random * diff;
		return a + r;
	}

};


int main() {

	//INPUT PARAMETERS
	int shapeNo = 10;
	float maxLength = 4.0;
	int searchSides = 4;
	std::string searchType = "circle";
	
	//GENERATE SHAPES
	shapeGenerator testGenerator;
	testGenerator.generateShapes(shapeNo, maxLength);

	std::vector<shape*> shapes = testGenerator.returnShapes();

	//SORT SHAPES
	shapeSorter testSorter(shapes);

	std::cout << "Search Sides: " << std::endl;
	testSorter.printShapes(searchSides);

	std::cout << std::endl << "Search Type: " << std::endl;
	testSorter.printShapes(searchType);

	std::cout << std::endl << "Area Decending: " << std::endl;
	testSorter.printAreaDecending();

	std::cout << std::endl << "Perimiter Decending: " << std::endl;
	testSorter.printPerimiterDecending();

	return 0;
}