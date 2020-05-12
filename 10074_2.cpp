/*******************************************************/
/* UVa 10074 Take the Land                             */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/09                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int M, N;
  while (scanf("%d%d", &M, &N) != EOF && M != 0 && N != 0) {
    vector< vector<int> > map(M, vector<int>(N));
    for (int i = 0 ; i < M ; ++i) {
      for (int j = 0 ; j < N ; ++j) {
        scanf("%d", &map[i][j]);
      }
    }

    int maxAllZeroArea = 0;
    for (int startRow = 0 ; startRow < M ; ++startRow) {
      vector<bool> sameColumnIsAllZeroDP(N, true);
      for (int endRow = startRow ; endRow < M ; ++endRow) {
        for (int column = 0 ; column < N ; ++column) {
          sameColumnIsAllZeroDP[column] = 
            (sameColumnIsAllZeroDP[column] && map[endRow][column] == 0);
        }

        /* Enlarge the range of columns */
        bool isAllZeroResult = sameColumnIsAllZeroDP[0];
        int startColumn = 0;
        int endColumn = 0; 
        if (isAllZeroResult) {
          maxAllZeroArea = max(maxAllZeroArea, (endRow - startRow + 1));
        }
        for (int column = 1 ; column < N ; ++column) {
          if (!isAllZeroResult) {
            isAllZeroResult = sameColumnIsAllZeroDP[column];
            startColumn = column;
            endColumn = column;
          } else {
            isAllZeroResult = isAllZeroResult && sameColumnIsAllZeroDP[column];
            endColumn = column;
          }

          if (isAllZeroResult) {
            maxAllZeroArea = max(maxAllZeroArea, 
              (endRow - startRow + 1) * (endColumn - startColumn + 1));
          }
        }
      }
    }

    printf("%d\n", maxAllZeroArea);
  }


  return 0;
}