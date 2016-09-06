#include<iostream>
#include "Functions.h"
#include <climits>
int maxProfit(std::vector<int>& prices);

int main()
{
  std::vector<int> prices({7, 1, 5, 3, 6, 4});
  //std::vector<int> prices({7, 3, 8, 2, 6, 4});
  //std::vector<int> prices({2,1,2,1,0,1,2});
  //std::vector<int> prices({2,7,1,4,11});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
}

int maxProfit(std::vector<int>& prices)
{
  int maxProfit = 0;
  int minPrice = INT_MAX;
  int vSize = prices.size();
  for(int i = 0; i < vSize; ++i)
  {
    minPrice  = std::min(minPrice,  prices[i]);
    maxProfit = std::max(maxProfit, prices[i] - minPrice);
  }
  return maxProfit;
}

#include "Functions.cc"
