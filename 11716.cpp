/*******************************************************/
/* UVa 11716 Digital Fortress                          */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/05                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double DOUBLE_ERROR = 1e-9;
const int NOT_INTEGER_ROOT = -1;

bool isEqualWithError(double a, double b) {
  return a < b + DOUBLE_ERROR && a > b - DOUBLE_ERROR;
}

int findRoot(int number) {
  double realRoot = sqrt((double)number);
  int integerRoot = (int)realRoot;
  return isEqualWithError((double)integerRoot, realRoot) ? integerRoot : NOT_INTEGER_ROOT;
}

int main() {
  int T;
  while (scanf("%d ", &T) != EOF) {
    for (int caseNumber = 1 ; caseNumber <= T ; ++caseNumber) {
      string cipherText;
      getline(cin, cipherText);
      int cipherTextLength = cipherText.length();

      int rootNumber = findRoot(cipherTextLength);
      if (rootNumber == NOT_INTEGER_ROOT) {
        printf("INVALID\n");
        continue;
      }

      for (int i = 0 ; i < rootNumber ; ++i) {
        for (int j = 0 ; j < rootNumber ; ++j) {
          printf("%c", cipherText[i + j * rootNumber]);
        }
      }
      printf("\n");
    }
  }
}