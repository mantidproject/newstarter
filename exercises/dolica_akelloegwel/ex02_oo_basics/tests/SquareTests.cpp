//
// Created by dolica on 16/10/18.
//

#include <gtest/gtest.h>
#include "../src/Square.h"

class SquareTests : public ::testing::Test {

public:
  double squareSide = 3.8;
  Square mySquare = Square(squareSide);
};

TEST_F(SquareTests, first_test)
{
  EXPECT_FLOAT_EQ(mySquare.GetSide(), squareSide);
  EXPECT_FLOAT_EQ(mySquare.GetArea(), squareSide * squareSide);
  EXPECT_FLOAT_EQ(mySquare.GetPerimeter(), squareSide * 4);

  EXPECT_EQ(mySquare.GetNumSides(),4);

  EXPECT_TRUE("Square" == mySquare.GetType());
}
