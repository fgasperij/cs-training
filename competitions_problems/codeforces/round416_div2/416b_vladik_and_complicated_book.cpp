#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, tests;
    cin >> n >> tests;

    vector<int> p(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    int l, r, x;
    for (int t = 0; t < tests; ++t) {
        cin >> l >> r >> x;
        int value = p[x];
        int smallers = 0;
        for (int i = l; i <= r; ++i) {
            if (p[i] < value) {
                ++smallers;
            }
        }
        if (x == l + smallers) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
