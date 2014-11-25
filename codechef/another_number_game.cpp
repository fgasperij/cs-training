#include <iostream>

int main() 
{
  int test_cases;
  std::cin >> test_cases;
  
  long long n;
  for (int i = 0; i < test_cases; ++i) {
    std::cin >> n; 
    std::cout << ((n % 2 == 0) ? "ALICE" : "BOB") << std::endl;
  }

  return 0;
}
