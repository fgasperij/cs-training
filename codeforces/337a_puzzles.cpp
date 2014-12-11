#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
  int students, puzzles;
  cin >> students >> puzzles;

  vector<int> puzzles_pieces (puzzles);
  for (int p = 0; p < puzzles; ++p) {
    cin >> puzzles_pieces[p];
  }

  sort(puzzles_pieces.begin(), puzzles_pieces.end());

  int min_difference = numeric_limits<int>::max();
  for (int p = students-1; p < puzzles_pieces.size(); ++p) {
    int diff = puzzles_pieces[p] - puzzles_pieces[p-(students-1)];
    if (diff < min_difference) {
      min_difference = diff;
    }
  }

  cout << min_difference << endl;

  return 0;
}
