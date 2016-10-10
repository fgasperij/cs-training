#include <iostream>
#include <string>

using namespace std;

int main() {
  int messages;
  cin >> messages;
  while (messages--) {
    string line;
    cin >> line;
    int message_length = line.length()-2;
    string message(message_length, 0);

    for (int i = 1; i < 9; ++i) {
      cin >> line;
      for (int j = 1; j < line.length()-1; ++j) {
        int val = line[j] == '\\' ? 1 : 0;
        val <<= i-1;
        message[j-1] |= val;
      }
    }
    cin.ignore(message_length+1000, '\n');
    cin.ignore(10000, '\n');
    cout << message << '\n';
  }

  return 0;
}
