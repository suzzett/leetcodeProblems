#include<iostream>
#include<queue>

#include "Functions.h"

std::vector<int> rightSideView(TreeNode* root);

int main()
{
  TreeNode* tree1 = getSampleTree1();
  printTree(tree1);
  printVector(rightSideView(tree1));
  tree1 = getSampleTree2();
  printTree(tree1);
  printVector(rightSideView(tree1));
  tree1 = getSampleTree3();
  printTree(tree1);
  printVector(rightSideView(tree1));
}

std::vector<int> rightSideView(TreeNode* root)
{
  std::vector<int> returnValues;
  if (root==NULL) return returnValues;
  std::queue<std::pair<TreeNode*, int> > nodesQueue;
  int currHeight = -1;
  int lastValue = 0;
  std::pair<TreeNode*, int> currNodeFromQ;
  TreeNode* currNode = root;
  do
  {
    if (!nodesQueue.empty())
    {
      currNodeFromQ = nodesQueue.front();
      currNode = currNodeFromQ.first;
      currHeight = currNodeFromQ.second;
      nodesQueue.pop();
    }
    bool hasRight = ((currNode->right==NULL)?false:true);
    bool hasLeft = ((currNode->left==NULL)?false:true);
    if (hasLeft) nodesQueue.emplace(std::pair<TreeNode*, int>(currNode->left, currHeight+1));
    if (hasRight) nodesQueue.emplace(std::pair<TreeNode*, int>(currNode->right, currHeight+1));
    if (currHeight == returnValues.size()) returnValues.emplace_back(lastValue);
    lastValue = currNode->val;
  } while(!nodesQueue.empty());
  returnValues.emplace_back(lastValue);
  return returnValues;
}

#include "Functions.cc"
