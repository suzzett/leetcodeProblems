#include<iostream>
#include<cmath>
#include<climits>

int divide(int dividend, int divisor);

int main()
{
  int dividend = 19;
  int divisor = 3;
  std::cout << dividend << "/" << divisor << " = " << divide(dividend, divisor) << std::endl;
  dividend = -2147483648;
  divisor = -1;
  std::cout << dividend << "/" << divisor << " = " << divide(dividend, divisor) << std::endl;
}

int divide(int dividend, int divisor)
{
  if (dividend == INT_MAX && divisor == -1) return INT_MIN;
  else if (dividend == INT_MIN && divisor == -1) return INT_MAX;
  bool isPositive = ((dividend>=0 && divisor>=0) || (dividend<0 && divisor<0))?true:false;
  dividend = std::abs(dividend);
  divisor = std::abs(divisor);
  int quotient = 0;
  while (dividend >= divisor)
  {
    dividend -= divisor;
    quotient++;
  }
  return (isPositive?quotient:0-quotient);
}
