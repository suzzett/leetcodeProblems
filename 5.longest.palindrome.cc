#include<iostream>

std::string longestPalindrome(std::string s);
int main()
{
  std::string str = "abxbmnsaghgaspo";
  std::cout << "longest palindrome in " << str << " is " << longestPalindrome(str) << std::endl;
  str = "aaaa";
  std::cout << "longest palindrome in " << str << " is " << longestPalindrome(str) << std::endl;
  str = "ccc";
  std::cout << "longest palindrome in " << str << " is " << longestPalindrome(str) << std::endl;
  str = "asdfccccopip";
  std::cout << "longest palindrome in " << str << " is " << longestPalindrome(str) << std::endl;
  str = "asdfmnbvvbnmopip";
  std::cout << "longest palindrome in " << str << " is " << longestPalindrome(str) << std::endl;
  str = "bb";
  std::cout << "longest palindrome in " << str << " is " << longestPalindrome(str) << std::endl;
  str = "abb";
  std::cout << "longest palindrome in " << str << " is " << longestPalindrome(str) << std::endl;
  str = "aba";
  std::cout << "longest palindrome in " << str << " is " << longestPalindrome(str) << std::endl;
}

std::string longestPalindrome(std::string s)
{
  if (s.length() < 2) return s;
  // std::cout << "==============================================" << std::endl;
  // std::cout << "'" << s << "'" << ", size: " << s.length() << std::endl;
  int currLen = 0;
  int currStart = 0;
  int maxPalindromeSize = 0;
  int maxPalindromeStartPoint = 0;

  int finalEndPoint, finalBeginningPoint;
  int midPoint, endPoint, beginningPoint;
  for (int i = 0; i < s.length()-1; i++)
  {
    midPoint = i;
    beginningPoint = midPoint;
    endPoint = midPoint;
//    std::cout << "BEFORE BEGINNING: Beginning: " << beginningPoint << ", end: " << endPoint << ", i = " << i << std::endl;
    while ((beginningPoint > 0) && (s.at(beginningPoint-1) == s.at(midPoint))) beginningPoint--;
//    std::cout << "AFTER BEGINNING: Beginning: " << beginningPoint << ", end: " << endPoint << ", i = " << i << std::endl;
    while ((endPoint < s.length()-1) && (s.at(midPoint) == s.at(endPoint+1))) endPoint++;
//    std::cout << "AFTER END: Beginning: " << beginningPoint << ", end: " << endPoint << ", i = " << i  << std::endl;
    currLen = endPoint-beginningPoint;
    currStart = beginningPoint;
    while (s.at(beginningPoint) == s.at(endPoint))
    {
//      std::cout << "IN-LOOP: Beginning: " << beginningPoint << ", end: " << endPoint << ", i = " << i  << std::endl;
      currLen = endPoint-beginningPoint+1;
      currStart = beginningPoint;
      beginningPoint--;
      endPoint++;
//      std::cout << "IN-LOOP END: Beginning: " << beginningPoint << ", end: " << endPoint << ", i = " << i  << std::endl;
      if (beginningPoint < 0 || endPoint >= s.length()) break;
    }
//    std::cout << "FINAL STAGE: Beginning: " << beginningPoint << ", end: " << endPoint << ", i = " << i  << std::endl;
    //std::cout << "Checking repeat outside loop: Beginning: " << beginningPoint << ", end: " << endPoint << ", i = " << i  << std::endl;
    if (currLen > maxPalindromeSize)
    {
      maxPalindromeSize = currLen;
      maxPalindromeStartPoint = currStart;
    }
  }
  return s.substr(maxPalindromeStartPoint, maxPalindromeSize);
}
