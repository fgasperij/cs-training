#include <iostream>

using namespace std;

void remove_duplicates(char *s) {
  if (s == NULL || strlen(s) == 0) return;

  bool seen[256];
  for (int i = 0; i < 256; ++i) seen[i] = false;
  int tail = 0;
  int l = strlen(s);
  for (int i = 0; i < l; ++i) {
    if (seen[s[i]]) continue;
    s[tail] = s[i];
    seen[s[i]] = true;
    ++tail;
  }

  s[tail] = 0;
}

int main(int argc, char *argv[]) {

  char *s = argv[1];
  remove_duplicates(s);
  cout << s << '\n';

  return 0;
}
