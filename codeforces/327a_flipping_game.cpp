#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
  int discs;
  cin >> discs;

  int ones;
  vector<int> board(discs);
  for (int i = 0; i < discs; ++i) {
    cin >> board[i];
    if (board[i]) {
      ++ones;
    }
  }

  int max = numeric_limits<int>::min();
  vector<vector<int> > dp(discs, vector<int> (discs));
  for (int i = 0; i < discs; ++i) {
    dp[i][i] = board[i] ? -1 : 1;
    if (dp[i][i] > max) {
      max = dp[i][i];
    }
  }

  for(int i = 0; i < discs; ++i) {
    for(int j = i+1; j < discs; ++j) {
      int change = board[j] ? -1 : 1;
      dp[i][j] = dp[i][j-1]+change;
      if (dp[i][j] > max) {
        max = dp[i][j];
      }
    }
  }

  cout << ones+max << endl;

  return 0;
}
