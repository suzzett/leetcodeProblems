#include<iostream>
#include<unordered_map>

int romanToInt(std::string s);

int main()
{
  std::string roman = "I";
  std::cout << roman << " is " << romanToInt(roman) << " in roman." << std::endl;
  roman = "XVI";
  std::cout << roman << " is " << romanToInt(roman) << " in roman." << std::endl;
  roman = "CXXIII";
  std::cout << roman << " is " << romanToInt(roman) << " in roman." << std::endl;
  roman = "MMMDLXXVI";
  std::cout << roman << " is " << romanToInt(roman) << " in roman." << std::endl;
  roman = "MMMCMXCIX";
  std::cout << roman << " is " << romanToInt(roman) << " in roman." << std::endl;
}

//Improced to 40ms from 80 by removing unordered_map and changed to simply if then
//Got it down to 36ms by removing one char variable
int romanToInt(std::string s)
{
  int intValue = 0;
  int currVal = 0;
  int prevVal = 0;
  int convertTable['X'-'A'];
  convertTable['M'-'A'] = 1000;
  convertTable['D'-'A'] = 500;
  convertTable['C'-'A'] = 100;
  convertTable['L'-'A'] = 50;
  convertTable['X'-'A'] = 10;
  convertTable['V'-'A'] = 5;
  convertTable['I'-'A'] = 1;
  for (unsigned int i = 0; i < s.length(); i++)
  {
    currVal = convertTable[s.at(i)-'A'];
    if ((i>0) && (currVal > prevVal)) intValue += currVal-(2*prevVal);
    else intValue += currVal;
    prevVal = currVal;
  }
  return intValue;
}
