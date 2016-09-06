#include<iostream>
#include<vector>


struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n);
void printList(ListNode* head);

int main()
{
  ListNode* head;
  ListNode* tmp;
  tmp = new ListNode(1);
  head = tmp;
  //std::cout << head << " = head, " << tmp << " = tmp" << std::endl;
  tmp->next = new ListNode(2);
  tmp = tmp->next;
  // tmp->next = new ListNode(3);
  // tmp = tmp->next;
  // tmp->next = new ListNode(4);
  // tmp = tmp->next;
  // tmp->next = new ListNode(5);
  // tmp = tmp->next;
  //std::cout << head << " = head, " << head->next << " = headNext, " << tmp << " = tmp" << std::endl;
  printList(head);
  head = removeNthFromEnd(head, 1);
  printList(head);
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
  ListNode* origHead = NULL;
  std::vector<ListNode*> allNodes;
  while (head != NULL)
  {
    allNodes.push_back(head);
    head = head->next;
  }
  if (allNodes.size() < 2) return origHead;

  allNodes.erase(allNodes.end()-n);

  origHead = allNodes[0];
  ListNode* tmp = origHead;
  for (unsigned int i = 1; i < allNodes.size(); i++)
  {
    tmp->next = allNodes[i];
    tmp = tmp->next;
  }
  tmp->next = NULL;
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
