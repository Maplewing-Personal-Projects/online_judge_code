#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main () {
  int T;
  while (scanf("%d", &T) != EOF) {
    for (int caseNumber = 1 ; caseNumber <= T ; ++caseNumber) {
      int n, P, Q;
      scanf("%d%d%d", &n, &P, &Q);

      vector<int> eggs;
      for (int i = 0 ; i < n ; ++i) {
        int egg;
        scanf("%d", &egg);
        eggs.push_back(egg);
      }

      vector<int> weightDPTable(Q + 1, 0);
      for (int i = 0 ; i < n ; ++i) {
        for (int j = Q ; j >= eggs[i] ; --j) {
          weightDPTable[j] = max(weightDPTable[j], weightDPTable[j - eggs[i]] + 1);
        }
      }

      printf("Case %d: %d\n", caseNumber, min(weightDPTable[Q], P));
    }
  }

  return 0;
}