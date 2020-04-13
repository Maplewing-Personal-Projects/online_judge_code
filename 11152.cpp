/*******************************************************/
/* UVa 11152 Colourful Flowers                         */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/04/14                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  double a, b, c;
  while(scanf("%lf%lf%lf", &a, &b, &c) != EOF){
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    double innerR = area / s;
    double outerR = a * b * c / (4 * area);

    double rosesArea = innerR * innerR * M_PI;
    double violetsArea = area - rosesArea;
    double sunflowersArea = outerR * outerR * M_PI - area;

    printf("%.4lf %.4lf %.4lf\n",
      sunflowersArea,
      violetsArea,
      rosesArea);
  }
  return 0;
}