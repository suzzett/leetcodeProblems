#include<iostream>
#include<iomanip>

struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printPostOrder(TreeNode* p, int indent=0);
TreeNode* invertTree(TreeNode* root);
void invertSubTree(TreeNode* root);

int main()
{
  TreeNode* root = new TreeNode(5);
  TreeNode* tmp = new TreeNode(15);
  root->left = tmp;
  tmp = new TreeNode(25);
  root->right = tmp;
  tmp = new TreeNode(35);
  root->right->left = tmp;
  tmp = new TreeNode(45);
  root->right->right = tmp;
  tmp = new TreeNode(55);
  root->left->right = tmp;
  tmp = new TreeNode(65);
  root->left->left = tmp;
  std::cout << "Before invert : " << std::endl;
  printPostOrder(root);
  root = invertTree(root);
  std::cout << "After invert : " << std::endl;
  printPostOrder(root);
  std::cout << std::endl;
}


TreeNode* invertTree(TreeNode* root)
{
  invertSubTree(root);
  return root;
}

void invertSubTree(TreeNode* root)
{
  if ((root==NULL) || (root->left == NULL && root->right==NULL)) return;
  TreeNode* leftTree = root->left;
  TreeNode* rightTree = root->right;
  invertSubTree(leftTree);
  invertSubTree(rightTree);
  root->right = leftTree;
  root->left = rightTree;
}

void printPostOrder(TreeNode* p, int indent)
{
  if(p != NULL)
  {
    if(p->right) printPostOrder(p->right, indent+4);
    if (indent)  std::cout << std::setw(indent) << ' ';
    if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
    std::cout<< p->val << "\n ";
    if(p->left)
    {
      std::cout << std::setw(indent) << ' ' <<" \\\n";
      printPostOrder(p->left, indent+4);
    }
  }
}
