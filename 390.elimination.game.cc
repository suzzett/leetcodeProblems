#include<iostream>
#include "Functions.h"
int lastRemaining(int n);

int main()
{
  int n = 6;
  std::cout << "Last remaining: " << lastRemaining(n) << std::endl;
}
int lastRemaining(int n)
{
  std::vector<int> numsVector(n,0);
  int totalNums = 0;
  bool removeThis = true;
  for (unsigned int i = 0; i < n; i++)
  {
    if (!removeThis)
    {
      numsVector[i] = i+1;
      totalNums++;
    }
    removeThis = !removeThis;
  }
  printVector(numsVector);
  bool reverse = true;
  while (totalNums > 1)
  {
    int currIndex;
    removeThis = false;
    totalNums=0;
    for (unsigned int i = 0; i < n; i++)
    {
      currIndex = (reverse)?n-i-1:i;
      if (numsVector[currIndex] != 0) removeThis = !removeThis;
      if (numsVector[currIndex] != 0 && removeThis) numsVector[currIndex] = 0;
      if (numsVector[currIndex] != 0) totalNums++;
    }
    printVector(numsVector);
    std::cout << totalNums << std::endl;
    reverse = !reverse;
  }
  for (auto &item: numsVector) if (item!=0) return item;
  return n;
}

#include "Functions.cc"
