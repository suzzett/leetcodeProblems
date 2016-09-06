#include<iostream>
#include<algorithm>
#include<unordered_map>
#include "Functions.h"
std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);

int main()
{
  std::vector<int> nums1({1, 2, 2, 1,3,4,5,6,6,7});
  std::vector<int> nums2({2, 2, 9, 8, 1, 5});
  printVector(nums1);
  printVector(nums2);
  printVector(intersect(nums1, nums2));
  std::cout << "=======================================" << std::endl;
  nums1 = std::vector<int>({1});
  nums2 = std::vector<int>({1});
  printVector(nums1);
  printVector(nums2);
  printVector(intersect(nums1, nums2));
  std::cout << "=======================================" << std::endl;
  nums1 = std::vector<int>({1});
  nums2 = std::vector<int>({1,2});
  printVector(nums1);
  printVector(nums2);
  printVector(intersect(nums1, nums2));
  std::cout << "=======================================" << std::endl;
  nums1 = std::vector<int>({1,2,2,1});
  nums2 = std::vector<int>({2});
  printVector(nums1);
  printVector(nums2);
  printVector(intersect(nums1, nums2));
  std::cout << "=======================================" << std::endl;
  nums1 = std::vector<int>({2,1});
  nums2 = std::vector<int>({1,2});
  printVector(nums1);
  printVector(nums2);
  printVector(intersect(nums1, nums2));
  std::cout << "=======================================" << std::endl;
  nums1 = std::vector<int>({9,3,7});
  nums2 = std::vector<int>({6,4,1,0,0,4,4,8,7});
  printVector(nums1);
  printVector(nums2);
  printVector(intersect(nums1, nums2));
}

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
{
  std::vector<int> returnVector;
  int vSize1 = nums1.size();
  int vSize2 = nums2.size();
  if (vSize1 < 0 && vSize2 < 0) return returnVector;
  std::unordered_map<int, int> nums1Freq;
  std::unordered_map<int, int> nums2Freq;
  for (auto & item: nums1) nums1Freq[item]++;
  for (auto & item: nums2) nums2Freq[item]++;
  int totalNums = 0;
  int currNum = -1;
  for (auto & item: nums1Freq)
  {
    if (item.second > 0 && nums2Freq[item.first] > 0)
    {
      totalNums = std::min(item.second, nums2Freq[item.first]);
      currNum = item.first;
      for (int i = 0; i < totalNums; i++)
      {
        returnVector.emplace_back(currNum);
      }
    }
  }
  return returnVector;
}
//12ms
// std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
// {
//   std::vector<int> returnVector;
//   int vSize1 = nums1.size()-1;
//   int vSize2 = nums2.size()-1;
//   if (vSize1 < 0 && vSize2 < 0) return returnVector;
//   std::sort(nums1.begin(), nums1.end());
//   std::sort(nums2.begin(), nums2.end());
//   int num1 = 0, num2 = 0;
//   while (vSize1>=0 && vSize2>=0)
//   {
//     std::cout << "V1: " << vSize1 << " = " << nums1[vSize1] << ", V2: ";
//     while (vSize1>=0 && (nums1[vSize1] > nums2[vSize2])) vSize1--;
//     std::cout << vSize2 << " = " << nums2[vSize2] << std::endl;
//     while (vSize2>=0 && (nums2[vSize2] > nums1[vSize1])) vSize2--;
//     if (vSize1<0 || vSize2<0) break;
//     num1 = nums1[vSize1];
//     num2 = nums2[vSize2];
//     if (num1==num2)
//     {
//       std::cout << "Insert Now " << vSize1 << " = " << nums1[vSize1] << ", V2: ";
//       std::cout << vSize2 << " = " << nums2[vSize2] << std::endl;
//       returnVector.emplace_back(num1);
//       vSize1--;
//       vSize2--;
//     }
//   }
//   return returnVector;
// }

#include "Functions.cc"
