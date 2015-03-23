#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

void print_vector(const vector<int> &A);

class SegmentTree {
  private:
    vector<int> st;
    vector<int> A;
    int n;

    int left(int p);
    int right(int p);
    void build(int p, int l, int r);
    int rmq(int p, int l, int r, int i, int j);

  public:
    SegmentTree(const vector<int> &A);
    int rmq(int i, int j);
};

SegmentTree::SegmentTree(const vector<int> &A) {
  this->A = A;
  n = A.size();
  st.assign(4*n, 0);
  build(1, 0, n-1);
}

void SegmentTree::build(int p, int l, int r) {
  if (l == r) {
    // base case
    st[p] = l;
    return;
  } 

  int l_child = left(p);
  int r_child = right(p);
  build(l_child, l, (r+l)/2);
  build(r_child, (r+l)/2 + 1, r);
  if ( A[st[l_child]] < A[st[r_child]] ) {
    st[p] = st[l_child];
  } else {
    st[p] = st[r_child];
  }
}

int SegmentTree::rmq(int p, int l, int r, int i, int j) {
  if (l >= i && r <= j) {
    return st[p];
  }

  int min_l = -1;
  int min_r = -1;
  if (l <= j && (l+r)/2 >= i) {
    min_l = rmq(left(p), l, (l+r)/2, i, j);
  }
  if ((l+r)/2 + 1 <= j && r >= i) {
    min_r = rmq(right(p), (l+r)/2 + 1, r, i, j);
  }

  if (min_r == -1 || (A[min_l] < A[min_r] && min_l != -1)) {
    return min_l;
  }

  return min_r;
}

int SegmentTree::rmq(int i, int j) {
  return rmq(1, 0, n-1, i, j);
}

int SegmentTree::left(int p) {
  return p << 1;
}

int SegmentTree::right(int p) {
  return (p << 1) + 1;
}

void print_vector(const vector<int> &A) {
  cout << "A: ";
  for (int i = 0; i < A.size(); ++i) {
    cout << A[i] << " ";
  }
  cout << '\n';
}

int main() {
  vector<int> A;
  A.push_back(18); A.push_back(17); A.push_back(13); A.push_back(19); A.push_back(15); A.push_back(11); A.push_back(20);

  //print_vector(A);
  SegmentTree st = SegmentTree(A);
  for (int i = 0; i < A.size(); ++i) {
    for (int j = i; j < A.size(); ++j) {
      int res = st.rmq(i, j);
      cout << "rmq(" << i << ", "<< j << ") = " << res << "\n";
    }
  }

  return 0;
}
