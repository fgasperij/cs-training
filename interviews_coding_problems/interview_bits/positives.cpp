#include <vector>
#include <iostream>

using namespace std;

int firstMissingPositive(vector<int> &A) {
    // all negatives
    // misses the first one
    // misses the last one
    int n = A.size();
    cout << "Size: " << n << '\n';
    for (int i = 0; i < n; ++i) {
        if (A[i] > n || A[i] < 1) {
            A[i] = 0;
        }
    }
    
    int temp1, temp2;
    for (int i = 0; i < n; ++i) {
        if (A[i] > 0) {
            temp1 = A[A[i]-1];
            A[A[i]-1] = -1;
            A[i] = 0;
            while (temp1 > 0) {
                temp2 = A[temp1-1];
                A[temp1-1] = -1;
                temp1 = temp2;
            }
        }
    }
    
    cout << "A[0]: " << A[0] << '\n';
    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) {
            return i+1;
        }
    }
    
    return n+1;
}

int main() {
  vector<int> v;
  int temp;
  cin >> temp;
  while (!cin.eof()) {
    v.push_back(temp);
    cin >> temp;
  }

  int res = firstMissingPositive(v);

  cout << res << '\n';

  return 0;
}
