#include<iostream>
#include<vector>

std::string longestCommonPrefix(std::vector<std::string>& strs);

int main()
{
  std::vector<std::string> v({"aa", "a"});
  std::cout << "Longest common prefix = " << longestCommonPrefix(v) << std::endl;
}

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
  if (strs.size() < 1) return "";
  if (strs.size() ==1) return strs[0];
  std::string currentPrefix = "";
  char currentChar;
  for (unsigned int i = 0; i < strs[0].size(); i++)
  {
    currentChar = strs[0].at(i);
    for (unsigned int j = 0; j < strs.size(); j++)
    {
      if (strs[j].length() <= i) return currentPrefix;
      if (strs[j].at(i) != currentChar) return currentPrefix;
    }
    currentPrefix += currentChar;
  }
  return currentPrefix;
}
