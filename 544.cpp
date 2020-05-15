/*******************************************************/
/* UVa 544 Heavy Cargo                                 */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/13                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <climits>
#include <map>
#include <vector>
using namespace std;

const int UNKNOWN_MAX_WEIGHT = -1;

struct City {
  string name;
  map<string, int> edges;
  int maxWeight;
  bool isVisited;
};

int findMaxWeight(
  map<string, City>& roadMap, 
  const string& sourceCityName, 
  const string& targetCityName
) {
  City* currentCity = &(roadMap[sourceCityName]);
  currentCity->maxWeight = INT_MAX;
  do {
    currentCity->isVisited = true;

    City* nextCity = NULL;
    for (
      map<string, City>::iterator it = roadMap.begin() ;
      it != roadMap.end() ;
      ++it
    ) {
      City* city = &(it->second);
      if (currentCity->edges.find(city->name) != currentCity->edges.end()) {
        int edgeMaxWeight = currentCity->edges[city->name];
        int maxWeight = min(currentCity->maxWeight, edgeMaxWeight);

        if (maxWeight > city->maxWeight) {
          city->maxWeight = maxWeight;
        }
      }
      
      if (
        !city->isVisited && 
        (nextCity == NULL || city->maxWeight > nextCity->maxWeight)
      ) {
        nextCity = city;
      }
    }

    currentCity = nextCity;
  } while (currentCity != NULL && currentCity->maxWeight != UNKNOWN_MAX_WEIGHT);

  return roadMap[targetCityName].maxWeight;
}

int main() {
  int n, r;
  int caseNumber = 1;
  while (scanf("%d%d", &n, &r) != EOF && n != 0 && r != 0) {
    map<string, City> roadMap;

    for (int i = 0 ; i < r ; ++i) {
      string sourceCityName, targetCityName;
      int maxWeight;
      cin >> sourceCityName >> targetCityName >> maxWeight;

      if (roadMap.find(sourceCityName) == roadMap.end()) {
        roadMap[sourceCityName] = (City){
          sourceCityName, map<string, int>(), UNKNOWN_MAX_WEIGHT
        };
      }

      if (roadMap.find(targetCityName) == roadMap.end()) {
        roadMap[targetCityName] = (City){
          targetCityName, map<string, int>(), UNKNOWN_MAX_WEIGHT
        };
      }

      int* sourceToTargetMaxWeightPtr = &roadMap[sourceCityName].edges[targetCityName];
      int* targetToSourceMaxWeightPtr = &roadMap[targetCityName].edges[sourceCityName];
      *sourceToTargetMaxWeightPtr = max(*sourceToTargetMaxWeightPtr, maxWeight);
      *targetToSourceMaxWeightPtr = max(*targetToSourceMaxWeightPtr, maxWeight);
    }

    string sourceCityName, targetCityName;
    cin >> sourceCityName >> targetCityName;
    printf(
      "Scenario #%d\n%d tons\n\n", 
      caseNumber++, 
      findMaxWeight(roadMap, sourceCityName, targetCityName)
    );
  }
  return 0;
}