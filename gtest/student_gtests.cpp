#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(is_adjacent, tests) {
  string1 = "cat";
  string2 = "cats";
  string3 = "cot";
  string4 = "cots";
  EXPECT_TRUE(is_adjacent(string1, string2));
  EXPECT_TRUE(is_adjacent(string1, string3));
  EXPECT_FALSE(is_adjacent(string1, string4));
} 


int main(int argc, char ** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}