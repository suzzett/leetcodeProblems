#include<iostream>
#include<cstdlib>
#include<climits>

int myAtoi(std::string str);

int main()
{
  std::string str = "123abc";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
  str = "abc123abc";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
  str = "+1";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
  str = "-1";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
  str = "++1";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
  str = "123    ";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
  str = "   123";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
  str = "  +0 123";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
  str = "2147483648";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
  str = "-2147483648";
  std::cout << str << " is " << atoi(str.c_str()) << ", miAtoi is: " << myAtoi(str) << std::endl;
}

int myAtoi(std::string str)
{
  char currChar;
  int intValue;
  int returnValue = 0;
  bool isPositive = true;
  bool gotSign = false;
  int strSize = str.length();
  int tmp;
  for (int i = 0; i < strSize; i++)
  {
    currChar = str.at(i);
    while (currChar == 32 && i<strSize-1)
    {
      if (gotSign) break;
      i++;
      currChar = str.at(i);
    }
    intValue = currChar-48;
    if (currChar == '+')
    {
      if (gotSign) break;
      gotSign = true;
      isPositive = true;
    }
    else if (currChar == '-')
    {
      if (gotSign) break;
      gotSign = true;
      isPositive = false;
    }
    else if (intValue >=0 && intValue <= 9)
    {
      while ((intValue >=0) && (intValue <= 9))
      {
        tmp = ((returnValue*10)+intValue);
        if (returnValue != tmp/10)
        {
          returnValue = INT_MAX;
          return (isPositive?INT_MAX:INT_MIN);
        }
        returnValue = tmp;
        i++;
        if (i >= strSize)
        {
          return (isPositive?1:-1)*returnValue;
        }
        currChar = str.at(i);
        intValue = currChar-48;
      }
      break;
    }
    else                                    break;
  }
  return (isPositive?1:-1)*returnValue;
}
