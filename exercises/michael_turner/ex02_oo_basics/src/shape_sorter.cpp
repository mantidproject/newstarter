#include "shape_sorter.h"

#include "shapes.h"

#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <map>
#include <vector>

ShapeSorter::ShapeSorter(std::vector<std::reference_wrapper<Shape> > &v): shapes(v){}

void ShapeSorter::printRank(std::multimap<double, std::reference_wrapper<Shape> > &rank){
    for(std::multimap<double, std::reference_wrapper<Shape>>::reverse_iterator iter = rank.rbegin(); iter != rank.rend(); ++iter){
        std::cout <<std::left << std::setw(constants::COL_WIDTH) << iter->first;
        iter->second.get().printShape();
    }
    std::cout << std::endl;
}

void ShapeSorter::printRank(std::vector<std::reference_wrapper<Shape>> &rank){
    for(std::vector<std::reference_wrapper<Shape>>::iterator iter = rank.begin(); iter < rank.end(); ++iter){
        iter->get().printShape();
    }
    std::cout << std::endl;
}

void ShapeSorter::types(const std::string& type){
    std::vector<std::reference_wrapper<Shape>> rank;
    int occurences;

    for (std::vector<std::reference_wrapper<Shape>>::const_iterator iter = shapes.begin(); iter != shapes.end(); ++iter){

        if (!(iter->get().getType().compare(type))){
            rank.push_back(iter->get());
            ++occurences;
        }
    }
    std::cout << "Type = " << type << std::right << std::setw(constants::COL_WIDTH) << "Occurences = " << occurences << std::endl;
    printRank(rank);
}


void ShapeSorter::sides(const int &numSides){
    std::vector<std::reference_wrapper<Shape>> rank;
    int occurences;

    for (std::vector<std::reference_wrapper<Shape>>::const_iterator iter = shapes.begin(); iter != shapes.end(); ++iter){
         if( iter->get().getSides() == numSides){
             rank.push_back(iter->get());
             ++occurences;
         }
    }
    std::cout << "Num Sides = " << numSides <<std::right <<std::setw(constants::COL_WIDTH) << "Occurences = " << occurences << std::endl;
    printRank(rank);
}

void ShapeSorter::area(){
    std::multimap<double, std::reference_wrapper<Shape>> rank;

    for (std::vector<std::reference_wrapper<Shape>>::const_iterator iter = shapes.begin(); iter != shapes.end(); ++iter){
        rank.insert(std::pair<double, std::reference_wrapper<Shape>>(iter->get().getArea(), iter->get()));
    }
    std::cout <<std::left <<std::setw(constants::COL_WIDTH)<<"Area" << "Type"<<std::endl;
    printRank(rank);
}

void ShapeSorter::perim(){
    std::multimap<double, std::reference_wrapper<Shape>> rank;

    for (std::vector<std::reference_wrapper<Shape>>::const_iterator iter = shapes.begin(); iter != shapes.end(); ++iter)
        rank.insert(std::pair<double, std::reference_wrapper<Shape>>(iter->get().getPerim(), iter->get()));

    std::cout << std::left << std::setw(constants::COL_WIDTH)<< "Perimeter" <<"Type"<<std::endl;
    printRank(rank);
}
