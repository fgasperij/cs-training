#include <stdlib.h>

int* spiral_lines(int n) {
  if (n < 0) return NULL;
  if (n == 0) return NULL;

  int* m = malloc(sizeof(int) * n * n);
  int spi = 1, n2 = n * n, i = 0;
  while (i < n2) {
    int last = (n-1)-i;
    int first = i;
    for (int j = first; j <= last; ++j) {
      m[first][j] = spi;
      ++spi;
    }
    for (int j = first+1; j < last; ++j) {
      m[j][last] = spi;
      ++spi;
    }
    for (int j = last; j > first; --j) {
      m[last][j] = spi;
      ++spi;
    }
    for (int j = last; j > first; --j) {
      m[j][first] = spi;
      ++spi;
    }

    ++i;
  }

  return m;
}
