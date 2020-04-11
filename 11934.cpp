/*******************************************************/
/* UVa 11934 Magic Formula                             */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/11                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int a, b, c, d, L;
  while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &L) != EOF &&
        (a != 0 || b != 0 || c != 0 || d != 0 || L != 0)){
    int count = 0;
    for(int i = 0 ; i <= L ; ++i){
      if((a*i*i + b*i + c) % d == 0) ++count;
    }   
    
    printf("%d\n", count);
  }
  return 0;
}
