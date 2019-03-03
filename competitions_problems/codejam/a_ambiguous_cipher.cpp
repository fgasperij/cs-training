#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string m;
        cin >> m;

        if (count(m.begin(), m.end(), 'A') == m.size()) {
            cout << "Case #" << i << ": " << m << endl;
            continue;
        }
        
        int n = m.size();
        string d;
        d.resize(n);
        vector<bool> decrypted(n, false);
        decrypted[1] = true;
        d[1] = m[0];
        decrypted[n-2] = true;
        d[n-2] = m.back();

        bool updated = true;
        int chars_left = n - 2;
        while (updated) {
            updated = false;
            for (int i = 0; i < n; ++i) {
                if (!decrypted[i] && ( (i > 0 && m[i - 1] == 'A') || (i < n - 1 && m[i + 1] == 'A') )) {
                    decrypted[i] = true;
                    updated = true;
                    d[i] = 'A';
                    --chars_left;
                }
                if (decrypted[i] && i - 2 >= 0 && !decrypted[i - 2]) {
                    decrypted[i - 2] = true;
                    d[i - 2] = (((m[i - 1] - d[i]) + 26) % 26) + (int)'A';
                    updated = true;
                    --chars_left;
                }
                if (decrypted[i] && i + 2 < n && !decrypted[i + 2]) {
                    decrypted[i + 2] = true;
                    d[i + 2] = (((m[i + 1] - d[i]) + 26) % 26) + (int)'A';
                    updated = true;
                    --chars_left;
                }
            }
        }

        cout << "Case #" << i << ": ";
        if (chars_left > 0) {
            cout << "AMBIGUOUS";
        } else {
            cout << d;
        }
        cout << endl;
    }

    return 0;
}