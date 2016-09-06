#include<iostream>
#include<cmath>
int bulbSwitch(int n);

int main()
{
  for (unsigned int i = 1; i <= 200; i++)
  {
    std::cout << i << "^2 = " << i*i << std::endl;
  }
  for (unsigned int i = 1; i <= 99999; i+=100)
  {
    int n = i;
    std::cout << "There are " << bulbSwitch(n) << " turned on bulbs out of " << n << " bulbs." << std::endl;
  }
}

int bulbSwitch(int n)
{
  return sqrt(n);
  //Other solution
  // int totalOn = 0;
  // int sqrtN = sqrt(n);
  // for (int i = 1; i <= sqrtN; i++) totalOn += (n >= (i*i));
  // return totalOn;
}
