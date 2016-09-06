#include<iostream>
#include<vector>

int removeElement(std::vector<int>& nums, int val);
void printVector(std::vector<int> &v);

int main()
{
  std::vector<int> nums({1});
  std::cout << "Total non-duplicates are: " << removeElement(nums, 1) << std::endl;
  printVector(nums);
}

int removeElement(std::vector<int>& nums, int val)
{
  int vSize = nums.size();
  if (vSize < 1) return vSize;
  int currIndex = 0;
  for (unsigned int i = 0; i < vSize; i++)
  {
    if (nums[i] != val)
    {
      nums[currIndex] = nums[i];
      currIndex++;
    }
  }
  return currIndex;
}

void printVector(std::vector<int> &v)
{
  std::cout << "Vector size: "<<  v.size() << ", Values:  ";
  for (unsigned int i = 0; i < v.size(); i++)
  {
    std::cout << " " << v[i];
  }
  std::cout << std::endl;
}
