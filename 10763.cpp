/*******************************************************/
/* UVa 10763 Foreign Exchange                          */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/07                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

struct Edge {
  int originalLocation;
  int targetLocation;

  bool operator<(const Edge& edge) const {
    return (originalLocation < edge.originalLocation) ||
      (originalLocation == edge.originalLocation && 
      targetLocation < edge.targetLocation);
  }
};

int main() {
  int n;
  while (scanf("%d", &n) != EOF && n != 0) {
    map<Edge, int> edgeCount;
    for (int i = 0 ; i < n ; ++i) {
      Edge edge;
      scanf("%d%d", &(edge.originalLocation), &(edge.targetLocation));
      ++edgeCount[edge];
    }

    if (n % 2 == 1) {
      printf("NO\n");
      continue;
    }

    bool isValid = true;
    for (
      map<Edge, int>::iterator it = edgeCount.begin() ;
      it != edgeCount.end() ;
      ++it
    ) {
      Edge reverseEdge = { it->first.targetLocation, it->first.originalLocation };
      if (edgeCount[reverseEdge] != it->second) {
        isValid = false;
        break;
      }
    }

    printf("%s\n", isValid ? "YES" : "NO");
  }
  
  return 0;
}