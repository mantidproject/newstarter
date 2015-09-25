#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include <memory>
#include <vector>
#include <string>

//----------------------------------------------------------------------
// Typedefs & Forward Declarations
//----------------------------------------------------------------------
class Shape;
typedef std::unique_ptr<Shape> ShapeUPtr;
typedef std::vector<ShapeUPtr> ShapeVector;



/**
	
*/
class ShapeSorter
{
public:
	/// Constructor
	ShapeSorter(const ShapeVector& shapes);
	
	/// Print out Shapes that match the chosen type
	void printByTypeMatch(std::string type);

	/// Print out Shapes that match the chosen number of sides
	void printBySideCount(int sidecount);
	
	/// Print out Shapes in order of area descending
	void printByArea();

	/// Print out Shapes that match the chosen type
	void printByPerimeter();


private:
	/// 
	const ShapeVector& m_shapes;
};

#endif // SHAPESORTER_H_
