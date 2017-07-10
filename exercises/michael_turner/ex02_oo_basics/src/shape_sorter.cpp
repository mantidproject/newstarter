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
ShapeSorter::ShapeSorter(std::vector<std::reference_wrapper<Shape> > &v): shapes(v){}


/**
 * @brief ShapeSorter::printRank        Prints the rank of shapes (sorted by area or perimeter)
 *                                                          in decreasing order
 * @param rank      The shapes in ranking order
 */
void ShapeSorter::printRank(std::multimap<double, std::reference_wrapper<Shape> > &rank){

    //Iterate through map in reverse order and print value of area/perimeter, followed by the Shape data
    for(std::multimap<double, std::reference_wrapper<Shape>>::const_reverse_iterator iter = rank.rbegin(); iter != rank.rend(); ++iter){
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
void ShapeSorter::printSort(std::vector<std::reference_wrapper<Shape>> &sorted){
    //Iterate through vector and print each shape's data
    for(auto iter = sorted.begin(); iter < sorted.end(); ++iter){
        iter->get().printShape();
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
    std::vector<std::reference_wrapper<Shape>> sorted;
    int occurences;

    for (auto iter = shapes.begin(); iter < shapes.end(); ++iter){

        if (!(iter->get().getType().compare(type))){
            sorted.push_back(iter->get());
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
    std::vector<std::reference_wrapper<Shape>> sorted;
    int occurences;

    for (auto iter = shapes.begin(); iter < shapes.end(); ++iter){
         if( iter->get().getSides() == numSides){
             sorted.push_back(iter->get());
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

    for (auto iter = shapes.begin(); iter < shapes.end(); ++iter){
        rank.insert(std::pair<double, std::reference_wrapper<Shape>>(iter->get().getArea(), iter->get()));
    }
    std::cout <<std::left <<std::setw(COL_WIDTH)<<"Area" << "Type"<<std::endl;
    printRank(rank);
}


/**
 * @brief ShapeSorter::perim    Ranks shapes in order of decreasing perimeter
 */
void ShapeSorter::perim(){
    std::multimap<double, std::reference_wrapper<Shape>> rank;

    for (auto iter = shapes.begin(); iter < shapes.end(); ++iter){
        rank.insert(std::pair<double, std::reference_wrapper<Shape>>(iter->get().getPerim(), iter->get()));
    }
    std::cout << std::left << std::setw(COL_WIDTH)<< "Perimeter" <<"Type"<<std::endl;
    printRank(rank);
}
