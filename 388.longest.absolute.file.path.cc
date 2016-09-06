#include<iostream>
#include<vector>

struct FolderStructure
{
  std::string folderName;
  int depth;
  FolderStructure(std::string name, int level): folderName(name), depth(level){};
};
int lengthLongestPath(std::string input);

int main()
{
  std::cout << "================================" << std::endl;
  std::string systemPath = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
  std::cout << "Longest path in: \n" << systemPath << "\nis of size " << lengthLongestPath(systemPath) << std::endl << std::endl;
  std::cout << "================================" << std::endl;
  systemPath = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
  std::cout << "Longest path in: \n" << systemPath << "\nis of size " << lengthLongestPath(systemPath) << std::endl << std::endl;
}

int lengthLongestPath(std::string input)
{
  int inputLen = input.length();
  if (inputLen < 2) return -1;
  std::vector<FolderStructure> pathStack;
  int lastDepth = 0;
  int currentDepth = 0;
  int nextDepth = 0;
  char currentChar;
  std::string currentName = "";
  int longestLength = 0;
  for (int i = 0; i < inputLen; i++)
  {
    currentChar = input.at(i);
    if (currentChar == '\n')
    {
      currentDepth = nextDepth;
      nextDepth = 0;
      i++;
      currentChar = input.at(i);
      while (currentChar == '\t')
      {
        i++;
        currentChar = input.at(i);
        nextDepth++;
      }
      while ((!pathStack.empty()) && (currentDepth <= pathStack.back().depth)) pathStack.pop_back();
      pathStack.push_back(FolderStructure(currentName, lastDepth));
      currentName = "";
      lastDepth = nextDepth;
    }
    if (currentChar == '.')
    {
      currentName += currentChar;
      i++;
      currentChar = input.at(i);
      while (currentChar != '\n' && i < inputLen-1)
      {
        currentName += currentChar;
        i++;
        currentChar = input.at(i);
      }
      if (i>=inputLen-1) currentName += currentChar;
      std::string currentAbsPath = "";
      for(auto const& pathValue: pathStack) currentAbsPath += pathValue.folderName+"/";
      currentAbsPath += currentName;
      if (currentAbsPath.length() > longestLength) longestLength = currentAbsPath.length();
      i--;
    }
    if (!((currentChar == '.') || (currentChar == '\t') || (currentChar == '\n'))) currentName += currentChar;
  }
  return longestLength;
}
