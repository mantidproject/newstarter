
#ifndef MAIN_H
#define MAIN_H

#include "ShapeController.h"

#include <vector>
#include <iosfwd>

enum printOptions { TYPE, SIDES, DESC_VOL, DESC_PERIM, PRINT_ENUM_LEN };

//Tidy up function pointer for future use
using outputSortFuncPtr = std::vector<ShapeController>(*)(const std::vector<ShapeController>&,
	std::istream &inputSource);

int getPrintType();

void printShapeOutput(outputSortFuncPtr sortMethod, std::vector<ShapeController> const &inputVector);

//Output sorting methods
std::vector<ShapeController> sortOutputByType(const std::vector<ShapeController> &inputVector,
	std::istream &inputSource);

std::vector<ShapeController> sortOutputBySides(const std::vector<ShapeController> &inputVector,
	std::istream &inputSource);

#endif