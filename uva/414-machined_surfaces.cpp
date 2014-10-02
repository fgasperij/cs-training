#include <iostream>
#include <string>

using namespace std;

int main() {
  int rows;
  cin >> rows;
  cin.ignore();
  while (rows) {
    string line;
    int image_spaces = 0, min_spaces = 23;
    for(int i = 0; i < rows; i++) {
      int line_spaces = 0;
      getline(cin, line);
      for (int j = 0; j < 25; j++) {
        if (line[j] == ' ') {
          line_spaces++;
        }
      }
      image_spaces += line_spaces;
      if (line_spaces < min_spaces) {
        min_spaces = line_spaces;
      }
    }
    int leftover_spaces = image_spaces - (min_spaces * rows);
    cout << leftover_spaces << endl;
    cin >> rows;
    cin.ignore();
  }

  return 0;

}
