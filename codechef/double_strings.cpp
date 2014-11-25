#include <iostream>

int main()
{
  int test_cases, length;
  std::cin >> test_cases;

  for (int i = 0; i < test_cases; ++i) {
    std::cin >> length;
    std::cout << ((length % 2 == 0) ? length : --length) << std::endl;
  }

  return 0;
}
