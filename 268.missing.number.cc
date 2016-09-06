#include<iostream>
#include<algorithm>

#include "Functions.h"
int missingNumber(std::vector<int>& nums);

int main()
{
  std::vector<int> nums({9,6,5,4,3,7,1,2,0});
  printVector(nums);
  std::cout << "Missing number: " << missingNumber(nums) << std::endl;
}

int missingNumber(std::vector<int>& nums)
{
  int sum = nums.size()*(nums.size()+1)/2;
  for (auto & item: nums) sum -= item;
  return sum;
}
//68 ms solution
// int missingNumber(std::vector<int>& nums)
// {
//   int vSize = nums.size();
//   if (vSize == 0) return 0;
//   if (vSize == 1) return (!nums[0]);
//   std::sort(nums.begin(), nums.end());
//   if (nums[0] != 0) return 0;
//   for (unsigned int i = 1; i < vSize; i++)
//   {
//     if (nums[i] != (nums[i-1]+1)) return nums[i-1]+1;
//   }
//   return vSize;
// }
#include "Functions.cc"
