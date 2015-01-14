#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  char the_zero[] = "0";
  char sequence[1000000];
  int test_case = 1;
  while (scanf("%s\n", sequence) != EOF) {
    if (strcmp(sequence, "\n") == 0) return 0;
    // 10^6 long sequence
    vector<int> zeros(1000001);
    int i_zeros = 0;
    int i = 0;
    while (sequence[i]) {
      if (sequence[i] ==  '0') {
        ++i_zeros;
      }
      zeros[i] = i_zeros;
      ++i;
    }

    printf("Case %d:\n", test_case);

    int queries;
    scanf("%d\n", &queries);
    int left, right, q1, q2;
    for(int j = 0; j < queries; ++j) {
      scanf("%d %d\n", &q1, &q2);
      left = min(q1, q2);
      right = max(q1, q2);
      bool all_ones, all_zeros;
      if (left == 0) {
        all_ones = zeros[right] == 0;
        all_zeros = zeros[right] == right+1; 
      } else {
        all_ones = (zeros[left-1] == zeros[right]);
        all_zeros = (zeros[right]-zeros[left-1] == right-(left-1));
      }
      if (all_zeros || all_ones) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }

    ++test_case;
  }
  return 0;
}
