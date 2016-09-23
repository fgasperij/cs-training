#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
  int l = 0, r = 0, cl = 0, candies = ratings.size(), n = candies;
  if (ratings.empty()) return 0;

  bool decreasing = false;
  while (l < n-1) {
    if (ratings[r+1] > ratings[r]) {
      decreasing = false;
      while (r < n-1 && ratings[r+1] > ratings[r]) ++r;
    } else if (ratings[r+1] < ratings[r]) {
      decreasing = true;
      while (r < n-1 && ratings[r+1] < ratings[r]) ++r;
    } else {
      ++l;
      ++r;
      cl = 0;
      continue;
    }

    candies += ((r-l)*(r-l+1))/2;
    if (decreasing && cl > 0) {
      if (cl < r-l ) {
        candies -= cl;
      } else {
        candies -= r-l;
      }
    } else if (!decreasing) {
      cl = r-l;
    }

    l = r;
  }

  return candies;
}
