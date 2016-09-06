#include<iostream>
#include "Functions.h"
class Solution
{
  private:
    std::vector<int> nums;
    int vSize = 0;
  public:
    Solution(std::vector<int> nums);
    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset();
    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle();
};

int main()
{
  std::vector<int> nums({1,2,3,4,5});
  Solution s(nums);
  printVector(s.shuffle());
  printVector(s.reset());
}

Solution::Solution(std::vector<int> nums)
{
  this->nums = nums;
  vSize = nums.size();
  srand(time(NULL));
}

std::vector<int> Solution::reset()
{
  return this->nums;
}

std::vector<int> Solution::shuffle()
{
  if (vSize == 0) return std::vector<int>();
  std::vector<int> newNums(vSize, 0);
  bool usedNums[vSize] = {false};
  int totalRemaining = vSize;
  int currentIndex = 0;
  while (totalRemaining-->0)
  {
    currentIndex = rand()%vSize;
    while (usedNums[currentIndex]) currentIndex = rand()%vSize;
    usedNums[currentIndex] = true;
    newNums[totalRemaining] = nums[currentIndex];
  }
  return newNums;
}

#include "Functions.cc"
