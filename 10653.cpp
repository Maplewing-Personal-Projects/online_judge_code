/*******************************************************/
/* UVa 10653 Bombs! NO they are Mines!!                */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/27                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Vector
{
  int x;
  int y;

  bool equals(const Vector& v) {
    return x == v.x && y == v.y;
  }
};

struct BFSData {
  Vector point;
  int distance;
};

const Vector DIRECTIONS[] = {
  { -1, 0 },
  { 1, 0 },
  { 0, -1 },
  { 0, 1 }
};

int main() {
  int R, C;
  while (scanf("%d%d", &R, &C) != EOF && R != 0 && C != 0) {
    vector< vector<bool> > map(R, vector<bool>(C, false));
    
    int rows;
    scanf("%d", &rows);
    for (int i = 0 ; i < rows ; ++i) {
      int row;
      scanf("%d", &row);

      int columns;
      scanf("%d", &columns);
      for (int j = 0 ; j < columns ; ++j) {
        int column;
        scanf("%d", &column);
        map[row][column] = true;  
      }
    }

    Vector start, end;
    scanf("%d%d%d%d", &(start.x), &(start.y), &(end.x), &(end.y));

    int distance = -1;
    queue<BFSData> bfsQueue;
    bfsQueue.push((BFSData){ start, 0 });
    map[start.x][start.y] = true;
    while (!bfsQueue.empty()) {
      BFSData front = bfsQueue.front();
      bfsQueue.pop();
      if (front.point.equals(end)) {
        distance = front.distance;
        break;
      }

      for (int i = 0 ; i < sizeof(DIRECTIONS) / sizeof(Vector) ; ++i) {
        Vector nextPoint = { front.point.x + DIRECTIONS[i].x, front.point.y + DIRECTIONS[i].y };
        if (nextPoint.x >= 0 && nextPoint.x < R &&
            nextPoint.y >= 0 && nextPoint.y < C &&
            !map[nextPoint.x][nextPoint.y]
        ) {
          bfsQueue.push((BFSData){ nextPoint, front.distance + 1 });
          map[nextPoint.x][nextPoint.y] = true;
        }
      }
    }

    printf("%d\n", distance);
  }

  return 0;
}