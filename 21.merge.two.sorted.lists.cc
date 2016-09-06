#include<iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode* head);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

int main()
{
  ListNode* head1;
  ListNode* tmp1;
  tmp1 = new ListNode(1);
  head1 = tmp1;
  tmp1->next = new ListNode(3);
  tmp1 = tmp1->next;
  tmp1->next = new ListNode(5);
  tmp1 = tmp1->next;
  printList(head1);
  ListNode* head2;
  ListNode* tmp2;
  tmp2 = new ListNode(2);
  head2 = tmp2;
  tmp2->next = new ListNode(4);
  tmp2 = tmp2->next;
  tmp2->next = new ListNode(6);
  tmp2 = tmp2->next;
  printList(head2);

  printList(mergeTwoLists(head1, head2));
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;
  ListNode* head = NULL;
  ListNode* tmp = NULL;

  while (l1 != NULL && l2 != NULL)
  {
    if (l1->val < l2->val)
    {
      if (tmp == NULL) tmp = l1;
      else
      {
        tmp->next = l1;
        tmp = tmp->next;
      }
      l1 = l1->next;
    }
    else
    {
      if (tmp == NULL) tmp = l2;
      else
      {
        tmp->next = l2;
        tmp = tmp->next;
      }
      l2 = l2->next;
    }
    if (head == NULL) head = tmp;
  }
  if (l1 != NULL)tmp->next = l1;
  if (l2 != NULL)tmp->next = l2;
  return head;
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
