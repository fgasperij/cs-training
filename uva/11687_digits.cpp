#include <stdio.h>
#include <string.h>

int main()
{
  const int MAX_DIGITS = 1000100;
  char digits[MAX_DIGITS];
  scanf("%s", digits);
  while (strcmp(digits, "END") != 0) {
    int digits_length = strlen(digits);
    int first_i;
    if (strcmp(digits, "1") == 0) {
      first_i = 1;
    } else if (digits_length == 1) {
      first_i = 2;
    } else if (digits_length < 10) {
      first_i = 3;
    } else {
      first_i = 4;
    }
    
    printf("%d\n", first_i);

    scanf("%s", digits);
  }

  return 0;
}
