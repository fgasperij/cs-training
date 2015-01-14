#include <iostream>
#include <string>

using namespace std;

int main()
{
  string text;
  /*
  cout << "Text parsed with getline.\n\n";
  while(!cin.eof()) {
    getline(cin, text);
    cout << text;
  }
  */
  cout << "Text parsed with cin.\n\n";
  int i = 0;
  while(!cin.eof()) {
    if (i % 2) {
      cin >> text;
      cout << text;
    } else {
      getline(cin, text, ' ');
      cout << text;
    }
    ++i;
  }

  return 0;
}
