#include<iostream>
#include<cmath>
#include<unordered_map>

std::string intToRoman(int num);

int main()
{
  int num = 1;
  std::cout << num << " is " << intToRoman(num) << " in roman." << std::endl;
  num = 16;
  std::cout << num << " is " << intToRoman(num) << " in roman." << std::endl;
  num = 123;
  std::cout << num << " is " << intToRoman(num) << " in roman." << std::endl;
  num = 3576;
  std::cout << num << " is " << intToRoman(num) << " in roman." << std::endl;
  num = 0;
  std::cout << num << " is " << intToRoman(num) << " in roman." << std::endl;
  num = 3999;
  std::cout << num << " is " << intToRoman(num) << " in roman." << std::endl;
}

//40ms answer
std::string intToRoman(int num)
{
  std::string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
  std::string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
  std::string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
  std::string M[] = {"", "M", "MM", "MMM"};
  return M[num/1000]+C[(num%1000)/100]+X[(num%100)/10]+I[num%10];
}

//36ms answer
std::string intToRoman2(int num)
{
  std::string conversionArr[7] =      {"I", "V", "X", "L", "C", "D", "M"};
  std::string roman = "";
  int level = 0;
  std::string currNumStr;
  int lastNum = 0;
  while (num>0)
  {
    currNumStr = "";
    lastNum = num%10;
    num/=10;
    if (lastNum>0)
    {
      if (lastNum == 4)
      {
        currNumStr = conversionArr[level*2]+conversionArr[(level*2)+1];
      }
      else if (lastNum == 5)
      {
        currNumStr = conversionArr[(level*2)+1];
      }
      else if (lastNum == 9)
      {
        currNumStr = conversionArr[level*2]+conversionArr[(level+1)*2];
      }
      else if (lastNum <= 3)
      {
        for (int i = 0; i < lastNum; i++) currNumStr += conversionArr[level*2]; //romanTable.at(1*pow(10, level));
      }
      else if (lastNum >= 6 && lastNum < 9)
      {
        currNumStr = conversionArr[(level*2)+1]; //romanTable.at(5*pow(10, level));
        for (int i = 6; i <= lastNum; i++) currNumStr += conversionArr[level*2];//romanTable.at(1*pow(10, level));
      }
      roman = currNumStr + roman;
    }
    level++;
  }
  return roman;
}
