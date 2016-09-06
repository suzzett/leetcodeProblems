#include<iostream>
#include "Functions.h"

std::vector<int> twoSum(std::vector<int>& numbers, int target);

int main()
{
  std::vector<int> nums({2,7,11,15});
  int target = 9;
  printVector(twoSum(nums,target));
}

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
  int pointer1 = 0, pointer2 = numbers.size()-1;
  while (pointer1 < pointer2)
  {
    if      ((numbers[pointer1] + numbers[pointer2]) < target) pointer1++;
    else if ((numbers[pointer1] + numbers[pointer2]) > target) pointer2--;
    else    return std::vector<int>({pointer1+1, pointer2+1});
  }
  return std::vector<int>();
}
#include "Functions.cc"
