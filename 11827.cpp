/*******************************************************/
/* UVa 11827 Maximum GCD                               */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/14                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int gcd(int a, int b){
  if( a != 0 && b != 0 ){ 
    while((a %= b) && (b %= a));
  }
  return a + b; 
}

int main(){
  int N;
  while(scanf("%d ", &N) != EOF){
    for(int caseNumber = 1 ; caseNumber <= N ; ++caseNumber){
      string input;
      getline(cin, input);
      stringstream ss(input);

      vector<int> integers;
      int inputNumber;
      while(ss >> inputNumber) integers.push_back(inputNumber);

      int maxGCD = 1;
      for(int i = 0 ; i < integers.size() ; ++i){
        for(int j = i+1 ; j < integers.size() ; ++j){
          maxGCD = max(maxGCD, gcd(integers[i], integers[j]));
        }
      }

      printf("%d\n", maxGCD);
    }
  }
  return 0;
}