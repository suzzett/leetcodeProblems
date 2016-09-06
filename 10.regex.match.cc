#include<iostream>
bool isMatch(std::string s, std::string p);

int main()
{
  std::string strExp = "aa";
  std::string strCheck = "a";
  std::cout << strExp << " and " << strCheck << " is" << (isMatch(strExp, strCheck)?"":" not") << " match." << std::endl;
  strExp = "aa";
  strCheck = "aa";
  std::cout << strExp << " and " << strCheck << " is" << (isMatch(strExp, strCheck)?"":" not") << " match." << std::endl;
  strExp = "aaa";
  strCheck = "aa";
  std::cout << strExp << " and " << strCheck << " is" << (isMatch(strExp, strCheck)?"":" not") << " match." << std::endl;
  strExp = "aa";
  strCheck = "a*";
  std::cout << strExp << " and " << strCheck << " is" << (isMatch(strExp, strCheck)?"":" not") << " match." << std::endl;
  strExp = "ab";
  strCheck = ".*";
  std::cout << strExp << " and " << strCheck << " is" << (isMatch(strExp, strCheck)?"":" not") << " match." << std::endl;
  strExp = "aa";
  strCheck = ".*";
  std::cout << strExp << " and " << strCheck << " is" << (isMatch(strExp, strCheck)?"":" not") << " match." << std::endl;
  strExp = "aab";
  strCheck = "c*a*b*";
  std::cout << strExp << " and " << strCheck << " is" << (isMatch(strExp, strCheck)?"":" not") << " match." << std::endl;
  strExp = "ab";
  strCheck = ".*c";
  std::cout << strExp << " and " << strCheck << " is" << (isMatch(strExp, strCheck)?"":" not") << " match." << std::endl;
  strExp = "aaa";
  strCheck = "a*a";
  std::cout << strExp << " and " << strCheck << " is" << (isMatch(strExp, strCheck)?"":" not") << " match." << std::endl;
}
bool isMatch(std::string s, std::string p)
{
  std::cout << "============================" << std::endl;
  std::cout << s << " and " << p << std::endl;
  char currChar;
  char currCharCheck;
  bool dotChar = false;
  bool zeroOrMoreChar = false;
  int i = 0;
  int j = 0;
  while (i < p.length())
  {
    currChar = p.at(i);
    if (p.at(i)=='.') dotChar=true;
    else dotChar = false;
    if ((i < (p.length()-1)) && (p.at(i+1)=='*'))
    {
      i++;
      zeroOrMoreChar=true;
    }
    else zeroOrMoreChar=false;
    std::cout << "Current char to match: " << currChar << ", zeroOrMoreChar: " << zeroOrMoreChar << ", dotChar: " << dotChar << std::endl;
    while (j < s.length())
    {
      currCharCheck = s.at(j);
      if (dotChar && zeroOrMoreChar)
      {
        std::cout << "Going through .*. New j= " << j << std::endl;
        currChar = currCharCheck;
        while (currChar == currCharCheck)
        {
          j++;
          if (j >= s.length()) break;
          currCharCheck = s.at(j);
        }
        std::cout << "Going through .*. New j= " << j << std::endl;
        j++;
        if (j >= s.length()) break;
        currCharCheck = s.at(j);
        currChar = currCharCheck;
        while (currChar == currCharCheck)
        {
          j++;
          if (j >= s.length()) break;
          currCharCheck = s.at(j);
        }
        std::cout << "Finished going through .*. New j= " << j << std::endl;
        break;
      }
      else if (dotChar)
      {
        j++;
        break;
      }
      else if (zeroOrMoreChar)
      {
        while (currChar == currCharCheck)
        {
          j++;
          if (j >= s.length()) break;
          currCharCheck = s.at(j);
        }
        std::cout << "Finished going through *. New j= " << j << std::endl;
        break;
      }
      else if (currChar != currCharCheck)
      {
        return false;
      }
      else
      {
        std::cout << "Characters matched..." << std::endl;
        j++;
        break;
      }
    }
    std::cout << "Just matched characters. i = " << i << ", j = " << j << std::endl;
    i++;
    if (j>= s.length()) break;
  }
  if (j < s.length() || i < p.length()) return false;
  return true;
}
