#include<iostream>
#include<vector>

template <class T>
void printVector(std::vector<T> v)
{
  std::cout << "Vector: ";
  for(auto const& value: v) std::cout << " " << value;
  std::cout << std::endl;
  std::cout << "Size: " << v.size() << std::endl;
}
std::vector<int> lexicalOrder(int n);

int main()
{
  int n = 234;
  printVector(lexicalOrder(n));
}

std::vector<int> lexicalOrder(int n)
{
  std::vector<int> returnVector;
  if (n < 1) return returnVector;
  int currentNum = 1;
  int lastNum = 0;
  for (unsigned int i = 1; i <= n; i++)
  {
    while (currentNum > n)
    {
      currentNum/=10;
      lastNum = (currentNum%10)+1;
      while (lastNum>9)
      {
        currentNum/=10;
        lastNum = ((currentNum%10)+1);
      }
      currentNum = ((currentNum/10)*10)+lastNum;
      while (currentNum > n)
      {
        currentNum/=10;
        lastNum = ((currentNum%10)+1);
      }
      currentNum = ((currentNum/10)*10)+lastNum;
    }
    returnVector.emplace_back(currentNum);
    currentNum *= 10;
  }
  return returnVector;
}
