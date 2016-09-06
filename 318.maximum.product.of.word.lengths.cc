#include<iostream>
#include<algorithm>
#include<set>
#include "Functions.h"
int maxProduct(std::vector<std::string>& words);

int main()
{
  std::vector<std::string> words({"abcw", "baz", "foo", "bar", "xtfn", "abcdef"});
  printVector(words);
  std::cout << "Max product is: " << maxProduct(words) << std::endl;
}

int maxProduct(std::vector<std::string>& words)
{
  std::sort(words.begin(), words.end(), [](std::string s1, std::string s2) {return s1.length() > s2.length();});
  int product = 0;
  std::vector<std::set<char> > availableChars(words.size());
  int i = 0;
  for (std::string &s: words)
  {
    for (int j = 0; j < s.length(); j++)
    {
      availableChars[i].insert(s.at(j));
    }
    i++;
  }

  int smallerIndex = 1;
  int largerIndex = 0;
  std::set<char> intersectionSet;
  while (largerIndex < (words.size()-1))
  {
    for (int i = 0; i < words.size()-1; i++)
    {
      for (int j = i+1; j < words.size(); j++)
      {
        set_intersection(availableChars[i].begin(),availableChars[i].end(),availableChars[j].begin(),availableChars[j].end(), std::inserter(intersectionSet,intersectionSet.begin()));
        if (intersectionSet.size() < 1) return (words[largerIndex].size()*words[smallerIndex].size());
        intersectionSet.clear();
      }
    }
  }
  return 0;
}
#include "Functions.cc"
