#include<iostream>
#include<vector>
#include<algorithm>
#include "Functions.h"

typedef std::vector<std::vector<int> > Matrix;
int kthSmallest(Matrix& matrix, int k);

int main()
{
  Matrix m({{1,5,9}, {10,11,13}, {12,13,15}});
  printVector2D(m);
  int pos = 8;
  std::cout << "smallest element at: " << pos << " is " << kthSmallest(m, pos) << std::endl;
}
int kthSmallest(Matrix& matrix, int k)
{
  std::vector<int> matrixInVector;
  for (unsigned int i = 0; i < matrix.size(); i++)
  {
    for (unsigned int j = 0; j < matrix[i].size(); j++)
      matrixInVector.emplace_back(matrix[i][j]);
  }
  std::sort(matrixInVector.begin(), matrixInVector.end());
  return matrixInVector[k-1];
}
#include "Functions.cc"
