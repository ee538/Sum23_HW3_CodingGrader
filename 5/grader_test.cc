#include <climits>
#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAreArray;
using ::testing::IsEmpty;
using ::testing::UnorderedElementsAre;
template <class T>
void PrintVector(std::vector<T> input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
// Test the DoubleStack constructor
TEST(DoubleStackTest, ConstructorTest) {
  DoubleStack doubleStack;
  EXPECT_EQ(doubleStack.size(), 0);
  EXPECT_TRUE(doubleStack.empty());
}

// Test the DoubleStack push function for even input
TEST(DoubleStackTest, PushEvenTest) {
  DoubleStack doubleStack;
  doubleStack.push(2);
  EXPECT_EQ(doubleStack.size(), 1);
  EXPECT_FALSE(doubleStack.empty());
  EXPECT_EQ(doubleStack.top(), 2);
}

// Test the DoubleStack push function for odd input
TEST(DoubleStackTest, PushOddTest) {
  DoubleStack doubleStack;
  doubleStack.push(3);
  EXPECT_EQ(doubleStack.size(), 1);
  EXPECT_FALSE(doubleStack.empty());
  EXPECT_EQ(doubleStack.top(), 3);
}

TEST(DoubleStackTest, PushMixTest) {
  DoubleStack doubleStack;
  doubleStack.push(3);
  doubleStack.push(2);
  doubleStack.push(0);
  EXPECT_EQ(doubleStack.size(), 3);
  EXPECT_FALSE(doubleStack.empty());
  EXPECT_EQ(doubleStack.top(), 3);
}

// Test the DoubleStack pop function
TEST(DoubleStackTest, PopTest) {
  DoubleStack doubleStack;
  doubleStack.push(2);
  doubleStack.push(3);
  doubleStack.pop();
  EXPECT_EQ(doubleStack.size(), 1);
  EXPECT_EQ(doubleStack.top(), 2);
}

// Test the DoubleStack pop function
TEST(DoubleStackTest, PopTestOnlyEven) {
  DoubleStack doubleStack;
  doubleStack.push(2);
  EXPECT_EQ(doubleStack.size(), 1);
  EXPECT_EQ(doubleStack.top(), 2);

  doubleStack.pop();
  EXPECT_EQ(doubleStack.size(), 0);
  EXPECT_EQ(doubleStack.top(), -1);
}

// Test the DoubleStack top function
TEST(DoubleStackTest, TopTest) {
  DoubleStack doubleStack;
  doubleStack.push(2);
  doubleStack.push(3);
  EXPECT_EQ(doubleStack.top(), 3);
}

// Test the DoubleStack size function
TEST(DoubleStackTest, SizeTest) {
  DoubleStack doubleStack;
  doubleStack.push(2);
  doubleStack.push(3);
  EXPECT_EQ(doubleStack.size(), 2);
}

// Test the DoubleStack empty function
TEST(DoubleStackTest, EmptyTest) {
  DoubleStack doubleStack;
  EXPECT_TRUE(doubleStack.empty());
  doubleStack.push(2);
  EXPECT_FALSE(doubleStack.empty());
}

TEST(DoubleStackTest, EmptyTest2) {
  DoubleStack doubleStack;
  EXPECT_TRUE(doubleStack.empty());
  doubleStack.push(1);
  EXPECT_FALSE(doubleStack.empty());
  doubleStack.pop();
  EXPECT_TRUE(doubleStack.empty());
}