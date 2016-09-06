#include<iostream>
#include<vector>
#include<algorithm>

#include "Functions.h"
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);

int main()
{
  std::vector<int> nums1({1,2,2,1});
  std::vector<int> nums2({2,2});
  printVector(nums1);
  printVector(nums2);
  printVector(intersection(nums1,nums2));
}

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
  int vSize1 = nums1.size(), vSize2 = nums2.size();
  std::vector<int> returnVector;
  if ((vSize1 == 0) || (vSize2 == 0)) return returnVector;
  std::sort(nums1.begin(), nums1.end());
  std::sort(nums2.begin(), nums2.end());
  int pointer1=0, pointer2=0;
  int num1, num2;
  while ((pointer1<vSize1) && (pointer2<vSize2))
  {
    num1 = nums1[pointer1];
    num2 = nums2[pointer2];
    if (num1 == num2)
    {
      returnVector.emplace_back(num1);
      while (pointer1<vSize1 && nums1[pointer1]==num1) pointer1++;
      while (pointer2<vSize2 && nums2[pointer2]==num2) pointer2++;
    }
    else if (num1 < num2) pointer1++;
    else                  pointer2++;
  }
  return returnVector;
}
#include "Functions.cc"
