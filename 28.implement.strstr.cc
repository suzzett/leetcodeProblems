#include<iostream>

int strStr(std::string haystack, std::string needle);

int main()
{
  std::string haystack = "mississippi";
  std::string needle = "issip";
  std::cout << "First occurance index: " << strStr(haystack, needle) << std::endl;
  haystack = "This is a sentence";
  needle = "sent";
  std::cout << "First occurance index: " << strStr(haystack, needle) << std::endl;
}

int strStr(std::string haystack, std::string needle)
{
  int hayLen = haystack.length();
  int needLen = needle.length();
  if (hayLen < needLen) return -1;
  if (needLen == 0) return 0;
  for (unsigned int i = 0; i < hayLen; i++)
  {
    if (hayLen-i < needLen) return -1;
    bool found = true;
    for (unsigned int j = 0; j < needLen; j++)
    {
      if (haystack.at(i+j) != needle.at(j))
      {
        found = false;
        break;
      }
    }
    if (found) return i;
  }
  return -1;
}
