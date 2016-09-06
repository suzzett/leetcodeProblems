#include<iostream>
#include "Functions.h"
int maxProfit(std::vector<int>& prices);
enum TREND_TYPES {NO_CHANGE, GOING_UP, GOING_DOWN};
int main()
{
  std::vector<int> prices({7, 1, 0, 4, 5, 6, 3, 6, 4});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({7, 3, 8, 2, 6, 4});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({2,1,2,1,0,1,2});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({2,7,1,4,11});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({1,2,3,4,5,6,7});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({7,6,5,4,3,2,1});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({1});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({1,2});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({1,4,2});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
  prices = std::vector<int>({2,1});
  printVector(prices);
  std::cout << "Max profit is: " << maxProfit(prices) << std::endl;
}

int maxProfit(std::vector<int>& prices)
{
  int l=prices.size();
  if(l<2) return 0;
  int profit=0;
  for(int i=1 ; i<l ; i++)
  {
    if(prices[i]>prices[i-1]) profit=profit+prices[i]-prices[i-1];
  }
  return profit;
}

/*
//Best solution: 8ms
int maxProfit(std::vector<int>& prices)
{
  int vSize = prices.size();
  if (vSize < 2) return 0;
  int trend = NO_CHANGE; // 0 = no change, 1 = going up, -1 = going down
  int currPrice;
  int totalProfit = 0;
  int prevPrice = prices[0];
  int buyPrice=prevPrice, sellPrice;
  for (unsigned int i = 1; i < vSize; i++)
  {
    currPrice = prices[i];
    if (currPrice < prevPrice)
    {
      if (trend == NO_CHANGE)
      {
        buyPrice = currPrice;
        trend = GOING_DOWN;
      }
      else if (trend == GOING_UP)
      {
        //Calculate profit here...
        sellPrice = prevPrice;
        std::cout << i << ". Buy at: " << buyPrice << ", Sell at: " << sellPrice << std::endl;
        totalProfit += (sellPrice - buyPrice);
        buyPrice = currPrice;
        sellPrice = 0;
        trend = NO_CHANGE;
      }
      else
      {
        buyPrice = currPrice;
        trend = GOING_DOWN;
      }
    }
    else trend = GOING_UP;
    prevPrice = currPrice;
  }
  if (buyPrice < prices[vSize-1]) totalProfit += (prices[vSize-1]-buyPrice);
  return totalProfit;
}
*/
#include "Functions.cc"
