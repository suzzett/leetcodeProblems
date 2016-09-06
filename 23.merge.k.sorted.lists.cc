#include<iostream>
#include<vector>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode* head);
ListNode* mergeKLists(std::vector<ListNode*>& lists);
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
  std::vector<ListNode*> listVectors({head1, head2});

  printList(mergeKLists(listVectors));
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
  if (lists.size() == 1) return lists[0];
  else if (lists.size() == 0) return NULL;
  int listSize = lists.size();
  while (listSize > 1)
  {
    for (int i = 0; i < listSize/2; i++)
    {
      lists[i] = mergeTwoLists(lists[i], lists[listSize - 1 - i]);
    }
    listSize = (listSize+1)/2;
  }
  return lists[0];
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;
  if (l1->val < l2->val)
  {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  }
  else
  {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
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
