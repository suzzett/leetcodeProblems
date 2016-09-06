#include<iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);
void printVector(std::vector<int> v);

int main()
{
  std::vector<int> nums({1, 0, -1, 0, -2, 2});
  std::cout << "total unique sums: " << fourSum(nums, 0).size() << std::endl;
  std::vector<int> nums1({-1, 0, 1, 2, -1, -4});
  std::cout << "total unique sums: " << fourSum(nums1, -1).size() << std::endl;
  //printVector(nums1);
}

//20 ms solution reduced from 128 ms by adding the checks for continue and break;
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
  std::vector<std::vector<int>> returnVector;
  if (nums.size()<4) return returnVector;
  std::sort(nums.begin(), nums.end());
  int currentSum = 0;
  unsigned int vectorSize = nums.size();

  for (unsigned int i = 0; i < vectorSize-3; i++)
  {
    if (i>0 && nums[i] == nums[i-1]) continue;
    if((nums[i]+nums[i+1]+nums[i+2]+nums[i+3])>target) break;
    if(nums[i]+nums[vectorSize-3]+nums[vectorSize-2]+nums[vectorSize-1]<target) continue;
    for (unsigned int j = i+1; j < vectorSize-2;j++)
    {
      if (j>(i+1) && nums[j] == nums[j-1]) continue;
      if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
      if(nums[i]+nums[j]+nums[vectorSize-2]+nums[vectorSize-1]<target) continue;
      int k = j+1, l = vectorSize-1;
      while (k < l)
      {
        currentSum = nums[i]+nums[j]+nums[k]+nums[l];
        if (currentSum < target)
        {
          k++;
          while ((nums[k] == nums[k-1]) && (k < l)) k++;
        }
        else if (currentSum > target)
        {
          l--;
          while ((nums[l] == nums[l+1]) && (k < l)) l--;
        }
        else
        {
          returnVector.push_back(std::vector<int>({nums[i], nums[j], nums[k], nums[l]}));
          l--;
          while ((nums[l] == nums[l+1]) && (k < l)) l--;
        }
      }
    }
  }
  return returnVector;
}

void printVector(std::vector<int> v)
{
  std::cout << "Vector: ";
  for (unsigned int i = 0; i < v.size(); i++)
  {
    std::cout << (i==0?"":",")+v[i];
  }
  std::cout << std::endl;
}
