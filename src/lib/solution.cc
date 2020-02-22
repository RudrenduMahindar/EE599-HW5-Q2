#include "solution.h"
#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;
BST::~BST()
{
  root_=nullptr;
}
BST::BST()
{
  root_=nullptr;
}
BST::BST(vector<int> initial_values)
{
  root_=nullptr;
  if(!initial_values.empty())
  {
    for(vector<int>:: iterator it=initial_values.begin();it!=initial_values.end();it++)
      push(*it);
  }  
  else
    root_=nullptr;
}
TreeNode* BST::get_root()
{
  return root_;
}
int BST::height(TreeNode *node)
{
  if(node==nullptr)
    return 0;
  else
  {
    int left_height=height(node->left);
    int right_height=height(node->right);
    if(left_height>right_height)
      return (left_height+1);
    return (right_height+1);  
  }
}
void insert(TreeNode** ptr,int key)
{
  if(*ptr==nullptr)
  { 
    *ptr=new TreeNode(key);
    return;
  }  
  TreeNode* t=*ptr;
  if(key<t->val)
    insert(&(t->left),key);
  else 
    insert(&(t->right),key);  
}
void BST::push(int key)
{
  if(root_==nullptr)
    root_=new TreeNode(key);
  else
    insert(&root_,key);
}
bool search(TreeNode** ptr,int key)
{
  if(*ptr==nullptr)
    return false;
  TreeNode* t=*ptr;  
  if(t->val==key)
    return true;
  else if(key<t->val)
    return search(&(t->left),key);
  else
    return search(&(t->right),key);
}
bool BST::find(int key)
{
  if(root_==nullptr)
    return false;
  else
    return search(&root_,key);  
}
TreeNode* FindMin(TreeNode *root) {
   if (root == nullptr) {
      return nullptr; // or undefined.
   }
   if (root->left != nullptr) {
      return FindMin(root->left); // left tree is smaller
   }
   return root;
}
TreeNode* erase_node(TreeNode* node,int key)
{
  if(node==nullptr)
    return nullptr;
  if (key < node->val) {  // data is in the left sub tree.
    node->left=erase_node(node->left, key);
  } 
  else if (key > node->val) { // data is in the right sub tree.
    node->right=erase_node(node->right, key);
  }
  else {
     // case 1: no children
     if (node->left == nullptr && node->right == nullptr) {
        delete(node);
        node = nullptr;
     }
     // case 2: one child (right)
     else if (node->left == nullptr) {
        TreeNode *temp = node; // save current node as a backup
        node = node->right;
        delete(temp);
     }
     // case 3: one child (left)
     else if (node->right == nullptr) {
        TreeNode *temp = node; // save current node as backup
        node = node->left;
        delete(temp);
     }
     // case 4: two children
     else {
        TreeNode *temp = FindMin(node->right); // find minimal value of right sub tree
        node->val = temp->val; // duplicate the node
        node->right=erase_node(node->right, temp->val); // delete the duplicate node
     }      
  }
  return node;
}
bool BST::erase(int key)
{
  bool find_node=find(key);
  TreeNode* node=erase_node(root_,key);
  if(node==nullptr || find_node==false)
    return false;
  return true;  
}
vector<int> BST::TreeToVector()
{
  vector<int> a;
  if(root_==nullptr)
    return a;
  queue<TreeNode*> q;
  q.push(root_);
  while(!q.empty())
  {
    TreeNode* node=q.front();
    a.push_back(node->val);
    q.pop();
    if(node->left!=nullptr)
      q.push(node->left);

    if(node->right!=nullptr)
      q.push(node->right);  
  }
  return a;
}
vector<int> BST::inorder_recursive()
{
  vector<int> v;
  traverse(root_,v);
  return v;  
}
void BST::traverse(TreeNode* node,vector<int>& v)
{
  if(node!=nullptr)
  {
    traverse(node->left,v);
    v.push_back(node->val);
    traverse(node->right,v);
  }  
}
vector<int> BST::inorder_nonrecursive()
{
  vector<int> v;
  stack<TreeNode*> s;
  TreeNode* node=root_;
  while(node!=nullptr || !s.empty())
  {
    while(node!=nullptr)
    {
      s.push(node);
      node=node->left;
    }
    node=s.top();
    v.push_back(node->val);
    s.pop();
    node=node->right;
  }
  return v;
}