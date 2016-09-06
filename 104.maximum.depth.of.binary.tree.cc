#include<iostream>
#include<iomanip>

struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxDepth(TreeNode* root);
int getMaxDepth(TreeNode* root, int depth);
void printPostOrder(TreeNode* p, int indent=0);


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
  std::cout << "Max depth is: " << maxDepth(root) << std::endl;
  printPostOrder(root);
  std::cout << std::endl;
}

int maxDepth(TreeNode* root)
{
  return getMaxDepth(root, 0);
}

int getMaxDepth(TreeNode* root, int depth)
{
  if (root == NULL) return depth;
  int depthRight = getMaxDepth(root->right, depth+1);
  int depthLeft = getMaxDepth(root->left, depth+1);
  return (depthRight>depthLeft?depthRight:depthLeft);
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
