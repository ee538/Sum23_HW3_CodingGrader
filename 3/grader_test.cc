#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAreArray;

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(Queue, EmptyQueue) {
  Queue q;
  EXPECT_TRUE(q.IsEmpty());
  EXPECT_FALSE(q.Dequeue());
  EXPECT_EQ(q.Front(), -1);
}

TEST(Queue, SimpleOperations) {
  Queue q;
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  q.Dequeue();

  EXPECT_EQ(q.Front(), 2);
}

TEST(Queue, CopyConstructor) {
  Queue q1;
  q1.Enqueue(1);
  q1.Enqueue(2);
  q1.Enqueue(3);
  q1.Dequeue();

  Queue q2 = q1;
  EXPECT_EQ(q2.Front(), 2);

  q1.Dequeue();
  EXPECT_EQ(q1.Front(), 3);
  EXPECT_EQ(q2.Front(), 2);
}

TEST(Queue, CopyAssignment1) {
  Queue q1;
  q1.Enqueue(1);
  q1.Enqueue(2);
  q1.Enqueue(3);
  q1.Dequeue();

  Queue q2;
  q2 = q1;
  EXPECT_EQ(q2.Front(), 2);

  q1.Dequeue();
  EXPECT_EQ(q1.Front(), 3);
  EXPECT_EQ(q2.Front(), 2);
}

TEST(Queue, CopyAssignment2) {
  Queue q1;
  q1.Enqueue(1);
  q1.Enqueue(2);
  q1.Enqueue(3);
  q1.Dequeue();

  Queue q2, q3;
  q3 = q2 = q1;
  EXPECT_EQ(q3.Front(), 2);

  q3.Dequeue();
  EXPECT_EQ(q3.Front(), 3);
  EXPECT_EQ(q2.Front(), 2);
}

TEST(Queue, AddOperatorBothNonEmpty) {
  Queue q1;
  q1.Enqueue(1);
  q1.Enqueue(2);
  q1.Enqueue(3);

  Queue q2;
  q2.Enqueue(4);
  q2.Enqueue(5);

  Queue q3 = q1 + q2;

  EXPECT_THAT(q3.GetData(), ElementsAreArray({4, 5, 1, 2, 3}));
}

TEST(Queue, AddOperatorQ1Empty) {
  Queue q1;

  Queue q2;
  q2.Enqueue(4);
  q2.Enqueue(5);

  Queue q3 = q1 + q2;

  EXPECT_THAT(q3.GetData(), ElementsAreArray({4, 5}));
}

TEST(Queue, AddOperatorQ2Empty) {
  Queue q1;
  q1.Enqueue(1);
  q1.Enqueue(2);
  q1.Enqueue(3);

  Queue q2;

  Queue q3 = q1 + q2;

  EXPECT_THAT(q3.GetData(), ElementsAreArray({1, 2, 3}));
}

TEST(Queue, BothEmpty) {
  Queue q1;
  Queue q2;

  Queue q3 = q1 + q2;

  EXPECT_TRUE(q3.IsEmpty());
}