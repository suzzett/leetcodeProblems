#include<iomanip>
#include<vector>
struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
template <class T, class U>
void printPairVector(std::vector<std::pair<T, U> > v)
{
  std::cout << "Vector: ";
  for(auto const& value: v) std::cout << " (" << value.first << ", " << value.second << ")";
  std::cout << std::endl;
  std::cout << "Size: " << v.size() << std::endl;
}

template <class T>
void printVector(std::vector<T> v)
{
  std::cout << "Vector: ";
  for(auto const& value: v) std::cout << " " << value;
  std::cout << std::endl;
  std::cout << "Size: " << v.size() << std::endl;
}
template <class T>
void printVector2D(std::vector<std::vector<T> > v)
{
  std::cout << std::endl << "Vector: " << std::endl;
  int i = 0;
  for(auto const& singleDimVector: v)
  {
    std::cout << "  " << i++ << ": [";
    int j = 0;
    for (auto const& value: singleDimVector) {std::cout << (j==0?"":", ") << value;j++;}
    std::cout << "]" << std::endl;
  }
  std::cout << "Size: " << v.size() << std::endl;
}
void printTree(TreeNode* p, int indent=0);
void printList(ListNode* head);
TreeNode* getSampleTree1();
TreeNode* getSampleTree2();
TreeNode* getSampleTree3();
ListNode* getSampleList1();
ListNode* getSampleList2();
