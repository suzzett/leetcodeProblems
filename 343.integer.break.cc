#include<iostream>
int integerBreak(int n);

int main()
{
  int n = 4;
  std::cout << "Maximum product is: " << integerBreak(n) << std::endl;
  n = 10;
  std::cout << "Maximum product " << n << " is: " << integerBreak(n) << std::endl;
  n = 15;
  std::cout << "Maximum product " << n << " is: " << integerBreak(n) << std::endl;
}

int integerBreak(int n)
{
  if (n < 4) return n-1;
  int currProduct = 1;
  while (n > 4)
  {
    currProduct *= 3;
    n -= 3;
  }
  return currProduct*n;
}
