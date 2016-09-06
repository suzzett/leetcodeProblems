#include<iostream>
#include "Functions.h"
char findTheDifference(std::string s, std::string t);

int main()
{
  std::string str1 = "abcde";
  std::string str2 = "abcd";
  std::cout << findTheDifference(str2, str1) << " is diff between " << str1 << " and " << str2 << std::endl;
}
char findTheDifference(std::string s, std::string t)
{
  int freqs1[26] = {0};
  int freqs2[26] = {0};
  for (unsigned int i = 0; i < s.length(); i++)    freqs1[s.at(i)-'a']++;
  for (unsigned int i = 0; i < t.length(); i++)    freqs2[t.at(i)-'a']++;
  for (int i = 0; i < 26; i++) if (freqs1[i] != freqs2[i]) return ('a'+i);
  return -1;
}
#include "Functions.cc"
