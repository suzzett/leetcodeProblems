#include<iostream>
#include<unordered_set>
#include "Functions.h"

typedef std::vector<std::pair<int, int>> EdgeList;
typedef std::vector<std::unordered_set<int> > Graph;
bool canFinish(int numCourses, EdgeList & prerequisites);
Graph makeGraphFromEdgeList(int totalVertices, EdgeList& edgeList);
bool hasCycle_DFS(int classNum, Graph &preReqGraph, std::vector<bool> &visitedNodes, std::vector<bool> &currNodes);

int main()
{
  std::cout << "=======================================================" << std::endl;
  int n = 1;
  EdgeList prerequisites({std::make_pair(1,0)});
  printPairVector(prerequisites);
  std::cout << "Student can" << (canFinish(n, prerequisites)?"":"not") << " finish the requirements." << std::endl;
  std::cout << "=======================================================" << std::endl;
  n = 2;
  prerequisites = EdgeList({std::make_pair(1,0), std::make_pair(0,1)});
  printPairVector(prerequisites);
  std::cout << "Student can" << (canFinish(n, prerequisites)?"":"not") << " finish the requirements." << std::endl;
  std::cout << "=======================================================" << std::endl;
  n = 4;
  prerequisites = EdgeList({std::make_pair(3,0), std::make_pair(0,1)});
  printPairVector(prerequisites);
  std::cout << "Student can" << (canFinish(n, prerequisites)?"":"not") << " finish the requirements." << std::endl;
  std::cout << "=======================================================" << std::endl;
  n = 4;
  prerequisites = EdgeList({ std::make_pair(1,0),
                                                std::make_pair(2,0),
                                                std::make_pair(3,1),
                                                std::make_pair(3,2)
                                              });
  printPairVector(prerequisites);
  std::cout << "Student can" << (canFinish(n, prerequisites)?"":"not") << " finish the requirements." << std::endl;
  std::cout << "=======================================================" << std::endl;
  n = 6;
  prerequisites = EdgeList({ std::make_pair(1,0),
                                                std::make_pair(2,1),
                                                std::make_pair(2,5),
                                                std::make_pair(3,1),
                                                std::make_pair(3,2),
                                                std::make_pair(4,3),
                                                std::make_pair(4,1),
                                                std::make_pair(5,4),
                                                std::make_pair(5,0)
                                              });
  printPairVector(prerequisites);
  std::cout << "Student can" << (canFinish(n, prerequisites)?"":"not") << " finish the requirements." << std::endl;
}
bool canFinish(int numCourses, EdgeList& prerequisites)
{
  if (numCourses < 2) return true;
  std::cout << "Creating Graph" << std::endl;
  Graph preReqGraph = makeGraphFromEdgeList(numCourses, prerequisites);
  std::vector<bool> nodesInCurrentDFS(numCourses, false);
  std::vector<bool> visitedNodes(numCourses, false);
  std::cout << "Graph created!" << std::endl;
  for (int i = 0; i < numCourses; i++) if ((!visitedNodes[i]) && hasCycle_DFS(i, preReqGraph, visitedNodes, nodesInCurrentDFS)) return false;
  std::cout << "Search complete" << std::endl;
  return true;
}

Graph makeGraphFromEdgeList(int totalVertices, EdgeList& edgeList)
{
  Graph mGraph(totalVertices);
  for (auto& item: edgeList) mGraph[item.first].insert(item.second);
  return mGraph;
}

bool hasCycle_DFS(int classNum, Graph &preReqGraph, std::vector<bool> &visitedNodes, std::vector<bool> &currNodes)
{
  std::cout << "Checking for class: " << classNum << std::endl;
  if (visitedNodes[classNum]) return false;
  currNodes[classNum] = visitedNodes[classNum] = true;
  for (int outEdge: preReqGraph[classNum])
  {
    std::cout << "Out edge to: " << outEdge << std::endl;
    if (currNodes[outEdge] || hasCycle_DFS(outEdge, preReqGraph, visitedNodes, currNodes)) return true;
  }
  currNodes[classNum] = false;
  return false;
}
#include "Functions.cc"
