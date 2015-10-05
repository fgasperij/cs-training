#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

#define ROWS 63
#define COLUMNS 100
#define MIDDLE 49
#define MAX_LEVEL 4

using namespace std;

int pow_sums(int n) {
  return pow(2, n+1) - 2;
}

void draw(int level) {
  int first = MIDDLE - (pow_sums(MAX_LEVEL) - pow_sums(MAX_LEVEL-level));
  int size = pow(2, MAX_LEVEL-level);
  int dist_between = size << 2;
  int rows = size << 1;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < COLUMNS; ++j) {
      int dist_from_trunk = i >= size ? 0 : size - i;
      bool is_left_branch = ((j + dist_from_trunk) - first) % dist_between == 0 && j+dist_from_trunk >= first && j+dist_from_trunk < first+dist_between*pow(2, level);
      bool is_right_branch = ((j - dist_from_trunk) - first) % dist_between == 0 && j-dist_from_trunk >= first && j-dist_from_trunk < first+dist_between*pow(2, level);
      bool is_trunk = ((j - first) % dist_between == 0) && i > size && j-first > 0 && j < first+dist_between*pow(2, level);
      if (is_right_branch || is_left_branch || is_trunk) {
        cout << "1";
      } else {
        cout << "_";
      }
    }
    cout << '\n';
  }

}

int main(int argc, char **argv) {
  if (argc > 2) {
    cout << "Wrong number of arguments.\n";
    return 0;
  }

  for (int i = 0; i < COLUMNS; ++i) {
    cout << "_";
  }

  cout << '\n';
  int n = atoi(argv[1]);
  for (int i = n; i >= 0; --i) {
    draw(i);
  }

  return 0;
}
