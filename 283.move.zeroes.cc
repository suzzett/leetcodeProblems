#include<iostream>
#include<vector>
#include "Functions.h"
void moveZeroes(std::vector<int>& nums);

int main()
{
  std::vector<int> nums({4,2,4,0,0,3,0,5,1,0});
  printVector(nums);
  moveZeroes(nums);
  printVector(nums);
}

//20 ms solution
// void moveZeroes(std::vector<int>& nums)
// {
//   int vectorSize = nums.size();
//   if (vectorSize < 2) return;
//   int currNonZeroIndex = 0;
//   int currentIndex = 0;
//   while (currentIndex < vectorSize)
//   {
//     if (nums[currentIndex] != 0) nums[currNonZeroIndex++] = nums[currentIndex];
//     currentIndex++;
//   }
//   for (unsigned int i = currNonZeroIndex; i < vectorSize; i++) nums[i] = 0;
// }

//Quick sort style solution. Goes up to 40 ms
// void moveZeroes(std::vector<int>& nums)
// {
//   int vectorSize = nums.size();
//   if (vectorSize < 2) return;
//   int swapPos = 0;
//   int index = 1;
//   while (index < vectorSize)
//   {
//     while (nums[swapPos] != 0) swapPos++;
//     index = swapPos+1;
//     if (index >= vectorSize) break;
//     while (nums[index] == 0) index++;
//     if (index >= vectorSize) break;
//     std::swap(nums[swapPos], nums[index]);
//   }
// }

//Better quick sort type solution. Still 20ms
void moveZeroes(std::vector<int>& nums)
{
  int i=0,j=0,vectorSize = nums.size();
  while(i<vectorSize)
  {
    if (!(nums[i]==0)) std::swap(nums[i],nums[j++]);
    i++;
  }
}
#include "Functions.cc"
