#include<iostream>
int addDigits(int num);

int main()
{
  int n = 123;
  std::cout << n << " is added to " << addDigits(n) << std::endl;
  n = 123589735;
  std::cout << n << " is added to " << addDigits(n) << std::endl;
}

// int addDigits(int num)
// {
//   bool isNegative = (num<0);
//   if (isNegative) num = -num;
//   if (num < 10) return num;
//   int sum = num;
//   while (sum > 9)
//   {
//     int tmpNum = sum;
//     sum = 0;
//     while (tmpNum>0)
//     {
//       sum += tmpNum%10;
//       tmpNum /= 10;
//     }
//   }
//   return sum;
// }
//
//Mathematical answer
int addDigits(int num)
{
  return (1+((num-1)%9));
}
