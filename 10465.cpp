/*******************************************************/
/* UVa 10465 Homer Simpson                             */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/28                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
  int m, n, t;
  while (scanf("%d%d%d", &m, &n, &t) != EOF) {
    int minBurgerTime = min(m, n);
    int maxBurgerTime = max(m, n);

    int maxBurgerAmount = t / minBurgerTime;
    int remainingTime = t - maxBurgerAmount * minBurgerTime;
    for (int i = maxBurgerAmount - 1 ; i >= 0 && remainingTime != 0 ; --i) {
      int currentRemainingTime = t - i * minBurgerTime;
      int anotherBurgerAmount = currentRemainingTime / maxBurgerTime;
      currentRemainingTime -= anotherBurgerAmount * maxBurgerTime;
      
      if (currentRemainingTime < remainingTime) {
        maxBurgerAmount = i + anotherBurgerAmount;
        remainingTime = currentRemainingTime;
      }
    }

    printf("%d", maxBurgerAmount);
    if (remainingTime > 0) printf(" %d", remainingTime);
    printf("\n");
  }
  return 0;
}