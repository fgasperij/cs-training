#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  char my_char;
  while ((my_char = getchar()) != EOF) {
    if (my_char == '\n') { cout << endl;}
    else{ cout << (char)((int)my_char - 7);}
  }

  return 0;
}
