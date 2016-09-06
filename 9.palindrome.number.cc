#include<iostream>
bool isPalindrome(int x);

int main()
{
  int num = 222333;
  std::cout << num << " is " << (isPalindrome(num)?"":"not ") << "palindrome" << std::endl;
  num = 121;
  std::cout << num << " is " << (isPalindrome(num)?"":"not ") << "palindrome" << std::endl;
  num = 15351;
  std::cout << num << " is " << (isPalindrome(num)?"":"not ") << "palindrome" << std::endl;
  num = 456654;
  std::cout << num << " is " << (isPalindrome(num)?"":"not ") << "palindrome" << std::endl;
  num = -2147447412;
  std::cout << num << " is " << (isPalindrome(num)?"":"not ") << "palindrome" << std::endl;
}

bool isPalindrome(int x)
{
  if (x<0) return false;
  if (x<10) return true;
  int reversedNum = 0;
  int origNum = x;

  while (x)
  {
    reversedNum = reversedNum*10+(x%10);
    x /= 10;
    std::cout << "Reversed num: " << reversedNum << ", x = " << x << std::endl;
  }
  if (reversedNum == origNum) return true;
  else return false;
}
