#include<iostream>
#include<cmath>

int titleToNumber(std::string s);

int main()
{
  std::string str = "A";
  std::cout << str << " = " << titleToNumber(str) << std::endl;
  str = "Z";
  std::cout << str << " = " << titleToNumber(str) << std::endl;
  str = "AZ";
  std::cout << str << " = " << titleToNumber(str) << std::endl;
  str = "AA";
  std::cout << str << " = " << titleToNumber(str) << std::endl;
}
int titleToNumber(std::string s)
{
  int strLen = s.length();
  if (strLen < 1) return 0;
  int intVal =  0;
  int powVal = 1;
  for (int i = strLen-1; i>= 0; i--)
  {
    intVal += (s.at(i) - 'A' + 1)*powVal;
    powVal *= 26;
  }
  return intVal;
}
