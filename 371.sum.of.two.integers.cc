#include<iostream>
int getSum(int a, int b);

int main()
{
  int a = -1;
  int b = 1;
  std::cout << a << " + " << b << " = " << getSum(a,b) << std::endl;
}

int getSum(int a, int b)
{
  while (b!=0)
  {
    int carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return a;
}
