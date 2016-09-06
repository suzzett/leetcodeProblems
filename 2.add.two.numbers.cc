#include <iostream>
#include <cmath>

struct ListNode
{
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
void printList(ListNode* l);

int main()
{
  ListNode *l1;
  ListNode *l2;

  l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  ListNode *sumResult = addTwoNumbers(l1, l2);
  printList(sumResult);
  return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
  ListNode *returnNode = NULL;
  ListNode *headReturnNode = NULL;
  int val1, val2, carry = 0;
  int num1Digits = 0;
  int num2Digits = 0;
  int sum = 0;
  while ((l1 != NULL) || (l2 != NULL) || (carry > 0))
  {
    int num1 = 0;
    int num2 = 0;
    if (l1 != NULL)
    {
      num1 = l1->val;
      l1 = l1->next;
    }
    if (l2 != NULL)
    {
      num2 = l2->val;
      l2 = l2->next;
    }
    sum = num1+num2+carry;
    carry = sum/10;
    sum = sum%10;
    ListNode *tmpNode = new ListNode(sum);
    if (headReturnNode == NULL)
    {
      headReturnNode = tmpNode;
      returnNode = tmpNode;
    }
    else
    {
      returnNode->next = tmpNode;
      returnNode = returnNode->next;
    }
  }
  return headReturnNode;
}

void printList(ListNode* l)
{
  std::cout << "List: ";
  while (l != NULL)
  {
    std::cout << l->val << "->";
    l = l->next;
  }
  std::cout << "NULL" << std::endl;;
}
