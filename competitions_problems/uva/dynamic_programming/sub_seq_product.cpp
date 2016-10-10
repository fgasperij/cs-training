#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long long_max(long long a, long long b, long long c) {
  if (a > b && a > c) return a;
  if (b > a && b > c) return b;
  if (c > a && c > b) return c;

  if (a > b) return a;
  return b;
}

long long long_min(long long a, long long b, long long c) {
  if (a < b && a < c) return a;
  if (b < a && b < c) return b;
  if (c < a && c < b) return c;

  if (a < b) return a;
  return b;
}

int main() {
  int tmp;
  cin >> tmp;
  while (!cin.eof()) {
    vector<int> numbers;
    numbers.push_back(tmp);
    cin >> tmp;
    while (tmp != -999999) {
      numbers.push_back(tmp);
      cin >> tmp;
    }

    long long max_prod = numbers[0];
    long long curr_max = numbers[0];
    long long curr_min = numbers[0];
    int tmp_max;
    for (int i = 1; i < numbers.size(); ++i) {
      tmp_max = curr_max;
      curr_max = long_max(numbers[i], numbers[i]*curr_max, numbers[i]*curr_min);
      curr_min = long_min(numbers[i], numbers[i]*tmp_max, numbers[i]*curr_min);
      max_prod = max(max_prod, curr_max);
    }

    cout << max_prod << '\n';

    cin >> tmp;
  }

  return 0;
}
