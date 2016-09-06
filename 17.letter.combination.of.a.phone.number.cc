#include<iostream>
#include<vector>

std::vector<std::string> letterCombinations(std::string digits);
void printVector(std::vector<std::string> v);
void printVector(std::vector<char> v);

int main()
{
  std::string digits = "389";
  std::vector<std::string> combinations = letterCombinations(digits);
  printVector(combinations);
}

std::vector<std::string> letterCombinations(std::string digits)
{
  std::vector<std::string> returnVector;
  std::vector<char> possibleChars[] = {{}, {},  {'a', 'b', 'c'},
                                                {'d', 'e', 'f'},
                                                {'g', 'h', 'i'},
                                                {'j', 'k', 'l'},
                                                {'m', 'n', 'o'},
                                                {'p', 'q', 'r', 's'},
                                                {'t', 'u', 'v'},
                                                {'w', 'x', 'y', 'z'}};
  int totalCombinations = 1;
  std::string currentStr = "";
  int digitsLen = digits.length();
  std::vector<char> allDigits;
  std::vector<char> currCharVec;
  for (unsigned int i = 0; i < digitsLen; i++)
  {
    if (!(digits.at(i) == '1' || digits.at(i)=='0'))
    {
      allDigits.push_back(digits.at(i));
      totalCombinations *= possibleChars[digits.at(i)-'0'].size();
    }
  }

  digitsLen = allDigits.size();
  if (digitsLen <= 0) return returnVector;
  std::cout << totalCombinations << std::endl;
  int totalCharUsed[digitsLen] = {0};
  for (unsigned int i = 0; i < totalCombinations; i++)
  {
    currentStr = "";
    for (unsigned int j = 0; j < digitsLen; j++)
    {
      currentStr += possibleChars[allDigits[j]-'0'][totalCharUsed[j]];
    }
    int carry = 0;
    for (int j = digitsLen-1; j >= 0; j--)
    {
      if (j==(digitsLen-1))    totalCharUsed[j]++;
      else                     totalCharUsed[j] += carry;
      carry = totalCharUsed[j]/(possibleChars[allDigits[j]-'0'].size());
      totalCharUsed[j] = totalCharUsed[j]%(possibleChars[allDigits[j]-'0'].size());
    }
    returnVector.push_back(currentStr);
  }
  return returnVector;
}

void printVector(std::vector<std::string> v)
{
  std::cout << "Vector: ";
  for (unsigned int i = 0; i < v.size(); i++)
  {
    std::cout << (i==0?"":",")+v[i];
  }
  std::cout << std::endl;
}

void printVector(std::vector<char> v)
{
  std::cout << "Vector: ";
  for (unsigned int i = 0; i < v.size(); i++)
  {
    std::cout << (i==0?"":",")+v[i];
  }
  std::cout << std::endl;
}
