#include<iostream>
#include<vector>

std::string convert(std::string s, int numRows);

int main()
{
  std::string str = "PAYPALISHIRING";
  int numRows = 4;
  std::cout << str << " is converted to: " << convert(str, numRows) << std::endl;
  str = "THISAVERYLONGSENTENCEANDIWANTTOSEETHEPATTERN";
  numRows = 9;
  std::cout << str << " is converted to: " << convert(str, numRows) << std::endl;
  str = "ABC";
  numRows = 2;
  std::cout << str << " is converted to: " << convert(str, numRows) << std::endl;
}

std::string convert(std::string s, int numRows)
{
  if (numRows < 2) return s;
  std::string returnString = "";

  for (int rowID = 0; rowID < numRows; rowID++)
  {
    int currPos = rowID;
    bool goingDown = true;
    while (currPos < s.length())
    {
      returnString += s.at(currPos);
      std::cout << "returnString: " << returnString << ", currPos: " << currPos << ", goingDown: " << goingDown << std::endl;
      if ((rowID == 0) || ((rowID+1-numRows) == 0))     currPos += (numRows*2)-2;
      else if (goingDown)                               currPos += (numRows-(rowID+1))*2;
      else                                              currPos += (rowID*2);
      goingDown = !goingDown;
    }
  }
  return returnString;
}
