#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BST {
public:
  BST();
  // Inserts elements of initial_values one by one into the Tree
  BST(std::vector<int> initial_values);
  ~BST();
  void push(int key); // **GT** Inserts a key inside Tree
  bool find(int key); // **GT** Returns true of key is in the tree
  bool erase(int key); // **GT** Removes the key from the tree. If not successful, returns false.
  int height(TreeNode *node);
  TreeNode* get_root();
  vector<int> TreeToVector();
  vector<int> inorder_recursive();
  void traverse(TreeNode*, vector<int>&); //helper for inorder recursive calls
  vector<int> inorder_nonrecursive();
private:
  TreeNode *root_;
};
#endif