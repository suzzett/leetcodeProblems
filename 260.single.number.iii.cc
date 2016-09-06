#include<iostream>
#include "Functions.h"
std::vector<int> singleNumber(std::vector<int>& nums);

int main()
{
  std::vector<int> nums({1,2,1,3,2,5});
  printVector(singleNumber(nums));
}
std::vector<int> singleNumber(std::vector<int>& nums)
{
  int bothNumbers = 0;
  for (unsigned int i = 0; i < nums.size(); i++) bothNumbers ^= nums[i];
  int lastVaryingBit = bothNumbers & (-bothNumbers);//--or-- (bothNumbers & (bothNumbers-1))^bothNumbers;
  std::vector<int> returnVal(2, 0);
  for (unsigned int i = 0; i < nums.size(); i++)
  {
    if (nums[i] & lastVaryingBit) returnVal[0] ^= nums[i];
    else returnVal[1] ^= nums[i];
  }
  return returnVal;
}
#include "Functions.cc"
