#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
  int t, casen = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    deque<char> dq;
    for (int i = 0; i < s.size(); ++i) {
      if (dq.empty() || s[i] >= dq.front()) {
        dq.push_front(s[i]);
      } else {
        dq.push_back(s[i]);
      }
    }

    string last_word(dq.begin(), dq.end());

    cout << "Case #" << casen++ << ": " << last_word << '\n';
  }

  return 0;
}
