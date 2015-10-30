/** Square.h "Square.h"

	This Square class is a specialization of Rectangle which passes one dimension for width and height.
*/

#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

namespace Shapes
{
	class Square: public Rectangle
	{
	public:
		Square(double sideLength);
		~Square();
	};
};

#endif