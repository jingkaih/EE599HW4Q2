#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(GetParentIndexShould, ReturnParentIndex) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  int actual = myheap.GetParentIndex(2);
  int expected = 0;
  EXPECT_EQ(expected, actual);
}
TEST(GetParentIndexShould, HandleCornerCase) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  int actual = myheap.GetParentIndex(0);
  int expected = -1;
  EXPECT_EQ(expected, actual);
}
TEST(GetLeftIndexShould, GetLeftIndex) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  int actual = myheap.GetLeftIndex(3);
  int expected = 7;
  EXPECT_EQ(expected, actual);
}
TEST(GetLeftIndexShould, HandleCornerCase) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  int actual = myheap.GetLeftIndex(5);
  int expected = -1;
  EXPECT_EQ(expected, actual);
}

TEST(GetRightIndexShould, GetRightIndex) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  int actual = myheap.GetRightIndex(3);
  int expected = 8;
  EXPECT_EQ(expected, actual);
}
TEST(GetRightIndexShould, HandleCornerCase) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  int actual = myheap.GetRightIndex(4);
  int expected = -1;
  EXPECT_EQ(expected, actual);
}

TEST(GetLargestChildIndexShould, GetLargerOne) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  int actual = myheap.GetLargestChildIndex(2);
  int expected = 6;
  EXPECT_EQ(expected, actual);
}

TEST(TopShould, GetTop) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  int actual = myheap.top();
  int expected = 9;
  EXPECT_EQ(expected, actual);
}
TEST(PushShould, PushAndTrickleUp) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  myheap.push(25);
  int actual = myheap.top();
  int expected = 25;
  EXPECT_EQ(expected, actual);
}
TEST(PopShouldPopTheTop, AndTrickleTheNewTopOneDown) {
  MaxHeap myheap;
  for(int i = 1; i < 10; i++)
  myheap.push(i);
  myheap.pop();
  int actual = myheap.top();
  int expected = 8;
  EXPECT_EQ(expected, actual);
}