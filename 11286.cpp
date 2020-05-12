/*******************************************************/
/* UVa 11286 Conformity                                */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/09                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX_COURSE_NUMBER = 5;

string join(const vector<string>& strings) {
  string result;
  for (int i = 0 ; i < strings.size() ; ++i) {
    result += strings[i];
  }
  return result;
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF && n != 0) {
    map<string, int> courseCombinationCount;
    for (int i = 0 ; i < n ; ++i) {
      vector<string> courses(MAX_COURSE_NUMBER);
      for (int j = 0 ; j < MAX_COURSE_NUMBER ; ++j) {
        cin >> courses[j];
      }
      sort(courses.begin(), courses.end());
      ++courseCombinationCount[join(courses)];
    }

    int maxNumberStudents = 0;
    int totalNumberStudents = 0;
    for (
      map<string, int>::iterator it = courseCombinationCount.begin() ;
      it != courseCombinationCount.end() ;
      ++it
    ) {
      if (it->second > maxNumberStudents) {
        maxNumberStudents = it->second;
        totalNumberStudents = it->second;
      } else if (it->second == maxNumberStudents) {
        totalNumberStudents += it->second;
      }
    }

    printf("%d\n", totalNumberStudents);
  }

  return 0;
}