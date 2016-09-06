#include<iostream>
#include<stack>
#include<algorithm>
#include "Functions.h"
std::vector<int> inorderTraversal(TreeNode* root);
//void getInOrderOfTree(TreeNode* root, std::vector<int> &treeValues);

int main()
{
  TreeNode* tree = getSampleTree1();
  printTree(tree);
  printVector(inorderTraversal(tree));
  tree = getSampleTree3();
  printTree(tree);
  printVector(inorderTraversal(tree));
}

//Iterative solution
std::vector<int> inorderTraversal(TreeNode* root)
{
  std::vector<int> returnValues;
  if (root==NULL) return returnValues;
  std::vector<TreeNode*> visitedNodes;
  std::stack<TreeNode*> nodesStack;
  nodesStack.emplace(root);
  while (nodesStack.size() > 0)
  {
    root = nodesStack.top();
    bool leftNodeVisited = ((root->left!=NULL)?(std::find_if(visitedNodes.begin(), visitedNodes.end(), [&currItem = root->left](const TreeNode* node1) -> bool {return node1==currItem;})) != visitedNodes.end():true);
    if (leftNodeVisited)
    {
      bool nodeVisited = ((std::find_if(visitedNodes.begin(), visitedNodes.end(), [&currItem = root](const TreeNode* node1) -> bool {return node1==currItem;})) != visitedNodes.end());
      if (!nodeVisited) returnValues.emplace_back(root->val);
      visitedNodes.emplace_back(root);
      if (root->right!=NULL)
      {
        bool rightNodeVisited = (std::find_if(visitedNodes.begin(), visitedNodes.end(), [&currItem = root->right](const TreeNode* node1) -> bool {return node1==currItem;})) != visitedNodes.end();
        if (!rightNodeVisited) nodesStack.emplace(root->right);
        else nodesStack.pop();
      }
      else nodesStack.pop();
    }
    else nodesStack.emplace(root->left);
  }
  return returnValues;
}


//Recursive 0ms solution
// std::vector<int> inorderTraversal(TreeNode* root)
// {
//   std::vector<int> returnValues;
//   getInOrderOfTree(root, returnValues);
//   return returnValues;
// }
//
// void getInOrderOfTree(TreeNode* root, std::vector<int> &treeValues)
// {
//   if (root==NULL) return;
//   getInOrderOfTree(root->left, treeValues);
//   treeValues.emplace_back(root->val);
//   getInOrderOfTree(root->right, treeValues);
// }
#include "Functions.cc"
