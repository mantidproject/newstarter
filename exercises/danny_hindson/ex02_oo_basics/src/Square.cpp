// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#include "Square.h"

/**
 * Calculates perimeter of the square
  */
double Square::perimeter() const {
  return 4 * side;
}

/**
 * Calculates perimeter of the square
  */
double Square::area() const {
  return pow(side, 2);
}