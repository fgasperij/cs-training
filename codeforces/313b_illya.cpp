#include <iostream>
#include <string>

using namespace std;

int main()
{
  int MAX_LENGTH = 100000;
  int partials[MAX_LENGTH];
  string sequence;

  cin >> sequence;
  partials[0] = 0;
  for (int i = 1; i < sequence.length(); ++i) {
    if (sequence[i] == sequence[i-1]) {
      partials[i] = partials[i-1] + 1;
    } else {
      partials[i] = partials[i-1];
    }
  }

  int queries, q_left, q_right;
  cin >> queries;
  for (int i = 0; i < queries; ++i) {
    cin >> q_left >> q_right;
    cout << partials[q_right-1] - partials[q_left-1] << endl;
  }

  return 0;
}
