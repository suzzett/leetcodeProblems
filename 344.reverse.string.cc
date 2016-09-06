#include<iostream>
std::string reverseString(std::string s);

int main()
{
  std::string str = "hello";
  std::cout << "Reverse of '" << str << "' is " << reverseString(str) << std::endl;
  str = "hellox";
  std::cout << "Reverse of '" << str << "' is " << reverseString(str) << std::endl;
}

std::string reverseString(std::string s)
{
  int strLen = s.length();
  if (strLen < 2) return s;
  int maxLoop = strLen/2;
  for (int i = 0, j=strLen-1; i < maxLoop; i++, j--) std::swap(s[i], s[j]);
  return s;
}
