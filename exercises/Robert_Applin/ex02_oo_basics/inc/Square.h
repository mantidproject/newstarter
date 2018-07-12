#ifndef SQUARE_H_
#define SQUARE_H_

#include "Rectangle.h"

class Square : public Rectangle {
public:
  Square(double size);

  double getSize() const;
  std::string getType() const override;

private:
  using Rectangle::getHeight;
  using Rectangle::getWidth;
};

#endif
