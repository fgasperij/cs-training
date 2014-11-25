#include <iostream>
#include <string>

int main() {
  int test_cases;
  std::cin >> test_cases;

  // ABDOPQR
  std::string line;
  int holes;
  for (int i = 0; i < test_cases; ++i) {
    holes = 0;
    std::cin >> line;
    for (int j = 0; j < line.length(); ++j) {
      if (line[j] == 'A' ||
          line[j] == 'D' ||
          line[j] == 'O' ||
          line[j] == 'P' ||
          line[j] == 'R' ||
          line[j] == 'Q') { 
        ++holes;
      } else if (line[j] == 'B') {
        holes += 2;
      }
    } 
    std::cout << holes << std::endl;
  }

  return 0;
}
    

