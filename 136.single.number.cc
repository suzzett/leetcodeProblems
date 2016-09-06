#include<iostream>
#include "Functions.h"
int singleNumber(std::vector<int>& nums);

int main()
{
  std::vector<int> nums({12, 11, 10, 12, 10});
  std::cout << "Single number is given list is: " << singleNumber(nums) << std::endl;
}
int singleNumber(std::vector<int>& nums)
{
  unsigned int vSize = nums.size();
  int singleValue = 0;
  for (unsigned int i = 0; i < vSize; i++) singleValue ^= nums[i];
  return singleValue;
}
#include "Functions.cc"
