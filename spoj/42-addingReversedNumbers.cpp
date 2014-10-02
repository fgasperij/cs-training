#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int reverseNumber(int a)
{
    int reverse = 0;
    while (a) {
        reverse = reverse*10 + a%10;
        a = a/10;
    }

    return reverse;
}

int main(int argc, const char *argv[])
{
    int n, a, b;
    cin >> n;
    int sums[n];
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        sums[i] = reverseNumber(reverseNumber(a)+reverseNumber(b));

    }
    for(int i = 0; i < n; i++) {
        cout << sums[i] << endl;
    }
    return 0;
}
