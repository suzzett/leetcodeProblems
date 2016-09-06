#include<iostream>
#include<vector>
#include "Functions.h"

void deleteNode(ListNode* node);

int main()
{
  ListNode* root = new ListNode(1);
  ListNode* nodeToDelete;
  ListNode* tmp = new ListNode(2);
  root->next = tmp;
  tmp = new ListNode(3);
  root->next->next = tmp;
  tmp = new ListNode(4);
  root->next->next->next = tmp;
  tmp = new ListNode(5);
  nodeToDelete = tmp;
  root->next->next->next->next = tmp;
  printList(root);
  deleteNode(nodeToDelete);
  printList(root);
}

//16 ms solution
void deleteNode(ListNode* node)
{
  if (node->next == NULL) return;
  ListNode* nextPtr = node->next;
  node->val = nextPtr->val;
  node->next = nextPtr->next;
  delete nextPtr;
}

#include "Functions.cc"
