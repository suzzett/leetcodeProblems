#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
int threeSumClosest(std::vector<int>& nums, int target);

int main()
{
  std::vector<int> nums({6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10});
  std::cout << "total unique sums: " <<  threeSumClosest(nums, -52) << std::endl;
  std::vector<int> nums1({1,1,1,0});
  std::cout << "total unique sums: " <<  threeSumClosest(nums1, 100) << std::endl;
}

//16ms solution
int threeSumClosest(std::vector<int>& nums, int target)
{
  if (nums.size() < 3) return 0;
  std::sort(nums.begin(), nums.end());
  int currentSumOfSmallest = nums[0]+nums[1]+nums[2];
  if (nums.size() == 3) return currentSumOfSmallest;
  int numsLen = nums.size();
  int currentSum = 0;
  int smallestTarget = INT_MAX;
  int currDiff = 0;
  for (unsigned int i = 0; i < numsLen-2; i++)
  {
    int j = i+1, k = numsLen-1, prevDiff = 0;
    while (j < k)
    {
      currentSum = nums[i]+nums[j]+nums[k];
      currDiff = std::abs(currentSum-target);
      if (currentSum == target)
      {
        return currentSum;
      }
      if (smallestTarget > currDiff)
      {
        smallestTarget = currDiff;
        currentSumOfSmallest = currentSum;
      }
      if (currentSum < target)
      {
        j++;
        while ((nums[j] == nums[j-1]) && (j < k)) j++;
      }
      else
      {
        k--;
        while ((nums[k] == nums[k+1]) && (j < k)) k--;
      }
    }
  }
  return currentSumOfSmallest;
}
