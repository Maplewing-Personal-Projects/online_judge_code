/*******************************************************/
/* UVa 10179 Irreducable Basic Fractions               */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2020/05/07                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int SQRT_INPUT_UPPER_BOUND = 31622;

class PrimeTable {
  private:
    vector<int> _primeNumber;

  public:
    PrimeTable(int size) {
      vector<bool> isPrime(size + 1, true);
      isPrime[0] = false;

      for (int i = 2 ; i <= size ; ++i) {
        if (isPrime[i]) {
          _primeNumber.push_back(i);
          for (int j = i + i ; j <= size ; j += i) {
            isPrime[j] = false;
          }
        }
      }
    }

    int count() const {
      return _primeNumber.size();
    }

    int operator[](int i) const {
      return _primeNumber[i];
    }
};

long long int getEuler(const PrimeTable& primeTable, int n) {
  int number = n;
  long long int result = n;
  int totalPrimeCount = primeTable.count();

  for (int i = 0 ; i < totalPrimeCount ; ++i) {
    int currentPrimeNumber = primeTable[i];
    if (number % currentPrimeNumber == 0) {
      result /= currentPrimeNumber;
      result *= currentPrimeNumber - 1;
      
      while (number % currentPrimeNumber == 0) {
        number /= currentPrimeNumber;
      }
    }
  }

  if (number > 1) {
    result /= number;
    result *= number - 1;
  }

  return result;
}

int main() {
  PrimeTable primeTable(SQRT_INPUT_UPPER_BOUND + 5);

  int n;
  while (scanf("%d", &n) != EOF && n != 0) {
    printf("%lld\n", getEuler(primeTable, n));
  }
  
  return 0;
}