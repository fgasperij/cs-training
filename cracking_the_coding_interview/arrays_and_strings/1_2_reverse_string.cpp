#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

void reverse(char *s) {
  int left, right;
  left = 0;
  right = strlen(s)-1;
  while (left < right) {
    swap(s[left], s[right]);
    ++left; --right;
  }
}

int main() {
  const char *inputs[] = {"", "a", "abc", "abcd"};
  const char *outputs[] = {"", "a", "cba", "dcba"};


  for (int i = 0; i < 4; ++i) {
    char *s = (char *)malloc(strlen(inputs[i])+1);
    strcpy(s, inputs[i]);
    reverse(s);
    assert(strcmp(s, outputs[i]) == 0);

    string str(inputs[i]);
    reverse(str.begin(), str.end());
    assert(str.compare(outputs[i]) == 0);
  }

  cout << "All tests passed!\n";

  return 0;

}
