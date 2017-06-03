#include <iostream>

using namespace std;

int main() {
    long long vladik, valera;

    cin >> vladik >> valera;

    int round_candies = 1;
    while (true) {
        vladik -= round_candies;
        if (vladik < 0) {
            cout << "Vladik" << endl;
            break;
        }
        ++round_candies;

        valera -= round_candies;
        if (valera < 0) {
            cout << "Valera" << endl;
            break;
        }
        ++round_candies;
    }

    return 0;
}