
#ifndef MAIN_H
#define MAIN_H

#include "ShapeController.h"

#include <vector>
#include <iosfwd>

enum printOptions { TYPE, SIDES, DESC_AREA, DESC_PERIM, PRINT_ENUM_LEN };

//Tidy up function pointer for various sorting methods
using outputSortFuncPtr = std::vector<ShapeController>(*)(const std::vector<ShapeController>&,
	std::istream &inputSource);

//Gets the type of print the user wants and returns an int corresponding to the print ENUM
int getPrintType();

//Takes a pointer to a sort function and prints the resulting vector
void printShapeOutput(outputSortFuncPtr sortMethod, std::vector<ShapeController> const &inputVector);

/* Output sorting methods */
//Asks user for shape type and filter so only that type is present
std::vector<ShapeController> sortOutputByType(const std::vector<ShapeController> &inputVector,
	std::istream &inputSource);

//Asks user for the number of sides and filters so only shapes with that no is present
std::vector<ShapeController> sortOutputBySides(const std::vector<ShapeController> &inputVector,
	std::istream &inputSource);

//Sorts inputted shapes by their area
std::vector<ShapeController> sortOutputByDescArea(const std::vector<ShapeController> &inputVector,
	std::istream &inputSource);

//Sorts inputted shapes by their perimeter
std::vector<ShapeController> sortOutputByDescPerim(const std::vector<ShapeController> &inputVector,
	std::istream &inputSource);

bool compareShapeArea(const ShapeController &i, const ShapeController &j);
bool compareShapePerim(const ShapeController &i, const ShapeController &j);

#endif