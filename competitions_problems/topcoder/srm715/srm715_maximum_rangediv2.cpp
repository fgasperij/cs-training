#include <string>
#include <algorithm>

using namespace std;

class MaximumRangeDiv2 {
public:
  int findMax(string s) {
      int pluses = count(s.begin(), s.end(), '+');
      int minuses = s.size() - pluses;

      return max(pluses, minuses);
  }
};