#include<iostream>
#include<vector>
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);

int main()
{
  std::vector<int> v1;
  std::vector<int> v2;
  v1.push_back(1);
  v2.push_back(2);
  v2.push_back(3);
  v2.push_back(4);
  std::cout << "Median is: " << findMedianSortedArrays(v1, v2) << std::endl;
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
  double median = 0;
  unsigned int size1 = nums1.size(), size2=nums2.size();
  unsigned int totalSize = size1+size2;
  if (totalSize ==0)        return 0;
  else if (nums1.empty())   return (size2%2==0?(nums2[size2/2]+nums2[(size2/2)-1])/2.0:nums2[size2/2]);
  else if (nums2.empty())   return (size1%2==0?(nums1[size1/2]+nums1[(size1/2)-1])/2.0:nums1[size1/2]);

  unsigned int nums1Counter=0, nums2Counter=0;
  unsigned int currSize = 0;
  int medianNum1, medianNum2;
  int firstMedianPos=(totalSize%2==0?(totalSize/2)-1:totalSize/2);
  int currNum = 0;
  while (currSize < totalSize && (nums1Counter<size1) && (nums2Counter<size2))
  {
    currNum = (nums1[nums1Counter] < nums2[nums2Counter])?nums1[nums1Counter]:nums2[nums2Counter];
    if (nums1[nums1Counter] < nums2[nums2Counter]) nums1Counter++;
    else nums2Counter++;
    if (currSize == firstMedianPos)
    {
      if (totalSize%2!=0) return currNum;
      if (nums1Counter>=size1) return (currNum+nums2[nums2Counter])/2.0;
      else if (nums2Counter>=size2) return (currNum+nums1[nums1Counter])/2.0;
      else return (currNum+((nums1[nums1Counter] < nums2[nums2Counter])?nums1[nums1Counter]:nums2[nums2Counter]))/2.0;
    }
    currSize++;
  }
  if ((nums1Counter>=size1))
  {
    if (totalSize%2!=0) return nums2[size2-1-firstMedianPos];
    else return ((nums2[size2-1-firstMedianPos]) + (nums2[size2-1-firstMedianPos-1]))/2.0;
  }
  if ((nums2Counter>=size2))
  {
    if (totalSize%2!=0) return nums1[size1-1-firstMedianPos];
    else return ((nums1[size1-1-firstMedianPos]) + (nums1[size1-1-firstMedianPos-1]))/2.0;
  }
  return 0;
}
//    std::cout << "nums2 expired. totalSize: " << (totalSize%2!=0) << ", nums1Counter: " << nums1Counter << ", nums2Counter: " << nums2Counter << ", firstMedianPos: " << firstMedianPos<< std::endl;
