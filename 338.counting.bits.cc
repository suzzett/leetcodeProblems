#include<iostream>
#include "Functions.h"
std::vector<int> countBits(int num);
int totalBitsIn(int num);

int main()
{
  int n = 5;
  std::cout << "Bits for " << n << " are:" << std::endl;
  printVector(countBits(n));
}

//Dynamic programming for 84ms solution
std::vector<int> countBits(int num)
{
  std::vector<int> nums (num+1, 0);
  for (int i = 1, j = 0; i <= num;)
  {
    nums[i++] = nums[j++]+1;
    if (!(i & (i-1))) j = 0;
  }
  return nums;
}

//Recursive: 112 ms
// std::vector<int> countBits(int num)
// {
//   std::vector<int> nums;
//   for (int i = 0; i <= num; i++) nums.emplace_back(totalBitsIn(i));
//   return nums;
// }
//
// int totalBitsIn(int num)
// {
//   if (num==0) return 0;
//   else if (num==1) return 1;
//   return ((num%2)+totalBitsIn(num/2));
// }
#include "Functions.cc"
