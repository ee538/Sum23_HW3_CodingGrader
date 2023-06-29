#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H

#include <vector>

// Create a class that has two stacks: one for odd numbers and one for even
// numbers.
// Assume we only use the stack for non-negative integers.
class DoubleStack {
 private:
  std::vector<int> evenVec_;  // Vector for even numbers
  std::vector<int> oddVec_;   // Vector for odd numbers

 public:
  // Constructor
  DoubleStack();

  // Pushes the number in evenVec_ if the input is even
  // Pushes the number in oddVec_ if the input is odd
  void push(int num);

  // Removes the maximum number from the top of both vectors.
  // It does not do anything if both stacks are empty.
  void pop();

  // Returns the maximum number from the top of both vectors.
  // It returns -1 if both stacks are empty.
  int top();

  // Returns the size of evenVec_ plus the size of oddVec_
  int size();

  // Returns true if both vectors are empty, false otherwise
  bool empty();
};

#endif  // DOUBLESTACK_H
