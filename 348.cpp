#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
using namespace std;

struct Matrix {
  int row;
  int column;
};

struct DPData {
  int multipleTimes;
  int splitIndex;
};

void PrintMultipleSequence(
  vector< vector<DPData> > &minMultipleTimes, 
  int startIndex, 
  int endIndex
) {
  if (startIndex == endIndex) {
    printf("A%d", startIndex + 1);
    return;
  }

  int splitIndex = minMultipleTimes[startIndex][endIndex].splitIndex;
  printf("(");
  PrintMultipleSequence(minMultipleTimes, startIndex, splitIndex);
  printf(" x ");
  PrintMultipleSequence(minMultipleTimes, splitIndex + 1, endIndex);
  printf(")");
}

int main() {
  int N;
  int caseNumber = 1;
  while (scanf("%d", &N) != EOF && N != 0) {
    vector<Matrix> matrixSequence;
    for (int i = 0 ; i < N ; ++i) {
      Matrix input;
      scanf("%d%d", &(input.row), &(input.column));
      matrixSequence.push_back(input);
    }

    vector< vector<DPData> > minMultipleTimes(N, vector<DPData>(N, (DPData){ INT_MAX, -1 }));
    for (int index = 0 ; index < N ; ++index) {
      minMultipleTimes[index][index].multipleTimes = 0;
      minMultipleTimes[index][index].splitIndex = index;
    }

    for (int length = 1 ; length < N ; ++length) {
      for (int startIndex = 0 ; startIndex + length < N ; ++startIndex) {
        int endIndex = startIndex + length;
        for (int split = 0 ; split < length ; ++split) {
          int splitIndex = startIndex + split;
          int multipleTimes = minMultipleTimes[startIndex][splitIndex].multipleTimes + 
              minMultipleTimes[splitIndex + 1][endIndex].multipleTimes + 
              matrixSequence[startIndex].row * matrixSequence[splitIndex].column * matrixSequence[endIndex].column;
          
          if (multipleTimes < minMultipleTimes[startIndex][endIndex].multipleTimes) {
            minMultipleTimes[startIndex][endIndex].multipleTimes = multipleTimes;
            minMultipleTimes[startIndex][endIndex].splitIndex = splitIndex;
          }
        }
      }
    }

    printf("Case %d: ", caseNumber++);
    PrintMultipleSequence(minMultipleTimes, 0, N - 1);
    printf("\n");
  }

  return 0;
}