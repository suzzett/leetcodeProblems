#include<iostream>
#include<unordered_map>
#include<queue>
#include<algorithm>

#include "Functions.h"
std::vector<int> topKFrequent(std::vector<int>& nums, int k);

int main()
{
  std::vector<int> nums({3,1,5,1,5,2,3,5,1,2,2});
  printVector(topKFrequent(nums, 3));
  std::sort(nums.begin(), nums.end());
  printVector(nums);
}

//36 ms solution
std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
  int vSize = nums.size();
  std::vector<int> output;
  std::unordered_map<int, int> freqDist;
  for (auto n: nums) freqDist[n]++;
  std::priority_queue<std::pair<int, int> > maxHeap;
  for (auto freqPair: freqDist) maxHeap.emplace(freqPair.second, freqPair.first);
  while (k-->0)
  {
    output.push_back(maxHeap.top().second);
    maxHeap.pop();
  }
  return output;
}

//Time limit exceeding solution
// std::vector<int> topKFrequent(std::vector<int>& nums, int k)
// {
//   int vSize = nums.size();
//   std::vector<int> output;
//   std::vector<int> freq;
//   std::vector<int> value;
//   int currNum;
//   for (unsigned int i = 0; i < vSize; i++)
//   {
//     currNum = nums[i];
//     int pos = std::find(value.begin(), value.end(), currNum) - value.begin();
//     if (pos >= value.size())
//     {
//       value.push_back(currNum);
//       freq.push_back(1);
//     }
//     else
//     {
//       freq.at(pos)++;
//     }
//   }
//   for (int i = 0; i < k; i++)
//   {
//     int currLargestFreqVal = 0;
//     int currLargestFreq = 0;
//     for (unsigned int i = 0; i < freq.size(); i++)
//     {
//       if ((freq[i] >= currLargestFreq) && ((std::find(output.begin(), output.end(), value[i]) == output.end())))
//       {
//         currLargestFreq = freq[i];
//         currLargestFreqVal = value[i];
//       }
//     }
//     output.emplace_back(currLargestFreqVal);
//   }
//   return output;
// }
//460 ms solution
// std::vector<int> topKFrequent(std::vector<int>& nums, int k)
// {
//   int vSize = nums.size();
//   std::vector<int> output;
//   std::unordered_map<int, int> freqDist;
//   for (unsigned int i = 0; i < vSize; i++)
//   {
//     if (freqDist.find(nums[i]) != freqDist.end()) freqDist.at(nums[i])++;
//     else freqDist.emplace(nums[i], 1);
//   }
//   int freqsSize = freqDist.size();
//   std::vector<int> freqs;
//
//   for (auto& x: freqDist) freqs.emplace_back(x.second);
//   std::sort(freqs.begin(), freqs.end());
//   int lastLargest = 0;
//   int lastLargestVal = 0;
//   int largestFreq = 0;
//   for (int i = freqsSize-1; i > freqsSize-k-1; i--)
//   {
//     for (auto& x: freqDist)
//     {
//       if ((x.second == freqs[i]) && (std::find(output.begin(), output.end(), x.first) == output.end()))
//       {
//         output.emplace_back(x.first);
//         break;
//       }
//     }
//   }
//   return output;
// }
//72 ms solution
// std::vector<int> topKFrequent(std::vector<int>& nums, int k)
// {
//   int vSize = nums.size();
//   std::vector<int> output(k, 0);
//   std::vector<int> outputFreq(k, 0);
//   std::sort(nums.begin(), nums.end());
//   for (unsigned int i = 0; i < vSize; i++)
//   {
//     int currFreq = 1;
//     int currNum = nums[i];
//     while (i<vSize && currNum == nums[i+1]) {currFreq++; i++;}
//     if (currFreq >= outputFreq[0])
//     {
//       for (int j = k-1; j >= 0; j--)
//       {
//         if (currFreq >= outputFreq[j])
//         {
//           int tmp, tmp2;
//           while (j>=0)
//           {
//             tmp2 = output[j];
//             output[j] = currNum;
//             currNum = tmp2;
//             tmp = outputFreq[j];
//             outputFreq[j] = currFreq;
//             currFreq = tmp;
//             j--;
//           }
//         }
//       }
//     }
//   }
//   return output;
// }
#include "Functions.cc"
