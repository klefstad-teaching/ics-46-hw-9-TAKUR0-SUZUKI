#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(is_adjacent, tests) {
  string string1("cat");
  string string2("cats");
  string string3("cot");
  string string4("cots");
  EXPECT_TRUE(is_adjacent(string1, string2));
  EXPECT_TRUE(is_adjacent(string1, string3));
  EXPECT_FALSE(is_adjacent(string1, string4));
  EXPECT_FALSE(is_adjacent("cat", "coal"));
  EXPECT_FALSE(is_adjacent("cat", "cog"));
  EXPECT_FALSE(is_adjacent("coal", "cog"));
}  

int main(int argc, char ** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}