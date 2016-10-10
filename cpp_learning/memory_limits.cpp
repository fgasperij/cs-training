#include <vector>
#include <iostream>
#include <random>

using namespace std;

int main() {
  vector<int> v(10000000000, 1);
  mt19937 rng;
  rng.seed(random_device()());
  uniform_int_distribution<mt19937::result_type> dist6(1, 100000000);

  for (long long i = 0; i < v.size(); ++i) v[i] = dist6(rng);
  
  return 0;
}
