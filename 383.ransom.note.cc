#include<iostream>
#include "Functions.h"

bool canConstruct(std::string ransomNote, std::string magazine);

int main()
{
  std::string str1 = "a";
  std::string str2 = "b";
  std::cout << str1 << " can" << ((canConstruct(str1, str2))?"":"not") << " construct " << str2 << std::endl;

  str1 = "aa";
  str2 = "ab";
  std::cout << str1 << " can" << ((canConstruct(str1, str2))?"":"not") << " construct " << str2 << std::endl;

  str1 = "aa";
  str2 = "aab";
  std::cout << str1 << " can" << ((canConstruct(str1, str2))?"":"not") << " construct " << str2 << std::endl;
}
bool canConstruct(std::string ransomNote, std::string magazine)
{
  int noteLen = ransomNote.length();
  int magLen = magazine.length();
  if (magLen < noteLen) return false;
  if (magLen == noteLen && ransomNote!=magazine) return false;
  if (magLen == noteLen && ransomNote==magazine) return true;
  int noteContents[26] = {0};
  int magContents[26] = {0};
  for (int i = 0; i < noteLen; i++) noteContents[ransomNote[i]-'a']++;
  for (int i = 0; i < magLen; i++)  magContents[magazine[i]-'a']++;
  for (int i = 0; i < 26; i++) if (noteContents[i] > magContents[i]) return false;
  return true;
}
#include "Functions.cc"
