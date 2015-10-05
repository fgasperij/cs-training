#include <iostream>
#include <string>
#include <regex>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
  const int MAX_LINE = 500;
  const regex IPV4_RX = regex("([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})");
  const regex IPV6_RX = regex("([0-9a-f]{4})\\:([0-9a-f]{4})\\:([0-9a-f]{4})\\:([0-9a-f]{4})\\:([0-9a-f]{4})\\:([0-9a-f]{4})\\:([0-9a-f]{4})\\:([0-9a-f]{4})");

  int tests;
  cin >> tests;
  while (tests--) {
    char text[MAX_LINE];
    cin >> text;
    string s(text);
    if (regex_match(s, IPV4_RX)) {
      char *numbers = strtok(text, ".");
      bool all_in_range = true;
      while (numbers != NULL) {
        int number = atoi(numbers);
        all_in_range = all_in_range && (number < 256);
        numbers = strtok(NULL, ".");
      }
      cout << (all_in_range ? "IPv4" : "Neither");
    } else if (regex_match(s, IPV6_RX)) {
      cout << "IPv6";
    } else {
      cout << "Neither";
    }

    cout << '\n';
  }

  return 0;
}
