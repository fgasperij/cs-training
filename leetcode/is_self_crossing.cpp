/* 335. Self crossing
 * You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres 
 * to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east 
 * and so on. In other words, after each move your direction changes counter-clockwise.
 **/

#include <vector>

using namespace std;

bool isSelfCrossing(vector<int>& x) {
  if (x.size() < 4) return false;

  int i = 2;
  while (x[i-2] < x[i]) ++i;

  vector<int> moves(4);
  moves[i%4] = x[i];
  moves[(i-1)%4] = x[i-1];
  moves[(i-2)%4] = x[i-2];
  moves[(i-3)%4] = i > 2 ? x[i-3] : 0;

  if (i == 3 && x[i] == x[i-2]) moves[(i-1)%4] -= moves[(i-3)%4]; 
  if (i > 3) {
    int diff = x[i-2] - x[i-4];
    if (x[i] >= diff) moves[(i-1)%4] -= x[i-3];
  }
  ++i;

  while (i < x.size()) {
    if (moves[(i-2)%4] <= x[i]) return true;
    moves[i%4] = x[i];
    ++i;
  }

  return false;
}
