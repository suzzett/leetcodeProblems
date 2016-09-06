#include<iostream>
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode* head);
ListNode* reverseKGroup(ListNode* head, int k);

int main()
{
  ListNode* head1;
  ListNode* tmp1;
  tmp1 = new ListNode(1);
  head1 = tmp1;
  tmp1->next = new ListNode(2);
  tmp1 = tmp1->next;
  tmp1->next = new ListNode(3);
  tmp1 = tmp1->next;
  tmp1->next = new ListNode(4);
  tmp1 = tmp1->next;
  tmp1->next = new ListNode(5);
  tmp1 = tmp1->next;
  tmp1->next = new ListNode(6);
  printList(head1);

  printList(reverseKGroup(head1, 2));
  tmp1 = new ListNode(1);
  head1 = tmp1;
  tmp1->next = new ListNode(2);
  tmp1 = tmp1->next;
  tmp1->next = new ListNode(3);
  tmp1 = tmp1->next;
  tmp1->next = new ListNode(4);
  tmp1 = tmp1->next;
  tmp1->next = new ListNode(5);
  tmp1 = tmp1->next;
  //printList(reverseKGroup(head1, 3));
}

ListNode* reverseKGroup(ListNode* head, int k)
{
  if (head == NULL || head->next==NULL || k==1) return head;
  ListNode* origHead = NULL;
  ListNode* lastTail = NULL;
  while (head!=NULL)
  {
    ListNode* tmpHead = head;
    int i = k;
    bool doReverse = true;
    while (i-->0)
    {
      if (tmpHead == NULL)
      {
        doReverse = false;
        break;
      }
      tmpHead = tmpHead->next;
    }
    if (doReverse)
    {
      ListNode* listTail = NULL;
      for (int j = 0; j < k-1; j++)
      {
        if (listTail == NULL) listTail = head;
        ListNode* tmp = listTail->next;
        listTail->next = listTail->next->next;
        tmp->next = head;
        head = tmp;
      }
      if (origHead==NULL) origHead = head;
      if (lastTail == NULL) lastTail = listTail;
      else
      {
        lastTail->next = head;
        lastTail = listTail;
      }
      head = listTail->next;
    }
    else break;
  }
  return origHead==NULL?head:origHead;
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
