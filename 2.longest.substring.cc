#include<iostream>

int lengthOfLongestSubstring(std::string s);

int main()
{
  std::cout << "Longest length of abcabcbb = " << lengthOfLongestSubstring("abcabcbb") << std::endl;
  std::cout << "Longest length of bbbbb = " << lengthOfLongestSubstring("bbbbb") << std::endl;
  std::cout << "Longest length of pwwkew = " << lengthOfLongestSubstring("pwwkew") << std::endl;
  std::cout << "Longest length of mnomnopp = " << lengthOfLongestSubstring("mnomnopp") << std::endl;
  std::cout << "Longest length of dvdf = " << lengthOfLongestSubstring("dvdf") << std::endl;
}

int lengthOfLongestSubstring(std::string s)
{
  int longestLength = 0;
  int currLength = 0;
  int lastResetPos = 0;
  for (unsigned int i = 0; i < s.length(); i++)
  {
    for (unsigned int j = lastResetPos; j < i; j++)
    {
      if (s.at(i) == s.at(j))
      {
        lastResetPos = j+1;
        if (currLength > longestLength) longestLength = currLength;
        currLength = i-(j+1);
        break;
      }
    }
    currLength++;
  }
  if (currLength > longestLength) longestLength = currLength;
  return longestLength;
}
