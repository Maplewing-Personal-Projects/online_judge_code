/*******************************************************/
/* UVa 10190 Divide, But Not Quite Conquer!            */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/08                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

const string BORING_OUTPUT = "Boring!\n";

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n <= 1 || m <= 1) {
      printf("%s", BORING_OUTPUT.c_str());
      continue;
    }

    vector<int> sequence;
    for (int i = n ; i == 1 || (i > 1 && i % m == 0) ; i /= m) {
      sequence.push_back(i);
    }

    int sequenceSize = sequence.size();
    if (sequenceSize == 0 || sequence[sequenceSize - 1] != 1) {
      printf("%s", BORING_OUTPUT.c_str());
      continue;
    }

    for (int i = 0 ; i < sequenceSize ; ++i) {
      if (i > 0) printf(" "); 
      printf("%d", sequence[i]);
    }
    printf("\n");
  }

  return 0;
}