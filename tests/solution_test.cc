#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(InorderRecursiveTest, ReturnsEmptyVector) {
  vector<int> v={};
  BST s(v);
  vector<int> actual = s.inorder_recursive();
  vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}
TEST(InorderRecursiveTest, ReturnsValidVector) {
  vector<int> v={3,2,20,15,27};
  BST s(v);
  vector<int> actual = s.inorder_recursive();
  vector<int> expected = {2,3,15,20,27};
  EXPECT_EQ(expected, actual);
}
TEST(InorderNonRecursiveTest, ReturnsEmptyVector) {
  vector<int> v={};
  BST s(v);
  vector<int> actual = s.inorder_nonrecursive();
  vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}
TEST(InorderNonRecursiveTest, ReturnsValidVector) {
  vector<int> v={3,2,20,15,27};
  BST s(v);
  vector<int> actual = s.inorder_nonrecursive();
  vector<int> expected = {2,3,15,20,27};
  EXPECT_EQ(expected, actual);
}

/*TEST(HeightTest, ReturnsZero) {
  vector<int> v={};
  BST s(v);
  TreeNode* root_node=s.get_root();
  int actual = s.height(root_node);
  int expected = 0;
  EXPECT_EQ(expected, actual);
}
TEST(FindTest, ReturnsTrue) {
  vector<int> v={8, 3 ,10 ,1 ,6 ,14 ,4 ,7, 13};
  BST s(v);
  int val=10;
  bool actual = s.find(val);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}
TEST(FindTest, ReturnsFalse) {
  vector<int> v={8, 3 ,10 ,1 ,6 ,14 ,4 ,7, 13};
  BST s(v);
  int val=0;
  bool actual = s.find(val);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}
TEST(EraseTest, ReturnsTrue) {
  vector<int> v={8, 3 ,10 ,1 ,6 ,14 ,4 ,7, 13};
  BST s(v);
  int val=14;
  bool actual = s.erase(val);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}
TEST(EraseTest, ReturnsFalse) {
  vector<int> v={8, 3 ,10 ,1 ,6 ,14 ,4 ,7, 13};
  BST s(v);
  int val=20;
  bool actual = s.erase(val);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}*/