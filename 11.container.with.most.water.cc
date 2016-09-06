#include<iostream>
#include<vector>
int maxArea(std::vector<int>& height);

int main()
{
  std::vector<int> heights({1,2,3,4,5,6,7});
  std::cout << "Max area is: " << maxArea(heights) << std::endl;
}

int maxArea(std::vector<int>& height)
{
  int endPointer = height.size()-1;
  int frontPointer = 0, currentHeight = 0, currentArea = 0, maxAreaValue = 0, breadth = endPointer;
  while (frontPointer < endPointer)
  {
    currentHeight = (height[frontPointer]<height[endPointer])?height[frontPointer++]:height[endPointer--];
    currentArea = currentHeight*breadth;
    maxAreaValue = (currentArea>maxAreaValue?currentArea:maxAreaValue);
    //std::cout << "Max area now: " << maxAreaValue << " at b=" << (endPointer-frontPointer) << ", height: " << currentHeight<< std::endl;
    breadth--;
  }
  return maxAreaValue;
}
