/*******************************************************/
/* UVa 10347 Medians                                   */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/12                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool isTriangle(double a, double b, double c){
  return a + b > c && a + c > b && b + c > a;
}

int main(){
  double medianA, medianB, medianC;
  while(scanf("%lf%lf%lf", &medianA, &medianB, &medianC) != EOF){
    double medianTriangleA = 2.0 / 3.0 * medianA;
    double medianTriangleB = 2.0 / 3.0 * medianB;
    double medianTriangleC = 2.0 / 3.0 * medianC;

    if(!isTriangle(medianTriangleA, medianTriangleB, medianTriangleC)){
      printf("-1.000\n");
      continue;
    }

    double medianTriangleS = (medianTriangleA + medianTriangleB + medianTriangleC) / 2;
    double medianArea = sqrt(medianTriangleS * (medianTriangleS - medianTriangleA) * (medianTriangleS - medianTriangleB) * (medianTriangleS - medianTriangleC));
    double area = medianArea * 3;

    printf("%.3lf\n", area);
  }
  return 0;
}