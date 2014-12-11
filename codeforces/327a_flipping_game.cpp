#include <iostream>
#include <vector>
#include <algorithm>

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

  int max_so_far = -1;
  int previous_position_max = 0;
  for (int i = 0; i < discs; ++i) {
    int current = board[i] ? -1 : 1; 
    previous_position_max = max(current, previous_position_max+current);
    max_so_far = max(max_so_far, previous_position_max); 
  }

  cout << ones+max_so_far << endl;

  return 0;
}
