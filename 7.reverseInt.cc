#include<iostream>
#include<cmath>
#include<climits>
int reverse(int x);

int main()
{
  int num = 123;
  std::cout << "Reverse of " << num << " is " << reverse(num) << std::endl;
  num = -123;
  std::cout << "Reverse of " << num << " is " << reverse(num) << std::endl;
  num = 1534236469;
  std::cout << "Reverse of " << num << " is " << reverse(num) << std::endl;
  num = 1463847412;
  std::cout << "Reverse of " << num << " is " << reverse(num) << std::endl;
}

int reverse(int x)
{
  int newNum = 0;
  bool isPositive = (x>=0);
  x = (x>=0)?x:-1*x;
  int lastNum;
  int temp;
  while (x > 0)
  {
    lastNum = x%10;
    temp = newNum*10+(lastNum);
    if (newNum != temp/10) return 0;
    newNum = temp;
    x /= 10;
  }
  return (isPositive?1:-1)*newNum;
}
