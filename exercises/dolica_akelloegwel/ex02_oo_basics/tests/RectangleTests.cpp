//
// Created by dolica on 16/10/18.
//

#include <gtest/gtest.h>
#include "../src/Rectangle.h"

class RectangleTests : public ::testing::Test {

public:
   double rectWidth = 3.8;
   double rectHeight = 4.2;
   Rectangle myRectangle = Rectangle(rectWidth,rectHeight);
};

TEST_F(RectangleTests, first_test)
{
  EXPECT_FLOAT_EQ(myRectangle.GetWidth(), rectWidth);
  EXPECT_FLOAT_EQ(myRectangle.GetHeight(), rectHeight);
  EXPECT_FLOAT_EQ(myRectangle.GetArea(), rectHeight * rectWidth);
  EXPECT_FLOAT_EQ(myRectangle.GetPerimeter(), rectHeight * 2 + rectWidth * 2);

  EXPECT_EQ(myRectangle.GetNumSides(),4);

  EXPECT_TRUE("Rectangle" == myRectangle.GetType());
}
