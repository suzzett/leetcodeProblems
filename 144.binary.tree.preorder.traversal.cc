#include<iostream>
#include<stack>
#include<algorithm>
#include "Functions.h"
std::vector<int> preorderTraversal(TreeNode* root);
void getPreorderTraversal(TreeNode* root, std::vector<int> &treeValues);

int main()
{
  TreeNode* tree = getSampleTree1();
  printTree(tree);
  printVector(preorderTraversal(tree));
  tree = getSampleTree3();
  printTree(tree);
  printVector(preorderTraversal(tree));
}

//Iterative solution
std::vector<int> preorderTraversal(TreeNode* root)
{
  std::vector<int> returnValues;
  if (root==NULL) return returnValues;
  std::vector<TreeNode*> visitedNodes;
  std::stack<TreeNode*> nodesStack;
  do
  {
    std::cout << "Root before bools: " << root->val << std::endl;
    bool leftNodeIsVisited   = ((root->left!=NULL)?(std::find_if(visitedNodes.begin(), visitedNodes.end(), [root](const TreeNode* node1) -> bool {return node1==root->left;})) != visitedNodes.end():true);
    bool rightNodeIsVisited  = ((root->right!=NULL)?(std::find_if(visitedNodes.begin(), visitedNodes.end(), [root](const TreeNode* node1) -> bool {return node1==root->right;})) != visitedNodes.end():true);
    bool currNodeIsVisited   = (std::find_if(visitedNodes.begin(), visitedNodes.end(), [root](const TreeNode* node1) -> bool {return node1==root;})) != visitedNodes.end();
    std::cout << "Stack size: " << nodesStack.size() << std::endl;

    if (!currNodeIsVisited)
    {
      nodesStack.emplace(root);
      returnValues.emplace_back(root->val);
      visitedNodes.emplace_back(root);
    }
    else
    {
      if (!leftNodeIsVisited)
      {
        nodesStack.emplace(root->left);
        returnValues.emplace_back(root->left->val);
        visitedNodes.emplace_back(root->left);
      }
      else if (!rightNodeIsVisited)
      {
        nodesStack.emplace(root->right);
        returnValues.emplace_back(root->right->val);
        visitedNodes.emplace_back(root->right);
      }
      else
      {
        nodesStack.pop();
      }
    }
    root = nodesStack.size()>0?nodesStack.top():NULL;
    printVector(returnValues);
  } while (nodesStack.size() > 0);
  return returnValues;
}

//Recursive 0ms solution
// std::vector<int> preorderTraversal(TreeNode* root)
// {
//   std::vector<int> returnValues;
//   getPreorderTraversal(root, returnValues);
//   return returnValues;
// }
//
// void getPreorderTraversal(TreeNode* root, std::vector<int> &treeValues)
// {
//   if (root==NULL) return;
//   treeValues.emplace_back(root->val);
//   getPreorderTraversal(root->left, treeValues);
//   getPreorderTraversal(root->right, treeValues);
// }
#include "Functions.cc"
