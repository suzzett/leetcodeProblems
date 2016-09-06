#include<iostream>
#include<unordered_map>
#include<vector>

#include "Functions.h"

int majorityElement(std::vector<int>& nums);

int main()
{
  std::vector<int> nums({1,1,5,5,5,2,1,5,1,6,2,5,2,1,2,1,1,5,5,5,5,5,5,5});
  printVector(nums);
  std::cout << "Majority element is: " << majorityElement(nums) << std::endl;
}

//Solution with Moore Voting
int majorityElement(std::vector<int>& nums)
{
  int vSize = nums.size();
  int candidate = nums[0];
  int totalVotes = 0;
  for (unsigned int i = 0; i < vSize; i++)
  {
    if (totalVotes == 0) candidate = nums[i];
    if (candidate == nums[i]) totalVotes++;
    else totalVotes--;
  }
  return candidate;
}


//Regular solution with 28ms
// int majorityElement(std::vector<int>& nums)
// {
//   int vSize = nums.size();
//   std::unordered_map<int, int> freqs;
//   for (unsigned int i = 0; i < (vSize/2)+1; i++)
//   {
//     freqs[nums[i]]++;
//     freqs[nums[vSize-i-1]]++;
//   }
//   for (auto & item: freqs)    if (item.second > vSize/2) return item.first;
//   return -1;
// }

#include "Functions.cc"
