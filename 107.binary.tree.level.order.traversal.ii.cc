#include<iostream>
#include<queue>
#include<algorithm>

#include "Functions.h"
std::vector<std::vector<int>> levelOrderBottom(TreeNode* root);

int main()
{
  TreeNode* tree = getSampleTree1();
  printTree(tree);
  printVector2D(levelOrderBottom(tree));
  tree = getSampleTree2();
  printTree(tree);
  printVector2D(levelOrderBottom(tree));
  tree = getSampleTree3();
  printTree(tree);
  printVector2D(levelOrderBottom(tree));
}

std::vector<std::vector<int> > levelOrderBottom(TreeNode* root)
{
  std::vector<std::vector<int> > returnValues;
  if (root==NULL) return returnValues;
  std::queue<TreeNode*> nodesQueue;
  TreeNode* currNode = root;
  int totalNodesAtcurrHeight = 1;
  nodesQueue.emplace(root);
  do
  {
    std::vector<int> currLevelValues;
    for (unsigned int i = 0; i < totalNodesAtcurrHeight; i++)
    {
      currNode = nodesQueue.front();
      nodesQueue.pop();
      currLevelValues.emplace_back(currNode->val);
      bool hasRightNode = (currNode->right != NULL);
      bool hasLeftNode  = (currNode->left  != NULL);
      if (hasLeftNode)  nodesQueue.emplace(currNode->left);
      if (hasRightNode) nodesQueue.emplace(currNode->right);
    }
    returnValues.emplace_back(currLevelValues);
    totalNodesAtcurrHeight = nodesQueue.size();
  } while(!nodesQueue.empty());
  std::reverse(returnValues.begin(), returnValues.end());
  return returnValues;
}
#include "Functions.cc"
