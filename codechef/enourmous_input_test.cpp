#include <iostream>

int main ()
{
  std::ios_base::sync_with_stdio(false);
  long long n, k, t, result = 0;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> t;
    if (t % k == 0) {
      ++result;
    }
  }

  std::cout << result << std::endl;

  return 0;
    
}
