/*******************************************************/
/* UVa 12502 Three Families                            */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/01/22                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int T;
  while(scanf("%d", &T) != EOF){
    for(int caseNumber = 1 ; caseNumber <= T ; ++caseNumber){
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      printf("%d\n", z * (2*x - y) / (x + y));
    }
  }
  
  return 0;
}
