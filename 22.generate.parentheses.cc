#include<iostream>
#include<vector>
std::vector<std::string> generateParenthesis(int n);
void printVector(std::vector<std::string> v);
void recursiveGeneration(int openParenthesesLeft, int closeParenthesesLeft, std::string currentStr, std::vector<std::string> &v);

int main()
{
  int n = 3;
  printVector(generateParenthesis(n));
  n = 2;
  printVector(generateParenthesis(n));
  n = 4;
  printVector(generateParenthesis(n));
}

std::vector<std::string> generateParenthesis(int n)
{
  std::vector<std::string> v;
  std::string str;
  recursiveGeneration(n, 0, str, v);
  return v;
}

void recursiveGeneration(int openParenthesesLeft, int closeParenthesesLeft, std::string currentStr, std::vector<std::string> &v)
{
  if (closeParenthesesLeft <= 0 && openParenthesesLeft <= 0)
  {
    v.push_back(currentStr);
    return;
  }
  if (openParenthesesLeft > 0) recursiveGeneration(openParenthesesLeft-1, closeParenthesesLeft+1, currentStr+"(", v);
  if (closeParenthesesLeft > 0) recursiveGeneration(openParenthesesLeft, closeParenthesesLeft-1, currentStr+")", v);
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
