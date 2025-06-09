#include <vector>
#include <algorithm>

using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
  vector<int> uglies(1, 1);
  vector<int> ptrs(primes.size(), 0);
  vector<int> values = primes;

  while (uglies.size() < n) {
    vector<int>::iterator next = min_element(values.begin(), values.end());
    if (*next > uglies.back()) uglies.push_back(*next);

    int k = next-values.begin();
    *next = uglies[++ptrs[k]]*primes[k];
  }

  return uglies[n-1];
}
