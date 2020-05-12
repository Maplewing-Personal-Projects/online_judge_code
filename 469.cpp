/*******************************************************/
/* UVa 469 Wetlands of Florida                         */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/10                                 */
/*******************************************************/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

struct Direction {
  int rowDiff;
  int columnDiff;
};

const Direction directions[] = {
  {1, 0}, {1, -1}, {0, -1}, {-1, -1},
  {-1, 0}, {-1, 1}, {0, 1}, {1, 1}
};

int getTotalWaterArea(
  const vector<string>& map,
  vector< vector<bool> >& isVisited, 
  int row, int column
) {
  if (
    row < 0 || row >= map.size() ||
    column < 0 || column >= map[row].length() ||
    isVisited[row][column] || 
    map[row][column] == 'L'
  ) {
    return 0;
  }

  int area = 1;
  int directionCount = sizeof(directions) / sizeof(Direction);
  isVisited[row][column] = true;
  for (int i = 0 ; i < directionCount ; ++i) {
    area += getTotalWaterArea(map, isVisited, 
      row + directions[i].rowDiff, column + directions[i].columnDiff);
  }
  return area;
}

int main() {
  int caseAmount;
  while (scanf("%d ", &caseAmount) != EOF) {
    for (int caseNumber = 1 ; caseNumber <= caseAmount ; ++caseNumber) {
      if (caseNumber > 1) printf("\n");

      vector<string> map;
      string input;
      while (true) {
        getline(cin, input);
        if (isdigit(input[0])) break;
        map.push_back(input);
      }

      while (input != "") {
        stringstream ss(input);
        int row, column;
        ss >> row >> column;

        vector< vector<bool> > isVisited(map.size(), vector<bool>(map[0].length()));
        printf("%d\n", getTotalWaterArea(map, isVisited, row - 1, column - 1));
        getline(cin, input);
      }
    }
  }
  return 0;
}