#include<iostream>
#include<vector>
int removeDuplicates(std::vector<int>& nums);
void printVector(std::vector<int> &v);

int main()
{
  std::vector<int> nums({1,1,1,3});
  std::cout << "Total non-duplicates are: " << removeDuplicates(nums) << std::endl;
  printVector(nums);
}

//28ms solution after ont using erase
int removeDuplicates(std::vector<int>& nums)
{
  int origSize = nums.size();
  if (origSize < 2 ) return origSize;
  int i = 0;
  int currNewIndex = 0;
  int currNewSize = 1;
  while (i<origSize)
  {
    if (nums[i] != nums[currNewIndex])
    {
      currNewIndex++;
      currNewSize++;
      nums[currNewIndex] = nums[i];
    }
    i++;
  }
  return currNewSize;
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
