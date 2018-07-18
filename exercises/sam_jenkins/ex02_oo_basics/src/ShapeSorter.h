#ifndef GUARD_ShapeSorter_h
#define GUARD_ShapeSorter_h
#include "Shapes.h"
#include <memory>
#include <vector>
class ShapeSorter {
public:
	using ShapeVec = std::vector<std::unique_ptr<Shapes>>;
	void typePrint(const std::string &type,const ShapeVec &shapes);
	void sidesPrint(const int &sides,const ShapeVec &shapes);
	void areaSort(ShapeVec &shapes);
	void perimiterSort(ShapeVec &shapes);
};




#endif

