#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(CheckValidExpression, Empty) {
  CPPLib lib;
  EXPECT_TRUE(lib.CheckValidExpression(""));
}

TEST(CheckValidExpression, Test1) {
  CPPLib lib;
  EXPECT_TRUE(lib.CheckValidExpression("()"));
  EXPECT_TRUE(lib.CheckValidExpression("()[]"));
  EXPECT_TRUE(lib.CheckValidExpression("([])"));
  EXPECT_TRUE(lib.CheckValidExpression("({})"));
  EXPECT_TRUE(lib.CheckValidExpression("({(asdf)}).(123).[asdf]+{(asdfasdf)}"));
  EXPECT_TRUE(lib.CheckValidExpression("{2k++[5--*j]}"));

  EXPECT_FALSE(lib.CheckValidExpression("("));
  EXPECT_FALSE(lib.CheckValidExpression("(]"));
  EXPECT_FALSE(lib.CheckValidExpression("({)}"));
}

TEST(CheckValidExpression, SingleOpen) {
  CPPLib lib;

  EXPECT_FALSE(lib.CheckValidExpression("("));
  EXPECT_FALSE(lib.CheckValidExpression("{"));
  EXPECT_FALSE(lib.CheckValidExpression("["));
  EXPECT_FALSE(lib.CheckValidExpression("a(a"));
  EXPECT_FALSE(lib.CheckValidExpression("a{a"));
  EXPECT_FALSE(lib.CheckValidExpression("a[a"));
}

TEST(CheckValidExpression, SingleClosing) {
  CPPLib lib;

  EXPECT_FALSE(lib.CheckValidExpression("}"));
  EXPECT_FALSE(lib.CheckValidExpression("]"));
  EXPECT_FALSE(lib.CheckValidExpression(")"));

  EXPECT_FALSE(lib.CheckValidExpression("a}b"));
  EXPECT_FALSE(lib.CheckValidExpression("1]123"));
  EXPECT_FALSE(lib.CheckValidExpression("1)2"));
}

TEST(CheckValidExpression, MultipleClosing) {
  CPPLib lib;

  EXPECT_FALSE(lib.CheckValidExpression("}}}}"));
  EXPECT_FALSE(lib.CheckValidExpression("]]"));
  EXPECT_FALSE(lib.CheckValidExpression("))"));
}

//-----------------------------------------------------------------------------
TEST(IsPalindrome, Empty) {
  CPPLib lib;

  std::cout << "Empty string" << std::endl;
  EXPECT_TRUE(lib.IsPalindrome(""));
}
TEST(IsPalindrome, Simple) {
  CPPLib lib;

  EXPECT_TRUE(lib.IsPalindrome("a"));
  EXPECT_TRUE(lib.IsPalindrome("aba"));
  EXPECT_TRUE(lib.IsPalindrome("abba"));
  EXPECT_TRUE(lib.IsPalindrome(" "));
  EXPECT_TRUE(lib.IsPalindrome("amanaplanacanalpanama"));

  EXPECT_FALSE(lib.IsPalindrome("ab"));
  EXPECT_FALSE(lib.IsPalindrome("abc"));
}
//-----------------------------------------------------------------------------
TEST(OddChar, OddNumberOfCharacters) {
  CPPLib lib;

  EXPECT_EQ(lib.OddChar(std::string("aaabb")), 'a');
  EXPECT_EQ(lib.OddChar(std::string("aab")), 'b');
  EXPECT_EQ(lib.OddChar(std::string("a")), 'a');
}
