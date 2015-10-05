#include <iostream>

using namespace std;

int main () {

  cout << pow_mod(-1, 1, 20) << '\n';
  
  return 0;
}

int pow_mod(int x, int n, int d) {
    if (n == 0) {
        return 1;
    }
    if (x == 0) {
        return 0;
    }
    
    int accum = ((x % d) + d) % d, res = 1;
    while (n) {
        cout << n << '\n';
        if (1 & n) {
            res = (((accum*res) % d) + d) % d;
        }
        accum = (((accum*accum) % d) + d) % d;
        n >> 1;
    }
    
    return res;
}
