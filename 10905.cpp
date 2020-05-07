/*******************************************************/
/* UVa 10905 Children's Game                           */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/07                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(const string& a, string& b) {
  return a + b > b + a;
}

int main() {
  int N;
  while (scanf("%d", &N) != EOF && N != 0) {
    vector<string> numbers;
    for (int i = 0 ; i < N ; ++i) {
      string input;
      cin >> input;
      numbers.push_back(input);
    }

    sort(numbers.begin(), numbers.end(), compare);
    string result;
    for (int i = 0 ; i < numbers.size() ; ++i) {
      result += numbers[i];  
    }

    printf("%s\n", result.c_str());
  }

  return 0;
}