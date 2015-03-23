#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

void print_vector(const vector<int> &A);

class RSQSegmentTree {
  private:
    vector<int> st;
    vector<int> A;
    int n;

    int left(int p);
    int right(int p);
    void build(int p, int l, int r);
    int rsq(int p, int l, int r, int i, int j);

  public:
    RSQSegmentTree(const vector<int> &A);
    int rsq(int i, int j);
};

RSQSegmentTree::RSQSegmentTree(const vector<int> &A) {
  this->A = A;
  n = A.size();
  st.assign(4*n, 0);
  build(1, 0, n-1);
}

void RSQSegmentTree::build(int p, int l, int r) {
  if (l == r) {
    // base case
    st[p] = A[l];
    return;
  } 

  int l_child = left(p);
  int r_child = right(p);
  build(l_child, l, (r+l)/2);
  build(r_child, (r+l)/2 + 1, r);
  st[p] = st[l_child] + st[r_child];
}

int RSQSegmentTree::rsq(int p, int l, int r, int i, int j) {
  if (l >= i && r <= j) {
    return st[p];
  }
  if (j < l || i > r) {
    return 0;
  }

  int sum_l = rsq(left(p), l, (l+r)/2, i, j);
  int sum_r = rsq(right(p), (l+r)/2 + 1, r, i, j);

  return sum_l + sum_r;
}

int RSQSegmentTree::rsq(int i, int j) {
  return rsq(1, 0, n-1, i, j);
}

int RSQSegmentTree::left(int p) {
  return p << 1;
}

int RSQSegmentTree::right(int p) {
  return (p << 1) + 1;
}

void print_vector(const vector<int> &A) {
  cout << "A: ";
  for (int i = 0; i < A.size(); ++i) {
    cout << A[i] << " ";
  }
  cout << '\n';
}

int sum_range(const vector<int> &A, int i, int j) {
  int acum = 0;
  for (int s = i; s <= j; ++s) {
    acum += A[s];
  }

  return acum;
}


int main() {
  vector<int> A;
  A.push_back(18); A.push_back(17); A.push_back(13); A.push_back(19); A.push_back(15); A.push_back(11); A.push_back(20);

  //print_vector(A);
  RSQSegmentTree st = RSQSegmentTree(A);
  for (int i = 0; i < A.size(); ++i) {
    for (int j = i; j < A.size(); ++j) {
      int res = st.rsq(i, j);
      int sum = sum_range(A, i, j);
      cout << "rsq(" << i << ", "<< j << ") = " << res << " should be " << sum;
      if (res != sum) {
        cout << " WRONG!";
      }
      cout << "\n";
    }
  }

  return 0;
}
