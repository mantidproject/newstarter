#ifndef EX2_SHAPE_TYPE
#define EX2_SHAPE_TYPE
#include <ostream>
enum class ShapeType { Square, Rectangle, Circle, Triangle };

std::ostream &operator<<(std::ostream &OutputStream, ShapeType type);
#endif // EX2_SHAPE_TYPE
