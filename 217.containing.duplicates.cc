#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include "Functions.h"
bool containsDuplicate(std::vector<int>& nums);

int main()
{
  std::vector<int> nums({3,5,6,7,2,1,9});
  printVector(nums);
  std::cout << "Vector does " << (containsDuplicate(nums)?"":"not ") << "have dupplicates" << std::endl;
}

//lIME LIMIT EXCEEDS
// bool containsDuplicate(std::vector<int>& nums)
// {
//   int vSize = nums.size();
//   if (vSize < 1) return false;
//   for (unsigned int i = 0; i < vSize; i++)
//   {
//     if ( std::find(nums.begin(), nums.end()-(vSize-i), nums[i]) != (nums.end()-(vSize-i))) return true;
//   }
//   return false;
// }

//Sorting method for 40 ms solution
bool containsDuplicate(std::vector<int>& nums)
{
  int vSize = nums.size();
  if (vSize < 1) return false;
  std::sort(nums.begin(), nums.end());
  for (unsigned int i = 0; i < vSize-1; i++)
  {
    if (nums[i] == nums[i+1]) return true;
  }
  return false;
}
//using map: 52ms solution
// bool containsDuplicate(std::vector<int>& nums)
// {
//   std::unordered_map<int, int> freqCounter;
//   for (unsigned int i = 0; i < nums.size(); i++)
//   {
//     freqCounter[nums[i]]++;
//     if (freqCounter[nums[i]] > 1) return true;
//   }
//   return false;
// }
#include "Functions.cc"
