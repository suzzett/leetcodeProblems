#include<iostream>
int countNumbersWithUniqueDigits(int n);

int main()
{
  int n = 1;
  std::cout << "Number of unique digits for n = " << n << " is: " << countNumbersWithUniqueDigits(n) << std::endl;
  n = 3;
  std::cout << "Number of unique digits for n = " << n << " is: " << countNumbersWithUniqueDigits(n) << std::endl;
}
int countNumbersWithUniqueDigits(int n)
{
  if (n<1) return 1;
  int totalUnique = 10;
  int prevMultiplier = 9;
  for (int i = 1; i < n; i++)
  {
    prevMultiplier *= (10-i);
    totalUnique += prevMultiplier;
  }
  return totalUnique;
}
