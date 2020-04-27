/*******************************************************/
/* UVa 10369 Arctic Network                            */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/27                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  double x;
  double y;

  double getLength(const Point& point) {
    double diffX = x - point.x;
    double diffY = y - point.y;
    return sqrt(diffX * diffX + diffY * diffY);
  }
};

struct Outpost {
  Point position;
  int setNumber;
};

int findRoot(vector<Outpost>& outposts, int setNumber) {
  if (outposts[setNumber].setNumber == setNumber) return setNumber;
  return outposts[setNumber].setNumber = 
    findRoot(outposts, outposts[setNumber].setNumber);
}

bool unionSet(vector<Outpost>& outposts, int aIndex, int bIndex) {
  int aRoot = findRoot(outposts, aIndex);
  int bRoot = findRoot(outposts, bIndex);
  
  if (aRoot == bRoot) return false;

  outposts[bRoot].setNumber = aRoot;
  return true;
}

struct Edge {
  int aIndex;
  int bIndex;
  double length;
};

bool edgeCompare(const Edge& a, const Edge& b) {
  return a.length < b.length;
}

int main() {
  int caseAmount;
  while (scanf("%d", &caseAmount) != EOF) {
    for (int caseNumber = 1 ; caseNumber <= caseAmount ; ++caseNumber) {
      int S, P;
      scanf("%d%d", &S, &P);

      vector<Outpost> outposts(P);
      for (int i = 0 ; i < P ; ++i) {
        scanf("%lf%lf", &(outposts[i].position.x), &(outposts[i].position.y));
        outposts[i].setNumber = i;
      }

      vector<Edge> edges;
      for (int i = 0 ; i < P ; ++i) {
        for (int j = i + 1 ; j < P ; ++j) {
          edges.push_back((Edge) { i, j, 
            outposts[i].position.getLength(outposts[j].position) });
        }
      }
      sort(edges.begin(), edges.end(), edgeCompare);

      vector<Edge> mspEdges;
      for (int i = 0 ; mspEdges.size() < P - 1; ++i) {
        if (!unionSet(outposts, edges[i].aIndex, edges[i].bIndex)) {
          continue;
        }

        mspEdges.push_back(edges[i]);
      }

      printf("%.2lf\n", mspEdges[P - 1 - S].length);
    }
  }
  return 0;
}