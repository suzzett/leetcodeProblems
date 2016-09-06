#include<iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* swapPairs(ListNode* head);
void printList(ListNode* head);

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
  printList(head1);

  printList(swapPairs(head1));
}

ListNode* swapPairs(ListNode* head)
{
  if (head==NULL || head->next == NULL) return head;
  ListNode* origHead = NULL;
  ListNode* prevNode = NULL;
  while (head != NULL && head->next != NULL)
  {
    ListNode* tmp = head->next;
    if (origHead == NULL) origHead = tmp;
    if (prevNode != NULL) prevNode->next = tmp;
    head->next = tmp->next;
    tmp->next = head;
    prevNode = head;
    head = head->next;
  }
  return origHead;
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
