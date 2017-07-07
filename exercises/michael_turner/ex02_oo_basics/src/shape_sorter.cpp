#include "shape_sorter.h"

#include "shapes.h"

#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <vector>

ShapeSorter::ShapeSorter(std::vector<std::reference_wrapper<Shape> > &v): shapes(v){}

void ShapeSorter::printRank(std::multimap<double, std::string>& rank){
    for(std::multimap<double, std::string>::reverse_iterator iter = rank.rbegin(); iter != rank.rend(); ++iter)
        std::cout << iter->first << "\t\t" <<iter->second << std::endl;
    std::cout << std::endl;
}
void ShapeSorter::printRank(std::map<std::string, int>& rank){
    for(std::map<std::string, int>::reverse_iterator iter = rank.rbegin(); iter != rank.rend(); ++iter)
        std::cout << iter->first << "\t\t" <<iter->second << std::endl;
    std::cout << std::endl;
}

void ShapeSorter::types(const std::string& type){
    std::map<std::string, int> rank;

    for (std::vector<std::reference_wrapper<Shape>>::const_iterator iter = shapes.begin(); iter != shapes.end(); ++iter){

        if (!(iter->get().getType().compare(type)))
            ++rank[type];
    }
    std::cout << "Type = " << type << "\tOccurences" << std::endl;
    printRank(rank);
}

void ShapeSorter::sides(const int &numSides){
    std::map<std::string, int> rank;

    for (std::vector<std::reference_wrapper<Shape>>::const_iterator iter = shapes.begin(); iter != shapes.end(); ++iter){
         if( iter->get().getSides() == numSides)
            ++rank[iter->get().getType()];
    }
    std::cout << "Num Sides = " << numSides << "\tOccurences" << std::endl;
    printRank(rank);
}

void ShapeSorter::area(){
    std::multimap<double, std::string> rank;

    for (std::vector<std::reference_wrapper<Shape>>::const_iterator iter = shapes.begin(); iter != shapes.end(); ++iter){
        rank.insert(std::pair<double, std::string>(iter->get().getArea(), iter->get().getType()));
    }
    std::cout << "Area\t\tType"<<std::endl;
    printRank(rank);
}

void ShapeSorter::perim(){
    std::multimap<double, std::string> rank;

    for (std::vector<std::reference_wrapper<Shape>>::const_iterator iter = shapes.begin(); iter != shapes.end(); ++iter)
        rank.insert(std::pair<double, std::string>(iter->get().getPerim(), iter->get().getType()));

    std::cout << "Perimeter\tType"<<std::endl;
    printRank(rank);
}
