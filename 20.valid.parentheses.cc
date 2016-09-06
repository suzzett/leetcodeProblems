#include<iostream>
#include<stack>
bool isValid(std::string s);

int main()
{
  std::string str = "()";
  std::cout << str << " is " << ((isValid(str))?"":"not ") << "valid" << std::endl;
  str = "(])";
  std::cout << str << " is " << ((isValid(str))?"":"not ") << "valid" << std::endl;
  str = "[";
  std::cout << str << " is " << ((isValid(str))?"":"not ") << "valid" << std::endl;
}

bool isValid(std::string s)
{
  std::stack<char> parenthesesStack;
  char currChar;
  for (unsigned int i = 0; i < s.length(); i++)
  {
    currChar = s.at(i);
    if ((currChar == ')' || currChar == ']' || currChar =='}') && parenthesesStack.size() == 0) return false;
    if (currChar == '(' || currChar == '{' || currChar == '[')
      parenthesesStack.push(currChar);
    else if  ((currChar == ')' && parenthesesStack.top()!='(') || (currChar == '}' && parenthesesStack.top()!='{') || (currChar == ']' && parenthesesStack.top()!='['))
      return false;
    else
      parenthesesStack.pop();
  }
  if (parenthesesStack.size() == 0) return true;
  else return false;
}
