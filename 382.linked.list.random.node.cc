#include<iostream>
#include "Functions.h"
class Solution
{
  private:
    ListNode* head;
  public:
    /** @param head The linked list's head.
     * Note that the head is guaranteed to be not null, so it contains at least one node.
    **/
    Solution(ListNode* head);

    /** Returns a random node's value. */
    int getRandom();
};

int main()
{
  ListNode* list = getSampleList1();
  printList(list);
  Solution s(list);
  std::cout << "Random node is: " << s.getRandom() << std::endl;
}

Solution::Solution(ListNode* head)
{
  srand (time(NULL));
  this->head = head;
}

//60ms regular solution
// int Solution::getRandom()
// {
//   ListNode* tmp = head;
//   int total = 0;
//   while (tmp)
//   {
//     total++;
//     tmp = tmp->next;
//   }
//   int randomIndex = rand()%total;
//   tmp = head;
//   while (randomIndex-->0) tmp = tmp->next;
//   return tmp->val;
// }

//Using reservoir sampling for 76ms solution
int Solution::getRandom()
{
  ListNode* tmp = head;
  int total = 0;
  int result = 0;
  while (tmp)
  {
    total++;
    if (rand()%total == 0) result = tmp->val;
    tmp = tmp->next;
  }
  return result;
}

#include "Functions.cc"
