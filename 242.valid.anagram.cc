#include<iostream>
#include<unordered_map>

bool isAnagram(std::string s, std::string t);

int main()
{
  std::string str1 = "anagram";
  std::string str2 = "naagram";
  std::cout << str1 << " is" << ((isAnagram(str1, str2))?"":" not") << " anagram of " << str2 << std::endl;
  str1 = "car";
  str2 = "ca";
  std::cout << str1 << " is" << ((isAnagram(str1, str2))?"":" not") << " anagram of " << str2 << std::endl;
}

//For only lowercase
bool isAnagram(std::string s, std::string t)
{
  int strLen1 = s.length();
  int strLen2 = t.length();
  if (strLen1 != strLen2) return false;
  int charCounts1[26] = {0};
  int charCounts2[26] = {0};
  for (unsigned int i = 0; i < strLen1; i++)    charCounts1[s.at(i)-'a']++;
  for (unsigned int i = 0; i < strLen2; i++)    charCounts2[t.at(i)-'a']++;
  for (unsigned int i = 0; i < 26; i++) if (charCounts1[i] != charCounts2[i]) return false;
  return true;
}
//For all characters: runtime: 36ms
// bool isAnagram(std::string s, std::string t)
// {
//   int strLen1 = s.length();
//   int strLen2 = t.length();
//   if (strLen1 != strLen2) return false;
//   std::unordered_map<int, int> charCounts1;
//   std::unordered_map<int, int> charCounts2;
//
//   for (unsigned int i = 0; i < strLen1; i++)    charCounts1[s.at(i)]++;
//   for (unsigned int i = 0; i < strLen2; i++)    charCounts2[t.at(i)]++;
//   int freqSize1 = charCounts1.size();
//   int freqSize2 = charCounts1.size();
//   if (freqSize2 != freqSize1) return false;
//   for (auto &freqItem: charCounts1)
//   {
//     if (charCounts2[freqItem.first] != freqItem.second) return false;
//   }
//
//   return true;
// }
