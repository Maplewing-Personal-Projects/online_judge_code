/*******************************************************/
/* UVa 10074 Take the Land                             */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/09                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Rectangle {
  int startRow;
  int endRow;
  int startColumn;
  int endColumn;
  bool isAllZero;

  int getArea() {
    return (endRow - startRow + 1) * (endColumn - startColumn + 1);
  }
};

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
      vector<Rectangle> sameColumnRectangleDP(N);
      for (int endRow = startRow ; endRow < M ; ++endRow) {
        for (int column = 0 ; column < N ; ++column) {
          if (startRow == endRow) {
            sameColumnRectangleDP[column] = (Rectangle) {
              startRow, endRow, column, column, 
              map[endRow][column] == 0
            };
            continue;
          }

          Rectangle previousRectangle = sameColumnRectangleDP[column];
          sameColumnRectangleDP[column] = (Rectangle) {
            startRow, endRow, column, column, 
            previousRectangle.isAllZero && map[endRow][column] == 0
          };
        }

        /* Enlarge the range of columns */
        Rectangle resultRectangle = sameColumnRectangleDP[0];
        if (resultRectangle.isAllZero) {
          maxAllZeroArea = max(maxAllZeroArea, resultRectangle.getArea());
        }
        for (int column = 1 ; column < N ; ++column) {
          Rectangle currentRectangle = sameColumnRectangleDP[column];
          if (!resultRectangle.isAllZero) {
            resultRectangle = currentRectangle;
          } else {
            resultRectangle = (Rectangle) {
              resultRectangle.startRow,
              resultRectangle.endRow,
              resultRectangle.startColumn,
              currentRectangle.endColumn,
              resultRectangle.isAllZero && currentRectangle.isAllZero
            };
          }

          if (resultRectangle.isAllZero) {
            maxAllZeroArea = max(maxAllZeroArea, resultRectangle.getArea());
          }
        }
      }
    }

    printf("%d\n", maxAllZeroArea);
  }


  return 0;
}