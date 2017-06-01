#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int peds = 3;
    vector<vector<bool> > lights(4, vector<bool> (4));
    int t;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> t;
            lights[i][j] = t == 1;
        }
    }

    int right, left, opposite;
    for (int i =0; i < 4; ++i) {
        right = (i + 1) % 4;
        left = (i + 3) % 4;
        opposite = (i + 2) % 4;
        if (lights[i][peds] && (lights[i][0] || lights[i][1] || lights[i][2] || lights[right][0] || lights[opposite][1] || lights[left][2]) ) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;

}