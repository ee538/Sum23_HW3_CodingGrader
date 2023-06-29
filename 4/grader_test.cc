#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAreArray;
using ::testing::UnorderedElementsAre;
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(SinglyLinkedList, PushBackWorks) {
  SinglyLinkedList l;
  l.push_back(2);

  EXPECT_EQ(l[0], 2);
  EXPECT_EQ(l[1], -1);
  EXPECT_EQ(l[200], -1);
}

TEST(SinglyLinkedList, PopBackWorks) {
  SinglyLinkedList l;
  l.push_back(0);
  l.push_back(1);
  l.push_back(2);

  EXPECT_TRUE(l.pop_back());

  EXPECT_EQ(l[0], 0);
  EXPECT_EQ(l[1], 1);
  EXPECT_EQ(l.size(), 2);
}

TEST(SinglyLinkedList, PopBackWorksEmpty) {
  SinglyLinkedList l;
  EXPECT_FALSE(l.pop_back());
  EXPECT_TRUE(l.empty());
}

TEST(SinglyLinkedList, EraseWorks) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.erase(0);

  EXPECT_EQ(l[0], 2);
  EXPECT_EQ(l[1], 3);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(actual, nullptr);
}

TEST(SinglyLinkedList, EraseWorksMiddle) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.erase(1);

  EXPECT_EQ(l[0], 1);
  EXPECT_EQ(l[1], 3);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(actual->val, 1);
}

TEST(SinglyLinkedList, EraseWorksEnd) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.erase(2);

  EXPECT_EQ(l[0], 1);
  EXPECT_EQ(l[1], 2);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(actual->val, 2);
}

TEST(SinglyLinkedList, EraseWorksOutside) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.erase(3);

  EXPECT_EQ(l[0], 1);
  EXPECT_EQ(l[1], 2);
  EXPECT_EQ(l[2], 3);
  EXPECT_EQ(l.size(), 3);
  EXPECT_EQ(actual, nullptr);
}

TEST(SinglyLinkedList, ConvertToVectorWorks) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({1, 2, 3}));
}

TEST(SinglyLinkedList, ConvertToVectorEmpty) {
  SinglyLinkedList l;

  auto actual = l.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}

TEST(SinglyLinkedList, ConstructorWorks) {
  SinglyLinkedList l({0, 1, 2, 3});

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3}));
}

TEST(SinglyLinkedList, CopyConstructorWorks) {
  SinglyLinkedList l1({0, 1, 2, 3});
  SinglyLinkedList l2 = l1;
  auto actual = l2.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3}));
}

TEST(SinglyLinkedList, CopyConstructorWorksEmpty) {
  SinglyLinkedList l1;
  SinglyLinkedList l2 = l1;
  auto actual = l2.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}

TEST(SinglyLinkedList, RemoveDuplicatesWorks) {
  SinglyLinkedList l({0, 1, 2, 3, 1});
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3}));
}

TEST(SinglyLinkedList, RemoveDuplicatesWorksMoreNumbers) {
  SinglyLinkedList l({0, 1, 2, 3, 1, 2, 2, 3, 3, 1, 0, 0, 4});
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3, 4}));
}

TEST(SinglyLinkedList, RemoveDuplicatesWorksNoDuplicates) {
  SinglyLinkedList l({0, 1, 2, 3, 4});
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3, 4}));
}

TEST(SinglyLinkedList, RemoveDuplicatesWorksEmpty) {
  SinglyLinkedList l;
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}

// Erase

// Test for erasing the first element in the list.
TEST(SinglyLinkedListTest, EraseFirstElement) {
  std::vector<int> v = {1, 2, 3, 4};
  SinglyLinkedList list(v);
  ListNode* p = list.head();
  ListNode* expected_previous = nullptr;

  // Erase the first element and check that it was correctly removed.
  ListNode* previous = list.erase(p);
  EXPECT_EQ(list.convert_to_vector(), std::vector<int>({2, 3, 4}));
  EXPECT_EQ(previous, expected_previous);
}

