#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include "shapes.h"

#include <functional>
#include <map>
#include <string>
#include <vector>

class ShapeSorter
{
    private:
        const std::vector<std::reference_wrapper< Shape>> shapes;
        void printRank(std::multimap<double, std::string> &rank);
        void printRank(std::map<std::string, int>& rank);
    public:
        ShapeSorter (std::vector<std::reference_wrapper<Shape> >& v);

        void types(const std::string& type);
        void sides(const int& numSides);

        void area();
        void perim();
};

#endif // SHAPESORTER_H_
