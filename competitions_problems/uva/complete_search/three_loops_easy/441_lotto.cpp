#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_items(vector<int> items, vector<int> numbers) {
  for (int i = 0; i < 6; ++i) {
    cout << numbers[items[i]];
   if (i != 5) cout << " ";
  }
  cout << '\n';
}

int main() {
  int k;
  cin >> k;
  bool first = true;
  while (k) {
    if (!first) {
      cout << '\n';
    } else {
      first = false;
    }
    vector<int> numbers(k, 0);
    for (int i = 0; i < k; ++i) cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    vector<int> items(6, -1);
    items[0] = 0;
    int i = 1;
    while (true) {
      if (i == 6) {
        print_items(items, numbers);
        --i;
        while (i >= 0 && items[i] == k-(6-i)) --i;
        if (i == -1) break;
        ++items[i];
        for (int j = i+1; j < 6; ++j) items[j] = -1;
      } else if (items[i] == -1) {
        items[i] = items[i-1]+1;
      }
      ++i;
    }
    cin >> k;
  }

  return 0;
}
