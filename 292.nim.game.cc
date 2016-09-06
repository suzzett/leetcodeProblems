#include<iostream>
bool canWinNim(int n);
bool canWinNim(int n, bool myTurn);

int main()
{
  int n = 1348820612;
  std::cout << "I can" << (canWinNim(n)?"":"not") << " win this game with "<< n << " stones."  << std::endl;
}

bool canWinNim(int n)
{
  if (n <= 3) return true;
  return (canWinNim(n-1, false) || canWinNim(n-2, false) || canWinNim(n-3, false));
}

bool canWinNim(int n, bool myTurn)
{
  if (n <= 3 && myTurn) return true;
  else if (n <= 3 && !myTurn) return false;
  return (canWinNim(n-1, !myTurn) || canWinNim(n-2, !myTurn) || canWinNim(n-3, !myTurn));
}
