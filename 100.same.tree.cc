#include<iostream>
#include "Functions.h"

bool isSameTree(TreeNode* p, TreeNode* q);

int main()
{
  TreeNode* tree1 = getSampleTree1();
  TreeNode* tree2 = getSampleTree1();
  printTree(tree1);
  std::cout << std::endl << std::endl;
  printTree(tree2);
  std::cout << std::endl << std::endl;
  std::cout << "Tree1 and Tree2 are " << ((isSameTree(tree1, tree2))?"":"not ") << "same." << std::endl;
  tree2 = getSampleTree2();
  printTree(tree1);
  std::cout << std::endl << std::endl;
  printTree(tree2);
  std::cout << std::endl << std::endl;
  std::cout << "Tree1 and Tree2 are " << ((isSameTree(tree1, tree2))?"":"not ") << "same." << std::endl;
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
  if (p==NULL && q==NULL) return true;
  else if (p==NULL) return false;
  else if (q==NULL) return false;
  if (p->val != q->val) return false;
  return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
}
#include "Functions.cc"
