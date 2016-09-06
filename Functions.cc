void printTree(TreeNode* p, int indent)
{
  if(p != NULL)
  {
    if(p->right) printTree(p->right, indent+4);
    if (indent)  std::cout << std::setw(indent) << ' ';
    if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
    std::cout<< p->val << "\n ";
    if(p->left)
    {
      std::cout << std::setw(indent) << ' ' <<" \\\n";
      printTree(p->left, indent+4);
    }
  }
}

void printList(ListNode* head)
{
  std::cout << "List: ";
  while (head != NULL)
  {
    std::cout << head->val << "->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

TreeNode* getSampleTree1()
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
  return root;
}

TreeNode* getSampleTree2()
{
  TreeNode* root = new TreeNode(1);
  TreeNode* tmp = new TreeNode(2);
  root->left = tmp;
  tmp = new TreeNode(3);
  root->right = tmp;
  tmp = new TreeNode(4);
  root->right->left = tmp;
  tmp = new TreeNode(5);
  root->right->right = tmp;
  tmp = new TreeNode(7);
  root->left->left = tmp;
  tmp = new TreeNode(6);
  root->left->left->right = tmp;
  return root;
}

TreeNode* getSampleTree3()
{
  TreeNode* root = new TreeNode(1);
  TreeNode* tmp = new TreeNode(2);
  root->right = tmp;
  tmp = new TreeNode(3);
  root->right->left = tmp;
  return root;
}

ListNode* getSampleList1()
{
  ListNode* root = new ListNode(1);
  ListNode* tmp = new ListNode(2);
  root->next = tmp;
  tmp = new ListNode(3);
  root->next->next = tmp;
  tmp = new ListNode(4);
  root->next->next->next = tmp;
  tmp = new ListNode(5);
  root->next->next->next->next = tmp;
  return root;
}

ListNode* getSampleList2()
{
  ListNode* root = new ListNode(6);
  ListNode* tmp = new ListNode(7);
  root->next = tmp;
  tmp = new ListNode(8);
  root->next->next = tmp;
  tmp = new ListNode(9);
  root->next->next->next = tmp;
  tmp = new ListNode(10);
  root->next->next->next->next = tmp;
  return root;
}
