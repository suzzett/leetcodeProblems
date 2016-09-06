#include<iostream>
#include "Functions.h"
ListNode* reverseList(ListNode* head);

int main()
{
  ListNode *root = getSampleList1();
  printList(root);
  printList(reverseList(root));
}
ListNode* reverseList(ListNode* head)
{
  if (head==NULL || head->next==NULL) return head;
  ListNode* reverseList;
  ListNode* tmp;
  ListNode* tail = head;
  while (tail->next != NULL)
  {
    tmp = tail->next;
    tail->next = tmp->next;
    tmp->next = head;
    head = tmp;
  }
  return tmp;
}
#include "Functions.cc"
