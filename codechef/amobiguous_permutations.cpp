#include <iostream>
#include <vector>

int main()
{
  int length, temp;
  std::vector<int> permutation(100000, 0);
  std::cin >> length;

  while (length > 0) {
    for (int i = 0; i < length; ++i) {
      std::cin >> temp;
      permutation[i] = temp - 1;
    }

    bool ambiguous = true;
    for (int i = 0; i < length && ambiguous; ++i) {
      if (i != permutation[permutation[i]]) {
        ambiguous = false;
      }
    }
    std::cout << (ambiguous ? "ambiguous" : "not ambiguous") << std::endl;

    std::cin >> length;
  }

  return 0;
}
