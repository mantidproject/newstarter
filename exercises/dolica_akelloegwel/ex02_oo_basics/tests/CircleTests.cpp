//
// Created by dolica on 16/10/18.
//

#include <gtest/gtest.h>
#include "../src/Circle.h"

class CircleTests : public ::testing::Test
{
public:
  double circleRadius = 3.8;
  Circle myCircle = Circle(circleRadius);
};

TEST_F(CircleTests, first_test)
{
  EXPECT_FLOAT_EQ(myCircle.GetRadius(), circleRadius);
  EXPECT_FLOAT_EQ(myCircle.GetPerimeter(), circleRadius * 2 * M_PI);
  EXPECT_FLOAT_EQ(myCircle.GetArea(), circleRadius * circleRadius * M_PI);

  EXPECT_EQ(myCircle.GetNumSides(),1);

  EXPECT_TRUE("Circle" == myCircle.GetType());
}
