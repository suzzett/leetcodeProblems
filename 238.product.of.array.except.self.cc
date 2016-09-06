#include<iostream>
#include "Functions.h"
std::vector<int> productExceptSelf(std::vector<int>& nums);

int main()
{
  std::vector<int> v({1,2,3,4,5});
  printVector(productExceptSelf(v));
}

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
  int vSize = nums.size();
  std::vector<int> output(vSize, 1);
  int multiplesFromEnd = 1, multiplesFromFront = 1;
  for (unsigned int i = 0; i < vSize-1; i++)
  {
    multiplesFromFront *= nums[i];
    multiplesFromEnd *= nums[vSize-i-1];
    output[i+1] *= multiplesFromFront;
    output[vSize-i-2] *= multiplesFromEnd;
  }
  return output;
}
#include "Functions.cc"
