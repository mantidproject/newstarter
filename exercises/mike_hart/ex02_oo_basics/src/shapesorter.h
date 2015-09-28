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
typedef std::shared_ptr<ShapeVector> ShapeVectorSPtr;



/**
	Utility class that can sort and print a vector of shapes.
*/
class ShapeSorter
{
public:
	/// Constructor
	ShapeSorter(const ShapeVectorSPtr& shapes);

	/// Destructor
	~ShapeSorter();
	
	/// Print out Shapes that match the chosen type
	void printByTypeMatch(const std::string& type);

	/// Print out Shapes that match the chosen number of sides
	void printBySideCount(int sidecount);
	
	/// Sort and print Shapes in order of area, descending
	void printByArea();

	/// Sort and print Shapes in order of perimeter, descending
	void printByPerimeter();

private:
	/// Shared pointer to vector of shapes to be sorted/printed
	ShapeVectorSPtr m_shapes;

	/// Helper function to print out a single shape
	void printShape(const ShapeUPtr& shape);
};

#endif // SHAPESORTER_H_