// Test for erasing an element in the middle of the list.
TEST(SinglyLinkedListTest, EraseMiddleElement) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  SinglyLinkedList list(v);
  ListNode* p = list.GetIthPointer(2);
  ListNode* expected_previous = list.GetIthPointer(1);

  // Erase the middle element and check that it was correctly removed.
  ListNode* previous = list.erase(p);
  EXPECT_EQ(list.convert_to_vector(), std::vector<int>({1, 2, 4, 5}));
  EXPECT_EQ(previous, expected_previous);
}

// Test for erasing the last element in the list.
TEST(SinglyLinkedListTest, EraseLastElement) {
  std::vector<int> v = {1, 2, 3, 4};
  SinglyLinkedList list(v);
  ListNode* p = list.GetBackPointer();
  ListNode* expected_previous = list.GetIthPointer(2);

  // Erase the last element and check that it was correctly removed.
  ListNode* previous = list.erase(p);
  EXPECT_EQ(list.convert_to_vector(), std::vector<int>({1, 2, 3}));
  EXPECT_EQ(previous, expected_previous);
}

// Test for erasing a non-existent element.
TEST(SinglyLinkedListTest, EraseNonExistentElement) {
  std::vector<int> v = {1, 2, 3, 4};
  SinglyLinkedList list(v);
  ListNode* p = list.GetIthPointer(4);

  // Erase a non-existent element and check that nothing changed.
  ListNode* previous = list.erase(p);
  EXPECT_EQ(list.convert_to_vector(), v);
  EXPECT_EQ(previous, nullptr);
}

// Test for erasing the only element in the list.
TEST(SinglyLinkedListTest, EraseOnlyElement) {
  SinglyLinkedList list;
  list.push_back(42);
  ListNode* p = list.head();
  ListNode* expected_previous = nullptr;

  // Erase the only element in the list and check that the list is now empty.
  ListNode* previous = list.erase(p);
  EXPECT_EQ(list.convert_to_vector(), std::vector<int>());
  EXPECT_EQ(previous, expected_previous);
}

TEST(SinglyLinkedListTest, GetPrevious) {
  // Create a list with values 1, 2, 3, 4
  SinglyLinkedList lst({1, 2, 3, 4});

  // Test with pointer to head
  EXPECT_EQ(lst.GetPrevious(lst.head()), nullptr);

  // Test with pointer to second element
  EXPECT_EQ(lst.GetPrevious(lst.head()->next), lst.head());

  // Test with pointer to third element
  EXPECT_EQ(lst.GetPrevious(lst.head()->next->next), lst.head()->next);

  // Test with pointer to last element
  EXPECT_EQ(lst.GetPrevious(lst.GetBackPointer()), lst.head()->next->next);
}

TEST(SinglyLinkedListTest, GetPrevious_Nullptr) {
  // Create an empty list
  SinglyLinkedList lst;

  // Test with null pointer
  EXPECT_EQ(lst.GetPrevious(nullptr), nullptr);
}

TEST(SinglyLinkedListTest, GetPreviousSingleItem) {
  SinglyLinkedList list;
  list.push_back(42);

  // Try to get the previous node of the only item in the list
  ListNode* prev = list.GetPrevious(list.head());

  // Expect to get a nullptr since there is no previous node
  EXPECT_EQ(prev, nullptr);
}

TEST(SinglyLinkedListTest, ReverseEmptyList) {
  SinglyLinkedList list;
  list.reverse();
  EXPECT_TRUE(list.empty());
}

TEST(SinglyLinkedListTest, ReverseSingleItemList) {
  SinglyLinkedList list;
  list.push_back(5);
  list.reverse();
  EXPECT_EQ(5, list[0]);
}

TEST(SinglyLinkedListTest, ReverseMultipleItemList) {
  SinglyLinkedList list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  list.reverse();
  EXPECT_EQ(5, list[0]);
  EXPECT_EQ(4, list[1]);
  EXPECT_EQ(3, list[2]);
  EXPECT_EQ(2, list[3]);
  EXPECT_EQ(1, list[4]);
}

TEST(SinglyLinkedListTest, ReverseDuplicateItemList) {
  SinglyLinkedList list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(2);
  list.push_back(1);
  list.reverse();
  EXPECT_EQ(1, list[0]);
  EXPECT_EQ(2, list[1]);
  EXPECT_EQ(3, list[2]);
  EXPECT_EQ(2, list[3]);
  EXPECT_EQ(1, list[4]);
}
