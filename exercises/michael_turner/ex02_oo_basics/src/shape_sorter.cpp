#include "shape_sorter.h"

#include "shapes.h"

#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <map>
#include <vector>

/**
 * @brief ShapeSorter::ShapeSorter      Reads in the vector of shapes to be sorted
 * @param v         The vector of shapes
 */
ShapeSorter::ShapeSorter(ShapeVector &v): shapes(v){}


/**
 * @brief ShapeSorter::printRank        Prints the rank of shapes (sorted by area or perimeter)
 *                                                          in decreasing order
 * @param rank      The shapes in ranking order
 */
void ShapeSorter::printRank(std::multimap<double, std::reference_wrapper<Shape> > &rank){

    //Iterate through map in reverse order and print value of area/perimeter, followed by the Shape data
    for(auto iter = rank.crbegin(); iter != rank.crend(); ++iter){
        //Print data in columns
        std::cout <<std::left << std::setw(COL_WIDTH) << iter->first;
        iter->second.get().printShape();
    }
    std::cout << std::endl;
}


/**
 * @brief ShapeSorter::printSort        Prints the data of the shapes matching a criterium
 * @param sorted            The selected shapes
 */
void ShapeSorter::printSort(ShapeVector &sorted){
    //Iterate through vector and print each shape's data
    for(const auto &shape_ref: sorted){
        shape_ref.get().printShape();
    }
    std::cout << std::endl;
}


/**
 * @brief ShapeSorter::types        Selects shapes matching the chosen type (e.g. 'square')
 *                                                  Prints the selected shapes, and the number of matching shapes found.
 *
 * @param type      The type of shapes desired
 */
void ShapeSorter::types(const std::string& type){
    ShapeVector sorted;
    int occurences = 0;

    for (const auto &shape_ref: shapes){

        if (!(shape_ref.get().getType().compare(type))){
            sorted.push_back(shape_ref.get());
            //Increment number of matching shapes found
            ++occurences;
        }
    }
    std::cout << "Type = " << type << std::right << std::setw(COL_WIDTH)
                   << "Occurences = " << occurences << std::endl;
    printSort(sorted);
}


/**
 * @brief ShapeSorter::sides       Selects the shapes with the chosen number of sides
 * @param numSides
 */
void ShapeSorter::sides(const int &numSides){
    ShapeVector sorted;
    int occurences = 0;

    for (const auto &shape_ref: shapes){
         if( shape_ref.get().getSides() == numSides){
             sorted.push_back(shape_ref.get());
             //Increment number of matching shapes found
             ++occurences;
         }
    }
    std::cout << "Num Sides = " << numSides <<std::right <<std::setw(COL_WIDTH)
                   << "Occurences = " << occurences << std::endl;
    printSort(sorted);
}


/**
 * @brief ShapeSorter::area     Ranks shapes in order of decreasing area
 */
void ShapeSorter::area(){
    std::multimap<double, std::reference_wrapper<Shape>> rank;

    for (const auto &shape_ref: shapes){
        rank.insert(std::pair<double, std::reference_wrapper<Shape>>(shape_ref.get().getArea(), shape_ref.get()));
    }
    std::cout <<std::left <<std::setw(COL_WIDTH)<<"Area" << "Type"<<std::endl;
    printRank(rank);
}


/**
 * @brief ShapeSorter::perim    Ranks shapes in order of decreasing perimeter
 */
void ShapeSorter::perim(){
    std::multimap<double, std::reference_wrapper<Shape>> rank;

    for (const auto &shape_ref: shapes){
        rank.insert(std::pair<double, std::reference_wrapper<Shape>>(shape_ref.get().getPerim(), shape_ref.get()));
    }
    std::cout << std::left << std::setw(COL_WIDTH)<< "Perimeter" <<"Type"<<std::endl;
    printRank(rank);
}
