/*******************************************************/
/* UVa 10664 Luggage                                   */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/16                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
  int m;
  while(scanf("%d ", &m) != EOF){
    for(int caseNumber = 1 ; caseNumber <= m ; ++caseNumber){
      string input;
      getline(cin, input);
      
      stringstream ss(input);
      vector<int> weights;
      int sum = 0;
      
      int weight;
      while(ss >> weight){
        weights.push_back(weight);
        sum += weight;
      }
      
      if(sum % 2 == 1){
        printf("NO\n");
        continue;
      }
      
      vector<bool> isOneBootPossibleLoadWeight(sum + 1, false);
      isOneBootPossibleLoadWeight[0] = true;
      for(int i = 0 ; i < weights.size() ; ++i){
        for(int j = sum ; j >= weights[i] ; --j){
          if(isOneBootPossibleLoadWeight[j - weights[i]]){
            isOneBootPossibleLoadWeight[j] = true;
          }
        }
      }
      
      printf("%s\n", (isOneBootPossibleLoadWeight[sum / 2] ? "YES" : "NO"));
    }
  }
  return 0;
}
