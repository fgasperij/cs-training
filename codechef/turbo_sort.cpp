#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::ios_base::sync_with_stdio(false);
  int size;
  std::cin >> size;

  std::vector<int> numbers(10000001, 0);
  int max = 0;
  int temp;
  for (int i = 0; i < size; ++i) {
    std::cin >> temp;
    ++numbers[temp];
    if (temp > max) {
      max = temp;
    }
  }

  for (int i = 1; i <= max; ++i) {
    if (numbers[i]) {
      for (int j = 0; j < numbers[i]; ++j) {
        std::cout << i << '\n';
      }
    }
  }

  return 0;
}
