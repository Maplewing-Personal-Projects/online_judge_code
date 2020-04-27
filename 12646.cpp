/*******************************************************/
/* UVa 12646 Zero or One                               */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/27                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int aChoose, bChoose, cChoose;
  while (scanf("%d%d%d", &aChoose, &bChoose, &cChoose) != EOF) {
    if (aChoose != bChoose && aChoose != cChoose) printf("A\n");
    else if (bChoose != aChoose && bChoose != cChoose) printf("B\n");
    else if (cChoose != aChoose && cChoose != bChoose) printf("C\n");
    else printf("*\n");
  }
  return 0;
}