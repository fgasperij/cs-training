#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  if (A.empty()) return -1;
  if (A.size() == 1) return 0;
  
  stack<int> s;
  for (int i = 0; i < A.size()-1; ++i) {
    if (s.empty() || (A[i] < A[s.top()])) {
      cout << "i=" << i << " elem=" << A[i];
      if (!s.empty()) {
        cout << "s.top()=" << s.top() << " ";
      }
      s.push(i);
    }
  }
  cout << "s.top()=" << s.top() << " ";
  int max_gap = 0;
  for (int i = A.size()-1; i >= 0; --i) {
    while (!s.empty() && A[i] >= s.top()) {
      cout << "i=" << i << " ";
      max_gap = max(max_gap, i-s.top());
      cout << "max_gap=" << max_gap << " ";
      s.pop();
    }
  }

  cout << "max_gap=" << max_gap;
  cout << '\n';
    
  return 0;
}

