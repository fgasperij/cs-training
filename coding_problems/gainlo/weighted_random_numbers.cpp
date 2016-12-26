// Write a function that returns random numbers according to their weights.
// - for simplicity let's assume the input form is vector<int> numbers, vector<int> weights
// - a brute force approach would be to pick a random number between [1, sum(weights)] and then
//   check which number does it correspond to.

#include <vector>
#include <numeric>
#include <stdlib.h>

using namespace std;

int weighted_random(const vector<int>& numbers, const vector<int>& weights) {
  int n = accumulate(weights.begin(), weights.end(), 0);

  int i = (rand() % n)+1 - weights[0];
  int j = 0;

  while (i > 0) {
    i -= weights[++j];
  }

  return numbers[j];
}
