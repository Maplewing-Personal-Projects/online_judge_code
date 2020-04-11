/*******************************************************/
/* UVa 10344 23 out of 5                               */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/03/25                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
using namespace std;

const int TOTAL_NUMBER_COUNT = 5;
const int IS_USED_NUMBER_TAG = -1;
const int TARGET_NUMBER = 23;

bool IsCanCombinedTo23(int numbers[], int index, int value){
  if(index == TOTAL_NUMBER_COUNT) return value == TARGET_NUMBER;
  
  bool result = false;
  for(int i = 0 ; i < TOTAL_NUMBER_COUNT ; ++i){
    if(numbers[i] != IS_USED_NUMBER_TAG){
      int temp = numbers[i];
      numbers[i] = IS_USED_NUMBER_TAG;
      
      result = result || 
        IsCanCombinedTo23(numbers, index+1, 
          (index == 0)? temp : value + temp) ||
        IsCanCombinedTo23(numbers, index+1, 
          (index == 0)? temp : value - temp) ||
        IsCanCombinedTo23(numbers, index+1, 
          (index == 0)? temp : value * temp);
          
      numbers[i] = temp;
      if(result) break;
    }
  }
  
  return result;
}

int main(){
  int numbers[TOTAL_NUMBER_COUNT];
  while(true){
    bool isAllZero = true;
    for(int i = 0 ; i < TOTAL_NUMBER_COUNT ; ++i){
      scanf("%d", &numbers[i]);
      isAllZero = isAllZero && (numbers[i] == 0);
    }
    if(isAllZero) break;
    
    printf("%s\n", (IsCanCombinedTo23(numbers, 0, 0)) ?
      "Possible" : "Impossible");
  }
  
  return 0;
}
