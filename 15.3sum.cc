#include<iostream>
#include<vector>
#include<algorithm>
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

int main()
{
  std::vector<int> nums({-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0});
  std::cout << "total unique sums: " << threeSum(nums).size() << std::endl;
}

//56ms solution
std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
  std::vector<std::vector<int> > returnSum;
  if (nums.size() < 3) return returnSum;
  std::sort(nums.begin(), nums.end());
  int numsLen = nums.size();
  int currentSum = 0;
  for (unsigned int i = 0; i < numsLen-2; i++)
  {
    if (nums[i] > 0) break;
    if (!(i>0 && nums[i]==nums[i-1]))
    {
      int j=i+1, k=numsLen-1;
      while (j<k)
      {
        currentSum = nums[i]+nums[j]+nums[k];
        if (currentSum < 0)
        {
          j++;
          while ((nums[j] == nums[j-1]) && (j < k)) j++;
        }
        else if (currentSum > 0)
        {
          k--;
          while ((k<(numsLen-1)) && (nums[k] == nums[k+1]) && (k >= j)) k--;
        }
        else
        {
          returnSum.push_back(std::vector<int>({nums[i],nums[j],nums[k]}));
          k--;
          while ((k<(numsLen-1)) && (nums[k] == nums[k+1]) && (k >= j)) k--;
        };
      }
    }
  }
  return returnSum;
}
