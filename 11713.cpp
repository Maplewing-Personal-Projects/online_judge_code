/*******************************************************/
/* UVa 11713 Abstract Names                            */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/13                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool isVowel(char c){
  return c == 'a' || c == 'e' || 
    c == 'i' || c == 'o' || c == 'u';
}

int main(){
  int n;
  while(scanf("%d ", &n) != EOF){
    for(int caseNumber = 1 ; caseNumber <= n ; ++caseNumber){
      string a, b;
      getline(cin, a);
      getline(cin, b);

      if(a.length() != b.length()){
        printf("No\n");
        continue;
      }

      bool isSame = true;
      for(int i = 0 ; i < a.length() ; ++i){
        if(a[i] != b[i] && (!isVowel(a[i]) || !isVowel(b[i]))){
          isSame = false;
          break;
        }
      }

      printf("%s\n", isSame ? "Yes" : "No");
    }
  }

  return 0;
}