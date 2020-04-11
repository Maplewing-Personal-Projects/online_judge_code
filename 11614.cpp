/*******************************************************/
/* UVa 11614 Etruscan Warriors Never Play Chess        */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/01/28                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  int totalCaseCount;
  while(scanf("%d", &totalCaseCount) != EOF){
    for(int caseNumber = 1 ; caseNumber <= totalCaseCount ; ++caseNumber){
      long long int n;
      scanf("%lld", &n);
      
      long long int result = (-1 + sqrt(1 + 4 * 2 * n)) / 2;
      printf("%lld\n", result);
    }
  }
  return 0;
}
