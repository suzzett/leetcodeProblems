#include<iostream>
int firstUniqChar(std::string s);

int main()
{
  std::string str = "leetcode";
  std::cout << "First non-repeating character for " << str << " is at: " << firstUniqChar(str) << std::endl;
  str = "loveleetcode";
  std::cout << "First non-repeating character for " << str << " is at: " << firstUniqChar(str) << std::endl;
}

int firstUniqChar(std::string s)
{
  int strSize = s.length();
  if (strSize < 2) return strSize-1;
  char allChars[strSize];
  int allCharCount[26] = {0};
  for (unsigned int i = 0; i < s.length(); i++)
  {
    allChars[i] = s.at(i);
    allCharCount[allChars[i]-'a']++;
  }
  for (unsigned int i = 0; i < s.length(); i++) if (allCharCount[allChars[i]-'a']==1) return i;
  return -1;
}
