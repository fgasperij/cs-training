#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int test_cases, rows; 
  std::vector<std::vector<int> > triangle(100, std::vector<int> (100, 0));

  std::cin >> test_cases;

  for (int i = 0; i < test_cases; ++i) {
    std::cin >> rows;
    for (int j = 0; j < rows; ++j) {
      for (int c = 0; c <=j; ++c) {
        std::cin >> triangle[j][c];
      }
    }
    for (int r = (rows-2); r >= 0; --r) {
      for ( int c = 0; c <= r; ++c) {
        triangle[r][c] = triangle[r][c] + std::max(triangle[r+1][c], triangle[r+1][c+1]);
      }
    }

    std::cout << triangle[0][0] << std::endl;
  }

  return 0;
}
