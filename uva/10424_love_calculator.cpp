#include <stdio.h>
#include <algorithm>

using namespace std;

int ascii_sum(char name[])
{
  int i = 0, sum = 0, ascii_value;
  while (name[i]) {
    ascii_value = (int)name[i];
    bool lowercase_letter = ascii_value >= 97 && ascii_value <= 122;
    bool uppercase_letter = ascii_value >= 65 && ascii_value <= 90;
    if (lowercase_letter) {
      sum += (ascii_value-96);
    }
    if (uppercase_letter) {
      sum += (ascii_value-64);
    }
    ++i;
  }

  return sum;
}

int reduce_to_one_digit(int number)
{
  int reduced = number;
  while(reduced > 9) {
    int digits = reduced;
    int sum = 0;
    while(digits) {
      sum += (digits % 10);
      digits /= 10;
    }
    reduced = sum;
  }

  return reduced;
}

int main()
{
  // a = 97 z = 122
  // A = 65 Z = 90
  char first_name[26];
  char second_name[26];
  while (gets(first_name)) {
    gets(second_name);
    int first_sum = ascii_sum(first_name);
    int second_sum = ascii_sum(second_name);
    int first_reduced = reduce_to_one_digit(first_sum);
    int second_reduced = reduce_to_one_digit(second_sum);
    float love_percentage = ((float)min(first_reduced, second_reduced)/(float)max(first_reduced, second_reduced))*100;
    printf("%.2f %%\n", love_percentage);
  }

  return 0;
}
