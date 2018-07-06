#ifndef GUARD_ShapeSorter_h
#define GUARD_ShapeSorter_h
#include "Shapes.h"
#include <vector>
class ShapeSorter {
public:
	static void typePrint(std::string type,std::vector<Shapes*> shapes);
	static void sidesPrint(int sides, std::vector<Shapes*> shapes);
	static void areaSort(std::vector<Shapes*> shapes);
	static void perimiterSort(std::vector<Shapes*> shapes);
};




#endif

