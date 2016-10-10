#include <iostream>

using namespace std;

int reverseNumber(int a) {
    int reverse = 0;
    while (a) {
        reverse = reverse*10 + a%10;
        a = a/10;
    }

    return reverse;
}

int main() {
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << reverseNumber(reverseNumber(a)+reverseNumber(b)) << endl;
    }

    return 0;
}
