#include <stdio.h>

bool is_letter(char c) {
  int ic = (int)c;
  return (ic > 64 && ic < 91) || (ic > 96 && ic < 123);
}

int main() {
  char current_char;
  int wc = 0;
  bool onword = false;
  while ((current_char = getchar()) != EOF) {
    if (current_char == '\n') {
      printf("%d\n", wc);
      wc = 0;
      onword = false;
    } else if (onword && !is_letter(current_char)) {
      onword = false;
    } else if (!onword && is_letter(current_char)) {
      onword = true;
      wc++;
    }
  }
  return 0;
}
