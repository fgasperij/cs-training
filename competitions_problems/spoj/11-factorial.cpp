#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char *argv[])
{
    long long t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        long long maxPow = log10(n)/log10(5);
        long long zeros = 0;
        for (int j = 1; j <= maxPow; j++) {
            zeros += n/pow(5, j); 
        }
        cout << zeros << endl;
    }
    return 0;
}
