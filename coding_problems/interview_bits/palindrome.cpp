#include <iostream>
#include <cmath>

using namespace std;

int isPalindrome(int A) {
    if (A< 0) {
        return 0;
    }
    
    int digits = 1;
    while (A/(int)pow(10, digits) > 0) {
        ++digits;
    }
    
    int left = A / pow(10, digits-digits/2);
    int right = A % (int) pow(10, digits/2);
    int count = digits/2;
    while (count > 0) {
        if (right % 10 != (left /(int) pow(10, count-1))) {
            return 0;
        }
        left = left % (int) pow(10, count-1);
        right /= 10;
        --count;
    }
    
    return 1;
}

int main() {
  int i = 1234321;
  cout << isPalindrome(i) << '\n';

  return 0;
}
